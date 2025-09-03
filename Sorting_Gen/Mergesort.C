#include<stdio.h>
int n=50;
void mergesort(int arr[n],int left,int right);
void merge(int arr[n],int left,int mid,int right);

int main(){
    
    int arr[n],i;

    printf("Sorting the array with Merge sort!");
    
    printf("\nEnter the size of array:");
    scanf("%d",&n);
    printf("Enter array elements :\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    printf("\nSorted array:");
    for(i=0;i<n;i++){
        printf(" %d ,",arr[i]);
    }
    return 0;
}
void mergesort(int arr[n],int left,int right){
    int mid;
    if(left<right){
        mid=left+(right-left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void merge(int arr[n],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int i,j,k;
    int LA[n1],RA[n2];
    for(i=0;i<n1;i++){
        LA[i]=arr[left+i];
    }
    for(j=0;j<n2;j++){
        RA[j]=arr[mid+1+j];
    }
    i=0,j=0,k=left;
    while(i<n1&&j<n2){
        if(LA[i]<RA[j]){
            arr[k]=LA[i];
            i++;
        } 
        else{
            arr[k]=RA[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=LA[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=RA[j];
        j++;
        k++;
    }
}