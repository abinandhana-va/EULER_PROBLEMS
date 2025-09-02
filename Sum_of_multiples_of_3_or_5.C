#include<stdio.h>
#include<conio.h>

void main(){
    int n,i,sum=0;
    
    //Sum of multiples of 3 or 5 till n
    printf("Enter num n:");
    scanf("%d",&n);
    printf("Multiples of 3 / 5 and both till n are :\n");
    for(i=1;i<=n;i++){
        if(i%3==0||i%5==0){
            printf("%d  ",i);
            sum+=i;
        }
    }
    printf("\nSum of these multiples:%d",sum);
    getch();
}