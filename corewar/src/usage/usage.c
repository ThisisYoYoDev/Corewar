/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** usage
*/

#include <stdbool.h>
#include "help.h"

bool check_usage(int av, const char * const argv[])
{
    if (av == 2 && !my_strcmp((char *) argv[1], "-h")) {
        my_printf("%s", HELP);
        return true;
    }
    return false;
}