#include <stddef.h>

//A pointer library which uses only pointer arithmetic to manipulate arrays of floats.

void swap_float(float *a, float *b);

int minmax(const float *a, int n, float *min, float *max);

const float *find_above(const float *a, int n, float threshold);

void reverse(float *a, int n);