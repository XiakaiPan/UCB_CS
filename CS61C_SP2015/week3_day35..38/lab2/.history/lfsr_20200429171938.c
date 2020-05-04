#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "bit_ops copy.h"

void lfsr_calculate(uint16_t *reg)
{

    /* YOUR CODE HERE */
    uint16_t tmp = *reg;
    uint16_t x11 = get_bit(tmp, 5);
    uint16_t x13 = get_bit(tmp, 3);
    uint16_t x14 = get_bit(tmp, 2);
    uint16_t x16 = get_bit(tmp, 0);
    uint16_t x1 = (x11 ^ (x13 ^ (x14 ^ x16)));
    set_bit(reg, 15, 0);
    *reg |= x1 << 15;
}

int main()
{
    int8_t *numbers = (int8_t *)malloc(sizeof(int8_t) * 65535);
    if (numbers == NULL)
    {
        printf("Memory allocation failed!");
        exit(1);
    }

    memset(numbers, 0, sizeof(int8_t) * 65535);
    uint16_t reg = 0x1;
    uint32_t count = 0;
    int i;

    do
    {
        count++;
        numbers[reg] = 1;
        if (count < 24)
        {
            printf("My number is: %u\n", reg);
        }
        else if (count == 24)
        {
            printf(" ... etc etc ... \n");
        }
        for (i = 0; i < 32; i++)
            lfsr_calculate(&reg);
    } while (numbers[reg] != 1);

    printf("Got %u numbers before cycling!\n", count);

    if (count == 65535)
    {
        printf("Congratulations! It works!\n");
    }
    else
    {
        printf("Did I miss something?\n");
    }

    free(numbers);

    return 0;
}