#include "histogram.h"

#define BIN_WIDTH 5.0f
#define NUM_BINS 20

void print_histogram(float *temps, int count) {
    /* histogram of temperatures, 5 C bins; values outside 0..100 go to the end bins */

    int bins[NUM_BINS] = {0};

    for (int i = 0; i < count; i++) {
        int b = (int) (temps[i] / BIN_WIDTH);
        // the index of the bin is the lowest natural near ratio of temperature to width
        if (temps[i] < 0.0f) b = 0;  // catch temperatures below 0 in lowest bin
        if (b >= NUM_BINS) b = NUM_BINS - 1; // catch temperatures above 100 in highest bin
        bins[b]++; //place temperature i in bin number b
    }

    for (int b = 0; b < NUM_BINS; b++) {
        if (bins[b] == 0){
            printf("  %5.1f to %5.1f C | \n", b * BIN_WIDTH, (b + 1) * BIN_WIDTH);
            continue;
        }
        printf("  %5.1f to %5.1f C | \n", b * BIN_WIDTH, (b + 1) * BIN_WIDTH);
        for (int k = 0; k < bins[b]; k++)
            putchar('*');
    }
}