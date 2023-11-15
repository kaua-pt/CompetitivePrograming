#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int content;
    struct Node *rigth;
    struct Node *left;
} Node;

Node *search(Node *root, int x)
{
    if (root->content == x || root == NULL)
        return root;
    if (x < root->content)
        return search(root->left, x);
    return search(root->rigth, x);
}

void posord(Node *root)
{
    if (root == NULL)
        return;

    posord(root->left);
    posord(root->rigth);
    printf("%d ", root->content);
}
void preord(Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->content);
    preord(root->left);
    preord(root->rigth);
}
void ord(Node *root)
{
    if (root == NULL)
        return;

    ord(root->left);
    printf("%d ", root->content);
    ord(root->rigth);
}

Node *insert(Node *root, int x)
{
    if (root->content == x)
        return root;

    if (root->content < x && root->left == NULL)
    {
        Node *nl = calloc(sizeof(Node), 1);
        nl->content = x;
        root->left = nl;
        return root->left;
    }

    if (root->content > x && root->rigth == NULL)
    {
        Node *nl = calloc(sizeof(Node), 1);
        nl->content = x;
        root->rigth = nl;
        return root->rigth;
    }
    if (root->content < x)
        return insert(root->left, x);
    return insert(root->rigth, x);
}

int main()
{
}