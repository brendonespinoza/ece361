#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reading.h"
#include "stats.h"

#define LINE_LEN     128

int main(int argc, char *argv[]) {
    char line[LINE_LEN];
    float threshold = 30.0f;

    if (argc > 2) {
        fprintf(stderr, "usage: %s [threshold] < readings.txt\n", argv[0]);
        return 1;
    }
    if (argc == 2) {
        char *end;
        threshold = strtof(argv[1], &end);
        if (*end != '\0') {
            fprintf(stderr, "error: threshold '%s' is not a number\n", argv[1]);
            return 1;
        }
    }

    struct reading data = read_data();
    struct statistics hum_stats = calculate_statistics(data.hums, MAX_READINGS, threshold);
    struct statistics temp_stats = calculate_statistics(data.temps, MAX_READINGS, threshold);

    printf("Humidity Statistics:\n");
    printf("  Min: %d ", hum_stats.min);
    printf("  Max: %d ", hum_stats.max);
    printf("  Mean: %d %%RH\n", hum_stats.mean);
    printf("Temperature Statistics:\n");
    printf("  Min: %d ", temp_stats.min);
    printf("  Max: %d ", temp_stats.max);
    printf("  Mean: %d °C\n", temp_stats.mean);
    printf("  longest run: %d\n", temp_stats.longest_run);

    print_histogram(data.temps, MAX_READINGS);


    return 0;
}