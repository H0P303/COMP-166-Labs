//
//  density.c
//  Lab-3
//
//  Created by Daniel Schpak.
//

#include "density.h"
#include <math.h>

/*!
 * Compute the density of dry air in SI units.
 * (Uses the global gravitational constant g).
 *
 * @param altitude Altitude in metres above mean sea level
 *
 * @return Density in SI units
 */

double density(double altitude) {
  const double p0 = 101.325e3; // Sea-level std atmospheric pressure, Pascals
  const double T0 = 288.15;    // Sea-level std temperature, Kelvins
  const double L  = 0.0065;    // Temperature lapse rate, K/m
  const double R  = 8.31447;   // Ideal gas constant, J/(mol.K)
  const double M  = 0.0289644; // Molar mass of dry air, kg/mol
  const double g  = 9.80665;   // Gravitational pull (standard gravity)
  double p, T;
  T = T0 - (L * altitude);  //Temperature at given altitude
  p = p0 * pow((1 - (L * altitude) / T0), (g * M) / (R * L)); //pressure at given altitude
  return (p * M) / (R * T); //Returns Density at given altitude
}
