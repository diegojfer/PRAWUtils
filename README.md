# PRAWUtils

Utils to decode raw bytes buffer into integers.

## Functions
```c
// Check runtime cpu endianness.
// Returns CPU_LITTE_ENDIAN or CPU_BIG_ENDIAN
praw_endianness_t praw_check_endianness();

// Functions to parse signed integers.
praw_int8_t praw_parse_int8(praw_byte_t * buffer, praw_uint32_t offset);
praw_int16_t praw_parse_int16(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness);
praw_int32_t praw_parse_int32(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness);
praw_int64_t praw_parse_int64(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness);

// Functions to parse unsigned integers.
praw_uint8_t praw_parse_uint8(praw_byte_t * buffer, praw_uint32_t offset);
praw_uint16_t praw_parse_uint16(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness);
praw_uint32_t praw_parse_uint32(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness);
praw_uint64_t praw_parse_uint64(praw_byte_t * buffer, praw_uint32_t offset, praw_endianness_t endianness);
```

## SimpleExample
1. Compile simple example.
2. Create or select random input file.
4. Use it!

```c
./simple_example examples/simple_binary.bin
```

![Simple Example](https://raw.githubusercontent.com/diegojfer/PRAWUtils/master/examples/simple_screenshot.png)
