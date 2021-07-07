/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruction
*/

#include "war/war_fonc.h"
#include "instruction_tab.h"

bool zjmp(UNUSED vm_t *vm, champ_t *champ)
{
    if (champ->carry) {
        champ->instruction_pc =
            (champ->pc_pose + (((short) champ->cmd_params[0]) % IDX_MOD))
            % MEM_SIZE;
    }
    return true;
}