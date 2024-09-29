#include <stdio.h>
#include <time.h>

int main() {
    
    const char *name = "Dave Pujan M.";
    const char *rollNo = "230130107024";
    
    
    time_t t;
    time(&t);
    
    
    FILE *file = fopen("hash_table.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "Student Name: %s\n", name);
    fprintf(file, "Enrollment No: %s\n", rollNo);
    fprintf(file, "Date and Time: %s", ctime(&t));
    fprintf(file, "Sample data for demonstration:\n");
    fprintf(file, "Line 1: Hello, World!\n");
    fprintf(file, "Line 2: This is a test file.\n");
    
    fclose(file);
    printf("Data written to hash_table.txt\n");

    return 0;
}
