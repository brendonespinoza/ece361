#include <stdint.h>
#include <stdio.h>
#include "bits.h"
#include "status.h"

void print_binary(uint32_t x, int width) {
//Prints the lowest width bits of x, most significant bit first, in
//groups of four separated by a space. print_binary(0x2C,
//8) prints 0010 1100.

    for (int i = width - 1; i >= 0; i--) {
        // Shift the target bit all the way to the right and mask it with 1
        int bit = (x >> i) & 1;

        if (((i+1)%4 == 0)&&((i+1)!=width)) {
            printf(" "); // Print a space
        }

        printf("%d", bit); // Print bit

        if (i==0) {
            printf("\n"); // New line
        }
    }
}

uint32_t get_field(uint32_t word, int pos, int width) {
//Returns bits pos to pos+width-1 of word, shifted down to
//bit 0.

    return (word>>(pos-1))&(~(0xFFFFFFFF<<width));
}

uint32_t set_field(uint32_t word, int pos, int width, uint32_t value) {
//Returns word with bits pos to pos+width-1 replaced by the
//lowest width bits of value. All other bits are unchanged.

    uint32_t x = value<<(32-width);
    x = x>>(32-pos-width+1);
    uint32_t mask = 0xFFFFFFFF<<(32-width);
    mask = ~(mask>>(32-pos-width+1));

    return (mask & word)|x;

}

int32_t sign_extend(uint32_t value, int width) {
//Interprets the lowest width bits of value as a two’s
//complement number and returns it as an int32_t.
//sign_extend(0xF8, 8) returns -8.

    value = value<<(32-width);
    if (value&&0x80000000){
        uint32_t mask = 0xFFFFFFFF;
        mask = mask>>width;
        mask = mask<<width;
        value = value>>(32-width);
        return value|mask;
    }
    return value>>(32-width);
    
}

int main() {
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

    status_t s = status_unpack(word);

    printf("status test:\n 0x%x,\n 0x%x,\n 0x%x,\n 0x%x,\n 0x%x,\n 0x%x\n",s.HEAT,s.COOL,s.FAN,s.FAULT,s.MODE,s.SETPOINT);
    return 0;
}