#include <stdio.h>
#include "DoublyLinkedList.h" // Our implementation of DLL
#include "Tests.h" // Methods for testing insert, delete, update, traversal and testdeck


int main() {
    testDeck();
    testSearchAndDelete();
    Node* head = createTestDeck();
    printDeck(head);

    return 0;
}