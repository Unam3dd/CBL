#include "cbl.h"

uint8_t hex_nibble(char c)
{
    if (c >= 'A' && c <= 'F')
        c = c | 0x20;
    
    return ((c >= '0' && c <= '9') ? (c & 0xF) : (c >= 'a' && c <= 'f') ? (10 + (c - 'a')) : 0);
}

uint8_t hex_encode(char *str, char *output, size_t output_size)
{
    if ((string_len(str) << 1) > output_size)
        return (1);
    
    while (*str) {

        *(output)++ = BASE16_TABLE[*str >> 4];
        *(output)++ = BASE16_TABLE[*str & 0xF];
        
        str++;
    }

    *output = 0;
    
    return (0);
}

uint8_t hex_decode(char *str, char *output, size_t output_size)
{
    if ((string_len(str) >> 1) > output_size)
        return (1);
    
    while (*str) {
        
        *output = hex_nibble(*(str)++);
        
        *output <<= 4;
        
        *output += hex_nibble(*(str)++);
        
        output++;
    }

    *output = 0;

    return (0);
}
