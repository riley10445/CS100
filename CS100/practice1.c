#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

/*
 p1.c
 Define weight of a string as the sum of its ascii letters (only letters).
 eg: int wt = 'w'+'e'+'i'+'g'+'h'+'t'.
 The weight of "weight" is wt.
 Write a program that gives the weight of any arguments specified on the command line.
 eg:
 % ./a.out test this weight
 "test" has weight: 448
 "this" has weight: 440
 "weight" has weight: 648
 */
 
double weight(char * str){
    char *string = str;
    int i = 0;
    double weight = 0.0;
    while(*(string+i) != '\0'){
        weight += (double)*(string+i);
        i++;
    }
    return weight;
}

int main(int argc, char ** argv){
    FILE *input_file = fopen(argv[1], "r");
    int i = 0;
    int total = 0;
    int num_words =  atoi(argv[2]);
    int value = atoi(argv[3]);
    char string[100][100]; 

    while (i < num_words){
        fscanf(input_file, "%s", string[i]);
        total += weight(string[i]);
        i++;
    }

    double mean = (double)total / (double)num_words;
    for(i = 0; i < num_words; i++){
        if(fabs(weight(string[i]) - mean) < value){
            printf("%s\n", string[i]);
        }
    }

}