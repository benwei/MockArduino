#include "mock.h"

struct sound_msg {
    int tune;
    int uptime;
};

struct sound_msg sounds[] = {
{10, 2},  /* play sound in tune 10 with 2 loops*/
{1, 2}, /* delay 2 loops */
{50, 3},
{-1,-1}
};

struct sound_msg subsounds[] = { 
{12, 2},  /* play sound in tune 10 with 2 loops*/
{1, 2}, /* delay 2 loops */
{55, 3},
{-1,-1}
};

int sound_index = -1;
int subsound_index = -1;

struct sound_msg *get_next_sound()
{
    sound_index++;
    if (sounds[sound_index].tune == -1) {
        sound_index = 0;
    }

    return &sounds[sound_index];
}

struct sound_msg *get_next_subsound()
{
    subsound_index++;
    if (subsounds[subsound_index].tune == -1) {
        subsound_index = 0;
    }

    return &subsounds[subsound_index];
}


int time_slot = 10;
int time_remainer = 0;
int time_subremainer = 0;
struct sound_msg *snd = NULL;
struct sound_msg *sub = NULL;

void setup() {
    ;;
}

void loop()
{
    if (time_remainer == 0) {
        snd = get_next_sound();
        time_remainer = snd->uptime; 
    } else {
        time_remainer--;
        if (snd && snd->tune > 0) {
            setSound (snd->tune, 1);
        }
    }

    if (time_subremainer == 0) {
        sub = get_next_subsound();
        time_subremainer = sub->uptime; 
    } else {
        time_subremainer--;
        if (sub && sub->tune > 0) {
            setSound (sub->tune, 1);
        }
    }
}
