#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <setjmp.h>


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

int assertCharContaining(char *input, char expected) {
    int i = 0;
    while (input[i] != '\0') {
        if (input[i] == expected ) {
            printf("✅ PASS: Expected %c is in Index %d\n", expected, i);
            return 1;
        }
        i++;
    }
    printf("❌ FAIL: Expected char %c doesn't exist\n", expected);
    return 0;

}

int assertStrContainingStr(char *input, char *expected) {
    int inputLen = strlen(input);
    int expectedLen = strlen(expected);

    if (inputLen < expectedLen) {
        printf("❌ FAIL: Input string is shorter than expected string\n");
        return 0;
    }

    for (int i = 0; i <= inputLen - expectedLen; i++) {
        int matchFound = 1;
        for (int j = 0; j < expectedLen; j++) {
            if (input[i + j] != expected[j]) {
                matchFound = 0;
                break;
            }
        }
        if (matchFound) {
            printf("✅ PASS: Expected string '%s' found at index %d\n", expected, i);
            return 1;
        }
    }

    printf("❌ FAIL: Expected string '%s' not found\n", expected);
    return 0;
}



int assertIntArrayContainingInt(int input[], int inputLen, int expected) {
    int flag = 0;
    int i;
    for (i = 0 ; i < inputLen; i++) {
        if (input[i] == expected) {
            flag++;
            break;
        }
    }
    if (flag == 0) {
        printf("❌ FAIL: Expected %d not in Array\n",expected);
        return 0;
    }
    printf("✅ PASS: Expected Int %d found at index %d\n", expected, i);
    return 1;
}

int assertDoubleArrayContainingDouble(double input[], int inputLen, double expected) {
    int flag = 0;
    int i;
    for (i = 0 ; i < inputLen; i++) {
        if (input[i] == expected) {
            flag++;
        }
    }
    if (flag == 0) {
        printf("❌ FAIL: Expected %f not in Array\n",expected);
    }
    printf("✅ PASS: Expected Int %f found at index %d\n", expected, i);
    return 1;
}

int assertLongArrayContainingLong(long input[], int inputLen, long expected) {
    int flag = 0;
    int i;
    for (i = 0 ; i < inputLen; i++) {
        if (input[i] == expected) {
            flag++;
        }
    }
    if (flag == 0) {
        printf("❌ FAIL: Expected %ld not in Array\n",expected);
    }
    printf("✅ PASS: Expected Int %ld found at index %d\n", expected, i);
    return 1;
}


jmp_buf jump;

/** divide by zero
 *  ex = if( num < 0){
 *          try();
 *      }else{
 *          function();
 *      }
 ================================================
 *      void main(){
 *         if(setjmp(jump) == 0){
 *             function();
 *             function();
 *         }else{
 *              printf("Exception Occur");
 *         }
 *      }
 */

void try(){
    printf("🚨 에러 발생!\n");
    longjmp(jump, 1);
}






void runTests() {
    if (setjmp(jump) == 0) {
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

        assertCharContaining("hello",'o');
        assertCharContaining("hello",'q');

        assertStrContainingStr("hello", "ll");
        assertStrContainingStr("hello", "qq");
        try();
    }else {
        int intArray5[10] = {1, 2, 4,10,20,40,50,60,70,100};
        assertIntArrayContainingInt(intArray5,10 ,40);
        assertIntArrayContainingInt(intArray5,10 ,100);
        assertIntArrayContainingInt(intArray5,10 ,44);
    }
}

int main(void) {
    runTests();
    return 0;
}