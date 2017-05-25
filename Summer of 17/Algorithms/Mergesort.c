
#include<stdio.h>
#include<stdlib.h>

void mergesort(int arr[],int n) {
  if(n>1){
    int l1=n/2,l2=n-l1,x;
    int *u;
    int *v;
    u=(int*)malloc(l1*sizeof(int));
    v=(int*)malloc(l2*sizeof(int));
    for(x=0;x<l1;x++){
      u[x]=arr[x];
    }
    for(x=0;x<l2;x++){
      v[x]=arr[x+l1];
    }
      mergesort(u,l1);
      mergesort(v,l2);
      int i=0,j=0,l;

    for(l=0;l<n;l++){
      if(i<l1){
        if(j<l2){
          if(u[i]<v[j]){
            arr[l]=u[i];
            i++;
          }
          else{
            arr[l]=v[j];
            j++;
          }
        }
        else{
          arr[l]=u[i];
          i++;
        }
      }
      else{
        arr[l]=v[j];
        j++;
      }
    }
    free(u);
    free(v);
    }
}

int main(int argc, char const *argv[]) {
  int i,n,nm;
  //n=atoi(argv[2]);
  scanf("%d",&n );
  int* array;
  array=(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
    scanf("%d",&array[i]);
  mergesort(array,n);
  for(i=0;i<n;i++)
    printf("%d ", array[i]);
  return 0;
}
