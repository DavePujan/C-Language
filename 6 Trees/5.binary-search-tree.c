#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node)); // creating a pointer for node.
    n->left = NULL;
    n->right = NULL;
    n->data = data; // inserting the data
    return n;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
// ex. to understand below code:    1    3(prev)   4(root)   5   6
int isBST(struct Node *root)
{
    static struct Node *prev = NULL; // static is liye use kiya kyuki prev sirf first time hi null chahiye hame.
    if (root != NULL)
    {
        if (!isBST(root->left))
        { // agar left ke liye wrong he niche wali(matlab root>prev nahi he) condition toh fir 0(false) return kardo.
            return 0;
        }
        if (prev != NULL && root->data /*(4)*/ <= prev->data /*(3)*/)
        { // agar prev Null he ya fir jo new data aaya he wo prev se chhota he to 0(false) return kardo kyuki wo fir BST nahi he.
            return 0;
        }
        prev = root;               // fir root ko prev me daal do. (matlab 4 ko prev banado, or 5 ko root banado.)
        return isBST(root->right); // or same step right wale ke liye follow karo
    }
    else
        return 1; // or agr upar ki sari condition wrong hui tabhi ye 1 return karega matlab ye BST hoga.
}

int main()
{

    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);
    // tree look like this
    /*
            5
           / \
          3   6
         / \
        1   4
    */
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inorder(p);
    printf("\n");
    printf("%d", isBST(p));
    return 0;
}