#include <stdio.h>
#include "DoublyLinkedList.h" //
enum suits  {A,S,D,C};


Node* newDLL(){
    Node* head = malloc(sizeof (Node));
    head->prev=NULL;
    head->next=NULL;
    return head;
}

Node* createTestDeck(){
    Node* head = newDLL();

    // A setup of for-loops creates the 13 cards from each of the 4 suits
    for(int x=A; x<=C; x++){
        for(int i=0; i<13; i++){
            // Aces assigned and added first
            Card new;
            new.suit = conve;
            new.rank = 0;
            insertFromHead(new);
            head = head->next;

                // For cards 1 through 9 in the specific suit
                for(i>0;i<10;i++){
                    new.rank = i;
                    insertFromHead(new);
                    head = head->next;
                }
                // For cards T through K in the specific suit
                for(int i=10;i<14; i++){
                    switch (i) {
                        case 10:
                            new.rank = "T";
                            insertFromHead(new);
                            head = head->next;
                        case 11:
                            new.rank = "J";
                            insertFromHead(new);
                            head = head->next;
                        case 12:
                            new.rank = "Q";
                            insertFromHead(new);
                            head = head->next;
                        case 13:
                            new.rank = "K";
                            insertFromHead(new);
                            head = head->next;

                    }
                }
        }
    }
    return head;
}


int main() {
    createTestDeck();
    printf("Hello, World!\n");
    return 0;
}