//
//  main.c
//  Lab-7
//
//  Created by Alexander Ottosson on 2023-02-25.
//

#include <stdio.h>
#include <stdlib.h>

#define N_NUMS 10
typedef int WORD;
#define WORD_FORMAT "%d "
const WORD START = 1011;

void swap(WORD *x, WORD *y);
void printVector(const WORD *vec, const int N);
void printBytes(const WORD *vec, const int N);
void printBytesReverseEndian(const WORD *vec, const int N);

int main(int argc, const char * argv[]) {
    WORD numbers[N_NUMS];
    printf("Original Array Structure:\n");
    for (int i = 0; i < N_NUMS; i++) {
        //Fills array with values starting with value of START
        numbers[i] = START + i;
    }
    printVector(numbers, N_NUMS);
    
    printf("\n\n");

    printf("Adjacent Words Swapped:\n");
    
    for (int i = 0; i < N_NUMS; i += 2) {
        //provides the two adjacent indexes in the array to be swapped
        //the name "numbers" is a pointer to the [0] index of the array.
        //numbers + 1, therefore, is numbers[1].
        swap(numbers + i, numbers + (i+1));
    }
    printVector(numbers, N_NUMS);
    printf("\n\n");
    
    printf("Adjacent Words Swapped Back:\n");
    for (int i = 0; i < N_NUMS; i += 2) {
        //provides the two adjacent indexes in the array to be swapped
        swap(&numbers[i], &numbers[i+1]);
    }
    printVector(numbers, N_NUMS);
    printf("\n\n");
    
    printf("Data Bytes:\n");
    printBytes(numbers, N_NUMS);
    printf("\n\n");
    
    printf("Data Bytes Reversed:\n");
    printBytesReverseEndian(numbers, N_NUMS);
    printf("\n\n");
    
    return EXIT_SUCCESS;
}

void swap(WORD *x, WORD *y){    //Swaps two values at the given memory address.
    WORD temp = *y;
    *y = *x;
    *x = temp;
}

void printVector(const WORD *vec, const int N){
    for (int i = 0; i < N; i++) {  //Prints Swapped array
        printf(WORD_FORMAT, *vec++);
    }
}

void printBytes(const WORD *vec, const int N){ //*vec gets the memory location of the given array (numbers)
    uint8_t *p = (uint8_t *)vec; //cast pointer to byte pointer, allowing us to print one byte at a time instead of 4 (int)
    for (int i = 0; i < N*sizeof(WORD); i++) {  //loops through total amount of bytes
        printf("%hhu ", *p++);  //Prints byte value at current memory location
        if ((i + 1) % sizeof(WORD) == 0) {
            printf(" ");
        }
    }
}

void printBytesReverseEndian(const WORD *vec, const int N){
    uint8_t *p = (uint8_t *)vec;
    
    for (int i = 0; i < N; i++) {   //loops through # of values in array
        if(!(i > 0)){   //checks if this is the first run through the loop
            p = p + sizeof(WORD) - 1;  //if it is, move pointer p 3 memory location to the right.
        }
        else{
            //else, move pointer p 8 memory locations to the right. we use 8 in order to offset the 4x *p-- (going down 1 memory location)
            //overall, we want the pointer to go up by a total of 4 for each loop.
            p = p + (2 * sizeof(WORD));
        }
        for (int j = 0; j < sizeof(WORD); j++) {
            printf("%hhu ", *p--);  //prints each byte for the value inside the original array
        }
        printf(" ");    //prints space if we've printed all 4 bytes of value in array
    }
}
