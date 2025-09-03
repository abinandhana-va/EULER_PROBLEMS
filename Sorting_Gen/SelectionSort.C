#include<stdio.h>
int n=50;
void selectionsort(int arr[n],int n);

int main(){
    
    int arr[n],i;

    printf("Sorting the array with Selection sort!");
    
    printf("\nEnter the size of array:");
    scanf("%d",&n);
    printf("Enter array elements :\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selectionsort(arr,n);
    printf("\nSorted array:");
    for(i=0;i<n;i++){
        printf(" %d ,",arr[i]);
    }
    return 0;
}
void selectionsort(int arr[n],int n){
    int i,j,min,temp;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
    
}