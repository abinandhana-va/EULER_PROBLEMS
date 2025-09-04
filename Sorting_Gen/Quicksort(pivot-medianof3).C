#include <stdio.h>
#include <limits.h>
int n = 50;

void swap(int *a, int *b);
int medianOfThree(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);

int main() {
    int arr[n];
    printf("Enter the array size : ");
    scanf("%d", &n);
    printf("\nEnter the array elements : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[low] > arr[mid])
        swap(&arr[low], &arr[mid]);
    if (arr[low] > arr[high])
        swap(&arr[low], &arr[high]);
    if (arr[mid] > arr[high])
        swap(&arr[mid], &arr[high]);

    return mid;
}

int partition(int arr[], int low, int high) {
    int m = medianOfThree(arr, low, high);

    swap(&arr[m], &arr[high]);
    
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
