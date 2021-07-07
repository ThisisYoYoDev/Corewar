/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** main
*/

#include <stdlib.h>
#include "vm_struct.h"
#include "init_war.h"
#include "war/war_fonc.h"
#include "prototype.h"

void init_empty_vm(vm_t *vm)
{
    vm->champ_list = NULL;
    vm->last_alive = NULL;
    vm->alive = 0;
    for (int i = 0; i < MEM_SIZE; i += 1) {
        vm->memory_proprio[i] = 0;
        vm->memory[i] = 0;
    }
    vm->cycle_to_die = 0;
    vm->nbr_cycle_to_die = 0;
    vm->total_cycles = 0;
    vm->dump_cycle = 0;
}

int main(int av, const char * const argv[])
{
    vm_t vm;

    if (check_usage(av, argv))
        return 0;
    init_empty_vm(&vm);
    if (init_war(&vm, argv, av))
        return 84;
    start_war_loop(&vm);
    return 0;
}