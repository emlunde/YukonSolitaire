//#include "DoublyLinkedList.h" //https://gist.github.com/mycodeschool/7429492
#include "Commands.h"
#include "DoublyLinkedListTwo.h"
#include "Tests.h"


Node * c1;
Node * c2;
Node * c3;
Node * c4;
Node * c5;
Node * c6;
Node * c7;


///// Function for splitting up the cardDeck to the 7 piles. Should match with the startposition.
///// \param cardDeck: should be a full 52 set deck of cards. Can be shuffled or unshuffled.
//struct Node* distributeDeckForStartPosition(Node * head) {
//
//
//    Node *c1,*c2,*c3,*c4,*c5,*c6,*c7, **pptr;
//
//
//    pptr = (Node **) malloc(7*sizeof(Node*));
//    pptr = &c1;
//
//    Node **c;
//
//
//    insertNew(c[0]) =
//    head = deleteNode(head,head);
//    c[0];
//
//    //init the columns
//    for(int i = 0; i < 7; i++) {
//        Card tempCard;
//        setCard(&tempCard,NULL,NULL,NULL);       //A placeholder card
//
//        c[i] = createNewNode();
//        c[i]->prev = NULL;
//        c[i]->next = NULL;
//        c[i]->card = tempCard;
//    }
//
//    int cardCnt = 0;
//    while(cardCnt < 52) {
//
//
//        if (countElements(c[0]) < 1) {                          //for only inserting 1 valid card in stack c[0]
//            insertNew(c[0],head);                               //card added. The added node's Next and Prev are overwritten on insert.
//            if (c[0][0].card.rank == NULL) {                             //For checking if delete of placeholder needed (on first insert it is needed)
//                c[0] = deleteNode(c[0],c[0]);               //for deleting placeholder first element and setting the head, c[0], as the next element
//            }
//            head = deleteNode(head,head);
//            cardCnt++;
//        }
//        if (countElements(c[1]) < 6) {                          //for only inserting 6 valid card in stack c[1]
//            insertNew(c[1],head);                               //card added. The added node's Next and Prev are overwritten on insert.
//            if (c[1][0].card.rank == NULL) {                             //For checking if delete of placeholder needed (on first insert it is needed)
//                c[1] = deleteNode(c[1],c[1]);               //for deleting placeholder first element and setting the head, c[1], as the next element
//            }
//            head = deleteNode(head,head);
//            cardCnt++;
//        }
//        if (countElements(c[2]) < 7) {                          //for only inserting 7 valid card in stack c[2]
//            insertNew(c[2],head);                               //card added. The added node's Next and Prev are overwritten on insert.
//            if (c[2][0].card.rank == NULL) {                             //For checking if delete of placeholder needed (on first insert it is needed)
//                c[2] = deleteNode(c[2],c[2]);               //for deleting placeholder first element and setting the head, c[2], as the next element
//            }
//            head = deleteNode(head,head);
//            cardCnt++;
//        }
//
//
//
//    }
//
//
//    //todo: create start deck. create board from start deck.
//
//    //todo: get column for each linked list, and create array 'C' with the 7 linked lists
//    //---OBS--- temp test below, see task above, and delete below when task is complete
//    //card has visibility, suit, and rank
//    Node * head = createNewNode();
//    setCard(&head->card,'8','S',1);
//
//    quickInsertCard(head, '7', 'D');
//    getNodeFromCardRankAndSuit(head,'7','D')->card.visibility = 1;
//
//    traverseList(head);
//    //---OBS--- _______________________________________________________________________
//    return c
//}


