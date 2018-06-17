#ifndef EVENTS_H
#define EVENTS_H

#include "turnstile.h"

typedef struct turnstile_coin_t
{
    int grooves;
    int faces;
    int buildings;
} turnstile_coin_t;

typedef struct turnstile_person_t
{
    char *name;
} turnstile_person_t;

#endif
