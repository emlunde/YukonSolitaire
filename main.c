//#include "DoublyLinkedList.h" //https://gist.github.com/mycodeschool/7429492
#include "Commands.h"
#include "DoublyLinkedListTwo.h"
#include "Tests.h"


//todo implement function for hiding cards in piles
// void hideCards(Node ** head, int cardCntToHide)
// example hideCards(c3,2)   //should change the cards visibility in the first (from head) two node's cards visibility to 0. default visibility should be 1;
void hideCards(Node ** head, int cardCntToHide){
    for(int i = 0; i < cardCntToHide; i++){
        setCard(&getFromHead(*head, i)->card, getFromHead(*head, i)->card.rank, getFromHead(*head, i)->card.suit, 0);
    }
}

//todo implement function for revealing card in pile if remaining card is hidden after move of substack in pile
// void revealCard(Node ** card)
// example: revealCard(&getTail(c2)); //where c2 is the remaining cards after substack is moved from c2

//todo implement function moving substacks between piles
// should move the last (from tail) cards to another stack
// change the next and prev attribs for the nodes.
// example of use: moveSubStack(getNodeFromCardRankAndSuit(c1, 8, H), c2)       //should change the node holding card 8H to hold getTail(c2) as next,
//                                                                              // and set the node which previously had the 8H card node as next to now have next = NULL

//todo implement function for moving cards to suitStacks, with proper valid-move-checks
// allow the tail from the stacks to be moved to the suitstacks if the move is according to the yukon game rules.
// could maybe just use moveSubStack(getTail(c3), sH) to move 1 card from c3 to sH, suitstack hearts.
//                                     Could return 1 if valid move is done, and 0 if move was invalid, and not completed.

//todo implement function for shuffling deck
// should change the cards not the nodes

//todo implement function for creating deck (see createTestDeck function in Tests.h)
// already done in Tests.h, so not important, but can be moved out to main, as to show it is more than just a test function.


//_______________________________________________Game start_______________________________________________________________vvv

/// Function for splitting up the cardDeck to the 7 piles. Should match with the startposition.
/// \param headOfDeck: should be a full 52 set deck of cards. Can be shuffled or unshuffled.
/// The piles c1 through c7 are global static variables, that gets updated with the cards.
void distributeForStart(Node * headOfDeck, Node ** c1, Node ** c2, Node ** c3 , Node ** c4 , Node ** c5 , Node ** c6 , Node ** c7) {

    //c1
    *c1 = getTail(headOfDeck);
    getTail(headOfDeck)->prev->next = NULL;
    Node * tmp = *c1;
    tmp->prev = NULL;

    //c2
    *c2 = getFromTail(headOfDeck,6-1);
    getFromTail(headOfDeck,6-1)->prev->next = NULL;
    tmp = *c2;
    tmp->prev = NULL;

    //c3
    *c3 = getFromTail(headOfDeck,7-1);
    getFromTail(headOfDeck,7-1)->prev->next = NULL;
    tmp = *c3;
    tmp->prev = NULL;

    //c4
    *c4 = getFromTail(headOfDeck,8-1);
    getFromTail(headOfDeck,8-1)->prev->next = NULL;
    tmp = *c4;
    tmp->prev = NULL;

    //c5
    *c5 = getFromTail(headOfDeck,9-1);
    getFromTail(headOfDeck,9-1)->prev->next = NULL;
    tmp = *c5;
    tmp->prev = NULL;

    //c6
    *c6 = getFromTail(headOfDeck,10-1);
    getFromTail(headOfDeck,10-1)->prev->next = NULL;
    tmp = *c6;
    tmp->prev = NULL;

    //c7
    *c7 = getFromTail(headOfDeck,11-1);
    tmp = *c7;
    tmp->prev = NULL;
}

void setupGame(Node ** c2, Node ** c3, Node ** c4, Node ** c5, Node ** c6, Node ** c7){

    hideCards(c2,1);
    hideCards(c3,2);
    hideCards(c4,3);
    hideCards(c5,4);
    hideCards(c6,5);
    hideCards(c7,3);

}

//_______________________________________________Game start_______________________________________________________________^^^


//___________________________________________________UI___________________________________________________________________vvv

