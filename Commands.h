#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char ERROR_TOO_MANY_ARGUMENTS[] = "INVALID INPUT: Too many arguments in input command";

char *funcQ();
char *funcP();
char *funcQQ();
char *funcSD(char *arg2);
char *funcSR();
char *funcSI(char *arg2);
char *funcSW();
char *funcLD(char * filename);

int filenameIsValid(char *filename);
int fileContentIsValid(char *filename);

/// Selector method for the entered command.
/// Returns "OK" or an error message, depending on result.
char * cmdSelector(char * cmd) {

    char str[strlen(cmd)];
    strcpy(str,cmd);

    char * token = strtok(str, " ");             //OBS this modifies original str string

    char * cmdArg2 = strtok(NULL, " ");     //takes second argument. NULL if no second argument given

    if (strtok(NULL, " ") != NULL) {        //if more than 2 arguments given, input is invalid
        return ERROR_TOO_MANY_ARGUMENTS;
    }

    printf("orig: %s , cmdArg1: %s , cmdArg2: %s", cmd, token,cmdArg2);
    if(!strcmp(token,"LD")) {
        return funcLD(cmdArg2);                       //returns "OK" if success, and an error message otherwise
    }
    else if (!strcmp(token, "SW")) {
        if (cmdArg2 != NULL) {                        //SW should only take one argument
            return ERROR_TOO_MANY_ARGUMENTS;
        }
        return funcSW();
    }
    else if (!strcmp(token, "SI")) {
        return funcSI(cmdArg2);
    }
    else if (!strcmp(token, "SR")) {
        if (cmdArg2 != NULL) {                        //SR should only take one argument
            return ERROR_TOO_MANY_ARGUMENTS;
        }
        return funcSR();
    }
    else if (!strcmp(token, "SD")) {
        return funcSD(cmdArg2);
    }
    else if (!strcmp(token, "QQ")) {
        if (cmdArg2 != NULL) {                        //QQ should only take one argument
            return ERROR_TOO_MANY_ARGUMENTS;
        }
        return funcQQ();
    }
    else if (!strcmp(token, "P")) {
        if (cmdArg2 != NULL) {                        //P should only take one argument
            return ERROR_TOO_MANY_ARGUMENTS;
        }
        return funcP();
    }
    else if (!strcmp(token, "Q")) {
        if (cmdArg2 != NULL) {                        //Q should only take one argument
            return ERROR_TOO_MANY_ARGUMENTS;
        }
        return funcQ();
    }
//    todo: game moves
//    else if (!strcmp(token, "")) {
//        return func();
//    }

    return "test";
}


// COMMAND LOGIC IMPLEMENTATION vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//todo: some of the methods below may need visibility of the current game state.
// Should maybe be in main.c file instead.

//___funcLD______________________________________________________________________________v
//EXAMPLE OF IMPLEMENTATION ...
char *funcLD(char * filename) {
    if (filename == NULL) {
        //todo: implement loading of unshuffled deck.
        return "OK";
    }
    if (filenameIsValid(filename)) {
        if (fileContentIsValid(filename)) {
            //todo: implement loading deck from file.
            return "OK";
        } else {
            return "Invalid file content"; //TODO make better error overview.
        }
    } else {
        return "invalid filename";         //TODO make better error overview.
    }
}

/// used in funcLD to check if file with name exists. Returns FALSE, 0, or TRUE, 1.
int fileContentIsValid(char *filename) {
    //todo implement
    return 0;
}

/// used in func LD to check if file content is valid. Returns FALSE, 0, or TRUE, 1.
int filenameIsValid(char *filename) {
    //todo implement
    return 0;
}
//_______________________________________________________________________________________^

char *funcSW() {
    return NULL;
}

char *funcSI(char *arg2) {
    return NULL;
}

char *funcSR() {
    return NULL;
}

char *funcSD(char *arg2) {
    return NULL;
}

char *funcQQ() {
    return NULL;
}

char *funcP() {
    return NULL;
}

char *funcQ() {
    return NULL;
}

// COMMAND LOGIC IMPLEMENTATION ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^