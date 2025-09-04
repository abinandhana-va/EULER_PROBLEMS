#include<stdio.h>
int n=50;
int partition(int arr[n],int low,int high);
void swap(int *a,int *b);
void quicksort(int arr[n],int low,int high);
 
int main(){
    int arr[n];
    printf("Enter the array size :");
    scanf("%d",&n);
    printf("\nEnter the array elements :");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("\nSorted array:");
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void quicksort(int arr[n],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int partition(int arr[n],int low,int high){
    int pivot=arr[low];
    int i=low-1;
    int j=high+1;
    while(1){
        do{
            i++;
        }while(arr[i]<=pivot);
    
        do{
            j--;
        }while(arr[j]>pivot);
        
        if(i>=j){
            break;
        }
        swap(&arr[i],&arr[j]);
    }
    swap(&arr[j],&arr[low]);
    return j;
}