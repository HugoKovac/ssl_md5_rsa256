#ifndef MD5_H
#define MD5_H

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_md5
{
    int32_t *message; // * 16
    int32_t *cipher;  // * 4

    int32_t *a; // = cipher + 32bits * 0
    int32_t *b; // = cipher + 32bits * 1
    int32_t *c; // = cipher + 32bits * 2
    int32_t *d; // = cipher + 32bits * 3

    int32_t *aPrime;
    int32_t *bPrime;
    int32_t *cPrime;
    int32_t *dPrime;

    size_t counter;

    // int32_t (*algorithm[])(struct s_md5*);
    size_t (*index_functions[4])(size_t i);

} t_md5;

int md5();

#endif // MD5_H
