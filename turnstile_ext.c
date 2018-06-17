#include <stdio.h>
#include <string.h>
#include <smear.h>
#include "turnstile.h"
#include "events.h"
#include "turnstile_ext.h"

static turnstile_coin_t coin_to_validate;

SRT_HANDLERS(turnstile)
SRT_HANDLERS(coinInspector)

void flashLEDs(const turnstile_coin_t *coin)
{
    memcpy(&coin_to_validate, coin, sizeof(*coin));
    printf("Got coin: %dg %df %db\n", coin->grooves, coin->faces,
           coin->buildings);
}

void lightLEDs(void)
{
    printf("LED Test\n");
}

void lockedEnter(void)
{
    printf("Locking.\n");
}

void lockedExit(void)
{
    printf("Leaving locked state.\n");
}

void soundAlarm(const turnstile_person_t *person)
{
    printf("BLEEP BLEEP %s TRIED TO JUMP THE TURNSTILE!\n", person->name);
}

void soundOkay(const turnstile_person_t *person)
{
    printf("Letting %s through.\n", person->name);
}

void unlockedEnter(void)
{
    printf("Unlocking.\n");
}

void validateCoin(const coinInspector_validate_t *unused)
{
    printf("Validating coin...\n");
    if (coin_to_validate.grooves   != 16 ||
        coin_to_validate.faces     != 1  ||
        coin_to_validate.buildings != 1)
    {
        printf("Invalid coin: %dg %df %db\n", coin_to_validate.grooves,
               coin_to_validate.faces, coin_to_validate.buildings);
        coinInspector_invalid(NULL);
    }
    else
    {
        coinInspector_valid(NULL);
    }
}
