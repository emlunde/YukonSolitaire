/* Doubly Linked List implementation by @KasperBaun */
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
     Node* next;
     Node* prev;
};
// TODO : Implement this
struct node* createNewNode(){
    Node *newDLL = (Node*) malloc(sizeof(Node));
    newDLL->next=NULL;
    newDLL->prev=NULL;
    return newDLL;
}
void traverseList(Node* head){
    // Print from head to tail
    while(head->next!=NULL){
        printf("%c%c,Is visible: %d \n",head->card.suit,head->card.rank,head->card.visibility);
        head = head->next;
    }
    // Print the tail
    if(head->next==NULL){
        printf("%c%c,Is visible: %d \n",head->card.suit,head->card.rank,head->card.visibility);
    }
}
void insertNew(Node* head, Node* new){
    // Find tail
    while(head->next!=NULL){
        head = head->next;
    }
    // Insert new node at tail
    if(head->next==NULL){

        head->next = new;
        new->prev = head;
        new->next = NULL;
    }
}

void deleteNode(){}
void searchFromHead(){}
void searchFromTail(){}
void updateNode(){}
void sortListByIndex(){}