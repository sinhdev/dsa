typedef struct btreeNode
{
  void *data;
  struct btreeNode *left;
  struct btreeNode *right;
} btNode;
typedef int nodeCompare(const void *v1, const void *v2);
typedef void traversalFunc(const void *element);
typedef struct
{
  unsigned int sizeOfElement;
  nodeCompare *nodecmp;
  btNode *root;
} BinarySearchTree;

BinarySearchTree *bstInitRoot(void *root, unsigned int sizeOfElement, nodeCompare *nodecmp)
{
  if (sizeOfElement <= 0 || nodecmp == NULL)
    return NULL;
  BinarySearchTree *bst = (BinarySearchTree *)malloc(sizeof(BinarySearchTree));
  bst->sizeOfElement = sizeOfElement;
  bst->nodecmp = nodecmp;
  bst->root = root;
  return bst;
}
BinarySearchTree *bstInit(unsigned int sizeOfElement, nodeCompare *nodecmp)
{
  if (sizeOfElement <= 0 || nodecmp == NULL)
    return NULL;
  return bstInitRoot(NULL, sizeOfElement, nodecmp);
}
void btDestroyRoot(btNode *root)
{
  if (root != NULL)
  {
    free(root->data);
    btDestroyRoot(root->left);
    btDestroyRoot(root->right);
    free(root);
  }
}
void bstDestroy(BinarySearchTree *bst)
{
  btDestroyRoot(bst->root);
  free(bst);
}

int bstInsertNode(BinarySearchTree *bst, btNode *newNode)
{
  if (newNode == NULL)
    return 0;
  if (bst->root == NULL)
    bst->root = newNode;
  else
  {
    btNode *cur, *parent;
    cur = bst->root;
    parent = NULL;
    while (1)
    {
      parent = cur;
      // go to left of the tree
      if (bst->nodecmp(newNode->data, parent->data) < 0)
      {
        cur = cur->left;
        // insert to the left
        if (cur == NULL)
        {
          parent->left = newNode;
          break;
        }
      }
      else
      {
        cur = cur->right;
        // insert to the right
        if (cur == NULL)
        {
          parent->right = newNode;
          break;
        }
      }
    }
  }
  return 1;
}
int bstInsert(BinarySearchTree *bst, void *newElement)
{
  if (newElement == NULL)
    return 0;
  btNode *newNode = (btNode *)malloc(sizeof(btNode));
  newNode->data = malloc(bst->sizeOfElement);
  memcpy(newNode->data, newElement, bst->sizeOfElement);
  newNode->left = NULL;
  newNode->right = NULL;
  return bstInsertNode(bst, newNode);
}
void bstTraversal(btNode *root, traversalFunc *tf)
{
  if (root == NULL)
    return;
  bstTraversal(root->left, tf);
  tf(root->data);
  bstTraversal(root->right, tf);
}
void bstTraversalDesc(btNode *root, traversalFunc *tf)
{
  if (root == NULL)
    return;
  bstTraversalDesc(root->right, tf);
  tf(root->data);
  bstTraversalDesc(root->left, tf);
}
void bstTraversalCondition(btNode *root, nodeCompare *nodeCmp, const void *key, traversalFunc tf)
{
  if (root == NULL)
    return;
  if (!nodeCmp(root->data, key))
    tf(root->data);
  bstTraversalCondition(root->left, nodeCmp, key, tf);
  bstTraversalCondition(root->right, nodeCmp, key, tf);
}
btNode *bstMinNode(btNode *root)
{
  if (root == NULL || root->left == NULL)
    return root;
  else
    return bstMinNode(root->left);
}

btNode *bstRemoveNode(btNode *root, void *deleteElement, nodeCompare *nodecmp, unsigned int sizeOfElement)
{
  if (root == NULL)
    return root;
  if (nodecmp(deleteElement, root->data) < 0)
    root->left = bstRemoveNode(root->left, deleteElement, nodecmp, sizeOfElement);
  else if (nodecmp(deleteElement, root->data) > 0)
    root->right = bstRemoveNode(root->right, deleteElement, nodecmp, sizeOfElement);
  else
  {
    if (root->left == NULL)
    {
      btNode *temp = root->right;
      free(root->data);
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      btNode *temp = root->left;
      free(root->data);
      free(root);
      return temp;
    }
    else
    {
      btNode *temp = bstMinNode(root->right);
      memcpy(root->data, temp->data, sizeOfElement);
      root->right = bstRemoveNode(root->right, root->right->data, nodecmp, sizeOfElement);
    }
  }
  return root;
}
int bstRemove(BinarySearchTree *bst, void *delValue)
{
  if (delValue == NULL)
    return 0;
  bst->root = bstRemoveNode(bst->root, delValue, bst->nodecmp, bst->sizeOfElement);
  return 1;
}
btNode *bstSearch(BinarySearchTree *bst, void *key)
{
  btNode *cur = bst->root;
  while (cur != NULL && bst->nodecmp(cur->data, key) != 0)
  {
    if (bst->nodecmp(cur->data, key) > 0)
      cur = cur->left;
    else
      cur = cur->right;
  }
  return cur;
}

btNode *bstSearchCondition(btNode *root, nodeCompare searchCriteria, void *key)
{
  if (root == NULL || searchCriteria == NULL || key == NULL)
    return NULL;
  if (!searchCriteria(root->data, key))
    return root;
  btNode *left = bstSearchCondition(root->left, searchCriteria, key);
  if (left != NULL)
    return left;
  return bstSearchCondition(root->right, searchCriteria, key);
}