//#include "DoublyLinkedList.h" //https://gist.github.com/mycodeschool/7429492
#include "Commands.h"
#include "DoublyLinkedListTwo.h"
#include "Tests.h"

int main() {

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
