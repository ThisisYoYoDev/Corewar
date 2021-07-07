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

bool fork_instruction(vm_t *vm, champ_t *champ)
{
    champ_t *new_cell = malloc(sizeof(champ_t));

    champ->carry = false;
    *new_cell = *champ;
    new_cell->pc_pose =
        (new_cell->pc_pose + (champ->cmd_params[0] % IDX_MOD)) % MEM_SIZE;
    new_cell->instruction_pc = new_cell->pc_pose;
    new_cell->cycle_before_instruction = -1;
    add_cell_list(vm->champ_list, new_cell);
    return true;
}