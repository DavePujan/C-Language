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

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    char name[] = "Dave Pujan M.";   
    char enrollment[] = "230130107024";  
    printCurrentTime(name, enrollment);

    int arr[] = {5, 3, 8, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 4;
    
    int result = linearSearch(arr, size, target);
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }
    
    return 0;
}
