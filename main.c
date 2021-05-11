#include "Commands.h"
#include "DoublyLinkedListTwo.h"
#include "Tests.h"
#include <stdlib.h>



/// \param head             : The first card in the pile which is to get it's cards hidden.
/// \param cardCntToHide    : The number of cards to be hidden, counting from head
void hideCards(Node ** head, int cardCntToHide);
/// Creates a fresh 52-card new deck in ascending order (non-shuffled)
struct node* createNewDeck();
/// Creates a new shuffled deck and frees the original deck
Node* shuffleDeck(Node* head);

Node ** pickStacks(char stackCh1,char stackCh2,Node ** c1,Node ** c2,Node ** c3,Node ** c4,Node ** c5,Node ** c6,Node ** c7,Node ** sC,Node ** sD,Node ** sH,Node ** sS);
void printCurrentBoard();

void run();
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

/// For setting up the hidden cards to match with the games start position.
/// The dereference of the pointer to pointer is handled in the hideCards function.
void hideCardsForNewGame(Node ** c2, Node ** c3, Node ** c4, Node ** c5, Node ** c6, Node ** c7){

    hideCards(c2,1);
    hideCards(c3,2);
    hideCards(c4,3);
    hideCards(c5,4);
    hideCards(c6,5);
    hideCards(c7,6);

}

