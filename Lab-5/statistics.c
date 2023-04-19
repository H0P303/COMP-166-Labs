//
//  statistics.c
//  Lab-5
//
//  Created by Alexander Ottosson on 2023-02-08.
//

#include "statistics.h"
#include <math.h>


double mean(const double sum, const int count){
    return sum / count;
}


double ssdev(const double sum, const double sumsq, const int count){
    
    double variance = (sumsq - sum * sum / count) / (count - 1);
    
    return sqrt(variance);
}
