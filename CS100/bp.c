#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _letter {
        char info;
        struct _letter *next;
} Letter;

Letter *buildList(char word[]);
void printList(Letter *head);

int main() {
	char word[100];
	printf("Enter a word: ");
	scanf("%s", word);

	Letter *head = buildList(word);

	printList(head);

	return 0;
}

// DO NOT MODIFY ABOVE THIS LINE

// Optionally implement the following helper function
/*
Letter *addFront(Letter *head, char ch) {
   
}
*/

// Print the linked list.
// For example, if the linked list represents CRIMSON,
// it prints C-->R-->I-->M-->S-->O-->N
void printList(Letter *head) {
    while (head != NULL) {
        printf("%c", head->info);
        if (head->next != NULL) {
            printf("-->");
        }
        head = head->next;
    }
    printf("\n");
}

// Build a linked list to represent the specified word.
// Return the head of the linked list built.
Letter *buildList(char str[]) {
    Letter *head = NULL;
    int len = strlen(str);

    for (int i = len - 1; i >= 0; i--) {
        Letter *newNode = malloc(sizeof(Letter));
        newNode->info = str[i];
        newNode->next = head;
        head = newNode;
    }

    return head;
}
