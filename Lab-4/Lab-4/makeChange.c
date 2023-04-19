//Comp-166 Lab-4
//Author: Alexander Ottosson
//Date: 11/01/2023
//Requirements:  Your program must:
// 1) Prompt for the total purchase price
// 2) Prompt for the amount tendered
// 3) Display the total amount of change due
// 4) Compute and display the number and types of bills and coins in the change.
//    Assume that we have the following denominations: $20, $10, $5, $2, $1, 25¢, 10¢, and 5¢.
// 5) Store all of the currency values and the denomination names in arrays.
// 6) Repeatedly use the function changeItem() in a for loop.
// 7) Consist of three files:  two source files (makeChange.c, changeItem.c) and a header file (changeItem.h).
// 8) Use #ifndef to prevent multiple inclusions of the header file
// 9) Remember to include your header file in your changeItem.c so that the compiler will complain (in a convenient place)
//    if you did not implement what you promised.  You should always include.
//
//Description: Prompts user for input, price of product & tender. Calculates change rounded to nearest nickel.
//    Also displayes the breakdown of denominations used for change.

//Included files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "changeItem.h"

#define N_CURRENCY 8

const char *singleNames[N_CURRENCY] = {"Twenty", "Ten", "Five", "Toonie", "Loonie", "Quarter", "Dime", "Nickle"};
const char *pluralNames[N_CURRENCY] = {"Twenties", "Tens", "Fives", "Toonies", "Loonies", "Quarters", "Dimes", "Nickles"};
const double denomVals[N_CURRENCY] = {20, 10, 5, 2, 1, 0.25, 0.1, 0.05};

int main(void){
    double price, tender, change = 0, changeBuf;

    //Purchase price
    printf("Enter the amount of the purchase: $");
    scanf("%lf", &price);
    while(price < 0){   //if value entered is < 0, prompt to enter new value. (runs until accepted value is entered)
        printf("Value entered is negative, please enter new value: ");
        scanf("%lf", &price);
    }

    //Tendered value
    printf("Enter the amount tendered: $");
    scanf("%lf", &tender);
    while(tender < 0){   //if value entered is < 0, prompt to enter new value. (runs until accepted value is entered)
        printf("Value entered is negative, please enter new value: ");
        scanf("%lf", &tender);
    }

    if(price >= tender){  //checks if payment meets or exceeds price
        double amountShort = (price - tender);
        printf("makeChange Error: Please give me at least $%0.2lf more cash.\n", amountShort);
        return EXIT_FAILURE;
    }
    
    change = (tender - price); // calculates change
    printf("Change due: $%0.2lf\n", change);
    change = round(change * 20) / 20;
    printf("Rounded to nearest nickel: $%0.2lf\n", change);
    
    changeBuf = change;
    for (int i = 0; i < N_CURRENCY; i++) {//Loops through all denominations and prints breakdown for given change
        changeBuf = changeItem(changeBuf, denomVals[i], singleNames[i], pluralNames[i]);
    }

    return EXIT_SUCCESS;
}
