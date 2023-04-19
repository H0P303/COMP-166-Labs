//
//  main.c
//  Lab-6
//
//  Created by Alexander Ottosson on 2023-02-14.
//
//  Reads binary file and searches for user entered value. Returns location of value inside binary file
//  If found in file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include "arraySearch.h"


int main(int argc, char * argv[]) {
    
    if(argc != 3){  //Checks # of cmdline arguments
        fprintf(stderr, "Usage: %s numberFileName nNumbers\n", basename(argv[0]));
        return EXIT_FAILURE;
    }
    
    int nNum;
    if(sscanf(argv[2], "%d", &nNum) != 1){  //converts string from cmdline to int. If != 1 then not a number
        printf("Unable to convert \"%s\" into an integer value.\n", argv[2]);
        return EXIT_FAILURE;
    }
    
    int *num = (int *) malloc(nNum);    //allocates user specified amount of memory
    if(num == NULL){    //Verifies allocation was successful
        printf("Could not allocate memory\n");
        return EXIT_FAILURE;
    }
    
    FILE *inputFile = fopen(argv[1], "rb"); //opens user selected file
    if(inputFile == NULL){  //Verifies file open properly
        fprintf(stderr, "%s: Unable to open %s\n", basename(argv[0]), argv[1]);
        return EXIT_FAILURE;
    }
    
    if(fread(num, sizeof(int), nNum, inputFile) != nNum){ //attempts to read user selected file content
        printf("Unable to read %d from file \"%s\".\n", nNum, argv[1]);
        fclose(inputFile);
        return EXIT_FAILURE;
    }
    fclose(inputFile);  //closes file once content has been read
    
    while(1){
        char uVal[11];
        int x = -1;
        printf("Enter the integer value to find ('q' to quit):");
        scanf("%10s", uVal);
        if(uVal[0] == 'q'){
            printf("Quitting...\n");
            return EXIT_FAILURE;
        }
        else if(sscanf(uVal, "%d", &x) == 1){   //converts string from cmdline to int. If != 1 then not a number
            int searchRes = linearSearch(x, num, nNum); //searches for user entered value in array
            free(num);  //frees allocated memory
            if(searchRes != -1){    //user entered value was found
                printf("%d was found at position %d\n", x, searchRes);
            }
            else{   //user entered value was not found
                printf("%d was not found\n", x);
            }
        }
        else{
            printf("Unable to convert to number\n");
        }
    }
}
