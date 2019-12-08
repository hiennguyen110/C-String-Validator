#include <stdio.h>
#include <string.h>
#include <ctype.h>

void getString(char userString[], int maxLength) {
    int counter = 0;
    int userChar;
    while ((userChar = getchar()) != EOF && userChar != '\n') {
        if (counter < maxLength) {
            userString[counter] = (char) userChar;
            ++counter;
        }
    }
    userString[counter] = '\0';
}

int numberCounter(char userString[]) {
    int length = strlen(userString);
    int counter, numStrCtr;
    const char numberString[] = "0123456789";
    int numberCounter = 0;
    for (counter = 0; counter < length; ++counter) {
        for (numStrCtr = 0; numStrCtr < strlen(numberString); ++numStrCtr) {
            if (userString[counter] == numberString[numStrCtr]) {
                ++numberCounter;
            }
        }
    }
    return numberCounter;
}

int alphabetCounter(char userString[]) {
    int length = strlen(userString);
    int counter, apbCtr;
    const char alphabetString[] = "abcdefghijklmnopqrstuvwxyz";
    int alphabetCounter = 0;
    for (counter = 0; counter < length; ++counter) {
        for (apbCtr = 0; apbCtr < strlen(alphabetString); ++apbCtr) {
            if (tolower(userString[counter]) == alphabetString[apbCtr]) {
                ++alphabetCounter;
            }
        }
    }
    return alphabetCounter;
}

int hasInvalidChar(char userString[]) {
    int length = strlen(userString);
    int counter, invalidCharCrt;
    const char inValidCharSet[] = "!@#$%^&*()-+=~`' -/*<>?,.\n";
    for (counter = 0; counter < strlen(userString); ++counter) {
        for (invalidCharCrt = 0; invalidCharCrt < strlen(inValidCharSet); ++invalidCharCrt) {
            if (userString[counter] == inValidCharSet[invalidCharCrt]){
                return 1;
            }
        }
    }
    return 0;
}

int validator(char userString[]) {
    if (!hasInvalidChar(userString)) {
        if (numberCounter(userString) >= 3) {
            if (alphabetCounter(userString) >= 3) {
                return 1;
            } else {
                printf("NOT ENOUGH ALPHABET\n");
            }
        } else {
            printf("NOT ENOUGH NUMBER\n");
        }
    } else {
        printf("STRING CONTAINS INVALID CHARACTER\n");
    }
    return 0;
}
int main() {
    return 0;
}