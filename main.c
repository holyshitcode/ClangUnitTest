#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <setjmp.h>
#include <stdlib.h>

typedef enum Boolean {
    IsNot,null
}boolean;
int assertEqualString(char *input, char *expected, boolean boolean) {
    if (boolean == IsNot) {
        if (strcmp(input, expected) == 0) {
            printf("❌ FAIL: Expected \"%s\" but got \"%s\"\n", expected, input);
            return 0;
        }
        printf("✅ PASS: \"%s\" != \"%s\"\n", input, expected);
        return 1;
    }
    if (strcmp(input, expected) == 0) {
        printf("✅ PASS: \"%s\" == \"%s\"\n", input, expected);
        return 1;
    } else {
        printf("❌ FAIL: Expected \"%s\" but got \"%s\"\n", expected, input);
        return 0;
    }
}

int assertEqualInt(int input, int expected, boolean boolean) {
    if (boolean == IsNot) {
        if (input == expected) {
            printf("❌ FAIL: Expected %d to be different, but got %d\n", expected, input);
            return 0;
        }
        printf("✅ PASS: %d != %d\n", input, expected);
        return 1;
    }
    if (input != expected) {
        printf("❌ FAIL: Expected %d but got %d\n", expected, input);
        return 0;
    }
    printf("✅ PASS: %d == %d\n", input, expected);
    return 1;
}

int assertEqualCharLen(char *input, char *expected, boolean boolean) {
    if (input == NULL || expected == NULL) {
        if (boolean == IsNot) {
            printf("✅ PASS: One of the inputs is NULL as expected\n");
            return 1;
        }
        printf("❌ FAIL: One of the inputs is NULL\n");
        return 0;
    }

    int inputLen = strlen(input);
    int expectedLen = strlen(expected);

    if (boolean == IsNot) {
        if (inputLen == expectedLen) {
            printf("❌ FAIL: Expected different lengths but both are %d\n", inputLen);
            return 0;
        }
        printf("✅ PASS: Length %d != %d\n", inputLen, expectedLen);
        return 1;
    }

    if (inputLen != expectedLen) {
        printf("❌ FAIL: Expected length %d but got %d\n", expectedLen, inputLen);
        return 0;
    }

    printf("✅ PASS: Length %d == %d\n", inputLen, expectedLen);
    return 1;
}

int assertEqualIntArray(int input[], int inputLen, int expected[], int expectedLen, boolean boolean) {
    if (input == NULL || expected == NULL) {
        printf("❌ FAIL: One of the input arrays is NULL\n");
        return 0;
    }

    if (inputLen != expectedLen) {
        printf("❌ FAIL: Expected length %d but got %d\n", expectedLen, inputLen);
        return 0;
    }

    int isSame = 1;
    for (int i = 0; i < inputLen; i++) {
        if (input[i] != expected[i]) {
            printf("❌ FAIL: Arrays differ at index %d (expected %d, got %d)\n", i, expected[i], input[i]);
            return 0;
        }
    }

    if (boolean == IsNot) {
        printf("❌ FAIL: Expected arrays to be different, but they are identical\n");
        return 0;
    }

    printf("✅ PASS: Arrays are identical (length %d)\n", inputLen);
    return 1;
}



