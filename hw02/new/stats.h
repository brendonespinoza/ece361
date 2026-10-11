struct statistics
{
    int min;
    int max;
    int mean;
    int longest_run;
};

struct statistics calculate_statistics(int data[], int length, int threshold);