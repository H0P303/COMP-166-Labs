/*
 * An introduction to the C Programming Language.
 * Intended as a walk-through tutorial.
 *
 * Dale Shpak
 * Jan 6, 2017
 */

// Include header files that contain descriptions of library functions that we want to use
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int N_POWERS = 5;  // Declare an integer constant

// Every C program has a function named "main".  It is the starting point when it runs.
int main (void) {
  // Variables must be declared before they can be used
  double a = 0, b = 0, sum = 0, diff = 0, z = 0;

  // Prompt the user to enter two numbers
  printf("Enter two numbers: ");
  // Read those two numbers into the variables a and b at their respective memory location.
  scanf("%lf%lf", &a, &b);

  // Do some math
  sum = a + b;
  diff = a - b;

  // Print the results to the console
  printf("The sum of %lf and %lf is %lf\n", a, b, sum);
  printf("The difference of %0.0lf and %0.0lf is %0.0lf\n", a, b, diff);

  // Use a "for" loop to repeatedly perform similar computations
  for (int k=0; k <= N_POWERS; k++) {
    z = pow(a, k);  // Uses the math library function pow()
    printf("%0.0lf raised to the power %d is %0.0lf\n", a, k, z);
  }

  return EXIT_SUCCESS;
}