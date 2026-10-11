#include "stats.h"

struct statistics calculate_statistics(int data[], int length, int threshold){
    // Find the minimum, maximum, mean, and longest run above the threshold
    int min = data[0];
    int max = data[0];
    int sum = 0;
    int run = 0;
    int longest_run = 0;
    for (int i = 0; i < length; i++)
    {
        if (data[i] < min) min = data[i];
        if (data[i] > max) max = data[i];
        sum += data[i];
        if (data[i] > threshold) {
            run++;
        } else {
            if (run > longest_run) longest_run = run;
            run = 0;
        }
    }
    if (run > longest_run) longest_run = run; // catch for if the longest run involves the end of the array
    struct statistics result;
    result.min = min;
    result.max = max;
    result.mean = sum / length;
    result.longest_run = longest_run;
    return result;
}