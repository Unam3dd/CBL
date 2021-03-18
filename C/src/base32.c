#include "cbl.h"
#include <stdlib.h>

uint64_t get_base32_encoded_size(uint64_t len)
{
    uint64_t bits = (len * 8);

    return (((bits % 5) > 0) ? (bits / 5) + 1 : (bits / 5));
}


uint64_t get_base32_decoded_size(uint64_t len)
{
    return ((len * 5) / 8);
}


uint8_t base32_encode(char *buffer, char *output, uint64_t size_output)
{
    if (!buffer || size_output == 0)
        return (1);
    
    if (size_output < get_base32_encoded_size(strlen(buffer)))
        return (1);
    
    unsigned long long bits = 0, value = 0, i = 0;

    while (*buffer) {

        if (*buffer == ' ' && *buffer == '\r' && *buffer == '\n' && *buffer == '-')
            continue;

        value = (value << 8) | *(buffer)++;
        bits += 8;
        
        while (bits >= 5 && i < size_output) {
            
            output[i++] = BASE32_TABLE[(value >> (bits - 5)) & 0x1F];

            bits -= 5;
        }
    }

    if (bits)
        output[i++] = BASE32_TABLE[(value << (5 - bits)) & 0x1F];
    
    while ((strlen(output) % 8) && (i < size_output)) {
        output[i++] = '=';
    }

    return (0);
}

int return_index_base32(char c)
{
    int i = 0;

    for (i; i < strlen(BASE32_TABLE); i++) 
        if (c == BASE32_TABLE[i])
            break;
    
    return (i);
}

uint8_t base32_decode(char *buffer, char *output, uint64_t size_output)
{
    if (!buffer || size_output == 0)
        return (1);
    
    if (size_output < get_base32_decoded_size(strlen(buffer)))
        return (1);
    
    unsigned long long value = 0, bits = 0, i = 0;

    while (*buffer && i < size_output) {
        
        if (*buffer == '=') {
            buffer++;
            continue;
        }

        value = ((value << 5) | return_index_base32(*buffer));
        bits += 5;

        if (bits >= 8) {
            output[i++] = (value >> (bits - 0x8)) & 0xFF;
            bits -= 8;
        }

        buffer++;
    }

    return (0);
}