#include <stdint.h>

typedef struct {
    uint32_t HEAT;
    uint32_t COOL;
    uint32_t FAN;
    uint32_t FAULT;
    uint32_t MODE;
    int32_t SETPOINT;
} status_t;

status_t status_unpack(uint32_t word);