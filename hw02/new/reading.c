#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reading.h"

#define LINE_LEN     128

struct reading read_data(void){
    char line[LINE_LEN];
    int count = 0;
    int skipped = 0;
    struct reading data;

    while (fgets(line, sizeof line, stdin) != NULL) {
        int i = 0;
        while (line[i] == ' ' || line[i] == '\t')
            i++;
        if (line[i] == '\n' || line[i] == '\0' || line[i] == '#')
            continue;
        if (count == MAX_READINGS) {
            fprintf(stderr, "warning: more than %d readings, the rest are ignored\n", MAX_READINGS);
            break;
        }
        if (sscanf(line, "%d %f %f", &data.ticks[count], &data.temps[count], &data.hums[count]) == 3)
        {
            count++;
        }
        else
            skipped++;
    }

    data.count = count;

    printf("readings: %d\n", count);
    printf("skipped:  %d\n", skipped);
    if (count == 0) {
        printf("no readings, no summary\n");
    }

    return data;
}