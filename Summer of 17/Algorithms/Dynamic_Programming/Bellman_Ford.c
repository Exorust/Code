#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]) {
  int n,i,j;
  scanf("%d",&n );

  int **weight=(int**)malloc(n*sizeof(int*));
  int *length=(int*)malloc(n*sizeof(int));
  int *from=(int*)malloc(n*sizeof(int));

  for(i=0;i<n;i++){
    weight[i]=(int*)malloc(n*sizeof(int));
  }

  for(i=0;i<n;i++){
    length[i]=100;
    from[i]=0;
  }

  FILE *fr;
  fr=fopen("bell","r+");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      fscanf(fr,"%d",&weight[i][j] );
    }
  }
  for(i=0;i<n;i++){
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        int z;
        z=weight[i][j]+length[i];
        if(z<length[j]){
          length[j]=z;
          from[j]=i;
        }
      }
    }
  }
  for (i = 0; i < n; i++) {
      printf("%d ", length[i]);
  }
  return 0;
}
