#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue{
    int *data;
    int maxSize;
    int front;
    int rear;
};

bool initQueue(struct Queue *queue, int maxSize);
bool enqueue(struct Queue *queue, int rearValue);
bool dequeue(struct Queue *queue, int *frontValue);
bool peek(struct Queue queue, int *frontValue);
bool isFull(struct Queue queue);
bool isEmpty(struct Queue queue);

int main(int countArgs, char** args){
    struct Queue q;
    initQueue(&q, 3);

    if(enqueue(&q, 1)){
        printf("enqueue to queue complete!!!\n");
    }else{
        printf("Queue is full!!!\n");
    }
    if(enqueue(&q, 2)){
        printf("enqueue to queue complete!!!\n");
    }else{
        printf("Queue is full!!!\n");
    }
    if(enqueue(&q, 3)){
        printf("enqueue to queue complete!!!\n");
    }else{
        printf("Queue is full!!!\n");
    }

    int frontValue;
    if(dequeue(&q, &frontValue)){
        printf("front value: %d\n", frontValue);
    }
    if(dequeue(&q, &frontValue)){
        printf("front value: %d\n", frontValue);
    }

    if(dequeue(&q, &frontValue)){
        printf("front value: %d\n", frontValue);
    }
    printf("front: %d, rear: %d\n", q.front, q.rear);
    if(enqueue(&q, 4)){
        printf("enqueue to queue complete!!!\n");
    }else{
        printf("Queue is full!!!\n");
    }
    printf("front: %d, rear: %d\n", q.front, q.rear);
    
    return 0;
}

bool initQueue(struct Queue* queue, int maxSize){
    queue->maxSize = maxSize;
    queue->data = (int*)malloc(maxSize*sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    return true;
}

bool enqueue(struct Queue* queue, int rearValue){
    //Step 1 − Check if the queue is full
    if(queue->rear==queue->maxSize-1){
        if(queue->front==0){
            //Step 2 − If the queue is full, produce overflow error and exit
            return false;
        }else if(queue->front>0){
            //rear is last element of array but front not is first element of array -> move data to head of array
            for(int i=0, j=queue->front; j<=queue->rear; i++, j++){
                queue->data[i] = queue->data[j];
            }
            queue->rear -= queue->front;
            queue->front = 0;
        }
    }
    //Step 3 − If the queue is not full, increment rear pointer to point the next empty space
    queue->rear += 1;
    //Step 4 − Add data element to the queue location, where the rear is pointing
    queue->data[queue->rear] = rearValue;
    //Step 5 − return success
    return true;
}

bool dequeue(struct Queue *queue, int *frontValue){
    //Step 1 − Check if the queue is empty
    if(queue->rear<queue->front){
        //Step 2 − If the queue is empty, produce underflow error and exit.
        return false;
    }
    //Step 3 − If the queue is not empty, access the data where front is pointing
    *frontValue = queue->data[queue->front];
    //Step 4 − Increment front pointer to point to the next available data element
    queue->front += 1;
    //Step 5 − Return success
    return true;
}

bool peek(struct Queue queue, int *frontValue){
    if(isEmpty(queue)){
        return false;
    }
    *frontValue = queue.data[queue.front];
    return true;
}
bool isFull(struct Queue queue){
    return queue.rear == queue.maxSize-1;
}
bool isEmpty(struct Queue queue){
    return queue.rear < queue.front;
}