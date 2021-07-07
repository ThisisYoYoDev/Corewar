/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruction
*/

#include "war/war_fonc.h"
#include "instruction_tab.h"

bool add(UNUSED vm_t *vm, champ_t *champ)
{
    int values[2] = {0, 0};

    champ->carry = true;
    if (!REG(champ->cmd_params[0]) || !REG(champ->cmd_params[1]) ||
        !REG(champ->cmd_params[2]) ||
        OVERFLOW(champ->reg[champ->cmd_params[0] - 1],
        champ->reg[champ->cmd_params[1] - 1])) {
        champ->carry = false;
        return false;
    }
    for (int i = 0; i < op_tab[ADD].nbr_args - 1; i += 1) {
        if (champ->params_type[i] == REGISTER_TYPE) {
            values[i] = champ->reg[champ->cmd_params[i] - 1];
        } else {
            values[i] = champ->cmd_params[i];
        }
    }
    champ->reg[champ->cmd_params[2] - 1] = values[0] + values[1];
    return true;
}