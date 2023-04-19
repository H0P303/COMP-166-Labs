/*
 * Library functions for complex math
 *
 * Dale Shpak
 * June 18, 2015
 */

#ifndef COMPLEX_H
#define COMPLEX_H

#define Z_FORMAT "%9.4lf%+9.4lfi"

/* Struct to represent a complex number */
typedef struct  {
    double re, im;
} Complex;

/* Complex arithmetic operators */
Complex add (const Complex a, const Complex b);
Complex subtract (const Complex a, const Complex b);
Complex multiply (const Complex a, const Complex b);
Complex divide (const Complex a, const Complex b);
Complex conjugate (const Complex a);
double magnitude (const Complex a);
/* Returned angle must be in the correct quadrant! */
//use atan2
double angle (const Complex a);
#endif    /* COMPLEX_H */
