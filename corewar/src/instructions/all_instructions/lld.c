/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruction
*/

#include "war/war_fonc.h"
#include "instruction_tab.h"

bool lld(vm_t *vm, champ_t *champ)
{
    int value = 0;

    champ->carry = true;
    if (!REG(champ->cmd_params[0]) || !REG(champ->cmd_params[1])) {
        champ->carry = false;
        return false;
    }
    if (champ->params_type[0] == REGISTER_TYPE) {
        value = champ->reg[champ->cmd_params[0] - 1];
    } else {
        value = champ->cmd_params[0];
    }
    champ->reg[champ->cmd_params[1] - 1] =
        vm->memory[(champ->pc_pose + value) % MEM_SIZE];
    return true;
}