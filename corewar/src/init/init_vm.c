/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** init_vm
*/

#include <string.h>
#include <stdlib.h>
#include "vm_struct.h"

static void init_head_list(vm_t *vm)
{
    vm->champ_list = malloc(sizeof(champ_t));
    vm->champ_list->next = NULL;
}

void init_vm(vm_t *vm)
{
    init_head_list(vm);
    vm->dump_cycle = -1;
    vm->cycle_to_die = CYCLE_TO_DIE;
}
