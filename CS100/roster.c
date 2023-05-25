#include <stdio.h>
#define NUM_PLAYERS 5

void jerseyPrompt();
void printRoster(int jerseyNums[], int ratingNums[]);
void menu();
void update();
void replace();
void output();
void quit();

int main()
{
    jerseyPrompt();
}

void jerseyPrompt()
{
    int jersey_numbers[NUM_PLAYERS];
    int player_ratings[NUM_PLAYERS];
    int i, j, option, jersey_number, rating;
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

void menu(int jerseyNums[], int ratingNums[], int *on)
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
        printf("Enter jersey number for rating update:\n");
        update(jerseyNums, ratingNums);
    }
    else if (option == 'r')
    {
        printf("Enter jersey number to replace:\n");
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
    scanf("%d", &jersey_number);
    for (i = 0; i < NUM_PLAYERS; i++)
    {
        if (jersey_number == jerseyNums[i])
        {
            printf("Found jersey number. Enter new rating for player:\n");
            scanf("%d", &rating);
            while (rating < 1 || rating > 10)
            {
                printf("Invalid player rating. Enter valid rating:\n");
                scanf("%d", &rating);
            }
            ratingNums[i] = rating;
            break;
        }
    }
    if (i == NUM_PLAYERS)
    {
        printf("Invalid jersey number. Enter valid jersey number:\n");
        update(jerseyNums, ratingNums);
    }
}

void replace(int jerseyNums[], int ratingNums[])
{
    int i, jersey_number, rating, new_jersey_number;
    scanf("%d", &jersey_number);
    for (i = 0; i < NUM_PLAYERS; i++)
    {
        if (jersey_number == jerseyNums[i])
        {
            printf("Found player. Enter new Jersey number: \n");
            scanf("%d", &new_jersey_number);
            for (int j = 0; j < NUM_PLAYERS; j++)
            {
                while (new_jersey_number == jerseyNums[j] || new_jersey_number >= 100 || new_jersey_number <= 0)
                {
                    printf("Invalid jersey number. Enter valid jersey number:\n");
                    scanf("%d", &new_jersey_number);
                }
            }
            jerseyNums[i] = new_jersey_number;
            printf("Enter player rating: \n");
            scanf("%d", &rating);
            while (rating < 1 || rating > 10)
            {
                printf("Invalid player rating. Enter valid rating: \n");
                scanf("%d", &rating);
            }
            ratingNums[i] = rating;
            break;
        }
    }
    if (i == NUM_PLAYERS)
    {
        printf("Invalid jersey number. Enter valid jersey number:\n");
        replace(jerseyNums, ratingNums);
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

void quit(int *on)
{
    if (on != NULL)
    {
        *on = 0;
    }
}