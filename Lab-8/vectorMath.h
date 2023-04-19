//
//  vectorMath.h
//  Lab-8
//
//  Created by Alexander Ottosson on 2023-03-08.
//

#ifndef vectorMath_h
#define vectorMath_h

#include <stdio.h>

//#if not defined(WORD) || not defined(WORD_FORMAT)
//#error You must have compiler defines (-D) for both WORD and WORD_FORMAT
//#endif

#ifndef WORD || WORD_FORMAT
#error You must have compiler defines (-D) for both WORD and WORD_FORMAT
#endif

#define MAX_LENGTH 10

typedef struct vector{
    int n;  //Number of values currently stored.
    WORD x[MAX_LENGTH];
}Vector;

    /// Performs Vector Math
    /// - Parameters:
    ///   - V1: Vector 1
    ///   - V2: Vector 2
    ///   - resultPtr: Memory address of where we want the result to be stored
    ///   - op: Math operator specified
Vector *vectorMath(const Vector *V1, const Vector *V2, Vector *resultPtr, const char op);

void printVector(const Vector V, FILE *stream);

#endif /* vectorMath_h */
