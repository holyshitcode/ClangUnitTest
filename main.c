#include <stdio.h>
#include <string.h>

int assertEqualString(char *input, char *expected) {
    if (strcmp(input, expected) == 0) {
        return 1;
    }else {
        printf("Expected %s but got %s\n", expected, input);
        return 0;
    }
}

int assertEqualInt(int input, int expected) {
    if (input != expected) {
        printf("Expected %d but got %d\n", expected, input);
        return 0;
    }
    return 1;
}

int assertEqualCharLen(char *input, char *expected) {
    int inputLen = strlen(input);
    int expectedLen = strlen(expected);
    if (inputLen != expectedLen) {
        printf("Expected %d but got %d\n", expectedLen, inputLen);
    }
    return 1;
}



int main(void)
{

    return 0;
}
