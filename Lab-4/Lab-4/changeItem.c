//
//  changeItem.c
//  Lab-4
//
//  Created by Alexander Ottosson on 2023-01-12.
//

#include <math.h>
#include "changeItem.h"

double changeItem(double change, const double itemValue, const char * singleName, const char * plural){
    
    int numBills = change / itemValue;    //Calculates amount of bills for a given change amount

    change = change - (itemValue * numBills);    //Calculate new change after denom has been removed
    
    if(numBills < 1){
        return change;
    }
    else if(!(numBills > 1)){     //Finds if return of num is > 1. if so, use plural name of denom.
        printf("%d %s\n", numBills, singleName);
        return (change);
    }
    else{
        printf("%d %s\n", numBills, plural);
        return (change);
    }
}
