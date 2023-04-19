//
//  main.c
//  Lab-9
//
//  Created by Alexander Ottosson on 2023-03-09.
//

#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

    /// Hello world
    /// - Parameters:
    ///   - argc: THis does x
    ///   - argv: This does y
int main(int argc, const char * argv[]) {
    Complex x;
    Complex y;
    Complex res;
    char mustBeIorJ[2];
    
    if(argc != 3){
        printf("Failed to run. Enter Value\n");
        return EXIT_FAILURE;
    }
    
    if((sscanf(argv[1], "%lf%lf%1[ij]", &x.re, &x.im, mustBeIorJ) != 3) || (sscanf(argv[2], "%lf%lf%1[ij]", &y.re, &y.im, mustBeIorJ) != 3)){
        printf("Failed to run. Enter Valid Value\n");
        return EXIT_FAILURE;
    }
    
    
    printf("x           = " Z_FORMAT "\n", x.re, x.im);
    printf("y           = " Z_FORMAT "\n", y.re, y.im);
    
    //Sum
    res = add(x, y);
    printf("Sum         = " Z_FORMAT "\n", res.re, res.im);
    
    //Difference
    res = subtract(x, y);
    printf("Difference  = " Z_FORMAT "\n", res.re, res.im);
    
    //Product
    res = multiply(x, y);
    printf("Product     = " Z_FORMAT "\n", res.re, res.im);
    
    //Quoitient
    res = divide(x, y);
    printf("Quotient    = " Z_FORMAT "\n", res.re, res.im);
    
    //Conjugate
    res = conjugate(x);
    printf("X Conjugate = " Z_FORMAT "\n", res.re, res.im);
    res = conjugate(y);
    printf("Y Conjugate = " Z_FORMAT "\n", res.re, res.im);
    
    //Magnitude & Angle
    printf("X Magnitude = %9.4lf, Angle = %.4lf Rads\n", magnitude(x), angle(x));
    printf("X Magnitude = %9.4lf, Angle = %.4lf Rads\n", magnitude(y), angle(y));
    
    return EXIT_SUCCESS;
}
