#include <stdio.h>

#define MAX 1000   

int series[MAX];   

// Recursive function 
void fibonacci(int n, int index) {
    if (index >= n) return;   

    series[index] = series[index - 1] + series[index - 2];
    fibonacci(n, index + 1);  
}


int evenfibonacci(int limit, int n) {
    int sum = 0;
    for (int i = 0; i < n && series[i] < limit; i++) {
        if (series[i] % 2 == 0) {
            sum += series[i];
        }
    }
    return sum;
}

int main() {
    int n, limit, sum;

    printf("Enter how many Fibonacci terms to generate: ");
    scanf("%d", &n);

    printf("Enter limit: ");
    scanf("%d", &limit);

    //starting terms of Fibonacci
    series[0] = 1;
    series[1] = 2;

    // Generating using recursion
    fibonacci(n, 2);

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", series[i]);
    }
    printf("\n");

    sum = evenfibonacci(limit, n);

    printf("Sum of even Fibonacci terms less than %d: %d\n", limit, sum);

    return 0;
}
