#include <complex.h>
#include <xmmintrin.h>
#include <pmmintrin.h>
#include <math.h>
//Currently just a copy of naive...

void chemm(complex float* A,
        complex float* B,
        complex float* C,
        int m,
        int n,
        complex float alpha,
        complex float beta){
  //  printf("imag part:%f",A[1]);
        float trueReal=0.0, firstMix=0.0, secondMix=0.0, trueImag=0.0;
    for(int x = 0; x < n; x++){
        for(int y = x; y < m; y++){
            C[y*n + x] *= beta;
            for(int z = x; z < m; z++){
		trueReal = creal(A[y*m+z])*cimag(B[z*n+x]);
                firstMix = creal(A[y*m+z])*cimag(B[z*n+x]);
                secondMix = cimag(A[y*m+z])*creal(B[z*n+x]);
                trueImag = cimag(A[y*m+z])*cimag(B[z*n+x]);

                C[y*n + x] = trueReal + trueImag + (firstMix + secondMix)*I;
                C[x*n + y] = trueReal - trueImag + (firstMix - secondMix);                 
 
               // C[y*n + x] += alpha*A[y*m+z]*B[z*n + x];
            }
        }
    }

}
