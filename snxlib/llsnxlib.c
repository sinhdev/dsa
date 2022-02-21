typedef struct node
{
  void *data;
  struct node *next;
} llNode;
typedef struct
{
  unsigned int sizeOfElement;
  llNode *head;
  llNode *it;
} LinkedList;

LinkedList *llInit(unsigned sizeOfElement)
{
  if(sizeOfElement <=0){
    return NULL;
  }
  LinkedList *ll;
  ll = (LinkedList *)malloc(sizeof(LinkedList));
  ll->sizeOfElement = sizeOfElement;
  ll->head = NULL;
  ll->it = NULL;
  return ll;
}
int llInsert(LinkedList *ll, void *newElement)
{
  if(ll==NULL || ll->sizeOfElement<=0 || newElement==NULL){
    return 0;
  }
  llNode *newNode;
  newNode = (llNode *)malloc(sizeof(llNode));
  newNode->data = malloc(ll->sizeOfElement);
  memcpy(newNode->data, newElement, ll->sizeOfElement);
  newNode->next = ll->head;
  ll->head = newNode;
  return 1;
}
int llInsertAt(LinkedList *ll, void *newElement, unsigned position)
{
  if (position == 0)
  {
    return llInsert(ll, newElement);
  }
  if (ll == NULL || ll->sizeOfElement<=0 || position < 0)
  {
    return 0;
  }
  llNode *cur, *pre;
  cur = ll->head;
  int i = 0;
  while (cur != NULL && i < position)
  {
    pre = cur;
    cur = cur->next;
    i++;
  }
  if (cur == NULL && i < position)
  {
    return 0;
  }
  llNode *newNode;
  newNode = (llNode *)malloc(sizeof(llNode));
  newNode->data = malloc(ll->sizeOfElement);
  memcpy(newNode->data, newElement, ll->sizeOfElement);
  pre->next = newNode;
  newNode->next = cur;
  return 1;
}
int llIsEmpty(LinkedList *ll)
{
  if (ll == NULL || ll->sizeOfElement<=0 || ll->head == NULL)
  {
    return 1;
  }
  return 0;
}
void* llGetAt(LinkedList *ll, unsigned int position){
  if(position <0){
    return NULL;
  }
  llNode *cur;
  int i;
  for(cur=ll->head, i=0; i<position && cur!=NULL; cur = cur->next, i++);
  if(cur == NULL){
    return NULL;
  }
  return cur->data;
}
int llRemove(LinkedList *ll)
{
  if (llIsEmpty(ll))
  {
    return 0;
  }
  llNode *delFirst;
  delFirst = ll->head;
  ll->head = ll->head->next;
  free(delFirst);
  return 1;
}
int llRemoveAt(LinkedList *ll, unsigned int position)
{
  if (position == 0)
  {
    return llRemove(ll);
  }
  if (llIsEmpty(ll) || position < 0)
  {
    return 0;
  }
  llNode *cur, *pre;
  cur = ll->head;
  int i = 0;
  while (cur != NULL && i < position)
  {
    pre = cur;
    cur = cur->next;
    i++;
  }
  if (cur == NULL)
  {
    return 0;
  }
  pre->next = cur->next;
  free(cur);
  return 1;
}
int llInitIterator(LinkedList *ll)
{
  if (ll->head == NULL)
  {
    return 0;
  }
  ll->it = ll->head;
  return 1;
}
int llHasNext(LinkedList *ll)
{
  if (ll->head == NULL || ll->sizeOfElement<=0 || ll->it == NULL)
  {
    return 0;
  }
  return 1;
}
void *llNext(LinkedList *ll)
{
  void *pCur;
  pCur = ll->it->data;
  ll->it = ll->it->next;
  return pCur;
}
void llDestroy(LinkedList *ll)
{
  llNode *curNode, *delNode;
  curNode = ll->head;
  while (curNode != NULL)
  {
    delNode = curNode;
    curNode = curNode->next;
    free(delNode);
  }
  free(ll);
}
int llSaveToFile(LinkedList *ll, const char *path)
{
  if (path == NULL || ll == NULL || llIsEmpty(ll))
  {
    return 0;
  }
  FILE *f = fopen(path, "wb");
  if (f == NULL)
  {
    return 0;
  }
  fwrite(&(ll->sizeOfElement), sizeof(unsigned int), 1, f);
  llNode *cur;
  cur = ll->head;
  while (cur != NULL)
  {
    fwrite(cur->data, ll->sizeOfElement, 1, f);
    cur = cur->next;
  }
  fclose(f);
  return 1;
}
LinkedList *llLoadFromFile(const char *path)
{
  if (path == NULL)
  {
    return NULL;
  }
  FILE *f = fopen(path, "rb");
  if (f == NULL)
  {
    return NULL;
  }
  LinkedList *ll;
  ll = (LinkedList *)malloc(sizeof(LinkedList));
  fread(&(ll->sizeOfElement), sizeof(unsigned int), 1, f);
  if(ll->sizeOfElement <=0){
    return NULL;
  }
  ll->head = NULL;
  llNode *cur, *pre;
  void* temp;
  int i=0;
  while (!feof(f))
  {
    temp = malloc(ll->sizeOfElement);
    if (fread(temp, ll->sizeOfElement, 1, f) > 0)
    {
      llInsertAt(ll, temp, i++);
    }
  }
  fclose(f);
  return ll;
}