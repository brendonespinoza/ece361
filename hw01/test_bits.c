#include <stdint.h>
#include <stdio.h>
#include "bits.h"
#include "status.h"

int aux() {
    unsigned int num = 0x2C;
    printf("The binary representation of %d is: ", num);
    print_binary(0x2C,10);

    uint32_t word = 0xFAFAFAFA;
    uint32_t width = 5;
    uint32_t pos = 8;
    uint32_t value = 0xFF;

    printf("get_field test: 0x%x, 0x%x \n",word,get_field(word,pos,width));

    printf("set_field test: 0x%x, 0x%x, 0x%x \n",word,value,set_field(word,pos,width,value));

    printf("sign_extend test: 0x%x, %d \n",value,sign_extend(value,width));

    return 0;
}
