#include<stdio.h>
#include<stdlib.h>

void quicksort(int arr[],int n){
  int i;
  for(i=0;i<n;i++){
    printf("%d ",arr[i] );
  }
  printf("call\n" );
  if(n>1){
    int pivot=0,i,j,a;
    for(i=0;i<n;i++){
      if(arr[i]<arr[pivot]){
        a=arr[i];
        for(j=i-1;j>=pivot;j--){
          arr[j+1]=arr[j];
        }
        arr[pivot]=a;
        pivot++;
      }
    }
    int l1=pivot,l2=n-1-pivot;
    int* u;
    int* v;
    u=(int*)malloc(l1*sizeof(int));
    v=(int*)malloc(l2*sizeof(int));
    for(i=0;i<l1;i++){
      u[i]=arr[i];
    }
    for(i=l1+1,j=0;i<n;j++,i++){
      v[j]=arr[i];
    }
    quicksort(u,l1);
    quicksort(v,l2);
    for(i=0;i<l1;i++){
      arr[i]=u[i];
    }
    for(i=l1+1,j=0;i<n;j++,i++){
      arr[i]=v[j];
    }
  }
  for(i=0;i<n;i++){
    printf("%d ",arr[i] );
  }
  printf("finish\n" );
  free(u);
  free(v);
}

int main(int argc, char const *argv[]) {
  int i,n=9;
  //n=atoi(argv[2]);
  /*scanf("%d",&n );
  int* array;
  array=(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
    scanf("%d",&array[i]);
  */
  int array[]={9,2,3,8,4,5,6,7,1};
  quicksort(array,n);
  for(i=0;i<n;i++)
    printf("%d ", array[i]);
  return 0;
}
