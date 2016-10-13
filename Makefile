CFLAGS = -std=c99 -O3 -mavx2
LDLIBS = -lcblas -latlas -lm
DEPS = cblas.h 
all: chemm_naive chemm_atlas chemm_fast

chemm_naive : chemm.c naive.o
	gcc $(CFLAGS) $(LDFLAGS) chemm.c naive.o -o chemm_naive $(LDLIBS) 

chemm_atlas : chemm.c atlas.o
	gcc $(CFLAGS) $(LDFLAGS) chemm.c atlas.o -o chemm_atlas  $(LDLIBS)

chemm_fast : chemm.c fast.o
	gcc $(CFLAGS) $(LDFLAGS) -mavx2 chemm.c fast.o -o chemm_fast $(LDLIBS) -fopenmp

%.o : %.c $(DEPS)
	gcc $(CFLAGS) -mavx2 -O3 -c -fopenmp $<

clean:
	rm -f chemm_* *.o
