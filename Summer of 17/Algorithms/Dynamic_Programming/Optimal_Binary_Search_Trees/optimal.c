#include<stdio.h>
#include<stdlib.h>
struct node{
  node *left;
  node *right;
  int key;
  double key_prob;
};
int main(int argc, char const *argv[]) {
  int n,i,j,k,l,add;
  FILE *fr;
  fr=fopen("optimal_input","r");
  fscanf(fr,"%d",&n);

  int** midpt=(int**)malloc((n+1)*sizeof(int*));
  double** av_time=(double**)malloc((n+1)*sizeof(double*));
  double* prob=(double*)malloc((n+1)*sizeof(double));
  int* key=(int*)malloc((n+1)*sizeof(int));
  for(i=1;i<=n;i++){
    midpt[i]=(int*)malloc((n+1)*sizeof(int));
    av_time[i]=(double*)malloc((n+1)*sizeof(double));
  }

  for(i=0;i<=n;i++){
    fscanf(fr,"%f %d",&prob[i],&key[i]);
  }
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      midpt[i][j]=0;
      if(i==j)
        av_time[i][j]=prob[i];
      else
        av_time[i][j]=1000.00;
      }
  }
  for(add=1; add<n; add++){
    for(i=1; add+i<=n; i++){
      int sum;
      for(l=i;l<=add+i;l++){
        sum=
      }
    }
  }
  return 0;
}
