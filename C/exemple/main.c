#include "cbl.h"
#include <stdio.h>

int main(void)
{
    char buffer[] = "Hello World";

    char output[0xFF] = {0};
    char output_[0xFF] = {0};

    if (encode_hex(buffer, output, 0xFF))
        return (1);
    
    printf("Encoded in Base16 (Hexadecimal) : %s\n", output);
    convert_letter_in_upper(output);
    printf("Uppercase Mode : %s\n", output);

    if (decode_hex(output, output_, 0xFF))
        return (1);
    
    printf("Decoded in Base16 (Hexadecimal) : %s\n", output_);

    memset(output, 0, sizeof(output));
    memset(output_, 0, sizeof(output_));

    if (base64_encode(buffer, output, 0xFF))
        return (1);
    
    printf("Encoded in Base64 : %s\n", output);

    if (base64_decode(output, output_, 0xFF))
        return (1);
    
    printf("Decoded in Base64 : %s\n", output_);

    memset(output, 0, sizeof(output));
    memset(output_, 0, sizeof(output_));

    if (base32_encode(buffer, output, 0xFF))
        return (1);
    
    printf("Encoded in Base32 : %s\n", output);

    if (base32_decode(output, output_, 0xFF))
        return (1);
    
    printf("Decoded in Base32 : %s\n", output_);

    

    return (0);
}