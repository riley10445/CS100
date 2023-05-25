#include <stdio.h>
#include <stdlib.h>

int **allocateMatrix(int numRows, int numCols)
{
   int **matrix = (int **)malloc(sizeof(int *) *numRows);
   for(int i = 0; i < numRows; i++){
      matrix[i] = (int *)malloc(sizeof(int) * numCols);
   }
   return matrix;
}

void freeMatrix(int **matrix, int numRows, int numCols)
{
   for(int r = 0; r < numRows; r++){
      free(matrix[r]);
   }
   free(matrix);
}

void readMatrix(FILE *fp, int **matrix, int numRows, int numCols)
{
   for(int r=0; r< numRows; r++){
      for(int c=0; c< numCols; c++){
         fscanf(fp, "%d", &matrix[r][c]);
      }
   }
}

void printMatrix(int **matrix, int numRows, int numCols)
{
   for(int r = 0; r < numRows; r++){
      for(int c = 0; c < numCols; c++){
         printf("%d \t", matrix[r][c]);
      }
      printf("\n");
   }
}

int rangeRow(int **matrix, int numRows, int numCols, int r)
{
   int max = matrix[r][0];
   int min = matrix[r][0];
   for(int c = 0; c < numCols; c++){
      if(matrix[r][c] > max){
         max = matrix[r][c];
      }
      if(matrix[r][c] < min){
         min = matrix[r][c];
      }
   }
   return max - min;
}

void printCorners(int **matrix, int numRows, int numCols)
{
   int topLeft, topRight, bottomLeft, bottomRight;
   topLeft = matrix[0][0];
   topRight = matrix[0][numCols-1];
   bottomLeft = matrix[numRows-1][0];
   bottomRight = matrix[numRows-1][numCols-1];
   printf("%d %d %d %d, ", topLeft, topRight, bottomLeft, bottomRight);
}

int sumSubMatrix(int **matrix, int startRow, int endRow, int startCol, int endCol)
{
   int sum = 0;
   for(int r = startRow; r <= endRow; r++){
      for(int c = startCol; c <= endCol; c++){
         sum += matrix[r][c];
      }
   }
   return sum;
}
