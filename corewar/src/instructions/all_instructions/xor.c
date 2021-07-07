/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruction
*/

#include "war/war_fonc.h"
#include "instruction_tab.h"

bool xor(UNUSED vm_t *vm, champ_t *champ)
{
    int values[2] = {0, 0};

    champ->carry = true;
    for (int i = 0; i < op_tab[XOR].nbr_args - 1; i += 1) {
        if (champ->params_type[i] == REGISTER_TYPE &&
            !REG(champ->cmd_params[i])) {
            champ->carry = false;
            return false;
        }
        values[i] = (champ->params_type[i] == REGISTER_TYPE) ?
        champ->reg[champ->cmd_params[i] - 1] : champ->cmd_params[i];
    }
    if (!REG(champ->cmd_params[2])) {
        return false;
    }
    champ->reg[champ->cmd_params[2] - 1] = values[0] ^ values[1];
    return true;
}