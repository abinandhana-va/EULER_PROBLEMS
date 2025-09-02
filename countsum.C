//Get input n and return an integer which is the count of number of 
//alphabets used to write the numbers until n in letters.
#include<stdio.h>
#include<string.h>
char arr[15][10]={"one","two","three","four","five","six","seven","eight","nine","ten"};
int countsum(int n);

int main(){
    int n,ct;
    printf("Enter the num:");
    scanf("%d",&n);
    ct=countsum(n);
    printf("\nNo of Alphabets used : %d",ct);
    return 0;
}

int countsum(int n){
    int sum=0,i;
    for(i=0;i<n;i++){
        sum+=strlen(arr[i]);
        printf("\n%ld",strlen(arr[i]));
    }
    return sum;
}