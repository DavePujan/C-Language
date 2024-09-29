#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NAME "Dave Pujan M."
#define ENROLLMENT "230130107024"

// structure Define karva mate
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//  insert a node into the binary search tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int main() {
    // today's date and time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Name: %s\n", NAME);
    printf("Enrollment: %s\n", ENROLLMENT);
    printf("Date and Time: %02d-%02d-%04d %02d:%02d:%02d\n", 
           tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, 
           tm.tm_hour, tm.tm_min, tm.tm_sec);

    struct Node* root = NULL;
    int n, value;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter %d values to insert into the BST:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    return 0;
}
