//
//  temperatureConversion.c
//  Lab-2
//
//  Created by Alexander Ottosson on 2023-01-12.
//
//  Desc: Reads user input temperature and unit. Prints converted entered temperature.
//  Validation: Program was validated by entering a given temp, Ex. -40F, seeing if output matches expectiation, Ex. -40F == -40C
//              Then I entered the returned value back into the program to see if original temperature was returned again.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    double inputTemp, cTemp, kTemp, fTemp;
    int type;
    char line[11];
    char tempUnit;
    
    printf("Enter a temperature followed by F, C, K, e.g. 24.4F: ");
    scanf("%lf%10s", &inputTemp, line);
    type = line[0];
    
    tempUnit = toupper(type);
    
    switch (tempUnit) {
        case 'C':
            //Convert C to K and F
            cTemp = inputTemp;
            fTemp = (cTemp * 9/5) + 32;
            kTemp = (cTemp + 273.15);
            break;
        case 'F':
            //Convert F to K and C
            fTemp = inputTemp;
            cTemp = (fTemp - 32.0) / 1.8;
            kTemp = ((fTemp + 459.67) * (5.0/9.0));
            break;
        case 'K':
            //Convert F to K and C
            kTemp = inputTemp;
            cTemp = (kTemp - 273.15);
            fTemp = ((kTemp * (9.0/5.0)) - 459.67);
            break;
        default:
            fprintf(stderr, "Unknown Temperature Type: %c\n", (char)type);
            return EXIT_FAILURE;
    }
    printf("%0.3lfK =\t%0.3lfC =\t%0.3lfF =\n", kTemp, cTemp, fTemp);
    return 0;
}
