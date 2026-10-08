#include "status.h"
#include "bits.h"

status_t status_unpack(uint32_t word) {
    status_t s;
    s.HEAT = get_field(word,0,1);
    s.COOL = get_field(word,1,1);
    s.FAN = get_field(word,2,1);
    s.FAULT = get_field(word,3,1);
    s.MODE = get_field(word,4,3);
    s.SETPOINT = sign_extend(get_field(word,8,8),8);
    return s;
};