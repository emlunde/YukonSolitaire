/* Doubly Linked List implementation */
#include<stdio.h>
#include<stdlib.h>

typedef struct card Card;
typedef struct node Node;

struct card
{
    char suit;
    char rank;
    int visibility;
};

struct node  {
    Card card;
    struct Node* next;
    struct Node* prev;
};

void traverseListFromHead(Node *head){
    while(head->next!=NULL){
        printf("%c,%c,Is visible: %d",head->card.suit,head->card.rank,head->card.visibility);
        head = head->next;
    }
}
void traverseListFromTail(){}
void insertFromHead(){}
void inserFromTail(){}
void deleteNode(){}
void searchFromHead(){}
void searchFromTail(){}
void updateNode(){}
void sortListByIndex(){}