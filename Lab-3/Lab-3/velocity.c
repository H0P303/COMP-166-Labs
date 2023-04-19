//
//  velocity.c
//  Lab-3
//
//  Created by Alexander Ottosson on 2023-01-12.
//
//  Desc: Calculates the velocity of a user specified object falling from a user specified starting altitude over user defined steps in time.
//        Program uses Eulers Method to find the velocity of the object. Allows comparison of found terminal velocity with calculated
//        velocity.
//        Calculations take drag into account at each given altitude.
//
//  Note: I had to alter your density.c file to include a variable for gravity (g). The code I copied from your website didnt include this
//        and it caused an error in that file. I made g = 9.80665. Seen on line 26 of that file.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "density.h"

int main(int argc, const char * argv[]) {
    double height = 0.0;                    //User entered height in M (Starting altitude)
    double mass = 0.0;                      //User entered mass in KG
    double dragCoef = 0.0;                  //User entered drag coef
    double xArea = 0.0;                     //User entered cross sectional area
    double time = 0.0, currentTime = 0.0;   //User entered time step size and currentTime tracker
    double v = 0.0;                         //Velocity of object
    double vT = 0.0;                        //Calculated terminal velocity
    double a = 0.0;                         //Acceleration
    const double g  = 9.80665;              //Gravitational pull (Standard gravity)
    #define iterLimit 100000                //iteration limit in for loop
    
    printf("Enter the height in metres: ");
    scanf("%lf", &height);
    
    printf("Enter the mass in KG: ");
    scanf("%lf", &mass);
    
    printf("Enter the drag coefficient: ");
    scanf("%lf", &dragCoef);
    
    printf("Enter the cross-sectional area: ");
    scanf("%lf", &xArea);
    
    printf("Enter the time step size: ");
    scanf("%lf", &time);
    
    printf("\tTime\tHeight\tVelocity\n");
    
    //Iterates the acceleration calculation for each given timestep (time). Uses the acceleration to find current velocity and altitude.
    for (int i = 0; i < iterLimit; i++) {
        printf("\t%6.2lf\t%6.1lf\t%6.2lf\n", currentTime, height, v);
        
        currentTime = currentTime + time;
        
        //            (0.5 * dragCoef * density * xArea * v^2)
        //  a =   g - ----------------------------------------
        //                           mass
        a = (g - (((dragCoef * density(height) * xArea * pow(v, 2)) / 2.0) / mass)); //Calculates acceleration
        
        v = v + time * a;  //Finds new velocity using euler method
        
        height = height - v * time; //Finds new height using current velocity and time spent at that velocity
        
        if(height < 0){
            printf("Program ended as object has reached the ground.\n");
            break;
        }
    }
    
    vT = (sqrt((2.0 * mass * g)/(dragCoef * density(0) * xArea)));    //Calculates terminal velocity at sea level
    printf("\n\nTheoretical terminal velocity at sea level: %0.2lfm/s\n", vT);
    
    return EXIT_SUCCESS;
}
