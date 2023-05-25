#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"

// open the file, create an ImagePPM, and return the pointer
// return NULL if the file cannot be opened

ImagePPM *readPPM(char *filename)
{
    ImagePPM *image;
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to read the PPM file: %s\n", filename);
        exit(1);
    }
    image = (ImagePPM *) malloc(sizeof(ImagePPM));
    fscanf(file, "%s", image->magic);
    fscanf(file, "%d%d%d", &image->numCols, &image->numRows, &image->maxVal);
    image->pixels = (Pixel **) malloc(image->numRows * sizeof(Pixel *));
    for (int i = 0; i < image->numRows; i++) {
        image->pixels[i] = (Pixel *) malloc(image->numCols * sizeof(Pixel));
        for (int j = 0; j < image->numCols; j++) {
            fscanf(file, "%d %d %d", &image->pixels[i][j].red, &image->pixels[i][j].green, &image->pixels[i][j].blue);
        }
    }
    fclose(file);
    return image;
}

// open the file and write the ImagePPM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePPM(ImagePPM *pImagePPM, char *filename)
{
    FILE *file;
    file = fopen(filename, "w");
    if(file == NULL) {
        printf("Unable to write to the file: %s\n", filename);
        exit(1);
    }
    fprintf(file, "%s\n%d %d\n%d\n ", pImagePPM->magic, pImagePPM->numCols, pImagePPM->numRows, pImagePPM->maxVal);
    for (int i = 0; i < pImagePPM->numRows; i++) {
        for (int j = 0; j < pImagePPM->numCols; j++) {
            fprintf(file, "%3d %3d %3d   ", pImagePPM->pixels[i][j].red, pImagePPM->pixels[i][j].green, pImagePPM->pixels[i][j].blue);
        }
        fprintf(file, "\n ");
    }
    fclose(file);
    return 1;
}

// free the ImagePPM and its pixels
// everything with a malloc needs a free

void freePPM(ImagePPM *pImagePPM)
{
    for (int i = 0; i < pImagePPM->numRows; i++) {
        free(pImagePPM->pixels[i]);
    }
    free(pImagePPM->pixels);
    free(pImagePPM);
}

// open the file, create an ImagePGM, and return the pointer
// return NULL if the file cannot be opened

ImagePGM *readPGM(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to read the PGM file: %s\n", filename);
        exit(1);
    }
    char magic_number[3];
    int width, height, max;
    fscanf(file, "%s", magic_number);
    fscanf(file, "%d%d%d", &width, &height, &max);
    ImagePGM *image = malloc(sizeof(ImagePGM));
    strcpy(image->magic, magic_number);
    image->numRows = height;
    image->numCols = width;
    image->maxVal = max;
    image->pixels = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        image->pixels[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            fscanf(file, "%d", &(image->pixels[i][j]));
        }
    }
    fclose(file);
    return image;
}

// open the file and write the ImagePGM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePGM(ImagePGM *pImagePGM, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Unable to write to the file: %s\n", filename);
        exit(1);
    }
    fprintf(file, "%s\n%d %d\n%d\n ", pImagePGM->magic, pImagePGM->numCols, pImagePGM->numRows, pImagePGM->maxVal);
    for (int i = 0; i < pImagePGM->numRows; i++) {
        for (int j = 0; j < pImagePGM->numCols; j++) {
            fprintf(file, "%3d ", pImagePGM->pixels[i][j]);
        }
        fprintf(file, "\n ");
    }
    fclose(file);
    return 1;
}

// free the ImagePGM and its pixels
// everything with a malloc needs a free

void freePGM(ImagePGM *pImagePGM) {
    for (int i = 0; i < pImagePGM->numRows; i++) {
        free(pImagePGM->pixels[i]);
    }
    free(pImagePGM->pixels);
    free(pImagePGM);
}

ImagePGM *convertToPGM(ImagePPM *pImagePPM)
{
    ImagePGM *pImagePGM = malloc(sizeof(ImagePGM));
    pImagePGM->magic[0] = 'P';
    pImagePGM->magic[1] = '2';
    pImagePGM->magic[2] = '\0';
    pImagePGM->numRows = pImagePPM->numRows;
    pImagePGM->numCols = pImagePPM->numCols;
    pImagePGM->maxVal = pImagePPM->maxVal;
    pImagePGM->pixels = malloc(pImagePGM->numRows * sizeof(int *));
    for (int i = 0; i < pImagePGM->numRows; i++) {
        pImagePGM->pixels[i] = malloc(pImagePGM->numCols * sizeof(int));
        for (int j = 0; j < pImagePGM->numCols; j++) {
            pImagePGM->pixels[i][j] = (pImagePPM->pixels[i][j].red + pImagePPM->pixels[i][j].green + pImagePPM->pixels[i][j].blue) / 3;
        }
    }
    return pImagePGM;
}

ImagePGM *shrinkPGM(ImagePGM *pImagePGM)
{
    int width = pImagePGM->numCols;
    int height = pImagePGM->numRows;
    int newWidth = width / 2;
    int newHeight = height / 2;
    ImagePGM *pNewImage = (ImagePGM*) malloc(sizeof(ImagePGM));
    pNewImage->magic[0] = 'P';
    pNewImage->magic[1] = '2';
    pNewImage->magic[2] = '\0';
    pNewImage->numCols = newWidth;
    pNewImage->numRows = newHeight;
    pNewImage->maxVal = pImagePGM->maxVal;
    pNewImage->pixels = (int**) malloc(newHeight * sizeof(int*));
    for (int i = 0; i < newHeight; i++) {
        pNewImage->pixels[i] = (int*) malloc(newWidth * sizeof(int));
    }
    int sum;
    for (int i = 0; i < newHeight; i++) {
        for (int j = 0; j < newWidth; j++) {
            sum = pImagePGM->pixels[2*i][2*j] + pImagePGM->pixels[2*i][2*j+1] +
                  pImagePGM->pixels[2*i+1][2*j] + pImagePGM->pixels[2*i+1][2*j+1];
            pNewImage->pixels[i][j] = sum / 4;
        }
    }
    return pNewImage;
}