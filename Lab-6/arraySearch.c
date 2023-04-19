//
//  arraySearch.c
//  Lab-6
//
//  Created by Alexander Ottosson on 2023-02-24.
//

#include "arraySearch.h"


int linearSearch(const int value, const int numbers[], const int nNumbers){
    for(int i = 0; i < nNumbers; i++){
        if(value == numbers[i]){
            return i;
        }
        else if(i == nNumbers){
            return -1;
        }
    }
    return -1;
}
