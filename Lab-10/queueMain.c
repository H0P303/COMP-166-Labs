/* Tests for Queue library.
 *
 * Dale Shpak
 * March 25, 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef enum {QUIT=-1, ENQUEUE, DEQUEUE, PRINT, N_CHOICES} Choice;

int main(int ac, char *av[]) {
    Queue queue = {NULL, NULL, 0};

    int done = 0;
    while (!done) {
        Choice choice;
        int nValid;
        do {    //Runs until the user enters a valid command
            printf("Enter %d to add to queue, %d to remove, or %d to print contents "
                   "(%d to quit): ", ENQUEUE, DEQUEUE, PRINT, QUIT);
            nValid = scanf("%d", &choice);
            while (getchar() != '\n') { } // Get rid of rest of line
        } while (nValid != 1 || choice < QUIT || choice >= N_CHOICES);
        
        
        switch (choice) {   //choice is the user command, will run a function depending on user input
            case DEQUEUE: { //Removes either the first or last item in the queue
                ItemType *itemPtr;  //Creates an int pointer
                
                char frontRear[2];
                printf("Remove from FRONT (f) or REAR (r) of queue?\n");
                if(scanf("%s", frontRear) != 1){
                    fprintf(stderr, "Unable to read input \n");
                    break;
                }
                
                if(frontRear[0] == FRONT){//Removes item to front of queue
                    if ((itemPtr = dequeue(&queue, FRONT)) != NULL) {
                        printf("Removed " ITEM_FORMAT "\n", *itemPtr);
                        free (itemPtr);
                    } else {
                        printf("Queue is empty\n");
                    }
                }
                else if(frontRear[0] == REAR){//Removes item to rear of queue
                    if ((itemPtr = dequeue(&queue, REAR)) != NULL) {
                        printf("Removed " ITEM_FORMAT "\n", *itemPtr);
                        free (itemPtr);
                    } else {
                        printf("Queue is empty\n");
                    }
                }
                else{
                    printf("Didnt enter valid command\nItem was not removed to queue\nReturning to main menu...\n\n");
                }
                break;
            }
                
            case ENQUEUE: {//Adds new item either to the first or last position in queue
                ItemType *itemPtr = (ItemType *) malloc (sizeof(ItemType));
                if (itemPtr == NULL) {
                    fprintf(stderr, "%s: Error allocating memory for item.\n", av[0]);
                    return EXIT_FAILURE;
                }
                
                printf ("Enter " ITEM_PROMPT ": ");
                if (scanf(ITEM_FORMAT, itemPtr) != 1) {
                    fprintf(stderr, "Unable to read " ITEM_PROMPT "\n");
                    break;
                }
                
                char frontRear[2];
                printf("Add to FRONT (f) or REAR (r) of queue?\n");
                if(scanf("%s", frontRear) != 1){
                    fprintf(stderr, "Unable to read input \n");
                    break;
                }
                
                if(frontRear[0] == FRONT){//Adds item to front of queue
                    if ((itemPtr = enqueue(&queue, itemPtr, FRONT)) != NULL) {
                        printf("Added " ITEM_FORMAT " to front of queue\n", *itemPtr);
                        break;
                    }
                    else {
                        fprintf(stderr, "%s: Error allocating memory to queue.\n", av[0]);
                        return EXIT_FAILURE;
                    }
                }
                else if(frontRear[0] == REAR){//Adds item to rear of queue
                    if ((itemPtr = enqueue(&queue, itemPtr, REAR)) != NULL) {
                        printf("Added " ITEM_FORMAT " to back of queue\n", *itemPtr);
                        break;
                    }
                    else {
                        fprintf(stderr, "%s: Error allocating memory to queue.\n", av[0]);
                        return EXIT_FAILURE;
                    }
                }
                else{
                    printf("Didnt enter valid command\nItem was not added to queue\nReturning to main menu...\n\n");
                }
                break;
            }
                
            case PRINT: {
                printf ("%d Items currently in the queue:\n", queueSize(queue));
                printQueue (queue, stdout);
                break;
            }
                
            case QUIT: {
                done = 1;
                break;
            }
                
                
            default: {
                fprintf(stderr, "Invalid choice entered");
                break;
            }
        }
    }
    
    printf ("%d Items remaining in the queue:\n", queueSize(queue));
    printQueue (queue, stdout);


    return EXIT_SUCCESS;
}
