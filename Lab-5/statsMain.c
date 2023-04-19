    //
    //  statsMain.c
    //  Lab-5
    //
    //  Created by Alexander Ottosson on 2023-02-14.
    //  Reads user selected input txt file. Calculates Mean and sample standard deviation.
    //  Prints results to terminal and to Result_nameOfFile.txt that can be read later.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include "statistics.h"

#define PREFIX "Result_"

static void printStats(FILE *dest, const int count, const double theMean, const double stddev);

int main(int argc, char *argv[]) {
    
    if(argc != 2){
        fprintf(stderr, "Usage: %s fileName \n", basename(argv[0]));
        return EXIT_FAILURE;
    }
    
    const char *inputFileName = argv[1];    //2nd argument specifies file user wants to use
    
    FILE *inputFile = fopen(inputFileName, "r");    //Opens specified file with "read" specifier
    
    if(inputFile == NULL){
        fprintf(stderr, "%s: Unable to open %s because: %s\n", basename(argv[0]), argv[1], strerror(errno));
        return EXIT_FAILURE;
    }
    
    double value, sum = 0.0, sumsq = 0.0;
    int count = 0;
    
    //Loops through each character of the file.
    while (fscanf(inputFile, "%lf", &value) == 1) {
        count += 1;
        sum += value;
        sumsq += value * value;
    }
    if(count < 2){
        fprintf(stderr, "Not enough values read from input file %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    
    //Calculates mean and standard deviation for file content
    double theMean = mean(sum, count);
    double stdDev = ssdev(sum, sumsq, count);
    
    printf("Results from input file: %s\n", argv[1]);
    printStats(stdout, count, theMean, stdDev); //Prints value to the standard output stream (stdout)
    
    int nChar = strlen(PREFIX) + strlen(argv[1]) + 1;   //Length of output string array
    
    // malloc() returns the starting address of the block of memory.
    // It returns NULL if it fails, but no need to check in this lab.
    // The chunk of memory is persistent, i.e., it remains until our
    // program finishes (or until we free() it),
    // even if it was allocated in a function.
    char *outName = (char *) malloc(nChar); //Request chunk of memory
    strncpy(outName, PREFIX, strlen(PREFIX));    //copies prefix into outName pointer
    strncat(outName, argv[1], strlen(argv[1])); //concatenate the existing 2nd cmdline parameter with existing outName data
    
    FILE *outFile = fopen(outName, "w");    //Opens created output file with "write" specifier
    
    if(outFile == NULL){
        fprintf(stderr, "%s: Unable to open %s because: %s\n", basename(argv[0]), outName, strerror(errno));
        return EXIT_FAILURE;
    }
    
    printStats(outFile, count, theMean, stdDev);
    
    free(outName);
    fclose(inputFile);
    fclose(outFile);
    return EXIT_SUCCESS;
}

static void printStats(FILE *dest, const int count, const double theMean, const double stdDev) {
    fprintf(dest, "Number of values: %d\n", count);
    fprintf(dest, "Mean: %0.4lf\n", theMean);
    fprintf(dest, "Sample Standard Deviation: %0.4lf\n", stdDev);
}
