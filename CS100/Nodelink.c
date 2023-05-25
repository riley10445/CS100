# include <stdio.h>
# include <stdlib.h>

typedef struct _node{
    char ch;
    struct _node *next;
}Node;

Node createNode(char data, Node *next){
    Node *ptr = malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = next;
    return ptr;
}

void printNode(Node *head){
    Node *ptr = head;
    while(ptr != NULL){
        printf("%c", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    
    Node *head = NULL;
    head = createNode('T', head);
    head = createNode('I', head);
    head = createNode('D', head);
    head = createNode('E', head);
    printNode(head);

    return 0;
}