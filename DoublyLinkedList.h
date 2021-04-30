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

struct node* createNewNode(){
    Node *newDLL = (Node*) malloc(sizeof(Node));
    newDLL->next=NULL;
    newDLL->prev=NULL;
    return newDLL;
}
void traverseList(Node* head){
    // Print from head to tail
    while(head!=NULL){
        printf("%c%c - Vis:%d - *prev: %d - *next: %d \n",head->card.rank,head->card.suit,head->card.visibility,head->prev,head->next);
        head = head->next;
    }
    /* Print the tail
    if(head->next==NULL){
        printf("%c%c - Vis:%d - *next: %d - *prev: %d \n",head->card.suit,head->card.rank,head->card.visibility,head->next,head->prev);
    } */
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
// TODO : Implement this
struct node* searchForCard(Node* head, Card card){
    while(head != NULL) {
       // If the card is found in the list ptr to the node containing rank and suit is returned
        if (head->card.rank == card.rank & head->card.suit == card.suit) {
            return head;
        }
        head =  head->next;
    }   printf("Node not found in list - return 0\n");
        return 0;
}
struct node* deleteNode(Node* head, Node* node){
    struct node* staticHead = head;
    while(head != NULL) {
        // Checking if node is in the list
        if (head == node) {
            // If node==tail
            if(node->next==NULL){
                // Node's previous = new tail
                node->prev->next = NULL;
                free(node);
                return staticHead;
            }
            // If node==head
            if(node->prev==NULL){
                node->next->prev = NULL;
                head = node->next;
                free(node);
                return head;
            }

            // If node != tail || head
            if((node->next!=NULL&&node->prev!=NULL)){
                /* printf("Node found in list - deleting\n");
                Update pointers & delete node */
                node->prev->next = node->next;
                // Update note->next ptr to
                node->next->prev = node->prev;
                free(node);
                return staticHead;
            }
        }
        head = head->next;
    }
}

void updateNode(){}
void sortListByIndex(){}