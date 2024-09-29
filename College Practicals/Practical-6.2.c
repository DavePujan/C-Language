#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NAME "Dave Pujan M."
#define ENROLLMENT "230130107024"

// Define the structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function for in-order traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function for pre-order traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for post-order traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
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

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 10;
    root->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->data = 5;
    root->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->data = 15;

    printf("In-order Traversal: ");
    inorder(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preorder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
