//
//  complex.c
//  Lab-9
//
//  Created by Alexander Ottosson on 2023-03-15.
//

#include "complex.h"
#include <math.h>

Complex add (const Complex a, const Complex b){
    Complex res = {0,0};
    
    res.im = a.im + b.im;
    res.re = a.re + b.re;
    
    return res;
}

Complex subtract (const Complex a, const Complex b){
    Complex res = {0,0};
    
    res.im = a.im - b.im;
    res.re = a.re - b.re;
    
    return res;
}

Complex multiply (const Complex a, const Complex b){
    //Foil (a+bj)(c+dj) == ac + (ad)j + (cb)j + (bd)j^2
    //j^2 == -1
    //(a+bj)(c+dj) == ac + (ad)j + (cb)j + (-1)(bd)
    
    Complex res = {0,0};
    
    res.re = (a.re * b.re) - (a.im * b.im);
    res.im = (a.re * b.im) + (a.im * b.re);
    
    return res;
}

//https://stackhowto.com/c-program-to-divide-two-complex-numbers-using-structures/
Complex divide (const Complex a, const Complex b){
    Complex res = {0,0};
    
    res.re = ((a.re * b.re) + (a.im * b.im)) / ((b.re * b.re) + (b.im * b.im));
    res.im = ((a.im * b.re) - (a.re * b.im)) / ((b.re * b.re) + (b.im * b.im));
    
    return res;
}

Complex conjugate (const Complex a){
    Complex res = {0,0};
    
    res.re = a.re;
    res.im = -1 * a.im;
    
    return res;
}

double magnitude (const Complex a){
    return sqrt((a.re * a.re) + (a.im * a.im));
}

///* Returned angle must be in the correct quadrant! */
////use atan2
double angle (const Complex a){
    return atan2(a.im, a.re);
}

