#define MAX_READINGS 1000

struct reading
{
    int ticks[MAX_READINGS];
    float temps[MAX_READINGS];
    float hums[MAX_READINGS];
};

struct reading read_data(void);