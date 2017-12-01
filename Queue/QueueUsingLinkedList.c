#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int value;
    struct Node *next;
};
struct Queue
{
    struct Node *front;
    struct Node *rear;
};

bool initQueue(struct Queue *q);
bool enqueue(struct Queue *q, int value);
bool dequeue(struct Queue *q, int *frontValue);

int main(int countArgs, char **args)
{
    struct Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, 5);
    enqueue(&myQueue, 6);
    enqueue(&myQueue, 7);
    enqueue(&myQueue, 8);

    int value;
    while (dequeue(&myQueue, &value))
    {
        printf("%d\n", value);
    }

    return 0;
}
bool dequeue(struct Queue *q, int *frontValue)
{
    if (q->front == NULL)
    {
        return false;
    }
    *frontValue = (q->front)->value;
    if (q->rear == q->front)
    {
        q->rear = NULL;
        free(q->front);
        q->front = NULL;
    }
    else
    {
        struct Node *preFront;
        preFront = q->rear;
        while (preFront->next != q->front)
        {
            preFront = preFront->next;
        }
        preFront->next = NULL;
        free(q->front);
        q->front = preFront;
    }
    return true;
}
bool enqueue(struct Queue *q, int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = q->rear;
    q->rear = newNode;
    //if queue is empty
    if (q->front == NULL)
    {
        q->front = newNode;
    }
    return true;
}
bool initQueue(struct Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
    return true;
}