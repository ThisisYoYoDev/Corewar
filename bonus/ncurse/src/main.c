/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** ncurse main
*/

#include "vm_struct.h"
#include "init_war.h"
#include "war/war_fonc.h"
#include "prototype.h"
#include "ncurse_fonc.h"

int main(int av, const char * const argv[])
{
    vm_t vm = {0};

    if (check_usage(av, argv))
        return 0;
    if (init_war(&vm, argv, av))
        return 84;
    graphical_war_loop(&vm);
    return 0;
}