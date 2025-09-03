#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int largestproduct(char* num,int size,int seqsize);
int main(){

    int n,k,max; 
    char* num;
    printf("Enter max size of num:");
    scanf("%d",&n);
    printf("Sub-sequnce size:");
    scanf("%d",&k);
    printf("Enter num:");
    num = (char *)malloc(512000 * sizeof(char));
    scanf("%s",num);
    max=largestproduct(num,n,k);
    printf("\nMaximum product of seq :%d",max);
    return 0;
}

int largestproduct(char* num,int size,int seqsize){
    int i,j,max=0,product;
    for(i=0;i<=size-seqsize;i++){
        product=1;
        for(j=0;j<seqsize;j++){
            product*=(num[i+j]-'0');
            
        }
        printf("\nProduct of seq %d is %d",i+1,product);
        if(product>max){
            max=product;
        }
    }
    return max;
}