#ifndef ROFI_DIALOG_SHARED_H
#define ROFI_DIALOG_SHARED_H

typedef struct range_pair {
    unsigned int start;
    unsigned int stop;
} range_pair;


/**
 * @param input  String to parse.
 * @param list   List of ranges.
 * @param length Length of ranges.
 *
 * ranges.
 */
void parse_ranges ( char *input, struct range_pair **list, unsigned int *length );




/**
 * @param array Bit array.
 * @param index Index of bit to get.
 *
 * Efficient bit storage.
 *
 * @retuns returns 1 if the bit is set, 0 if not.
 */
unsigned int bitget ( uint32_t *array, unsigned int index );

/**
 * @param array Bit array.
 * @param index Index of bit to set.
 *
 * Set/unset bit in array.
 */
void bittoggle ( uint32_t *array, unsigned int index );

#endif // ROFI_DIALOG_SHARED_H
