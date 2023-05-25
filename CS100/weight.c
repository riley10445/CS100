#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 1000

int weight(char *word)
{
    int weight = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            weight += (int)word[i];
        }
    }
    return weight;
}

int main(int argc, char *argv[])
{

    char *filename = argv[1];
    int count = atoi(argv[2]);
    int value = atoi(argv[3]);

    FILE *fp = fopen(filename, "r");

    // Calculate the mean weight of all the words in the file
    int total_weight = 0;
    int num_words = 0;
    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word) == 1)
    {
        total_weight += weight(word);
        num_words++;
    }
    fclose(fp);
    float mean_weight = (float)total_weight / num_words;

    // Print out all words within value from the mean
    fp = fopen(filename, "r");
    while (fscanf(fp, "%s", word) == 1)
    {
        int word_weight = weight(word);
        if (abs(word_weight - mean_weight) <= value)
        {
            printf("%s\n", word);
        }
    }
    fclose(fp);

    return 0;
}
