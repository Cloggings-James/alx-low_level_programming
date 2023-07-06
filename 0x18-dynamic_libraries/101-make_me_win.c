#include <stdio.h>
#include <stdlib.h>

void __attribute__((constructor)) jackpot(void)
{
    char *winning_numbers = "9 8 10 24 75 9";
    char *command = "/bin/bash -c 'echo \"$@\" > /tmp/winning_numbers'";
    char full_command[128];

    sprintf(full_command, command, winning_numbers);
    system(full_command);
}

