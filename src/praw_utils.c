// praw_utils.c
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
#include "praw_utils.h"

praw_endianness_t praw_check_endianness() {
    volatile uint32_t i = 0x01234567;
    // return 0 for big endian, 1 for little endian.
    return (*((uint8_t*)(&i))) == 0x67;
}

praw_int8_t praw_parse_int8(praw_byte_t * buffer, praw_uint32_t offset) {
	return (praw_int8_t)*(buffer + offset);
}
praw_uint8_t praw_parse_uint8(praw_byte_t * buffer, praw_uint32_t offset) {
	return (praw_uint8_t)*(buffer + offset);
}

praw_int16_t praw_parse_int16(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness) {
	praw_byte_t data[2];
	
	if (praw_check_endianness() == endianness) {
		data[0] = *(buffer + offset);
		data[1] = *(buffer + offset + 1);
	} else {
		data[0] = *(buffer + offset + 1);
		data[1] = *(buffer + offset);
	}
	
	return *((praw_int16_t *)data);
}
praw_uint16_t praw_parse_uint16(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness) {
	praw_byte_t data[2];
	
	if (praw_check_endianness() == endianness) {
		data[0] = *(buffer + offset + 0);
		data[1] = *(buffer + offset + 1);
	} else {
		data[0] = *(buffer + offset + 1);
		data[1] = *(buffer + offset + 0);
	}
	
	return *((praw_uint16_t *)data);
}

praw_int32_t praw_parse_int32(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness) {
	praw_byte_t data[4];
	
	if (praw_check_endianness() == endianness) {
		data[0] = *(buffer + offset + 0);
		data[1] = *(buffer + offset + 1);
		data[2] = *(buffer + offset + 2);
		data[3] = *(buffer + offset + 3);
	} else {
		data[0] = *(buffer + offset + 3);
		data[1] = *(buffer + offset + 2);
		data[2] = *(buffer + offset + 1);
		data[3] = *(buffer + offset + 0);
	}
	
	return *((praw_int32_t *)data);
}
praw_uint32_t praw_parse_uint32(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness) {
	praw_byte_t data[4];
	
	if (praw_check_endianness() == endianness) {
		data[0] = *(buffer + offset + 0);
		data[1] = *(buffer + offset + 1);
		data[2] = *(buffer + offset + 2);
		data[3] = *(buffer + offset + 3);
	} else {
		data[0] = *(buffer + offset + 3);
		data[1] = *(buffer + offset + 2);
		data[2] = *(buffer + offset + 1);
		data[3] = *(buffer + offset + 0);
	}
	
	return *((praw_uint32_t *)data);
}


praw_int64_t praw_parse_int64(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness) {
	praw_byte_t data[8];
	
	if (praw_check_endianness() == endianness) {
		data[0] = *(buffer + offset + 0);
		data[1] = *(buffer + offset + 1);
		data[2] = *(buffer + offset + 2);
		data[3] = *(buffer + offset + 3);
		data[4] = *(buffer + offset + 4);
		data[5] = *(buffer + offset + 5);
		data[6] = *(buffer + offset + 6);
		data[7] = *(buffer + offset + 7);
	} else {
		data[0] = *(buffer + offset + 7);
		data[1] = *(buffer + offset + 6);
		data[2] = *(buffer + offset + 5);
		data[3] = *(buffer + offset + 4);
		data[4] = *(buffer + offset + 3);
		data[5] = *(buffer + offset + 2);
		data[6] = *(buffer + offset + 1);
		data[7] = *(buffer + offset + 0);
	}
	
	return *((praw_int64_t *)data);
}
praw_uint64_t praw_parse_uint64(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness) {
	praw_byte_t data[8];
	
	if (praw_check_endianness() == endianness) {
		data[0] = *(buffer + offset + 0);
		data[1] = *(buffer + offset + 1);
		data[2] = *(buffer + offset + 2);
		data[3] = *(buffer + offset + 3);
		data[4] = *(buffer + offset + 4);
		data[5] = *(buffer + offset + 5);
		data[6] = *(buffer + offset + 6);
		data[7] = *(buffer + offset + 7);
	} else {
		data[0] = *(buffer + offset + 7);
		data[1] = *(buffer + offset + 6);
		data[2] = *(buffer + offset + 5);
		data[3] = *(buffer + offset + 4);
		data[4] = *(buffer + offset + 3);
		data[5] = *(buffer + offset + 2);
		data[6] = *(buffer + offset + 1);
		data[7] = *(buffer + offset + 0);
	}
	
	return *((praw_uint64_t *)data);
}