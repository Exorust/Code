#include<stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  long long n,k,i,index;
  scanf("%Ld %Ld",&n,&k);
  if(k>(n/2)){
    k=n-k;
  }
  long long *arr=(long long*)malloc((n+1)*sizeof(long long));
  for(i=0;i<n+1;i++){
    arr[i]=0;
  }
  arr[0]=1;
  arr[1]=1;
  for(index=2;index<=n;index++){
    for(i=index;i>0;i--){
      arr[i]+=arr[i-1];
    }
  }

    printf("%Ld ",arr[k-1]);

  printf("\n" );
  free(arr);
  return 0;
}
