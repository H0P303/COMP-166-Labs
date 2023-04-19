//
//  vectorMath.c
//  Lab-8
//
//  Created by Alexander Ottosson on 2023-03-08.
//

#include "vectorMath.h"

Vector *vectorMath(const Vector *V1, const Vector *V2, Vector *resultPtr, const char op){
    
    if(V1->n != V2->n){   //If sizes are not the same, return null
        return NULL;
    }
    
    resultPtr->n = V1->n;
    
    switch(op){
        case '+':
            for (int i = 0; i < MAX_LENGTH; i++) {
                resultPtr->x[i] = V1->x[i] + V2->x[i];
            }
            return resultPtr;
            break;
        case '-':
            for (int i = 0; i < MAX_LENGTH; i++) {
                resultPtr->x[i] = V1->x[i] - V2->x[i];
            }
            resultPtr->n = V1->n;
            return resultPtr;
            break;
        case '*':
            for (int i = 0; i < MAX_LENGTH; i++) {
                resultPtr->x[i] = V1->x[i] * V2->x[i];
            }
            resultPtr->n = V1->n;
            return resultPtr;
            break;
        case '/':
            for (int i = 0; i < MAX_LENGTH; i++) {
                resultPtr->x[i] = V1->x[i] / V2->x[i];
            }
            resultPtr->n = V1->n;
            return resultPtr;
            break;
        default:
            return NULL;
            break;
    }
    
    return resultPtr;
}

void printVector(const Vector V, FILE *stream){
    for (int i = 0; i < V.n; i++) {
        fprintf(stream, WORD_FORMAT, *(V.x + i));   //prints value at memory address V.x +i
    }
    fprintf(stream, "\n");
}
