#include <stdio.h>
#include <string.h>

int assertEqualString(char *input, char *expected) {
    if (strcmp(input, expected) == 0) {
        printf("✅ PASS: \"%s\" == \"%s\"\n", input, expected);
        return 1;
    } else {
        printf("❌ FAIL: Expected \"%s\" but got \"%s\"\n", expected, input);
        return 0;
    }
}

int assertEqualInt(int input, int expected) {
    if (input != expected) {
        printf("❌ FAIL: Expected %d but got %d\n", expected, input);
        return 0;
    }
    printf("✅ PASS: %d == %d\n", input, expected);
    return 1;
}

int assertEqualCharLen(char *input, char *expected) {
    if (input == NULL || expected == NULL) {
        printf("❌ FAIL: One of the inputs is NULL\n");
        return 0;
    }

    int inputLen = strlen(input);
    int expectedLen = strlen(expected);

    if (inputLen != expectedLen) {
        printf("❌ FAIL: Expected length %d but got %d\n", expectedLen, inputLen);
        return 0;
    }

    printf("✅ PASS: Length %d == %d\n", inputLen, expectedLen);
    return 1;
}

void runTests() {
    assertEqualString("hello", "hello");
    assertEqualString("hello", "world");

    assertEqualInt(10, 10);
    assertEqualInt(10, 5);

    assertEqualCharLen("hello", "world");
    assertEqualCharLen("hi", "hello");
    assertEqualCharLen(NULL, "test");  
}

int main(void) {
    runTests();
    return 0;
}