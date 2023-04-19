//
//  changeItem.h
//  Lab-4
//
//  Created by Alexander Ottosson on 2023-01-12.
//

#ifndef changeItem_h
#define changeItem_h

#include <stdio.h>

    /// The function changeItem computes the number of bills or coins returned in one step of the changemaking process.
    /// - Parameters:
    ///   - change: Current amount of change due
    ///   - itemValue: The value of the current bill or coin
    ///   - singleName: The name for a single bill or coin
    ///   - plural: The name for multiple bills or coins
double changeItem(double change, const double itemValue, const char * singleName, const char * plural);

#endif /* changeItem_h */
