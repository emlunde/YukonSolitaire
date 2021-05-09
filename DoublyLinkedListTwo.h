/* Doubly Linked List implementation by @KasperBaun */
#include<stdio.h>
#include<stdlib.h>

typedef struct card Card;
typedef struct node Node;

struct card
{
    char suit;          //C,D,H,S
    char rank;          //A,2,3,4,5,6,7,8,9,T,J,Q,K
    int visibility;     //0 means notVisible. 1 means visible.
};

void setCard(Card* c, char rank, char suit, int visibility) {
    c->suit = suit;
    c->rank = rank;
    c->visibility = visibility;
}

struct node  {
    Card card;
    Node* next;
    Node* prev;
    int index;
};
struct node* createNewNode(){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->next=NULL;
    newNode->prev=NULL;
    newNode->index=0;
    return newNode;
}
void traverseList(Node* head){
    // Print from head to tail
    while(head!=NULL){
        printf("%c%c - Vis:%d - *prev: %8d - *next: %8d - index: %d \n",head->card.rank,head->card.suit,head->card.visibility,head->prev,head->next,head->index);
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
        new->index = head->index+1;
    }
}

//todo: create function for getNodeAndAllFollowingNodes()
struct node* getNodeAndAllFollowingNodes(){
}

// Gets a pointer to the node in index = int index - is tested with testGetFromIndex()
struct node* getFromIndex(Node* head, int index){
    while (head!=NULL){
        head=head->next;
        if(head->index==index){
            return head;
        }
    } return printf("No such node with index: %d",index);
}

// Gets the tail - is tested with testGetTail() in Tests.h
struct node* getTail(Node* head){
    Node* tail;
    while (head!=NULL){
        tail = head;
        head = head->next;
    } return tail;
}
//Inserts the nodeToInsert at the tail of the list given by *head - is tested with testInsertLinkedListAtEnd()
void insertLinkedListAtEnd(Node* head, Node* nodeToInsert){
    Node* tail=getTail(head);
    tail->next = nodeToInsert;
    nodeToInsert->prev = tail;
}
struct node* getNodeFromCard(Node* head, Card card){
    while(head != NULL) {
        // If the card is found in the list ptr to the node containing rank and suit is returned
        if (head->card.rank == card.rank & head->card.suit == card.suit) {
            return head;
        }
        head =  head->next;
    }   printf("Node not found in list - return 0\n");
    return 0;
}
struct node* getNodeFromCardRankAndSuit(Node* head, char rank, char suit){
    while(head != NULL) {
        // If the card is found in the list ptr to the node containing rank and suit is returned
        if (head->card.rank == rank & head->card.suit == suit) {
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
int countElements(Node* head){
    int count;
    while(head!=NULL){
    count++;
    head=head->next;
    }
    return count;
}
// TODO : Implement this
void updateNode(){}

//Node * node = createNewNode();
//setCard(&node->card,'7','D',1);
//insertNew(head, node);


void quickInsertCard(Node* listHead, char rank, char suit) {
    Node * node = createNewNode();
    setCard(&node->card,rank,suit,0);
    insertNew(listHead, node);
}
void printNode(Node* node){
    printf("%c%c - Vis:%d - *prev: %8d - *next: %8d - index: \n",node->card.rank,node->card.suit,node->card.visibility,node->prev,node->next,node->index);
}

Node * getFromTail(Node * head, int cnt) {
    Node * tmp = getTail(head);
    for (int i = 0; i < cnt-1; ++i) {
        tmp = tmp->prev;
    }
    return tmp;
}