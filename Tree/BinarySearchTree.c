#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

int insert(struct node **root, int newValue);
int recursiveInsert(struct node **root, int newValue);
struct node *search(struct node *root, int data);
struct node *recursiveSearch(struct node *root, int data);
struct node *findMin(struct node *root);
struct node *delete (struct node *root, int deleteValue);
void printInorderTraversal(struct node *root);

int main(int countArgs, char *args[])
{
    struct node *root;
    root = NULL;

    recursiveInsert(&root, 5);
    recursiveInsert(&root, 7);
    recursiveInsert(&root, 6);
    recursiveInsert(&root, 4);
    recursiveInsert(&root, 2);
    recursiveInsert(&root, 1);
    recursiveInsert(&root, 9);
    recursiveInsert(&root, 3);
    recursiveInsert(&root, 8);

    printInorderTraversal(root);

    root = delete (root, 4);
    printf("\nafter delete:\n");
    printInorderTraversal(root);

    struct node *found;
    found = search(root, 8);
    if (found != NULL)
    {
        printf("\nFound.... %d\n", found->value);
    }
    else
    {
        printf("\nNot Found....\n");
    }

    printf("Min value is: %d\n", findMin(root)->value);
    return 0;
}

int insert(struct node **root, int newValue)
{
    struct node *newNode;
    struct node *current;
    struct node *parent;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = newValue;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*root == NULL)
    {
        *root = newNode;
    }
    else
    {
        current = *root;
        parent = NULL;
        while (1)
        {
            parent = current;
            //go to left of the tree
            if (newValue < parent->value)
            {
                current = current->left;
                //insert to the left
                if (current == NULL)
                {
                    parent->left = newNode;
                    break;
                }
            } //go to right of the tree
            else
            {
                current = current->right;
                //insert to the right
                if (current == NULL)
                {
                    parent->right = newNode;
                    break;
                }
            }
        }
    }
    return 1;
}

struct node *search(struct node *root, int data)
{
    struct node *current = root;
    while (current != NULL && current->value != data)
    {
        //go to left tree
        if (current->value > data)
        {
            current = current->left;
        } //else go to right tree
        else
        {
            current = current->right;
        }
    }
    return current;
}

int recursiveInsert(struct node **root, int newValue)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = newValue;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*root == NULL)
    {
        *root = newNode;
    }
    else
    {
        if (newValue < (*root)->value)
        {
            insert(&(*root)->left, newValue);
        }
        else
        {
            insert(&(*root)->right, newValue);
        }
    }
    return 1;
}
struct node *recursiveSearch(struct node *root, int data)
{
    if (root == NULL || data == root->value)
    {
        return root;
    }
    else if (data < root->value)
    {
        return recursiveSearch(root->left, data);
    }
    else
    {
        return recursiveSearch(root->right, data);
    }
}

struct node *findMin(struct node *root)
{
    if (root == NULL || root->left == NULL)
    {
        return root;
    }
    else
    {
        return findMin(root->left);
    }
}

struct node *delete (struct node *root, int deleteValue)
{
    struct node *temp;
    if (root == NULL)
    {
        return NULL;
    }
    else if (deleteValue < root->value)
    {
        root->left = delete (root->left, deleteValue);
    }
    else if (deleteValue > root->value)
    {
        root->right = delete (root->right, deleteValue);
    }
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            root->right = NULL;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            root->left = NULL;
            free(root);
            return temp;
        }
        else
        {
            temp = findMin(root->right);
            root->value = temp->value;
            if (temp == root->right)
            {
                free(root->right);
                root->right = NULL;
            }
            else
            {
                struct node *parentMin;
                parentMin = root->right;
                while (parentMin->left != temp)
                {
                    parentMin = parentMin->left;
                }
                parentMin->left = NULL;
                free(temp);
            }
        }
    }
    return root;
}

void printInorderTraversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInorderTraversal(root->left);
    printf("value: %d\n", root->value);
    printInorderTraversal(root->right);
}