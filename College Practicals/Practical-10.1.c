#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 10


typedef struct {
    int key;
    int value;
} HashEntry;

HashEntry hashTable[TABLE_SIZE];


void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].key = -1;
    }
}


int hashFunction(int key) {
    return key % TABLE_SIZE;
}


void insert(int key, int value) {
    int index = hashFunction(key);
    while (hashTable[index].key != -1) {
        index = (index + 1) % TABLE_SIZE; 
    }
    hashTable[index].key = key;
    hashTable[index].value = value;
}

void displayHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].key != -1) {
            printf("Index %d: Key %d, Value %d\n", i, hashTable[i].key, hashTable[i].value);
        }
    }
}


int main() {
    
    printf("Name: Dave Pujan M.\n");
    printf("Enrollment No: 230130107024\n");
    
    time_t t;
    time(&t);
    printf("Date and Time: %s", ctime(&t));

    initHashTable();
    
    insert(1, 10);
    insert(2, 20);
    insert(12, 30); // This will cause a collision
    insert(22, 40); // This will cause a collision
    insert(32, 50); // This will cause a collision


    displayHashTable();

    return 0;
}
