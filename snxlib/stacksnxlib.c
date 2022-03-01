typedef struct snode
{
  void *data;
  struct snode *next;
} sNode;
typedef struct stack{
  unsigned int sizeOfElement;
  sNode *top;
} Stack;

 Stack* initStack(unsigned int sizeOfElement){
   if(sizeOfElement <=0){
     return NULL;
   }
   Stack *s;
   s = (Stack*)malloc(sizeof(Stack));
   s->sizeOfElement = sizeOfElement;
   s->top = NULL;
   return s;
 }
int sPush(Stack *s, void *newElement){
  if(s==NULL || newElement==NULL){
    return 0;
  }
  sNode *newNode;
  newNode = (sNode *)malloc(sizeof(sNode));
  newNode->data = malloc(s->sizeOfElement);
  memcpy(newNode->data, newElement, s->sizeOfElement);
  newNode->next = s->top;
  s->top = newNode;
  return 1;
}
int sIsEmpty(Stack *s){
  return s==NULL || s->top==NULL;
}
void* sPop(Stack *s){
  if(sIsEmpty(s)){
    return NULL;
  }
  void *topValue;
  topValue = s->top->data;
  sNode *topNode;
  topNode = s->top;
  s->top = s->top->next;
  free(topNode);
  return topValue;
}
void* sPeek(Stack *s){
  if(sIsEmpty(s)){
    return NULL;
  }
  return s->top->data;
}