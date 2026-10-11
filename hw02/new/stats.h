struct statistics
{
    int min;
    int max;
    int mean;
    int longest_run;
};

struct statistics calculate_statistics(float *data, int length, float threshold);