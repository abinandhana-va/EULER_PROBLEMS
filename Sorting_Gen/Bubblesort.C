#include<stdio.h>
int n=50
void bubblesort(int arr[n],int n);

int main(){
    
    int arr[n],i;

    printf("\nSorting the array with Bubble sort!");
    
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("\nEnter array elements  :")
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubblesort(arr,n);
    printf("\nSorted array:");
    for(i=0;i<n;i++){
        printf(" %d ,",arr[i]);
    }
    return 0;
}
void bubblesort(int arr[n],int n){
    int i,j,swf=0,temp;
    for(i=0;i<n;i++){
        swf=0;
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swf++;
            }
        }
        if(swf==0){
            printf("\nArray has been sorted.");
            break;
        }
    }
}