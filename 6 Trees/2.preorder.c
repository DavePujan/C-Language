/*
same create nodes, assign them

for preorder create void preorder function (int data) -->
    if root!= NULL then
        print root , call function again for left and right

*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * createNode(int data){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node)); // creating a pointer for node.
    n->left = NULL;
    n->right = NULL;
    n->data=data; //inserting the data
    return n;
}

void preorder(struct Node * root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{

    struct Node * p= createNode(4);
    struct Node * p1= createNode(1);
    struct Node * p2= createNode(6);
    struct Node * p3= createNode(2);
    struct Node * p4= createNode(5);
    //tree look like this
    /*
            4
           / \
          1   6
         / \
        5   2
    */
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    preorder(p);
    return 0;
}