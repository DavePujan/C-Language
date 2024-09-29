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

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    char name[] = "Dave Pujan M.";  
    char enrollment[] = "230130107024"; 
    printCurrentTime(name, enrollment);

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    
    printf("Sorted array (Bubble Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
