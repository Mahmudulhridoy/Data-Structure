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

struct Node *delete(struct Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->key)
    {
        root->right = delete (root->right, key);
    }
    else
    {
        // Node with only one child or no child
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

        // Node with two children
        // Find inorder successor (smallest in right subtree)
        struct Node *succParent = root;
        struct Node *succ = root->right;

        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        // Copy successor's key to root
        root->key = succ->key;

        // Delete the successor
        if (succParent != root)
            succParent->left = delete (succParent->left, succ->key);
        else
            succParent->right = delete (succParent->right, succ->key);
    }

    return root;
}

// Inorder traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Main function to test
int main()
{
    struct Node *root = NULL;

    // Insert nodes
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

    root = delete (root, 50); // Delete node with two children

    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
    
}
