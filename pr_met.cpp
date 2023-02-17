
#include <iostream>

y = matA[0][0];
  a[0] = -matA[0][1] / y;
  B[0] = matB[0] / y  ;
  for (int i = 1; i < N1; i++) {
    y = matA[i][i] + matA[i][i - 1] * a[i - 1];
    a[i] = -matA[i][i + 1] / y;
    B[i] = (matB[i] - matA[i][i - 1] * B[i - 1]) / y;
  }


matRes[N1] = (matB[N1] - matA[N1][N1 - 1] * B[N1 - 1]) / (matA[N1][N1] + matA[N1][N1 - 1] * a[N1 - 1]);
  for (int i = N1 - 1; i >= 0; i--) {
    matRes[i] = a[i] * matRes[i + 1] + B[i];
  }
