struct statistics
{
    float min;
    float max;
    float mean;
    int longest_run;
};

struct statistics calculate_statistics(float *data, int length, float threshold);