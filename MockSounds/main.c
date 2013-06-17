#include <stdio.h>
#include "mock.h"

static unsigned long long counter = 0;
// mock setSound
void setSound(int tune, int uptime) {
    counter++;
    printf("[%-lld] set_tune: %d, uptime: %d\n", counter, tune, uptime);
}

int main(int argc, char **argv)
{
    setup();
    while(1) {
        loop();
        sleep(1);
    }
}
