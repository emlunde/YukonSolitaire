#include <stdio.h>
#include "DoublyLinkedList.h" //

struct node* createTestDeck(){
    Node* head = createNewNode();
    Card temp_card;
    Node* temp;
    temp_card.visibility=0;
    // A setup of for-loops creates the 13 cards from each of the 4 suits
    for(int index=1; index<=4; index++){
        if(index==1) temp_card.suit = 'A';
        if(index==2) temp_card.suit = 'C';
        if(index==3) temp_card.suit = 'D';
        if(index==4) temp_card.suit = 'S';

        for(int i=0; i<=13; i++){

            // For assigning the aces card in the respective suit
            if(i==0 && index==1){
                temp_card.rank ='A';
                head->card = temp_card;
                printf("\n %c%c \t", head->card.suit, head->card.rank);
            } else if(index>=1&&i==0){
                temp_card.rank = 'A';
                temp = createNewNode();
                temp->card = temp_card;
                insertNew(head,temp);
                printf(" %c%c \t",temp->card.rank,temp->card.suit);
            }
                // For cards 1 through K in the specific suit
            if(i>0){
                switch(i) {
                case 1:
                    break;

                case 2:
                    temp_card.rank = '2';
                    temp = createNewNode();
                    temp->card = temp_card;
                    insertNew(head,temp);
                    printf(" %c%c \t",temp->card.rank,temp->card.suit);
                    break;

                case 3:
                    temp_card.rank = '3';
                    temp = createNewNode();
                    temp->card = temp_card;
                    insertNew(head,temp);
                    printf(" %c%c \t",temp->card.rank,temp->card.suit);
                    break;

                case 4:
                    temp_card.rank = '4';
                    temp = createNewNode();
                    temp->card = temp_card;
                    insertNew(head,temp);
                    printf(" %c%c \t",temp->card.rank,temp->card.suit);
                    break;

                case 5:
                    temp_card.rank = '5';
                    temp = createNewNode();
                    temp->card = temp_card;
                    insertNew(head,temp);
                    printf(" %c%c \t",temp->card.rank,temp->card.suit);
                    break;

                case 6:
                    temp_card.rank = '6';
                    temp = createNewNode();
                    temp->card = temp_card;
                    insertNew(head,temp);
                    printf(" %c%c \t",temp->card.rank,temp->card.suit);
                    break;

                case 7:
                    temp_card.rank = '7';
                    temp = createNewNode();
                    temp->card = temp_card;
                    insertNew(head,temp);
                    printf(" %c%c \t",temp->card.rank,temp->card.suit);
                    break;

                case 8:
                    temp_card.rank = '8';
                    temp = createNewNode();
                    temp->card = temp_card;
                    insertNew(head,temp);
                    printf(" %c%c \t",temp->card.rank,temp->card.suit);
                    break;

                case 9:
                    temp_card.rank = '9';
                    temp = createNewNode();
                    temp->card = temp_card;
                    insertNew(head,temp);
                    printf(" %c%c \t",temp->card.rank,temp->card.suit);
                    break;

                case 10:
                    temp_card.rank = 'T';
                    temp = createNewNode();
                    temp->card = temp_card;
                    insertNew(head,temp);
                    printf(" %c%c \t",temp->card.rank,temp->card.suit);
                break;

                case 11:
                    temp_card.rank = 'J';
                    temp = createNewNode();
                    temp->card = temp_card;
                    insertNew(head,temp);
                    printf(" %c%c \t",temp->card.rank,temp->card.suit);
                    break;

                case 12:
                    temp_card.rank = 'Q';
                    temp = createNewNode();
                    temp->card = temp_card;
                    insertNew(head,temp);
                    printf(" %c%c \t",temp->card.rank,temp->card.suit);
                    break;

                case 13:
                    temp_card.rank = 'K';
                    temp = createNewNode();
                    temp->card = temp_card;
                    insertNew(head,temp);
                    printf(" %c%c \t\n",temp->card.rank,temp->card.suit);
                    break;

                default:
                    printf("Switch case ran default option - something went wrong \n");
                }
            }
        }
    } return head;
}
void testDeck(){
    Node* head;
    head = createTestDeck();
    printf("------------------ createTestDeck() complete ------------------\n");
    printf("### Traversing linked list ### \n \t");
    traverseList(head);
}

int main() {
    testDeck();
    return 0;
}