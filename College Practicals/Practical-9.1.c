#include <stdio.h>
#include <time.h>

void printCurrentTime(const char* name, const char* enrollment) {
    time_t t;
    time(&t);
    struct tm* local = localtime(&t);
    
    printf("Name: %s\n", name);
    printf("Enrollment Number: %s\n", enrollment);
    printf("Current Date and Time: %s", asctime(local));
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    char name[] = "Dave Pujan M."; 
    char enrollment[] = "230130107024"; 
    printCurrentTime(name, enrollment);

    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    
    printf("Sorted array (Quick Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
