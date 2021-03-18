# CBL
CBL is a library containing hexadecimal (base16), base32, and base64 encoding, the implementation is written in C and C++


### the library is compatible with MSVC here are the build steps :
  open "x64 Native Tools Command Prompt for VS 2019", then navigate to the root of the CBL folder then choose the version you want to build "C" or "C++" then do the following command "nmake all" this command will simply create the library that will be at the end of the compilation in the lib directory and which is named cbl_x64. lib, then you can create your main file or take as example the given file then compile it with the following command "cl.exe /TC example\main.c /link cbl_x64.lib" then launch the program.
 
 
 ### Exemple :
 
```c
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
```