///sets up the game for start
void setupGame(Node * deckHead,Node ** c1,Node ** c2,Node ** c3,Node ** c4,Node ** c5,Node ** c6,Node ** c7,Node ** sC,Node ** sD,Node ** sH,Node ** sS) {
    distributeForStart(deckHead,c1,c2,c3,c4,c5,c6,c7);
    hideCardsForNewGame(c2, c3, c4, c5, c6, c7);
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

//____________________________________________Game card movement__________________________________________________________vvv

int getCardColor(Card card) {
    if (card.suit == 'H' || card.suit == 'D') {
        return 'r';                                       //char ascii value 114 for 'r'
    } else if (card.suit == 'C' || card.suit == 'S') {
        return 'b';                                       //char ascii value 98 for 'b'
    } else {
        return -1;
    }
}
int getRankIndex(char rank) {
    char ranks[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    for (int i = 0; i < strlen(ranks); ++i) {
        if (rank == ranks[i]) {
            return i;
        }
    }
    return -1;              //error rank not found
}

int moveToSuitStack(Node ** movingHeadCardNode, Node ** suitStack) {
    int hasEmptyStack = 0;

    Node * placeHoldMoving = *movingHeadCardNode;
    if (placeHoldMoving->next != NULL) {            //only the tail card can be moved to suitStack.
        return -1;
    }
    Node * placeHoldSuitStack = *suitStack;

    if (placeHoldSuitStack != NULL) {
        if (placeHoldMoving->card.suit == getTail(placeHoldSuitStack)->card.suit) {     //checking if suits match
            if (getRankIndex(placeHoldMoving->card.rank) == getRankIndex(getTail(placeHoldSuitStack)->card.rank) + 1) {       //checks if rank of card in placeHoldSuitStack is one rank lower
                if (placeHoldMoving->prev != NULL) {
                    if (placeHoldMoving->prev->card.visibility == 0) {
                        placeHoldMoving->prev->card.visibility = 1;           //reveal next card if hidden
                    }
                    placeHoldMoving->prev->next = NULL;             //make the card left after moving movingHeadCardNode new tail
                } else {
                    hasEmptyStack = 1;
                }

                getTail(placeHoldSuitStack)->card.visibility = 0;       //hides the old tail in suitStack to not allow paranormal moves from suitStack afterwards
                placeHoldMoving->prev = getTail(placeHoldSuitStack);   //make the placeHoldSuitStack become the previous cards for the moved placeHoldMoving
                getTail(placeHoldSuitStack)->next = placeHoldMoving;   //make the placeHoldSuitStack old tail point to to head in the now moved placeHoldMoving

                if (hasEmptyStack == 1) {
                    *movingHeadCardNode = NULL;
                }

                return 0;
            }
        }
    } else {                                //here placeHoldSuitStack == NULL
        if (placeHoldMoving->card.rank == 'A') {       //for moving and Ace of any suit to empty placeHoldSuitStack
            if (placeHoldMoving->prev == NULL) {
                hasEmptyStack = 1;
            }

            placeHoldMoving->prev = NULL;
            *suitStack = placeHoldMoving;

            if (hasEmptyStack == 1) {
                *movingHeadCardNode = NULL;
            }

            return 0;   //success
        }
    }
    return -1;          //failure
}

/// \param subHead      : The address of the first card in the subStack, that is to be moved
/// \param moveToStack  : The address of the head of the stack that the subStack is to be moved to
/// \return             : Returns 0 if success. Less than 0 if failure.
int moveSubStack(Node ** subHead, Node ** moveToStack) {
    int hasEmptyStack = 0;
    Node * placeHoldSubStack = *subHead;
    Node * placeHoldToStack = *moveToStack;

    if (placeHoldToStack == NULL && placeHoldSubStack->card.visibility == 1|| placeHoldSubStack->card.visibility == 1 && getTail(placeHoldToStack)->card.visibility == 1) {                //checks if the interacting cards are visible
        if (placeHoldToStack == NULL || getCardColor(placeHoldSubStack->card) != getCardColor(getTail(placeHoldToStack)->card)) {          //checks if colors are different
            if (placeHoldToStack == NULL || getRankIndex(placeHoldSubStack->card.rank) == getRankIndex(getTail(placeHoldToStack)->card.rank) - 1)  {     //checks if the first card in moved stack is one rank lower than the card moved to.
                //if the card left above the moved subStack is hidden, reveal it.
                if (placeHoldSubStack->prev != NULL) {
                    if (placeHoldSubStack->prev->card.visibility == 0) {
                        placeHoldSubStack->prev->card.visibility = 1;
                    }
                    placeHoldSubStack->prev->next = NULL;             //make the card left after moving subStack new tail
                } else {
                    hasEmptyStack = 1;
                }

                if (placeHoldToStack == NULL) {
                    placeHoldSubStack->prev = NULL;
                    *moveToStack = placeHoldSubStack;               //makes the new subStack the previously empty pile's new stack.
                } else {
                    placeHoldSubStack->prev = getTail(placeHoldToStack);   //make the movedToStack become the previous cards for the moved subStack
                    getTail(placeHoldToStack)->next = placeHoldSubStack;   //make the movedToStacks old tail point to to head in the now moved subStack
                }

                if (hasEmptyStack == 1) {
                    *subHead = NULL;
                }

                return 0;       //success

            }  else {
                return -3;  //error card ranks are not compatible for movement
            }
        } else {
            return -2;      //error cards are same color
        }
    } else {
        return -1;          //error movement between non-visible cards
    }
}

//todo make moveCardFromSuitStack


//____________________________________________Game card movement__________________________________________________________^^^

///returns 0 if valid, -1 otherwise
int checkIfSuit(char suit) {
    char suits[] = {'C','D','H','S'};
    for (int i = 0; i < (sizeof(suits)/sizeof(suits[0])) ; ++i) {
        if (suit == suits[i]) {
            return 0;
        }
    }
    return -1;
}

///returns 0 if valid, -1 otherwise
int checkIfRank(char rank) {
    char ranks[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    for (int i = 0; i < (sizeof(ranks)/sizeof(ranks[0])) ; ++i) {
        if (rank == ranks[i]) {
            return 0;
        }
    }
    return -1;
}

///returns 0 if cmd input is valid syntax
int validateCmd(char * cmd) {
    if (!(cmd[0] == 'C' || cmd[0] == 'F')) {        //checks first char in input
        return -1;
    }
    int is2ndChOk = 0;
    int is9thChOk = 0;
    for (int i = 1; i <= 7; ++i) {
        if (atoi(&cmd[1]) == i) {
            is2ndChOk = 1;
        }
        if (atoi(&cmd[8]) == i) {
            is9thChOk = 1;
        }
    }
    if (is2ndChOk != 1 || cmd[2] != ':') {          //checks second and third char input
        return -1;
    }
    if (checkIfRank(cmd[3]) != 0 || checkIfSuit(cmd[4]) != 0) {     //checks forth and fifth character
        return -1;
    }
    if (cmd[5] != '-' || cmd[6] != '>') {
        return -1;
    }
    if (!(cmd[7] == 'C' || cmd[7] == 'F')) {
        return -1;
    }
    if (is9thChOk != 1) {
        return -1;
    }
    if (cmd[7] == 'F') {
        return 2;           //returns 2 if it is a move to a suit stack
    } else if (cmd[7] == 'C') {
        return 0;           //returns 0 if it is a move to a pile
    }

    return -3;              //an unexpected error occurred
}



int main() {
//    static Node * c1;
//    static Node * c2;
//    static Node * c3;
//    static Node * c4;
//    static Node * c5;
//    static Node * c6;
//    static Node * c7;
//
//    //Stacks for the 4 suit piles
//    static Node * sC;
//    static Node * sD;
//    static Node * sH;
//    static Node * sS;
//
//    Node* test = createNewDeck();
////    traverseList(test);
////    test = shuffleDeck(test);
////    traverseList(test);
//
//    setupGame(test,&c1,&c2,&c3,&c4,&c5,&c6,&c7,&sC,&sD,&sH,&sS);
//
//    Node * tmp = getFromTail(c7,4);
//    moveSubStack(&tmp,&c6);
//
//    printCurrentBoard(c1,c2,c3,c4,c5,c6,c7,sC,sD,sH,sS);
////    distributeForStart(test,&c1,&c2,&c3,&c4,&c5,&c6,&c7);
////
////    hideCardsForNewGame(&c2, &c3, &c4, &c5, &c6, &c7);
////
////    printCurrentBoard(c1,c2,c3,c4,c5,c6,c7,sC,sD,sH,sS);
    char * command = "P";
    int i = strcmp(command, "P");
    printf("test %d command: %s", i, command);

    run();

    return 0;
}

Node* shuffleDeck(Node* head){
    int deckSize = countElements(head);
    int randomNumbers[deckSize];
    int generatedNumbers = 0;
    int hasOccured;

    for(int i = 0; i<deckSize;i++){
        randomNumbers[i]=-1;
    }

    while (generatedNumbers < deckSize) {
        int random = rand() % deckSize;
        hasOccured=0;
        for (int i=0; i < deckSize; i++) {
            if (random == randomNumbers[i]) {
                hasOccured = 1;
                continue;
            }
        }
        if (hasOccured == 0) {
            randomNumbers[generatedNumbers] = random;
            generatedNumbers++;
            continue;
        }
    }
    /*
     * Takes a random int from randomNumbers[i] and adds the corresponding Node to newDeck.
     */
    Node* newDeck = createNewNode();
    Node* temp;
    for (int i = 0; i < deckSize; ++i) {
     if(i==0){
         setCard(&newDeck->card, getFromHead(head,randomNumbers[i])->card.rank,getFromHead(head,randomNumbers[i])->card.suit,getFromHead(head,randomNumbers[i])->card.visibility);
     }
        if(i>0 && i<=deckSize){
        temp = createNewNode();
        setCard(&temp->card, getFromHead(head,randomNumbers[i])->card.rank,getFromHead(head,randomNumbers[i])->card.suit,getFromHead(head,randomNumbers[i])->card.visibility);
        insertNew(newDeck,temp);
        }
    }
    // free() original unshuffled list
    while(head!=NULL){
        temp = head;
        head = head->next;
        deleteNode(head,temp);
    }
    return newDeck;
}
struct node* createNewDeck(){
    Node* head = createNewNode();
    Card temp_card;
    Node* temp;
    temp_card.visibility=1;
    // A setup of for-loops creates the 13 cards from each of the 4 suits
    for(int index=1; index<=4; index++){
        if(index==1) temp_card.suit = 'C';
        if(index==2) temp_card.suit = 'D';
        if(index==3) temp_card.suit = 'H';
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
            // For cards 2 through K in the specific suit
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
void hideCards(Node ** head, int cardCntToHide){
    for(int i = 0; i < cardCntToHide; i++){
        setCard(&getFromHead(*head, i)->card, getFromHead(*head, i)->card.rank, getFromHead(*head, i)->card.suit, 0);
    }
}
void run(){

    char command[2];
    char gameCmd[9];

    while (1){

        printf("Please enter a valid command: \n");
        scanf("%s", &command);

        //Deck for playing
        Node * deckOfCardsHead = createNewDeck();

        if(!strcmp(command,"SW")){
            printDeck(deckOfCardsHead);
        } else if(!strcmp(command,"SR")){
            deckOfCardsHead = shuffleDeck(deckOfCardsHead);
        } else if (!strcmp(command, "QQ")){
            break;
        } else if(!strcmp(command, "P")){

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


            setupGame(deckOfCardsHead,&c1,&c2,&c3,&c4,&c5,&c6,&c7,&sC,&sD,&sH,&sS);

            //play loop
            while (1){

                printCurrentBoard(c1,c2,c3,c4,c5,c6,c7,sC,sD,sH,sS);

                //todo print message to user explaining that we need a move in the form of
                // [fromStack]:[movingCard]->[destStack] fx C4:H7->C3

                //for testing, give cmd: C7:7C->C6
                scanf("%s",&gameCmd);   //TODO can maybe just use command instead of a new variable, gameCmd.


                if(validateCmd(gameCmd) == 0) {                 //move to pile
                    char stackName[2];
                    Node ** fromStackPtr;
                    Node * subStackPtr;
                    Node ** destStackPtr;

                    fromStackPtr = pickStacks(gameCmd[0],gameCmd[1],&c1,&c2,&c3,&c4,&c5,&c6,&c7,&sC,&sD,&sH,&sS);
                    subStackPtr = getNodeFromCardRankAndSuit(*fromStackPtr,gameCmd[3],gameCmd[4]);
                    destStackPtr = pickStacks(gameCmd[7],gameCmd[8],&c1,&c2,&c3,&c4,&c5,&c6,&c7,&sC,&sD,&sH,&sS);

                    //todo make error handling if function returns other than 0. And prompt user with invalid move message.
                    int errorCode = moveSubStack(&subStackPtr,destStackPtr);
                    if (errorCode != 0) {
                        //print invalid move message
                    }

                } else if (validateCmd(gameCmd) == 2) {         //move to suitStack
                    char stackName[2];
                    Node ** fromStackPtr;
                    Node * subStackPtr;
                    Node ** destStackPtr;

                    fromStackPtr = pickStacks(gameCmd[0],gameCmd[1],&c1,&c2,&c3,&c4,&c5,&c6,&c7,&sC,&sD,&sH,&sS);
                    subStackPtr = getNodeFromCardRankAndSuit(*fromStackPtr,gameCmd[3],gameCmd[4]);
                    destStackPtr = pickStacks(gameCmd[7],gameCmd[8],&c1,&c2,&c3,&c4,&c5,&c6,&c7,&sC,&sD,&sH,&sS);

                    //todo make error handling if function returns other than 0. And prompt user with invalid move message.
                    int errorCode = moveToSuitStack(&subStackPtr,destStackPtr);
                    if (errorCode != 0) {
                        //print invalid move message
                    }


                    //win condition. All cards are moved to suit stacks
                    if (subStackPtr->card.rank == 'K') {         //only needs to check if game is won if moved card is a king
                        if (getTail(sC)->card.rank == 'K' && getTail(sD)->card.rank == 'K' && getTail(sH)->card.rank == 'K' && getTail(sS)->card.rank == 'K') {
                            printf("YOU WIN!");
                            break;
                        }
                    }

                } else {
                    //redo loop, with failure feedback prompt invalid move
                }

                if (!strcmp(command, "Q")){
                    break;
                }
            }
        }
    }
}

//todo ** is probably unnecessary. Can maybe be changed to * in both parameters and return. Then an & is just used with the returned * later.
Node ** pickStacks(char stackCh1,char stackCh2,Node ** c1,Node ** c2,Node ** c3,Node ** c4,Node ** c5,Node ** c6,Node ** c7,Node ** sC,Node ** sD,Node ** sH,Node ** sS) {

    if (stackCh1 == 'C' && stackCh2 == '1') {
        return c1;
    } else if (stackCh1 == 'C' && stackCh2 == '2') {
        return c2;
    } else if (stackCh1 == 'C' && stackCh2 == '3') {
        return c3;
    } else if (stackCh1 == 'C' && stackCh2 == '4') {
        return c4;
    } else if (stackCh1 == 'C' && stackCh2 == '5') {
        return c5;
    } else if (stackCh1 == 'C' && stackCh2 == '6') {
        return c6;
    } else if (stackCh1 == 'C' && stackCh2 == '7') {
        return c7;
    } else if (stackCh1 == 'F' && stackCh2 == '1') {
        return sC;
    } else if (stackCh1 == 'F' && stackCh2 == '2') {
        return sD;
    } else if (stackCh1 == 'F' && stackCh2 == '3') {
        return sH;
    } else if (stackCh1 == 'F' && stackCh2 == '4') {
        return sS;
    }
}
