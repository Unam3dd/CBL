#include "cbl.h"
#include <math.h>
#include <string.h>

int hex_chr_to_int(char c)
{
    if (c >= 'A' && c <= 'F')
        c = chr_to_lower(c);
    
    return ((c >= '0' && c <= '9') ? (c & 0xF) : (c >= 'a' && c <= 'f') ? (10 + (c - 'a')) : 0);
}

char int_to_hex_chr(int n)
{    
    return ((n < 10) ? (n + '0') : (n >= 10 && n <= 15) ? (((n - 10) + 'a')) : 0);
}

int hex_to_int(char *str, size_t size)
{
    int to_dec = 0, count = 0, i = 0;

    for (i = size - 1; i >= 0; i--)
        to_dec += hex_chr_to_int(str[i]) * pow(16, count++);

    return (to_dec);
}

uint8_t int_to_hex(int n, char *buffer, size_t size)
{
    if (!buffer)
        return (1);
    
    for (int i = 0; i < size && n; i++) {
        buffer[i] = int_to_hex_chr((n % 16));
        n /= 16;
    }

    strrev(buffer);

    return (0);
}


uint8_t encode_hex(char *str, char *output, size_t size_output)
{
    char tmp[0x10] = {0};

    while (*str) {
        
        if (int_to_hex(*(str)++, tmp, 0x10))
            return (1);
        
        strncat(output, tmp, size_output);
    }

    return (0);
}

uint8_t decode_hex(char *str, char *output, size_t size_output)
{
    char tmp = 0;
    char *origin = str;

    while (*str) {
        
        str += 2;
        tmp = *str;
        *str = 0;
        
        *output = hex_to_int(origin, 2);
        output++;

        *str = tmp;
        origin = str;
    }

    return (0);
}