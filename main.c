#include <stdio.h>
#include "DoublyLinkedList.h" //
enum suits  {A,C,D,S};

/*
Node* newDLL(){
    Node* head = malloc(sizeof (Node));
    head->prev=NULL;
    head->next=NULL;
    return head;
} */

void createTestDeck(){

    // A setup of for-loops creates the 13 cards from each of the 4 suits
    for(int x=A; A<=S; x++){
        for(int i=0; i<=13; i++){
            Card new;
            // For assigning the aces card in the respective suit
            if(i==0){
                new.suit = x;
                new.rank = "0";
                printf("Printing from aces assign: %c %c \n",new.suit,new.rank);
            }
                // For cards 1 through K in the specific suit
            switch(i) {
                case 1:
                    new.rank = "1";
                    printf("Printing from switch case: %d %c \n",i,new.rank);
                    break;

                case 2:
                    new.rank = "2";
                    printf("Printing from switch case: %d %c \n",i,new.rank);
                    break;

                case 3:
                    new.rank = "3";
                    printf("Printing from switch case: %d %c \n",i,new.rank);
                    break;

                case 4:
                    new.rank = "4";
                    printf("Printing from switch case: %d %c \n",i,new.rank);
                    break;

                case 5:
                    new.rank = "5";
                    printf("Printing from switch case: %d %c \n",i,new.rank);
                    break;

                case 6:
                    new.rank = "6";
                    printf("Printing from switch case: %d %c \n",i,new.rank);
                    break;

                case 7:
                    new.rank = "7";
                    printf("Printing from switch case: %d %c \n",i,new.rank);
                    break;

                case 8:
                    new.rank = "8";
                    printf("Printing from switch case: %d %c \n",i,new.rank);
                    break;

                case 9:
                    new.rank = "9";
                    printf("Printing from switch case: %d %c \n",i,new.rank);
                    break;

                case 10:
                    new.rank = "T";
                    printf("Printing from switch case: %d %c \n",i,new.rank);
                break;

                case 11:
                    new.rank = "J";
                    printf("Printing from switch case: %d %c \n",i,new.rank);
                    break;

                case 12:
                    new.rank = "Q";
                    printf("Printing from switch case: %d %c \n",i,new.rank);
                    break;

                case 13:
                    new.rank = "K";
                    printf("Printing from switch case: %d %c \n",i,new.rank);
                    break;
            }
        }
    }
}


int main() {
    createTestDeck();
    printf("Hello, World!\n");
    return 0;
}