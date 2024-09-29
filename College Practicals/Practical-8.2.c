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

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevent overflow

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return -1; // if not found
}

int main() {
    char name[] = "Dave Pujan M.";  
    char enrollment[] = "230130107024"; 
    printCurrentTime(name, enrollment);

    int arr[] = {2, 3, 4, 5, 8}; //  sorted hovo joie
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    
    int result = binarySearch(arr, size, target);
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }
    
    return 0;
}
