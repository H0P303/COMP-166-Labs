//
//  queue.c
//  Lab-10
//
//  Created by Alexander Ottosson on 2023-03-20.
//

//We create a new node for each item in the queue. The nodes have their memory dynamically allocated using malloc. When the item in the queue is removed then we use Free() to free that memory space used for that specific node.

//https://www.youtube.com/watch?v=o5wJkJJpKtM&ab_channel=PaulProgramming

#include "queue.h"

/* Add an item to the rear of the dynamically-allocated queue.
 * Returns:  pointer to the item if successful, NULL if not */
ItemType *enqueue (Queue *queuePtr, ItemType *newItem, char addFront){
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    
    newNode->dataPtr = newItem;
    newNode->next = NULL;
    queuePtr->size +=1; //Size of queue tracker increased.
    
    if(queuePtr->rear == NULL){
        //If this is the first item that is added then add newNode to front and rear of queue,
        queuePtr->front = queuePtr->rear = newNode;
        return queuePtr->rear->dataPtr;
    }
    
    if(addFront == REAR){   //Adds to rear of queue
        //Original rear node->next will point to the new node that was created. This happens before we make the queuePTR->rear point to the newNode that was created.
        newNode->prev = queuePtr->rear;
        queuePtr->rear->next = newNode;
        queuePtr->rear = newNode;
        return queuePtr->rear->dataPtr;
    }
    else if(addFront == FRONT){ //Adds to front of queue
        //Original rear node->next will point to the new node that was created. This happens before we make the queuePTR->rear point to the newNode that was created.
        queuePtr->front->prev = newNode;
        newNode->next = queuePtr->front;
        queuePtr->front = newNode;
        return queuePtr->front->dataPtr;
    }
    else{
        return NULL;
    }
    
}

/* Removes an item from the the queue.
 * Returns:  pointer to the item if successful, NULL if empty */
ItemType *dequeue (Queue *queuePtr, char removeFront){
    
    if(!(queuePtr->size > 0)){
        return NULL;
    }
    queuePtr->size -= 1;
    
    if(removeFront == FRONT){
        //Saves current F+1 node (F is current front node)
        ListNode *newFront = queuePtr->front->next;
        void *oldFront = queuePtr->front->dataPtr;
        free(queuePtr->front);
        queuePtr->front = newFront;
        return oldFront;
    }
    else if(removeFront == REAR){
        //Saves current R-1 node (R is current rear node)
        ListNode *newRear = queuePtr->rear->prev;
        void *oldRear = queuePtr->rear->dataPtr;
        free(queuePtr->rear);
        queuePtr->rear = newRear;
        queuePtr->rear->next = NULL;
        return oldRear;
    }
    else{
        return NULL;
    }
}

/* Returns:  number of items in the queue */
int queueSize (const Queue queue){
    return queue.size;
}

/* Print the contents of the queue to the specified stream */
void printQueue (const Queue queue, FILE *stream){
    
    if((queue.size > 0)){
        //Sets a current node tracker to == the first node in the queue
        ListNode *currentNode = queue.front;
        
        //Prints the data inside the node that we are currently looking at
        while (currentNode != NULL) {
            fprintf(stream, ITEM_FORMAT"\n", *currentNode->dataPtr);
            
            //points the node tracker to the next node in the queue.
            currentNode = currentNode->next;
        }
    }
    
}