int assertEqualDoubleArray(double input[], double inputLen, double expected[], double expectedLen, boolean boolean) {
    if (input == NULL || expected == NULL) {
        printf("❌ FAIL: One of the input arrays is NULL\n");
        return 0;
    }

    if (inputLen != expectedLen) {
        printf("❌ FAIL: Expected length %f but got %f\n", expectedLen, inputLen);
        return 0;
    }

    int isSame = 1;
    for (int i = 0; i < inputLen; i++) {
        if (input[i] != expected[i]) {
            printf("❌ FAIL: Arrays differ at index %d (expected %f, got %f)\n", i, expected[i], input[i]);
            return 0;
        }
    }

    if (boolean == IsNot) {
        printf("❌ FAIL: Expected arrays to be different, but they are identical\n");
        return 0;
    }

    printf("✅ PASS: Arrays are identical (length %f)\n", inputLen);
    return 1;
}



    int assertEqualLongArray(long input[], long inputLen, long expected[], long expectedLen, boolean boolean) {
        if (input == NULL || expected == NULL) {
            printf("❌ FAIL: One of the input arrays is NULL\n");
            return 0;
        }

        if (inputLen != expectedLen) {
            printf("❌ FAIL: Expected length %lf but got %lf\n", expectedLen, inputLen);
            return 0;
        }

        int isSame = 1;
        for (int i = 0; i < inputLen; i++) {
            if (input[i] != expected[i]) {
                printf("❌ FAIL: Arrays differ at index %d (expected %lf, got %lf)\n", i, expected[i], input[i]);
                return 0;
            }
        }

        if (boolean == IsNot) {
            printf("❌ FAIL: Expected arrays to be different, but they are identical\n");
            return 0;
        }

        printf("✅ PASS: Arrays are identical (length %lf)\n", inputLen);
        return 1;
    }

int assertCharContaining(char *input, char expected, boolean boolean) {
    if (input == NULL) {
        printf("❌ FAIL: Input string is NULL\n");
        return 0;
    }

    int i = 0;
    while (input[i] != '\0') {
        if (input[i] == expected) {
            if (boolean == IsNot) {
                printf("❌ FAIL: Expected %c to NOT be in the string, but found at index %d\n", expected, i);
                return 0;
            }
            printf("✅ PASS: Expected %c is in index %d\n", expected, i);
            return 1;
        }
        i++;
    }

    if (boolean == IsNot) {
        printf("✅ PASS: Expected %c is not in the string\n", expected);
        return 1;
    }

    printf("❌ FAIL: Expected char %c doesn't exist in the string\n", expected);
    return 0;
}

int assertStrContainingStr(char *input, char *expected, boolean boolean) {
    if (input == NULL || expected == NULL) {
        printf("❌ FAIL: One of the inputs is NULL\n");
        return 0;
    }

    int inputLen = strlen(input);
    int expectedLen = strlen(expected);

    if (expectedLen == 0) {
        printf("❌ FAIL: Expected string is empty\n");
        return 0;
    }

    if (inputLen < expectedLen) {
        if (boolean == IsNot) {
            printf("✅ PASS: Expected string '%s' does not exist in input (input is shorter)\n", expected);
            return 1;
        }
        printf("❌ FAIL: Input string is shorter than expected string\n");
        return 0;
    }

    for (int i = 0; i <= inputLen - expectedLen; i++) {
        if (strncmp(&input[i], expected, expectedLen) == 0) {
            if (boolean == IsNot) {
                printf("❌ FAIL: Expected string '%s' found at index %d, but should not exist\n", expected, i);
                return 0;
            }
            printf("✅ PASS: Expected string '%s' found at index %d\n", expected, i);
            return 1;
        }
    }

    if (boolean == IsNot) {
        printf("✅ PASS: Expected string '%s' does not exist in input\n", expected);
        return 1;
    }

    printf("❌ FAIL: Expected string '%s' not found\n", expected);
    return 0;
}



int assertIntArrayContainingInt(int input[], int inputLen, int expected, boolean boolean) {
    for (int i = 0; i < inputLen; i++) {
        if (input[i] == expected) {
            if (boolean == IsNot) {
                printf("❌ FAIL: Expected Int %d found at index %d, but it should not exist\n", expected, i);
                return 0;
            }
            printf("✅ PASS: Expected Int %d found at index %d\n", expected, i);
            return 1;
        }
    }

    if (boolean == IsNot) {
        printf("✅ PASS: Expected Int %d is not in array\n", expected);
        return 1;
    }

    printf("❌ FAIL: Expected %d not in Array\n", expected);
    return 0;
}

int assertDoubleArrayContainingDouble(double input[], int inputLen, double expected, boolean boolean) {
    for (int i = 0; i < inputLen; i++) {
        if (input[i] == expected) {
            if (boolean == IsNot) {
                printf("❌ FAIL: Expected Int %f found at index %d, but it should not exist\n", expected, i);
                return 0;
            }
            printf("✅ PASS: Expected Int %f found at index %d\n", expected, i);
            return 1;
        }
    }

    if (boolean == IsNot) {
        printf("✅ PASS: Expected Int %f is not in array\n", expected);
        return 1;
    }

    printf("❌ FAIL: Expected %f not in Array\n", expected);
    return 0;
    }


