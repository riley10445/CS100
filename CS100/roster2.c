#include <stdio.h>

int main()
{
    const int NUM_PLAYERS = 5;
    int jersey_numbers[NUM_PLAYERS];
    int player_ratings[NUM_PLAYERS];
    int i, j, option, jersey_number, rating;
    int on = 1;

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

    while (on)
    {
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
            scanf("%d", &jersey_number);
            for (i = 0; i < NUM_PLAYERS; i++)
            {
                if (jersey_number == jersey_numbers[i])
                {
                    printf("Enter a new rating for player %d:\n", i + 1);
                    scanf("%d", &rating);
                    while (rating < 1 || rating > 10)
                    {
                        printf("Invalid player rating. Enter a new rating for player %d:\n", i + 1);
                        scanf("%d", &rating);
                    }
                    player_ratings[i] = rating;
                    break;
                }
            }
            if (i == NUM_PLAYERS)
            {
                printf("Jersey number not found.\n");
            }
        }
        else if (option == 'r')
        {
            printf("Enter a jersey number:\n");
            scanf("%d", &jersey_number);
            for (i = 0; i < NUM_PLAYERS; i++)
            {
                if (jersey_number == jersey_numbers[i])
                {
                    printf("Found player. Enter new Jersey number: \n");
                    scanf("%d", &jersey_number);
                    jersey_numbers[i] = jersey_number;
                    printf("Enter player rating: \n");
                    scanf("%d", &rating);
                    player_ratings[i] = rating;
                    break;
                }
            }
            if (i == NUM_PLAYERS)
            {
                printf("Jersey number not found.\n");
            }
        }
        else if (option == 'o')
        {
            printf("ROSTER\n");
            for (i = 0; i < NUM_PLAYERS; i++)
            {
                printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, jersey_numbers[i], player_ratings[i]);
            }
        }
        else if (option == 'q')
        {
            on = 0;
        }
        else
        {
            printf("Invalid menu option.\n");
        }
    }
    return 0;
}