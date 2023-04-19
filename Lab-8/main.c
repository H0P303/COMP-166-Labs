//
//  main.c
//  Lab-8
//
//  Created by Alexander Ottosson on 2023-03-07.
//

#include <stdio.h>
#include <stdlib.h>
#include "vectorMath.h"

int main(int argc, const char * argv[]) {
    Vector V1 = {5, {1.0, 4.0, -7.2, -6.66, 1.23 }};
    Vector V2 = {5, {-5.2, 11.1, 0.1, 9.9, 7.123 }};
    Vector V3 = {7 };
    Vector rV;
    
    fprintf(stdout, "Vector #1\t");
    printVector(V1, stdout);
    
    fprintf(stdout, "Vector #2\t");
    printVector(V2, stdout);
    
    if(vectorMath(&V1, &V2, &rV, '+') != NULL){
        fprintf(stdout, "Sum\t\t\t");
        printVector(rV, stdout);
    }
    else{
        fprintf(stderr, "Addition Failed\n");
    }
    
    if(vectorMath(&V1, &V2, &rV, '-') != NULL){
        fprintf(stdout, "Difference\t");
        printVector(rV, stdout);
    }
    else{
        fprintf(stderr, "Subtraction Failed\n");
    }
    
    if(vectorMath(&V1, &V2, &rV, '*') != NULL){
        fprintf(stdout, "Product\t\t");
        printVector(rV, stdout);
    }
    else{
        fprintf(stderr, "Multiplication Failed\n");
    }
    
    if(vectorMath(&V1, &V2, &rV, '/') != NULL){
        fprintf(stdout, "Quotient\t");
        printVector(rV, stdout);
    }
    else{
        fprintf(stderr, "Division Failed\n");
    }
    
    
    // Check that the error handling works - Negative Testing
    // 1) Vector size mismatch
    if (vectorMath(&V1, &V3, &rV, '/') != NULL) {
        printf ("Quotient   ");
        printVector (rV, stdout);
    } else {
        fprintf(stderr, "Division failed\n");
    }
    // 2) Invalid operator
    if (vectorMath(&V1, &V2, &rV, '^') != NULL) {
        printf ("Exponent   ");
        printVector (rV, stdout);
    } else {
        fprintf(stderr, "Exponentiation failed\n");
    }
}
