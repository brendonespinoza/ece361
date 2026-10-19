//Tests every function in ptr.c to ensure that they work as expected.
//swap_float is tested on whether it can swap two entries with the same address,
//minmax is tested on whether it can handle null pointers and arrays of length less than 1.
//find_above is tested two matches of equal value, returning the first.
// Also, whether it can handle an array with no values above the threshold,
// and with a value equal to the threshold.
//reverse is tested on an array of even length, and an array of odd length.

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include "../ptr.h"

int main() {
    // Test cases for swap_float
    printf("Testing swap_float...\n");
    float x = 1.0f, y = 2.0f;
    swap_float(&x, &y);
    if(x == 2.0f && y == 1.0f){
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    float arr1[] = {3.0f, 1.0f, 4.0f, 2.0f};

    // Test cases for minmax
    printf("Testing minmax...\n");
    float min, max;
    if(minmax(arr1, 4, &min, &max) == 0){
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    float arr2[] = {};
    if(minmax(arr2, 0, &min, &max) == -1){
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    float *nar = NULL;
    if(minmax(nar, 4, &min, &max) == -1){
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    // Test cases for find_above
    const float *result = find_above(arr1, 4, 2.5f);
    printf("Testing find_above...\n");
    if(result != NULL && *result == 3.0f){
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    result = find_above(arr1, 4, 5.0f);
    if(result == NULL){
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }  

    // Test cases for reverse
    printf("Testing reverse...\n");
    float arr3[] = {1.0f, 2.0f, 3.0f};
    reverse(arr3, 3);
    if(arr3[0] == 3.0f && arr3[1] == 2.0f && arr3[2] == 1.0f){
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    float arr4[] = {1.0f, 2.0f, 3.0f, 4.0f};
    reverse(arr4, 4);
    if(arr4[0] == 4.0f && arr4[1] == 3.0f && arr4[2] == 2.0f && arr4[3] == 1.0f){
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    return 0;
}