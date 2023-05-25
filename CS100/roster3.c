#include <stdio.h>
#define NUM_PLAYERS 5

void jerseyPrompt(int i);
void printRoster(int jerseyNums[], int ratingNums[]);
char menu();
void update();
void replace();
void output();
void quit();

int main()
{
    int i, j;
    for (i = 0; i < NUM_PLAYERS; i++)
    {
        jerseyPrompt(i);
    }
}

void jerseyPrompt(int i)
{
    int jersey_numbers[NUM_PLAYERS];
    int player_ratings[NUM_PLAYERS];
    int j, option, jersey_number, rating;
    for (i = 0; i < NUM_PLAYERS; i++)
    {
        printf("Enter player %d's jersey number:\n", i + 1);
        scanf("%d", &jersey_number);
        while (jersey_number < 0 || jersey_number > 99)
        {
            printf("Invalid jersey number. Enter player %d's jersey number:\n", i + 1);
            scanf("%d", &jersey_number);
        }
        for (j = 0; j < i; j++)
        {
            if (jersey_number == jersey_numbers[j])
            {
                printf("Jersey number already exists. Enter player %d's jersey number:\n", i + 1);
                scanf("%d", &jersey_number);
                j = -1;
            }
        }
        jersey_numbers[i] = jersey_number;

        printf("Enter player %d's rating:\n", i + 1);
        scanf("%d", &rating);
        while (rating < 1 || rating > 10)
        {
            printf("Invalid player rating. Enter player %d's rating:\n", i + 1);
            scanf("%d", &rating);
        }
        player_ratings[i] = rating;
    }
    printf("\nROSTER\n");
    for (i = 0; i < NUM_PLAYERS; i++)
    {
        printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, jersey_numbers[i], player_ratings[i]);
    }
    int on = 1;
    while (on)
    {
        menu(jersey_numbers, player_ratings, &on);
    }
}

char menu(int jerseyNums[], int ratingNums[], int on)
{
    char option;
    printf("\nMENU\n");
    printf("u - Update player rating\n");
    printf("r - Replace player\n");
    printf("o - Output roster\n");
    printf("q - Quit\n");
    printf("Choose an option:\n");
    scanf(" %c", &option);
    if (option == 'u')
    {
        update(jerseyNums, ratingNums);
    }
    else if (option == 'r')
    {
        replace(jerseyNums, ratingNums);
    }
    else if (option == 'o')
    {
        output(jerseyNums, ratingNums);
    }
    else if (option == 'q')
    {
        quit(on);
    }
    else
    {
        printf("Invalid menu option.\n");
    }
}

void update(int jerseyNums[], int ratingNums[])
{
    int i, rating, jersey_number;
    printf("Enter jersey number for rating update:\n");
    scanf("%d", &jersey_number);
    for (i = 0; i < NUM_PLAYERS; i++)
    {
        if (jersey_number == jerseyNums[i])
        {
            printf("Enter a new rating for player %d:\n", i + 1);
            scanf("%d", &rating);
            while (rating < 1 || rating > 10)
            {
                printf("Invalid player rating. Enter a new rating for player %d:\n", i + 1);
                scanf("%d", &rating);
            }
            ratingNums[i] = rating;
            break;
        }
    }
    if (i == NUM_PLAYERS)
    {
        printf("Jersey number not found.\n");
    }
}

void replace(int jerseyNums[], int ratingNums[])
{
    int i, jersey_number, rating;
    printf("Enter a jersey number:\n");
    scanf("%d", &jersey_number);
    for (i = 0; i < NUM_PLAYERS; i++)
    {
        if (jersey_number == jerseyNums[i])
        {
            printf("Found player. Enter new Jersey number: \n");
            scanf("%d", &jersey_number);
            jerseyNums[i] = jersey_number;
            printf("Enter player rating: \n");
            scanf("%d", &rating);
            ratingNums[i] = rating;
            break;
        }
    }
    if (i == NUM_PLAYERS)
    {
        printf("Jersey number not found.\n");
    }
}

void output(int jerseyNums[], int ratingNums[])
{
    int i;
    printf("ROSTER\n");
    for (i = 0; i < NUM_PLAYERS; i++)
    {
        printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, jerseyNums[i], ratingNums[i]);
    }
}

void quit(int on)
{
    on = 0;
}