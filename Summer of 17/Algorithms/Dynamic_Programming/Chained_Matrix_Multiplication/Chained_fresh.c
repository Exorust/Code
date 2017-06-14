#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]) {

    int n,i,j,k,add;
    FILE *fr;
    fr=fopen("chain_input","r");
    fscanf(fr,"%d",&n);

    int** midpt=(int**)malloc((n+1)*sizeof(int*));
    int** min_length=(int**)malloc((n+1)*sizeof(int*));
    int* rows=(int*)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++){
      midpt[i]=(int*)malloc((n+1)*sizeof(int));
      min_length[i]=(int*)malloc((n+1)*sizeof(int));
    }

    for(i=0;i<=n;i++){
      fscanf(fr,"%d",&rows[i]);
    }
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
        midpt[i][j]=0;
        if(i==j)
          min_length[i][j]=0;
        else
          min_length[i][j]=100000000000;
        }
    }
    printf("before loop\n" );
    fflush(stdout);

    for(add=1; add<n; add++){
      for(i=1; add+i<=n; i++){
        for(k=i; k<add+i; k++){
          int temp= min_length[i][k]+min_length[k+1][i+add]+(rows[i-1]*rows[k]*rows[add+i]);
          if(min_length[i][i+add]>temp){
            min_length[i][i+add]=temp;
            midpt[i][i+add]=k;
          }
        }
        min_length[i+add][i]=min_length[i][i+add];
      }
      i=1;
    }

    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
        printf("%d ",min_length[i][j]);
      }
      printf("\n" );
    }

    for(i=1;i<=n;i++){
      free(midpt[i]);
      free(min_length[i]);
    }
    free(midpt);
    free(min_length);
    free(rows);
    fclose(fr);
    return 0;
}
