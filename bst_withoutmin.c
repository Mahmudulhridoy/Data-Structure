#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
        return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

struct Node *findMinNode(struct Node *node)
{
    struct Node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = findMinNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder before deletion: ");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 50);
    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
