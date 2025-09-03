#include<stdio.h>
int n=50;
void insertionsort(int arr[n],int n);

int main(){
    
    int arr[n],i;

    printf("Sorting the array with Insertion sort!");
    
    printf("\nEnter the size of array:");
    scanf("%d",&n);
    printf("Enter array elements :\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertionsort(arr,n);
    printf("\nSorted array:");
    for(i=0;i<n;i++){
        printf(" %d ,",arr[i]);
    }
    return 0;
}
void insertionsort(int arr[n],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        j=i-1;
        key=arr[i];
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    
}