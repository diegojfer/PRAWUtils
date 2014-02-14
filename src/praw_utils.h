// praw_utils.h
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
#ifndef __PRAW_UTILS_H
#define __PRAW_UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define CPU_BIG_ENDIAN ((praw_endianness_t)(0 == 1))
#define CPU_LITTLE_ENDIAN ((praw_endianness_t)(0 == 0))

typedef uint8_t praw_byte_t;
typedef uint8_t praw_boolean_t;
typedef uint8_t praw_endianness_t;

typedef uint8_t praw_uint8_t;
typedef uint16_t praw_uint16_t;
typedef uint32_t praw_uint32_t;
typedef uint64_t praw_uint64_t;

typedef int8_t praw_int8_t;
typedef int16_t praw_int16_t;
typedef int32_t praw_int32_t;
typedef int64_t praw_int64_t;

praw_endianness_t praw_check_endianness();

praw_int8_t praw_parse_int8(praw_byte_t * buffer, praw_uint32_t offset);
praw_int16_t praw_parse_int16(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness);
praw_int32_t praw_parse_int32(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness);
praw_int64_t praw_parse_int64(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness);

praw_uint8_t praw_parse_uint8(praw_byte_t * buffer, praw_uint32_t offset);
praw_uint16_t praw_parse_uint16(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness);
praw_uint32_t praw_parse_uint32(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness);
praw_uint64_t praw_parse_uint64(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness);

#endif
