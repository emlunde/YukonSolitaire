#include <stdio.h>
//#include "DoublyLinkedList.h" //https://gist.github.com/mycodeschool/7429492
#include "Commands.h"

int main() {

    printf("Please input command or move: ");
    char inputStr[100];
    gets(inputStr);
//    char testStr[100] = "LD filenameTest3";
    //TODO: delete ... this was for testing Commands.h's functions
    char * result = cmdSelector(inputStr);
    printf("\nresult: %s\n",result);


    printf("Hello, World!\n");
    return 0;
}
