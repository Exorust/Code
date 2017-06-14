#include<stdio.h>
#include<stdlib.h>

void add(int a[][],int b[][],int c[][],int n){
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      c[i][j]=a[i][j]+b[i][j];
    }
  }
}

void subtract(int a[][],int b[][],int c[][],int n){
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      c[i][j]=a[i][j]-b[i][j];
    }
  }
}
void copying(int a[][],int a11[][],int a12[][],int a21[][],int a22[][],int n){
  for ( i = 0; i < n/2; i++) {

    
  }
}

void mult(int a[][],int b[][],int c[][],int n){
  if(n>2){
    l=n/2;
    int** a11;
    a11=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           a11[i] = (int *)malloc(l * sizeof(int));
    }
    int** a12;
    a12=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           a12[i] = (int *)malloc(l * sizeof(int));
    }
    int** a21;
    a21=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           a21[i] = (int *)malloc(l * sizeof(int));
    }
    int** a22;
    a22=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           a22[i] = (int *)malloc(l * sizeof(int));
    }
    int** b11;
    b11=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           b11[i] = (int *)malloc(l * sizeof(int));
    }
    int** b12;
    b12=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           b12[i] = (int *)malloc(l * sizeof(int));
    }
    int** b21;
    b21=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           b21[i] = (int *)malloc(l * sizeof(int));
    }
    int** b22;
    b22=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           b22[i] = (int *)malloc(l * sizeof(int));
    }
    int** m1;
    m1=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           m1[i] = (int *)malloc(l * sizeof(int));
    }
    int** m2;
    m2=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           m2[i] = (int *)malloc(l * sizeof(int));
    }
    int** m3;
    m3=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           m3[i] = (int *)malloc(l * sizeof(int));
    }
    int** m4;
    m4=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           m4[i] = (int *)malloc(l * sizeof(int));
    }
    int** m5;
    m5=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           m5[i] = (int *)malloc(l * sizeof(int));
    }
    int** m6;
    m6=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           m6[i] = (int *)malloc(l * sizeof(int));
    }
    int** m7;
    m7=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           m7[i] = (int *)malloc(l * sizeof(int));
    }
    int** c11;
    c11=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           c11[i] = (int *)malloc(l * sizeof(int));
    }
    int** c12;
    c12=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           c12[i] = (int *)malloc(l * sizeof(int));
    }
    int** c21;
    c21=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           c21[i] = (int *)malloc(l * sizeof(int));
    }
    int** c22;
    c22=(int**)malloc(l*sizeof(int*));
    for (i=0; i<l; i++){
           c22[i] = (int *)malloc(l * sizeof(int));
    }

  }

  else if(n==2){

    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        c[i][j]=0;
        for (l = 0; l < n; l++) {
          c[i][j]+=a[i][l]*b[l][j];
        }
      }
    }
  }

}



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
  mult(a,b,c,n);

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ",c[i][j] );
    }
    printf("\n");
  }
  free(a);
  free(b);
  free(c);
  return 0;
}
