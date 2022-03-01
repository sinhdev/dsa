typedef struct qnode
{
  void *data;
  struct qnode *next;
} qNode;
typedef struct
{
  unsigned int sizeOfElement;
  qNode *front;
  qNode *rear;
} Queue;

Queue *initQueue(unsigned int sizeOfElement)
{
  if (sizeOfElement <= 0)
  {
    return NULL;
  }
  Queue *q;
  q = (Queue *)malloc(sizeof(Queue));
  q->sizeOfElement = sizeOfElement;
  q->front = NULL;
  q->rear = NULL;
  return q;
}
int qIsEmpty(Queue *q)
{
  return q->front == NULL;
}
int qEnqueue(Queue *q, void *newElement)
{
  qNode *newNode;
  newNode = (qNode *)malloc(sizeof(qNode));
  newNode->data = malloc(q->sizeOfElement);
  memcpy(newNode->data, newElement, q->sizeOfElement);
  newNode->next = q->rear;
  q->rear = newNode;
  if (qIsEmpty(q))
  {
    q->front = newNode;
  }
  return 1;
}
void *qDequeue(Queue *q)
{
  if (qIsEmpty(q))
  {
    return NULL;
  }
  void *frontElement;
  frontElement = q->front->data;
  qNode *front;
  front = q->front;
  if (q->front == q->rear)
  {
    q->front = NULL;
    q->rear = NULL;
  }
  else
  {
    qNode *it;
    for (it = q->rear; it->next != q->front; it = it->next);
    q->front = it;
  }
  free(front);
  return frontElement;
}