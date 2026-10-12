#include <stdio.h>
#include <stdlib.h>
#include "../stats.h"

#define threshold 50.0
void main(void) {
    printf("single value\n");
    float values[] = {42.0};
    int count = 1;
    struct statistics single = calculate_statistics(values, 1, threshold);
    if (single.mean) printf("Single Mean PASS\n");
    if (single.min) printf("Single Min PASS\n");
    if (single.max) printf("Single Max PASS\n");

    printf("Max at start and end\n");
    float values[] = {42.0,0,42.0};
    int count = 3;
    struct statistics single = calculate_statistics(values, 1, threshold);
    if (single.mean) printf("Maxs Mean PASS\n");
    if (single.min) printf("Maxs Min PASS\n");
    if (single.max) printf("Maxs Max PASS\n");

    printf("Exact threshold\n");
    float values[] = {threshold+1,threshold+2,threshold};
    int count = 3;
    struct statistics single = calculate_statistics(values, 1, threshold);
    if (single.mean) printf("Thresh Mean PASS\n");
    if (single.min) printf("Thresh Min PASS\n");
    if (single.max) printf("Thresh Max PASS\n");

    printf("Ten-thousand entry array\n");
    float values[10000];
    for (int i = 0; i < 10000; i++) {
        values[i] = 42.0f;
    }
    struct statistics result = calculate_statistics(values, 10000, threshold);
    if (single.mean) printf("TenThou Mean PASS\n");
    if (single.min) printf("TenThou Min PASS\n");
    if (single.max) printf("TenThou Max PASS\n");
}

