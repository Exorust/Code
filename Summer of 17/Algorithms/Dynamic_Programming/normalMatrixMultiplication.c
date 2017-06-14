#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]) {
  int i,j,l,n;
  scanf("%d",&n);
  int **a,**b,**c;
  a=(int**)malloc(n*sizeof(int*));
  for (i=0; i<n; i++)
         a[i] = (int *)malloc(n * sizeof(int));
  b=(int**)malloc(n*sizeof(int*));
  for (i=0; i<n; i++)
         b[i] = (int *)malloc(n * sizeof(int));
  c=(int**)malloc(n*sizeof(int*));
  for (i=0; i<n; i++)
         c[i] = (int *)malloc(n * sizeof(int));
  printf("Now type the matrix\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d",&a[i][j] );
    }
  }
  printf("Now type second matrix\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d",&b[i][j] );
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
    c[i][j]=0;
    printf("z\n" );
      for (l = 0; l < n; l++) {
        c[i][j]+=a[i][l]*b[l][j];
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ",c[i][j] );
    }
    printf("\n");
  }
    return 0;
}
