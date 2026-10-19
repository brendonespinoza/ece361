#include <stddef.h>

//A pointer library which uses only pointer arithmetic to manipulate arrays of floats.

void swap_float(float *a, float *b){
    ///exchanges *a and *b
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

int minmax(const float *a, int n, float *min, float *max){
    //Stores the smallest and largest of a[0..n-1] at *min and *max.
    //Returns 0 normally, or -1 if n < 1, or any pointer is NULL.

    //Null cases
    if(n < 1 || a == NULL || min == NULL || max == NULL){
        return -1;
    }

    //Initialize min and max with the first element
    *min = *max = *a;

    //Iterate through the array to find min and max
    for(const float *ptr = a; ptr < a + n; ++ptr){
        if(*ptr < *min){
            *min = *ptr;
        }
        if(*ptr > *max){
            *max = *ptr;
        }
    }

    return 0;
}

const float *find_above(const float *a, int n, float threshold){
    //Returns a pointer to the first element of a[0..n-1] that is greater than threshold.
    //Returns NULL if no such element exists or if any pointer is NULL.

    //Null cases
    if(a == NULL || n < 1){
        return NULL;
    }

    //Iterate through the array to find the first element greater than threshold
    for(const float *ptr = a; ptr < a + n; ++ptr){
        if(*ptr > threshold){
            return ptr;
        }
    }

    return NULL; // No element found
}

void reverse(float *a, int n){
    //Reverses the order of a[0..n-1] in place.
    //Does nothing if n < 2 or a is NULL.

    //Null cases
    if(a == NULL || n < 2){
        return;
    }

    //Use two pointers to swap elements from both ends of the array
    float *start = a;
    float *end = a + n - 1;

    //Safety counter to prevent infinite loops in case of pointer arithmetic issues
    const int max_iterations = n/2 + 1;
    int iterations = 0;
    while(start < end && iterations <= max_iterations){
        swap_float(start, end);
        ++start;
        --end;
        ++iterations;
        
    }
}