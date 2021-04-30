//
// Created by @KasperBaun on 30-04-2021.
//

#ifndef MASKPROG_P2_TESTS_H
#define MASKPROG_P2_TESTS_H

#endif //MASKPROG_P2_TESTS_H
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
            } else if(index>=1&&i==0){
                temp_card.rank = 'A';
                temp = createNewNode();
                temp->card = temp_card;
                insertNew(head,temp);
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
                        break;

                    case 3:
                        temp_card.rank = '3';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 4:
                        temp_card.rank = '4';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 5:
                        temp_card.rank = '5';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 6:
                        temp_card.rank = '6';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 7:
                        temp_card.rank = '7';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 8:
                        temp_card.rank = '8';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 9:
                        temp_card.rank = '9';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 10:
                        temp_card.rank = 'T';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 11:
                        temp_card.rank = 'J';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 12:
                        temp_card.rank = 'Q';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 13:
                        temp_card.rank = 'K';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    default:
                        printf("Switch case ran default option - something went wrong \n");
                }
            }
        }
    } return head;
}
void printDeck(Node* head){
    printf("\t");
    while(head!=NULL){
        printf("%c%c\t",head->card.rank,head->card.suit);
        head=head->next;
    }
}
void testDeck(){
    Node* head;
    head = createTestDeck();
    printf("------------------ createTestDeck() complete ------------------\n");
    printf("### Traversing linked list ### \n");
    traverseList(head);
}
void testSearchAndDelete(){
    Node* head;
    Node* deleteTest;
    Card card,card2,card3;
    card.rank = 'A';
    card.suit = 'A';
    head = createTestDeck();
    deleteTest = searchForCard(head,card);
    printf("------------- Test # 1: createTestDeck() and search for card AA -------------\n");
    printf("AA's ptr*: %d\n",deleteTest);
    traverseList(head);
    printf("------------- Test #1 concluded - AA's ptr* should be in the traversal list -------------\n");

    printf("------------- Test # 2: delete card AA -------------\n");
    head = deleteNode(head,deleteTest);
    traverseList(head);
    printf("------------- Test # 2: card AA should no longer be in set -------------\n");
}