int assertLongArrayContainingLong(long input[], int inputLen, long expected, boolean boolean) {
    for (int i = 0; i < inputLen; i++) {
        if (input[i] == expected) {
            if (boolean == IsNot) {
                printf("❌ FAIL: Expected Int %ld found at index %d, but it should not exist\n", expected, i);
                return 0;
            }
            printf("✅ PASS: Expected Int %ld found at index %d\n", expected, i);
            return 1;
        }
    }

    if (boolean == IsNot) {
        printf("✅ PASS: Expected Int %ld is not in array\n", expected);
        return 1;
    }

    printf("❌ FAIL: Expected %ld not in Array\n", expected);
    return 0;
}

int assertMallocIsNotNull(void *input, boolean boolean) {
    if (input == NULL) {
        if (boolean == IsNot) {
            printf("✅ PASS: Expected Location is NULL (as expected)\n");
            return 1;
        }
        printf("❌ FAIL: Memory Allocation has failed (NULL pointer)\n");
        return 0;
    }
    if (boolean == IsNot) {
        printf("✅ PASS: Expected Location is not NULL (as expected)\n");
        return 1;
    }
    printf("✅ PASS: Expected Location %p exists\n", input);
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
        // // 문자열 비교 테스트
        // assertEqualString("hello", "hello", IsNot);  // 서로 다를 때 실패
        // assertEqualString("hello", "worl", IsNot);   // 같은 길이로 다른 문자열
        // assertEqualString("test", "test", null);    // 같은 문자열
        //
        // // 정수 비교 테스트
        // assertEqualInt(10, 10, null);  // 값이 같을 때
        // assertEqualInt(10, 5, null);   // 값이 다를 때
        // assertEqualInt(100, 200, IsNot);  // 값이 다를 때 IsNot 모드
        //
        // // 문자열 길이 비교
        // assertEqualCharLen("hello", "world", null); // 길이가 같을 때
        // assertEqualCharLen("hi", "hello", null);    // 길이가 다를 때
        // assertEqualCharLen(NULL, "test", null);     // NULL 처리

        // 배열 비교
        int intArray[3] = {1, 2, 3};
        int intArray2[3] = {1, 2, 3};
        int intArray3[2] = {1, 2};
        int intArray4[3] = {1, 2, 4};

        assertEqualIntArray(intArray, 3, intArray2, 3, null);  // 배열이 같을 때
        assertEqualIntArray(intArray, 3, intArray3, 2, null);  // 길이가 다를 때
        assertEqualIntArray(intArray, 3, intArray4, 3, null);  // 값이 다를 때

        // 문자 포함 여부 테스트
        assertCharContaining("hello", 'o', null);  // 문자가 있을 때
        assertCharContaining("hello", 'q', null);  // 문자가 없을 때

        // 문자열 포함 여부 테스트
        assertStrContainingStr("hello", "ll", IsNot);  // 부분 문자열이 있을 때
        assertStrContainingStr("hello", "qq", IsNot);  // 부분 문자열이 없을 때

        // 메모리 할당 확인
        int *test = malloc(sizeof(int));
        assertMallocIsNotNull(NULL, null);  // 메모리 할당이 성공했을 때
        free(test);
        try();  // 예외 처리 테스트
    } else {
        // 예외 발생 후 후속 테스트
        int intArray5[10] = {1, 2, 4, 10, 20, 40, 50, 60, 70, 100};
        assertIntArrayContainingInt(intArray5, 10, 40, null);  // 배열에 값이 있을 때
        assertIntArrayContainingInt(intArray5, 10, 100, null); // 배열에 마지막 값이 있을 때
        assertIntArrayContainingInt(intArray5, 10, 44, null);  // 배열에 값이 없을 때
    }
}

int main(void) {
    runTests();
    return 0;
}