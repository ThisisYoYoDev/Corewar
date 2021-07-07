/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruction
*/

#include "enable_lib.h"
#include "war/war_fonc.h"
#include "instruction_tab.h"
#include "list.h"

bool lfork(vm_t *vm, champ_t *champ)
{
    champ_t *new_cell = malloc(sizeof(champ_t));

    champ->carry = false;
    new_cell[0] = champ[0];
    new_cell->pc_pose += champ->cmd_params[0];
    add_cell_list(vm->champ_list, new_cell);
    return true;
}