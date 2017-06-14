#include <stdio.h>
#include <stdlib.h>

void path(int **w,int **m,int a,int b,int n){
  if(*(*(m+a)+b)==0){
    printf(" %d",b );
    return;
  }
  else{
    path(w,m,a,*(*(m+a)+b),n);
    printf(" %d",b);
  }
}
int main(int argc, char const *argv[]) {
  FILE *inp;
  inp=fopen("floydinp","r");

  int n,i,j;
  fscanf(inp,"%d",&n );
  int** w= (int**)malloc((n+1)*sizeof(int*));
  for(i=1;i<=n;i++){
    w[i]=(int*)malloc((n+1)*sizeof(int));
  }
  int** m= (int**)malloc((n+1)*sizeof(int*));
  for(i=1;i<=n;i++){
    m[i]=(int*)malloc((n+1)*sizeof(int));
  }


  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      fscanf(inp,"%d",&w[i][j] );
      m[i][j]=0;
    }
  }
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      printf("%d ",w[i][j] );
    }
      printf("\n");
  }
  int k;
  for(k=1;k<=n;k++){
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
        if(w[i][j]>w[i][k]+w[k][j]){
          w[i][j]=w[i][k]+w[k][j];
          m[i][j]=k;
        }
      }
    }
  }
  printf("\n");
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      printf("%d ",w[i][j] );
    }
    printf("\n");
  }

  printf("\n");

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      printf("%d ",m[i][j] );
    }
    printf("\n");
  }
  int a,b;
  printf("From which two points do you want shortest path?");
  scanf("%d %d",&a,&b);
  printf("%d", a );
  path(w,m,a,b,n);

  for(i=0;i<=n;i++){
    free((*(m+i)));
    free(w[i]);
  }
  free(w);
  free(m);
  return 0;
}
