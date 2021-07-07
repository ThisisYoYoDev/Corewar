/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruction
*/

#include "enable_lib.h"
#include "war/war_fonc.h"
#include "instruction_tab.h"

bool st(vm_t *vm, champ_t *champ)
{
    int reg_value = 0;
    unsigned char bytes_array[4] = {0, 0, 0, 0};

    champ->carry = false;
    if (!REG(champ->cmd_params[0]))
        return false;
    reg_value = champ->reg[champ->cmd_params[0] - 1];
    if (champ->params_type[1] == REGISTER_TYPE) {
        if (!REG(champ->cmd_params[1]))
            return false;
        champ->reg[champ->cmd_params[1] - 1] =
            champ->reg[champ->cmd_params[0] - 1];
    } else {
        for (size_t i = 0; i != 4; i += 1) {
            vm->memory[ST_POS] = get_byte_array(reg_value, bytes_array)[i];
            vm->memory_proprio[ST_POS] = champ->champ_id;
        }
    }
    return true;
}