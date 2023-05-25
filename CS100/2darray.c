#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Allocating space for a 2D array
int **allca2D(int rows, int cols){
    int **array = (int **)malloc(sizeof(int *) *rows);
    for(int i = 0; i < rows; i++){
        array[i] = (int *)malloc(sizeof(int) * cols);
    }
    return array;
}

// initialize a 2D array using a random number generator
void initRan2D(int **arr, int rows, int cols){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            arr[r][c] = rand() % 100;
        }
    }
}

void free2D(int **arr, int rows){
    for(int r = 0; r < rows; r++){
        free(arr[r]);
    }
    free(arr);
}

int sum2D(int **arr, int rows, int cols){
    int sum = 0;
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            sum += arr[r][c];
        }
    }
    return sum;
}

double avg2D(int **arr, int rows, int cols){
    return (double)sum2D(arr, rows, cols) / (rows * cols);
}

double max(int **arr, int rows, int cols){
    int max = arr[0][0];
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            if(arr[r][c] > max){
                max = arr[r][c];
            }
        }
    }
    return max;
}

double min(int **arr, int rows, int cols){
    int min = arr[0][0];
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            if(arr[r][c] < min){
                min = arr[r][c];
            }
        }
    }
    return min;
}

// Printing an array
void print2D(int **arr, int rows, int cols){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            printf("%d \t", arr[r][c]);
        }
        printf("\n");
    }
}


// main function
int main(){
    srand(time(0));

    int rows = 5;
    int cols = 6;

    int **arr = allca2D(rows, cols);
    initRan2D(arr, rows, cols);
    printf("Sum: %d\n", sum2D(arr, rows, cols));
    printf("Average: %.2lf\n", avg2D(arr, rows, cols));
    printf("Maximum: %.2lf\n", max(arr, rows, cols));
    printf("Minimum: %.2lf\n", min(arr, rows, cols));
    print2D(arr, rows, cols);
    free2D(arr, rows);
    return 0;
}
