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

int assertEqualIntArray(int input[], int inputLen, int expected[], int expectedLen) {
    if (inputLen != expectedLen) {
        printf("❌ FAIL: Expected length %d but got %d\n", expectedLen, inputLen);
        return 0;
    }else{
        for (int i = 0; i < inputLen; i++) {
            if (input[i] != expected[i]) {
                printf("❌ FAIL: Arrays differ at index %d (expected %d, got %d)\n", i, expected[i], input[i]);
                return 0;
            }
        }
    }
    printf("✅ PASS: Length %d == %d\n", inputLen, expectedLen);
    return 1;

}

int assertEqualDoubleArray(double input[], double inputLen, double expected[], double expectedLen) {
    if (inputLen != expectedLen) {
        printf("❌ FAIL: Expected length %f but got %f\n", expectedLen, inputLen);
        return 0;
    }else{
        for (int i = 0; i < inputLen; i++) {
            if (input[i] != expected[i]) {
                printf("❌ FAIL: Arrays differ at index %d (expected %f, got %f)\n", i, expected[i], input[i]);
                return 0;
            }
        }
    }
    printf("✅ PASS: Length %f == %f\n", inputLen, expectedLen);
    return 1;
}

int assertEqualLongArray(long input[], long inputLen, long expected[], long expectedLen) {
    if (inputLen != expectedLen) {
        printf("❌ FAIL: Expected length %ld but got %ld\n", expectedLen, inputLen);
        return 0;
    }else{
        for (int i = 0; i < inputLen; i++) {
            if (input[i] != expected[i]) {
                printf("❌ FAIL: Arrays differ at index %d (expected %ld, got %ld)\n", i, expected[i], input[i]);
                return 0;
            }
        }
    }
    printf("✅ PASS: Length %ld == %ld\n", inputLen, expectedLen);
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

    int intArray[3] = {1, 2, 3};
    int intArray2[3] = {1, 2, 3};
    int intArray3[2] = {1, 2};
    int intArray4[3] = {1, 2, 4};
    assertEqualIntArray(intArray,3 ,intArray2,3);
    assertEqualIntArray(intArray, 3, intArray3,2);
    assertEqualIntArray(intArray, 3 ,intArray4,3);
}

int main(void) {
    runTests();
    return 0;
}