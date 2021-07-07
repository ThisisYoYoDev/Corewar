/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruction
*/

#include "war/war_fonc.h"
#include "instruction_tab.h"

int get_value_ld(unsigned char *memory, unsigned int index)
{
    return get_direct_indirect(&index, memory, 4);
}

bool ld(vm_t *vm, champ_t *champ)
{
    int value = 0;

    if (OVERFLOW(champ->cmd_params[0], champ->cmd_params[1]) ||
        (champ->params_type[0] == 1 && !REG(champ->cmd_params[0])) ||
        !REG(champ->cmd_params[1])) {
        champ->carry = false;
        return false;
    }
    value = (champ->params_type[0] == REGISTER_TYPE) ?
        champ->reg[champ->cmd_params[0] - 1] : champ->cmd_params[0];
    champ->reg[champ->cmd_params[1] - 1] = (champ->params_type[1] == 2) ?
        get_value_ld(vm->memory, (champ->pc_pose +
        ((value) % IDX_MOD)) % MEM_SIZE) : value;
    champ->carry = (champ->cmd_params[0] == 0) ? true : false;
    return true;
}