void printCurrentBoard(Node * c1, Node * c2, Node * c3, Node * c4, Node * c5, Node * c6, Node * c7, Node * sC, Node * sD, Node * sH, Node * sS){

    printf("\tC1\tC2\tC3\tC4\tC5\tC6\tC7\n\n");

    //get needed height for board to be printed
    int boardHeight = countElements(c1);

    if(countElements(c2) > boardHeight) {
        boardHeight = countElements(c2);
    }
    if(countElements(c3) > boardHeight) {
        boardHeight = countElements(c3);
    }
    if(countElements(c4) > boardHeight) {
        boardHeight = countElements(c4);
    }
    if(countElements(c5) > boardHeight) {
        boardHeight = countElements(c5);
    }
    if(countElements(c6) > boardHeight) {
        boardHeight = countElements(c6);
    }
    if(countElements(c7) > boardHeight) {
        boardHeight = countElements(c7);
    }


    //print for each row
    for (int i = 0; i < boardHeight; i++) {
        printf("\t");

        char chString[2];

        //c1
        if (countElements(c1) >= i + 1) {
            if (getFromHead(c1,i)->card.visibility == 1) {          //checks if card is visible (1 is visible, 0 is hidden)
                chString[0] = getFromHead(c1, i)->card.rank;
                chString[1] = getFromHead(c1, i)->card.suit;
            } else {                                                //if card is hidden should show '[]' in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("%c%c", chString[0],chString[1]);
        } else {
            printf("  ");
        }
        chString[0] = '\0';
        chString[1] = '\0';
        printf("\t");

        //c2
        if (countElements(c2) >= i + 1) {
            if (getFromHead(c2,i)->card.visibility == 1) {          //checks if card is visible (1 is visible, 0 is hidden)
                chString[0] = getFromHead(c2, i)->card.rank;
                chString[1] = getFromHead(c2, i)->card.suit;
            } else {                                                //if card is hidden should show '[]' in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("%c%c", chString[0],chString[1]);
        } else {
            printf("  ");
        }
        printf("\t");

        //c3
        if (countElements(c3) >= i + 1) {
            if (getFromHead(c3,i)->card.visibility == 1) {          //checks if card is visible (1 is visible, 0 is hidden)
                chString[0] = getFromHead(c3, i)->card.rank;
                chString[1] = getFromHead(c3, i)->card.suit;
            } else {                                                //if card is hidden should show '[]' in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("%c%c", chString[0],chString[1]);
        } else {
            printf("  ");
        }
        printf("\t");

        //c4
        if (countElements(c4) >= i + 1) {
            if (getFromHead(c4,i)->card.visibility == 1) {          //checks if card is visible (1 is visible, 0 is hidden)
                chString[0] = getFromHead(c4, i)->card.rank;
                chString[1] = getFromHead(c4, i)->card.suit;
            } else {                                                //if card is hidden should show '[]' in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("%c%c", chString[0],chString[1]);
        } else {
            printf("  ");
        }
        printf("\t");

        //c5
        if (countElements(c5) >= i + 1) {
            if (getFromHead(c5,i)->card.visibility == 1) {          //checks if card is visible (1 is visible, 0 is hidden)
                chString[0] = getFromHead(c5, i)->card.rank;
                chString[1] = getFromHead(c5, i)->card.suit;
            } else {                                                //if card is hidden should show '[]' in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("%c%c", chString[0],chString[1]);
        } else {
            printf("  ");
        }
        printf("\t");

        //c6
        if (countElements(c6) >= i + 1) {
            if (getFromHead(c6,i)->card.visibility == 1) {          //checks if card is visible (1 is visible, 0 is hidden)
                chString[0] = getFromHead(c6, i)->card.rank;
                chString[1] = getFromHead(c6, i)->card.suit;
            } else {                                                //if card is hidden should show '[]' in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("%c%c", chString[0],chString[1]);
        } else {
            printf("  ");
        }
        printf("\t");

        //c7
        if (countElements(c7) >= i + 1) {
            if (getFromHead(c7,i)->card.visibility == 1) {          //checks if card is visible (1 is visible, 0 is hidden)
                chString[0] = getFromHead(c7, i)->card.rank;
                chString[1] = getFromHead(c7, i)->card.suit;
            } else {                                                //if card is hidden should show '[]' in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("%c%c", chString[0],chString[1]);
        } else {
            printf("  ");
        }

        //suitStacks
        if (i == 0) {
            if (countElements(sC) > 0) {
                chString[0] = getTail(sC)->card.rank;
                chString[1] = getTail(sC)->card.suit;
            } else {                                                //if no cards in suitStack '[]' is shown in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("\t\t%c%c\tF1", chString[0],chString[1]);
        } else if (i == 2) {
            if (countElements(sD) > 0) {
                chString[0] = getTail(sD)->card.rank;
                chString[1] = getTail(sD)->card.suit;
            } else {                                                //if no cards in suitStack '[]' is shown in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("\t\t%c%c\tF2", chString[0],chString[1]);
        } else if (i == 4) {
            if (countElements(sH) > 0) {
                chString[0] = getTail(sH)->card.rank;
                chString[1] = getTail(sH)->card.suit;
            } else {                                                //if no cards in suitStack '[]' is shown in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("\t\t%c%c\tF3", chString[0],chString[1]);
        } else if (i == 6) {
            if (countElements(sS) > 0) {
                chString[0] = getTail(sS)->card.rank;
                chString[1] = getTail(sS)->card.suit;
            } else {                                                //if no cards in suitStack '[]' is shown in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("\t\t%c%c\tF4", chString[0],chString[1]);
        }
        printf("\n");
    }


    printf("LAST command: \n");
    printf("Message: \n");
    printf("INPUT > \n");

}


//___________________________________________________UI___________________________________________________________________^^^

int main() {

//    printCurrentBoard();
//
//    distributeDeckForStartPosition(createTestDeck());



//    while(1) {
//        printf("Please input command or move: ");
//        char inputStr[100];
//        gets(inputStr);
//    //    char testStr[100] = "LD filenameTest3";
//        //TODO: delete ... this was for testing Commands.h's functions
//        char * result = cmdSelector(inputStr);
//        printf("\nresult: %s\n",result);
//
//        if(strcmp(inputStr, "QQ") && strcmp(result,"OK")) {
//            break;
//        }
//    }
//    testSearchAndDelete();

//    Node* n = createNewNode();
//    printDeck(n);


//    Card tempCard;
//    setCard(&tempCard,'\0','\0',-1);
//
//    Node *n = createNewNode();
//    n->card = tempCard;
//
//    if (n->card.rank == NULL && n->next == NULL) {
//        printf("testetsetestst");
//    }


//    Node * head = createTestDeck();
//    head = deleteNode(head,head);
//    printDeck(head);

    //Stacks for the 7 game piles
    static Node * c1;
    static Node * c2;
    static Node * c3;
    static Node * c4;
    static Node * c5;
    static Node * c6;
    static Node * c7;



    //Stacks for the 4 suit piles
    static Node * sC;
    static Node * sD;
    static Node * sH;
    static Node * sS;


    Node * testHead = createTestDeck();
    printDeck(testHead);

    printf("\nfrom tail: ");
    printNode(getFromTail(testHead,2-1));

    printf("from head: ");
    printNode(getFromHead(testHead, 1));

//    printf("\n\n");

    distributeForStart(testHead, &c1, &c2, &c3,&c4,&c5,&c6,&c7);

    setupGame(&c2,&c3,&c4,&c5,&c6,&c7);

//    printDeck(c2);

//    sS = createTestDeck();      //test if suitStacks show revealed cards properly
//    getTail(sS)->prev->next = NULL;
//    printDeck(sS);

    printCurrentBoard(c1, c2, c3, c4, c5, c6, c7, sC, sD, sH, sS);


    printf("\n\n");
    printf("count: %d",countElements(testHead));

    /*printf("\nVisibility 1st card before: %i\n", getFromHead(c3,0)->card.visibility );
    printf("Visibility 2nd card before: %i\n", getFromHead(c3,0)->next->card.visibility );
    hideCards(c3, 2);
    printf("Visibility 1st card after: %i\n", getFromHead(c3,0)->card.visibility);
    printf("Visibility 2nd card after: %i\n", getFromHead(c3,0)->next->card.visibility);*/
    return 0;
}



