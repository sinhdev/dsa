#include <stdio.h>

struct queue{
    int data[50];
    int maxIndex;
    int front;
    int rear;
};

int enqueue(int value, struct queue* q);
int dequeue(int *value, struct queue* q);

int main(int count, char** args){
    //declare queue
    struct queue myQueue;
    //init queue
    myQueue.maxIndex = 49;
    myQueue.front = 0;
    myQueue.rear = -1;

    enqueue(1, &myQueue);
    enqueue(2, &myQueue);
    enqueue(3, &myQueue);
    enqueue(4, &myQueue);
    enqueue(5, &myQueue);

    int front;
    while(dequeue(&front, &myQueue)){
        printf("%d | ", front);
    }
    return 0;
}
int dequeue(int *value, struct queue* q){
    //Step 1 − Check if the queue is empty
    if(q->front > q->rear){
        //Step 2 − If the queue is empty, produce underflow error and exit.
        return 0;
    }
    //Step 3 − If the queue is not empty, access the data where front is pointing
    *value = q->data[q->front];
    //Step 4 − Increment front pointer to point to the next available data element
    q->front += 1;
    //Step 5 − Return success
    return 1;
}
int enqueue(int value, struct queue* q){
    //Step 1 − Check if the queue is full
    if(q->rear==q->maxIndex){
        if(q->front==0){
            //Step 2 − If the queue is full, produce overflow error and exit
            return 0;
        }
        int i, newRear = q->rear - q->front;
        for(i=0; i<newRear; i++){
            q->data[i] = q->data[i + q->front];
        }
        q->front = 0;
        q->rear = newRear;
    }
    //Step 3 − If the queue is not full, increment rear pointer to point the next empty space
    q->rear += 1;
    //Step 4 − Add data element to the queue location, where the rear is pointing
    q->data[q->rear] = value;
    //Step 5 − return success
    return 1;
}