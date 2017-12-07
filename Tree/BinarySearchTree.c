#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

int insert(struct node **root, int newValue);
int insertRecursive(struct node **root, int newValue);
struct node *search(struct node *root, int data);
struct node *searchRecursive(struct node *root, int data);
struct node *findMin(struct node *root);
struct node *delete (struct node *root, int deleteValue);
void showBST(struct node *root);

int main(int countArgs, char *args[])
{
    struct node *root;
    root = NULL;

    insertRecursive(&root, 5);
    insertRecursive(&root, 7);
    insertRecursive(&root, 6);
    insertRecursive(&root, 4);
    insertRecursive(&root, 2);
    insertRecursive(&root, 1);
    insertRecursive(&root, 9);
    insertRecursive(&root, 3);
    insertRecursive(&root, 8);

    showBST(root);

    root = delete (root, 4);
    printf("\nafter delete:\n");
    showBST(root);

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

int insertRecursive(struct node **root, int newValue)
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
struct node *searchRecursive(struct node *root, int data)
{
    if (root == NULL || data == root->value)
    {
        return root;
    }
    else if (data < root->value)
    {
        return searchRecursive(root->left, data);
    }
    else
    {
        return searchRecursive(root->right, data);
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
                temp = root->right;
                free(root->right);
                root->right = NULL;
            }
            else
            {
                struct node *tn;
                tn = root->right;
                while (tn->left != temp)
                {
                    tn = tn->left;
                }
                tn->left = NULL;
                free(temp);
            }
        }
    }
    return root;
}

void showBST(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    showBST(root->left);
    printf("value: %d\n", root->value);
    showBST(root->right);
}