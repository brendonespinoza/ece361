#include "histogram.h"

#define BIN_WIDTH 5.0f
#define NUM_BINS 20

void print_histogram(float *temps) {
    /* histogram of temperatures, 5 C bins; values outside 0..100 go to the end bins */

    int bins[NUM_BINS] = {0};
    int count = 0;

    for (int i = 0; i < count; i++) {
        int b = (int) (temps[i] / BIN_WIDTH);
        // the index of the bin is the lowest natural near ratio of temperature to width

        if (temps[i] < 0.0f)
        // catch temperatures below 0 in lowest bin
            b = 0;
        if (b >= NUM_BINS)
        // catch temperatures above 100 in highest bin
            b = NUM_BINS - 1;
        bins[b]++; //place temperature i in bin number b
    }

    printf("histogram:\n");

    for (int b = 0; b < NUM_BINS; b++) {
        if (bins[b] == 0)
            continue;
        printf("  %5.1f to %5.1f C | ", b * BIN_WIDTH, (b + 1) * BIN_WIDTH);
        for (int k = 0; k < bins[b]; k++)
            putchar('*');
    }
}