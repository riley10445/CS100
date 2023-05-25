#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int num;
    struct _node *next;
} Node;

Node *buildList(char filename[]);
void printList(char prefix[], Node *head);
Node *merge(Node *head1,  Node *head2);

int main(int argc, char *argv[]) {
	if (argc!=3) {
		printf("Usage: %s file1 file2\n", argv[0]);
		return 1;
	}
    Node *head1=buildList(argv[1]);
    printList("List1: ", head1);
    Node *head2=buildList(argv[2]);
    printList("List2: ", head2);
    Node *head3=merge(head1, head2);
    printList("Merged list: ", head3);
    return 0;
}

// Build a linked list of integers read from a file
Node *buildList(char filename[]) {
    Node *head=NULL, *tail;
	FILE *fp=fopen(filename, "r");
	if (fp==NULL) return NULL;
    while (1) {
        int n;
        fscanf(fp, "%d", &n);
        if (feof(fp)) break;
        Node *newNode=malloc(sizeof(Node));
        newNode->num=n;
        newNode->next=NULL;
		if (head==NULL)
			head=newNode;
		else
			tail->next=newNode;
		tail=newNode;
    }
	fclose(fp);
    return head;
}

// Print the linked list.
void printList(char prefix[], Node *head)
{
	printf("%s", prefix);
    for (Node *cur = head; cur != NULL; cur = cur->next)
        if (cur==head)
            printf("%d", cur->num);
       	else
            printf("-->%d", cur->num);
    printf("\n");
}

// DO NOT CHANGE ANYTHING ABOVE THIS LINE

/*
Merge two lists into one by:
- Appending the shorter list to the longer one.
- If both lists have the same length, put the second list after the first one.
- If one list is empty, return the other list.

You can either relink the existing lists or make new nodes.
*/

// You can write helper functions here if you wish

Node *merge(Node *head1, Node *head2)
{
        // Handle the case where one of the lists is empty
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    // Find the length of both lists
    int len1 = 0, len2 = 0;
    Node *cur = head1;
    while (cur != NULL) {
        len1++;
        cur = cur->next;
    }
    cur = head2;
    while (cur != NULL) {
        len2++;
        cur = cur->next;
    }

    // Append the shorter list to the longer one
    Node *longer, *shorter;
    int diff;
    if (len1 >= len2) {
        longer = head1;
        shorter = head2;
        diff = len1 - len2;
    } else {
        longer = head2;
        shorter = head1;
        diff = len2 - len1;
    }

    cur = longer;
    while (diff > 0) {
        cur = cur->next;
        diff--;
    }

    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = shorter;
    return longer;
}