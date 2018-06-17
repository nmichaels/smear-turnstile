#include <unistd.h>
#include <smear.h>
#include "events.h"
#include "turnstile.h"

turnstile_person_t *new_person(char *name)
{
    turnstile_person_t *p;

    p = malloc(sizeof(*p));
    p->name = name;
    return p;
}

turnstile_coin_t *new_coin(int grooves, int faces, int buildings)
{
    turnstile_coin_t *c;

    c = malloc(sizeof(*c));
    c->grooves = grooves;
    c->faces = faces;
    c->buildings = buildings;
    return c;
}

int main(void)
{
    turnstile_person_t *person;
    turnstile_coin_t *coin;

    SRT_init();
    SRT_run();

    person = new_person("Edward");
    turnstile_person(person);
    person = NULL;

    coin = new_coin(16, 0, 0);
    turnstile_coin(coin);
    coin = NULL;

    sleep(1);

    person = new_person("Edward");
    turnstile_person(person);
    person = NULL;

    coin = new_coin(16, 1, 1);
    turnstile_coin(coin);
    coin = NULL;

    sleep(1);

    person = new_person("George");
    turnstile_person(person);
    person = NULL;

    sleep(1);
    SRT_stop();
}
