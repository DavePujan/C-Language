/*
create node having data, left and right pointer

create createNode function using struct node (which is taking int data as parameter) -->
    in this create n pointer, fix n->left and right = NULL , set n->data = data, then return n

after this in main create nodes and then call function for then each, and then asign values left or right accordingly for them.
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

int main()
{
    struct Node * p= createNode(2);
    struct Node * p1= createNode(1);
    struct Node * p2= createNode(4);
    p->left=p1;
    p->right=p2;

    return 0;
}