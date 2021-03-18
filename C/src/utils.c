#include "cbl.h"


// Convert str to int
int to_int(char *str)
{
    int to_dec = 0;

    while (*str) {
        to_dec *= 10;
        to_dec += *(str)++ & 0xF;
    }

    return (to_dec);
}

// Convert str to long
long long to_long_long(char *str)
{
    long long to_long = 0;

    while (*str) {
        to_long *= 10;
        to_long += *(str)++ & 0xF;
    }

    return (to_long);
}


// convert int to str

uint8_t int_to_str(int dec, char *buffer, size_t size)
{
    if (!buffer)
        return (1);
    
    for (int i = 0; dec && i < size ; i++) {
        buffer[i] = (dec % 10) + '0';
        dec /= 10;
    }

    return (0);
}

// convert long long to str
uint8_t long_long_to_str(long long dec, char *buffer, size_t size)
{
    if (!buffer)
        return (1);
    
    for (int i = 0; dec && i < size ; i++) {
        buffer[i] = (dec % 10) + '0';
        dec /= 10;
    }

    return (0);
}

char chr_to_lower(char c) { return (c | 32); }

char chr_to_upper(char c) { return (c - 32); }

int reverse_integer(int n)
{
    int n_dec = 0;

    while (n) {
        n_dec *= 10;
        n_dec += (n % 10);
        n /= 10;
    }

    return (n_dec);
}

void convert_letter_in_upper(char *str)
{
    while (*str) {
        *str = (*str >= 'a' && *str <= 'z') ? (*str - 32) : *str;
        str++;
    }
}