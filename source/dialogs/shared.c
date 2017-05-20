#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <glib.h>
#include <dialogs/shared.h>

static inline void parse_pair ( char  *input, struct range_pair  *item );

void parse_ranges ( char *input, struct range_pair **list, unsigned int *length )
{
    char *endp;
    if ( input == NULL ) {
        return;
    }
    const char *const sep = ",";
    for ( char *token = strtok_r ( input, sep, &endp ); token != NULL; token = strtok_r ( NULL, sep, &endp ) ) {
        // Make space.
        *list = g_realloc ( ( *list ), ( ( *length ) + 1 ) * sizeof ( struct range_pair ) );
        // Parse a single pair.
        parse_pair ( token, &( ( *list )[*length] ) );

        ( *length )++;
    }
}

static inline void parse_pair ( char  *input, struct range_pair  *item )
{
    int                index = 0;
    const char * const sep   = "-";
    for ( char *token = strsep ( &input, sep ); token != NULL; token = strsep ( &input, sep ) ) {
        if ( index == 0 ) {
            item->start = item->stop = (unsigned int) strtoul ( token, NULL, 10 );
            index++;
        }
        else {
            if ( token[0] == '\0' ) {
                item->stop = 0xFFFFFFFF;
            }
            else{
                item->stop = (unsigned int) strtoul ( token, NULL, 10 );
            }
        }
    }
}

unsigned int bitget ( uint32_t *array, unsigned int index )
{
    uint32_t bit = index % 32;
    uint32_t val = array[index / 32];
    return ( val >> bit ) & 1;
}

void bittoggle ( uint32_t *array, unsigned int index )
{
    uint32_t bit = index % 32;
    uint32_t *v  = &array[index / 32];
    *v ^= 1 << bit;
}
