#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(uint16_t x,
                 unsigned n)
{
    // YOUR CODE HERE
    unsigned y = x << (63 - n);
    y = y >> 63;
    // Returning -1 is a placeholder (it makes
    // no sense, because get_bit only returns
    // 0 or 1)
    return y;
}

// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(uint16_t *x,
             unsigned n,
             unsigned v)
{
    // YOUR CODE HERE
    // set the nth bit of x to 0
    *x &= (~(1 << n));
    // set the nth bit of x to v
    *x |= (v << n);
}

// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void flip_bit(unsigned *x,
              unsigned n)
{
    // YOUR CODE HERE
    unsigned y = 1 << n;
    (*x) ^= y;
}

void lfsr_calculate(uint16_t *reg)
{

    /* YOUR CODE HERE */
    unsigned int tmp = *reg;
    /*
    unsigned int x11 = tmp << 10 >> 15;
    unsigned int x13 = tmp << 12 >> 15;
    unsigned int x14 = tmp << 13 >> 15;
    unsigned int x16 = tmp << 15 >> 15;
    // *reg >> 1;
    */
    unsigned int x11 = get_bit(tmp, 5);
    unsigned int x13 = get_bit(tmp, 3);
    unsigned int x14 = get_bit(tmp, 2);
    unsigned int x16 = get_bit(tmp, 0);
    unsigned int x1 = (x11 ^ (x13 ^ (x14 ^ x16)));
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