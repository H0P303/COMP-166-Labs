//
//  statistics.h
//  Lab-5
//
//  Created by Alexander Ottosson on 2023-02-08.
//

#ifndef statistics_h
#define statistics_h

#include <stdio.h>


    /// Calculates mean
    /// - Parameters:
    ///   - sum: Sum of all values
    ///   - count: Number of values
double mean(const double sum, const int count);


    /// Calculates sample standard deviation
    /// - Parameters:
    ///   - sum: Sum of all values
    ///   - sumsq: Sum of all values squared
    ///   - count: Number of all values
double ssdev(const double sum, const double sumsq, const int count);

#endif /* statistics_h */
