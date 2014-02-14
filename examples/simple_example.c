// simple_example.c
//
// Copyright (c) 2014 Diego Jose Fernandez Hernandez
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../src/praw_utils.h"

void hexdump(void * ptr, size_t count, uint32_t offset) {
	uint8_t * bytes = (uint8_t *)ptr;
	for (size_t i = 0; i < count; i++) {
		printf("%02hhx ", bytes[i + offset]);
	}
}

int main(int argc, char ** argv){
	if (argc < 2) {
		printf("File not specified!\n");
		return EXIT_FAILURE;
	}
	
	FILE * fp = fopen(argv[1], "rb");	
	if (fp == NULL) {
		printf("Unable to open file!\n");
		return EXIT_FAILURE;
	}
	
	fseek(fp, 0, SEEK_END);
	long int fs = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	if (fs < 16) {
		printf("File too small!\n");
		return EXIT_FAILURE;
	}
	
	praw_byte_t bytes[16];
	if (fread(bytes, sizeof(praw_byte_t), 16, fp) != 16 * sizeof(praw_byte_t)) {
		printf("Unable to read file!\n");
		return EXIT_FAILURE;
	}
	
	printf("NAME: %s\n", argv[1]);
	printf("SIZE: %ld\n", fs);
	printf("BYTES: ");
	hexdump((void *)bytes, 8, 8);
	printf("\n\n---\n\n");
	
	printf("BE | int8_t    = %hhd\n", praw_parse_int8(bytes, 8));
	printf("BE | uint8_t   = %hhu\n", praw_parse_uint8(bytes, 8));
	printf("BE | int16_t   = %hd\n", praw_parse_int16(bytes, 8, CPU_BIG_ENDIAN));
	printf("BE | uint16_t  = %hu\n", praw_parse_uint16(bytes, 8, CPU_BIG_ENDIAN));
	printf("BE | int32_t   = %d\n", praw_parse_int32(bytes, 8, CPU_BIG_ENDIAN));
	printf("BE | uint32_t  = %u\n", praw_parse_uint32(bytes, 8, CPU_BIG_ENDIAN));
	printf("BE | int64_t   = %lld\n", praw_parse_int64(bytes, 8, CPU_BIG_ENDIAN));
	printf("BE | uint64_t  = %llu\n", praw_parse_uint64(bytes, 8, CPU_BIG_ENDIAN));
	printf("\n");
	printf("LE | int8_t    = %hhd\n", praw_parse_int8(bytes, 8));
	printf("LE | uint8_t   = %hhu\n", praw_parse_uint8(bytes, 8));
	printf("LE | int16_t   = %hd\n", praw_parse_int16(bytes, 8, CPU_LITTLE_ENDIAN));
	printf("LE | uint16_t  = %hu\n", praw_parse_uint16(bytes, 8, CPU_LITTLE_ENDIAN));
	printf("LE | int32_t   = %d\n", praw_parse_int32(bytes, 8, CPU_LITTLE_ENDIAN));
	printf("LE | uint32_t  = %u\n", praw_parse_uint32(bytes, 8, CPU_LITTLE_ENDIAN));
	printf("LE | int64_t   = %lld\n", praw_parse_int64(bytes, 8, CPU_LITTLE_ENDIAN));
	printf("LE | uint64_t  = %llu\n", praw_parse_uint64(bytes, 8, CPU_LITTLE_ENDIAN));
	
	return EXIT_SUCCESS;
}
