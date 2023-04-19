//Comp-166 Lab-1
//Author: Alexander Ottosson
//Date: 11/01/2023
//Requirements:  Your program must:
// 1) Prompt for the total purchase price
// 2) Prompt for the amount tendered
// 3) Display the total amount of change due
// 4) Compute and display the number and types of bills and coins in the change.
//    Assume that we have the following denominations: $20, $10, $5, $2, $1, 25¢, 10¢, and 5¢.
//Description: Prompts user for input, price of product & tender. Calculates change rounded to nearest nickel.
//             Also displayes the breakdown of denominations used for change.

//Included files
#include <stdio.h>
#include <math.h>

//Global Variables
char singleName[8][8] = {"Twenty", "Ten", "Five", "Toonie", "Loonie", "Quarter", "Dime", "Nickle"};

char plural[8][8] = {"Twenties", "Tens", "Fives", "Toonies", "Loonies", "Quarters", "Dimes", "Nickles"};

double denomVal[8] = {20, 10, 5, 2, 1, 0.25, 0.1, 0.05};

//Rounds change to nearest nickel
double rounder(double c){
    double cRounded = 0, a = 0, b = 0;
    //Example calculation
    // b = 3.42 * 100 = 342
    // a = 342 % 5 = 2
    // (b - a) / 100 = (342 - 2) / 100 = 3.40
    b = (int)(c * 100);
    a = (int)b % 5;

    if((int)b % 2){ //checks to see if b is divisable by 2. if yes, means b is even and it should round to 0
        cRounded = ((b - a)) / 100;
    }
    else if(!((int)b % 2)){ //checks to see if b is divisable by 2. if no, means b is even and it should round to 5
        cRounded = ((b - a)) / 100;
    }
    
    if(0 < a && a < 3){ //if remainder is 0 < x < 3, round to 0
        cRounded = (b - a) / 100;
    }
    else if(3 <= a && a <= 4){   //else if remainder is 3 <= x <= 4, round to 5
        cRounded = ((b - a) + 5) / 100;
    }
    
    return cRounded;
}

//Calculates the denomination return for given change.
double denomCalc(double change, const double itemValue, const char * singleName, const char * plural){

    int num = 0;

    num = change / itemValue;   //find amount of certain demonination to return

    //Finds plural or singular demonination
    if(!(num > 1)){
        printf("%d %s\n", num, singleName);
    }
    else{
        printf("%d %s\n", num, plural);
    }

    change = change - (itemValue * num);    //Calculates change remaining

    return (change);
}

int main(void){

    double p = 0, t = 0, c = 0, cRounded = 0, cRoundedBuf = 0;

    //Purchase price
    printf("Enter the amount of the purchase: $");
    scanf("%lf", &p);   //reads console, saves value entered
    while(p < 0){   //if value entered is < 0, prompt to enter new value. (runs until accepted value is entered)
        printf("Value entered is negative, please enter new value: ");
        scanf("%lf", &p);   //reads console, saves value entered
    }

    //Tendered value
    printf("Enter the amount tendered: $");
    scanf("%lf", &t);   //reads console, saves value entered
    while(t < 0){   //if value entered is < 0, prompt to enter new value. (runs until accepted value is entered)
        printf("Value entered is negative, please enter new value: ");
        scanf("%lf", &t);   //reads console, saves value entered
    }

    //error checking. sees if payment covers cost
    if(p > t){
        double amountShort = (p - t);
        printf("makeChange Error: Please give me at least $%0.2lf more cash.\n", amountShort);
    }
    else{
        c = (t - p); // calculates change
        cRounded = rounder(c);
        printf("Change due: $%0.2lf\n", c);
        printf("Rounded to nearest nickel: $%0.2lf\n", cRounded);
    }

    // denomCalc(cRounded, singleName, plural);
    cRoundedBuf = cRounded;
    for (int i = 0; i < 8; i++)
    {
        cRoundedBuf = denomCalc(cRoundedBuf, denomVal[i], singleName[i], plural[i]);
    }

    return 0;
}
