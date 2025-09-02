//1.Takes a number between 1 and 10.
//2.Finds its word form (arr).
//3.Calculates the sum of positions of its letters in the English alphabet.
//4.Prints that sum
#include<stdio.h>
#include<string.h>
char arr[15][10]={"one",
                  "two",
                  "three",
                  "four",
                  "five",
                  "six",
                  "seven",
                  "eight",
                  "nine",
                  "ten"};
int countsum(int n);

int main(){
    int n,ct;
    printf("Enter the num:");
    scanf("%d",&n);
    ct=countsum(n);
    printf("\nValue of alphabets used for num %d : %d",n,ct);
    return 0;
}

int countsum(int n){
    int sum=0,j;
    char ch;
    for(j=0;j<strlen(arr[n-1]);j++){
        ch=arr[n-1][j];
        sum+=(ch-'a'+1); // ASCII value used.
    }
    return sum;
}
