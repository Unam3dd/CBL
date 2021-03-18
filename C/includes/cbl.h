#pragma once
#include <stdint.h>

// utils.c
int to_int(char *str);
long long to_long_long(char *str);
uint8_t int_to_str(int dec, char *buffer, size_t size);
uint8_t long_long_to_str(long long dec, char *buffer, size_t size);
char chr_to_lower(char c);
char chr_to_upper(char c);
int reverse_integer(int n);
void convert_letter_in_upper(char *str);

// base16.c
int hex_chr_to_int(char c);
char int_to_hex_chr(int n);
int hex_to_int(char *str, size_t size);
uint8_t int_to_hex(int n, char *buffer, size_t size);
uint8_t encode_hex(char *str, char *output, size_t size_output);
uint8_t decode_hex(char *str, char *output, size_t size_output);

// base32.c
static char BASE32_TABLE[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', '2', '3', '4', '5', '6', '7'};

uint64_t get_base32_encoded_size(uint64_t len);
uint64_t get_base32_decoded_size(uint64_t len);
int return_index_base32(char c);
uint8_t base32_encode(char *buffer, char *output, uint64_t size_output);
uint8_t base32_decode(char *buffer, char *output, uint64_t size_output);


// base64.c
#define DECODING_TABLE_IS_NULL (DECODING_TABLE == NULL)

static char BASE64_TABLE[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '/'};

static unsigned char *DECODING_TABLE = NULL;

uint64_t get_base64_padded_size(uint64_t len);
uint64_t get_ascii_size_from_base64(uint64_t len);
uint32_t base64_encode(char *buffer, char *output, uint64_t len_output_buffer);
uint32_t base64_decode(char *buffer, char *output, uint64_t len_output_buffer);
void make_decoding_table(void);
void free_decoding_table(void);