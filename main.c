//#include "DoublyLinkedList.h" //https://gist.github.com/mycodeschool/7429492
#include "Commands.h"
#include "DoublyLinkedListTwo.h"
#include "Tests.h"

void printStartPosition(){

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


    while(1) {
        printf("Please input command or move: ");
        char inputStr[100];
        gets(inputStr);
    //    char testStr[100] = "LD filenameTest3";
        //TODO: delete ... this was for testing Commands.h's functions
        char * result = cmdSelector(inputStr);
        printf("\nresult: %s\n",result);

        if(strcmp(inputStr, "QQ") && strcmp(result,"OK")) {
            break;
        }
    }
//    testSearchAndDelete();
    return 0;
}