/// Function for splitting up the cardDeck to the 7 piles. Should match with the startposition.
/// \param headOfDeck: should be a full 52 set deck of cards. Can be shuffled or unshuffled.
/// The piles c1 through c7 are global static variables, that gets updated with the cards.
void distributeForStart(Node * headOfDeck) {

    //cptr**
    //*ptr=c[0]=c1 = pointer to first pile top card
    //*ptr2=c[1]=c2 = pointer to second pile top card
    //...

//    Node **c = (Node **) malloc(7*sizeof(Node*));
    Node **c;

//    //init the columns
//    for(int i = 0; i < 7; i++) {
//        Card tempCard;
//        setCard(&tempCard,NULL,NULL,NULL);       //A placeholder card
//
//        c[i] = createNewNode();
//        c[i]->prev = NULL;
//        c[i]->next = NULL;
//        c[i]->card = tempCard;
//    }

    //c1
    insertNew(c1, headOfDeck);
    headOfDeck = deleteNode(headOfDeck, headOfDeck);


    insertNew(c2, headOfDeck);     //deleting the first placeholder element
    headOfDeck = deleteNode(headOfDeck, headOfDeck);
    for (int i = 0; i < 5; ++i) {       //inserting the column's needed card amount except for the card already added
        insertNew(c2, headOfDeck);
        headOfDeck = deleteNode(headOfDeck, headOfDeck);
    }

//    //c1
//    Node * c1 = c[0];               //Naming for easier understanding
//    insertNew(c[0],headOfDeck);
//    c[0] = deleteNode(c[0],c[0]);
//    headOfDeck = deleteNode(headOfDeck,headOfDeck);

    //c2
    Node * c2 = c[1];               //Naming for easier understanding
    insertNew(c2, headOfDeck);
    c2 = deleteNode(c2,c2);             //deleting the first placeholder element
    headOfDeck = deleteNode(headOfDeck, headOfDeck);
    for (int i = 0; i < 5; ++i) {       //inserting the column's needed card amount except for the card already added
        insertNew(c2, headOfDeck);
        headOfDeck = deleteNode(headOfDeck, headOfDeck);
    }

    //c3
    Node * c3 = c[2];               //Naming for easier understanding
    insertNew(c3, headOfDeck);
    c3 = deleteNode(c3,c3);             //deleting the first placeholder element
    headOfDeck = deleteNode(headOfDeck, headOfDeck);
    for (int i = 0; i < 6; ++i) {       //inserting the column's needed card amount except for the card already added
        insertNew(c3, headOfDeck);
        headOfDeck = deleteNode(headOfDeck, headOfDeck);
    }

    //c4
    Node * c4 = c[3];               //Naming for easier understanding
    insertNew(c4, headOfDeck);
    c4 = deleteNode(c4,c4);             //deleting the first placeholder element
    headOfDeck = deleteNode(headOfDeck, headOfDeck);
    for (int i = 0; i < 7; ++i) {       //inserting the column's needed card amount except for the card already added
        insertNew(c4, headOfDeck);
        headOfDeck = deleteNode(headOfDeck, headOfDeck);
    }

    //c5
    Node * c5 = c[4];               //Naming for easier understanding
    insertNew(c5, headOfDeck);
    c5 = deleteNode(c5,c5);             //deleting the first placeholder element
    headOfDeck = deleteNode(headOfDeck, headOfDeck);
    for (int i = 0; i < 8; ++i) {       //inserting the column's needed card amount except for the card already added
        insertNew(c5, headOfDeck);
        headOfDeck = deleteNode(headOfDeck, headOfDeck);
    }

    //c6
    Node * c6 = c[5];               //Naming for easier understanding
    insertNew(c6, headOfDeck);
    c6 = deleteNode(c6,c6);             //deleting the first placeholder element
    headOfDeck = deleteNode(headOfDeck, headOfDeck);
    for (int i = 0; i < 9; ++i) {       //inserting the column's needed card amount except for the card already added
        insertNew(c6, headOfDeck);
        headOfDeck = deleteNode(headOfDeck, headOfDeck);
    }

    //c7
    Node * c7 = c[6];               //Naming for easier understanding
    insertNew(c7, headOfDeck);
    c7 = deleteNode(c7,c7);             //deleting the first placeholder element
    headOfDeck = deleteNode(headOfDeck, headOfDeck);
    for (int i = 0; i < 10; ++i) {       //inserting the column's needed card amount except for the card already added
        insertNew(c7, headOfDeck);
        headOfDeck = deleteNode(headOfDeck, headOfDeck);
    }

    return c;
}


void printStartPosition(){

    printf("\tC1\tC2\tC3\tC4\tC5\tC6\tC7\n\n");

//    //get needed height for board to be printed
//    int boardHeight = 0;
//    for (int i = 0; i < 7; ++i) {
//        if (countElements(C[i]) > boardHeight) {
//            boardHeight = countElements(C[i]);
//        }
//    }

    //temporary simplification. delete after fix
    int boardHeight=8;

    //print for each row
    for (int i = 0; i < boardHeight; ++i) {

        printf("\t%2s\t%2s\t%2s\t%2s\t%2s\t%2s\t%2s\t", "AC","2C", "6D", "8H", "TS", "AD", "[]");

        if (i == 0) {
            printf("[]\tF1");
        } else if (i == 2) {
            printf("[]\tF2");
        } else if (i == 4) {
            printf("[]\tF3");
        } else if (i == 6) {
            printf("[]\tF4");
        }
        printf("\n");
    }


//    printf("\t\t\t\t\t\t\t\t[]\tF1\n");
//    printf("\t\t\t\t\t\t\t\t\n");
//    printf("\t\t\t\t\t\t\t\t[]\tF2\n");
//    printf("\t\t\t\t\t\t\t\t\n");
//    printf("\t\t\t\t\t\t\t\t[]\tF3\n");
//    printf("\t\t\t\t\t\t\t\t\n");
//    printf("\t\t\t\t\t\t\t\t[]\tF4\n");
//    printf("\t\t\t\t\t\t\t\t\n");
    printf("LAST command: \n");
    printf("Message: \n");
    printf("INPUT > \n");

}

void updatePosition(){

    printf("\tC1\tC2\tC3\tC4\tC5\tC6\tC7\n");
    printf("\t\t\t\t\t\t\t\t[]\tF1\n");
    printf("\t\t\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t\t\t[]\tF2\n");
    printf("\t\t\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t\t\t[]\tF3\n");
    printf("\t\t\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t\t\t[]\tF4\n");
    printf("\t\t\t\t\t\t\t\t\n");
    printf("LAST command: \n");
    printf("Message: \n");
    printf("INPUT > \n");

}

int main() {

//    printStartPosition();
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

    Node * testHead = createTestDeck();
    printDeck(testHead);

    Node ** c = distributeForStart(testHead);

    printDeck(c[1]);


//    popHead(head);

//    printDeck(head);
    return 0;
}
