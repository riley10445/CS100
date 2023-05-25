# include <stdio.h>
# include <stdlib.h>

typedef struct _letter{
    char *ch;
    struct _letter *next;
}Letter;

int main(){
    Letter *head = NULL;
    ptr = (Letter *)malloc(sizeof(Letter));
    one.ch = 'T';
    prt->next = head;
    head = ptr;

    ptr = (Letter *)malloc(sizeof(Letter));
    one.ch = 'I';
    prt->next = head;
    head = ptr;

    ptr = (Letter *)malloc(sizeof(Letter));
    one.ch = 'D';
    prt->next = head;
    head = ptr;

    ptr = (Letter *)malloc(sizeof(Letter));
    one.ch = 'E';
    prt->next = head;
    head = ptr;

    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = NULL;

    Letter *header = &one;

    while(header != NULL){
        printf("%c", header->ch);
        header = header->next;
        }
    printf("\n");  

    four.next = &three;
    three.next = &two;
    two.next = &one;
    one.next = NULL;

    header = &four;

    while(header != NULL){
        printf("%c", header->ch);
        header = header->next;
        }
    printf("\n");




    return 0;
}