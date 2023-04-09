/* main.h */
#ifndef MAIN_H
#define MAIN_H

unsigned int binary_to_uint(const char *b);

#endif /* MAIN_H */

/* binary_to_uint.c */
#include "main.h"

unsigned int binary_to_uint(const char *b)
{
    unsigned int result = 0;
    int i;

    if (b == NULL)
        return 0;

    for (i = 0; b[i] != '\0'; i++)
    {
        if (b[i] == '0')
        {
            result <<= 1;
        }
        else if (b[i] == '1')
        {
            result <<= 1;
            result |= 1;
        }
        else
        {
            return 0;
        }
    }

    return result;
}

