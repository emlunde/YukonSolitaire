//#include "DoublyLinkedList.h" //https://gist.github.com/mycodeschool/7429492
#include "Commands.h"
#include "DoublyLinkedListTwo.h"
#include "Tests.h"

void printStartPosition(){

    //todo: create start deck. create board from start deck.

    //todo: get column for each linked list, and create array 'C' with the 7 linked lists

    printf("\tC1\tC2\tC3\tC4\tC5\tC6\tC7\n");

//    //get needed height for board to be printed
//    int boardHeight = 0;
//    for (int i = 0; i < 7; ++i) {
//        if (countElements(C[i]) > boardHeight) {
//            boardHeight = countElements(C[i]);
//        }
//    }

    //temporary simplification. delete after fix
    int boardHeight=8;

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

    printStartPosition();


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
    return 0;
}
