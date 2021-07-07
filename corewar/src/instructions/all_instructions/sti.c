/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruction
*/

#include "enable_lib.h"
#include "war/war_fonc.h"
#include "instruction_tab.h"

static bool get_sti_reg(champ_t *champ, int *reg_value)
{
    champ->carry = false;
    if (!REG(champ->cmd_params[0]))
        return false;
    *reg_value = champ->reg[champ->cmd_params[0] - 1];
    return true;
}

bool sti(vm_t *vm, champ_t *champ)
{
    int values[2] = {0, 0};
    unsigned int offsets[2] = {champ->instruction_pc - 4,
        champ->instruction_pc - 2};
    int reg_value = 0;
    unsigned char bytes_array[4] = {0, 0, 0, 0};

    if (get_sti_reg(champ, &reg_value) == false)
        return false;
    for (int i = 1; i < op_tab[STI].nbr_args; i += 1) {
        if (champ->params_type[i] == 1 && !REG(champ->cmd_params[i]))
            return false;
        values[i - 1] = (champ->params_type[i] == REGISTER_TYPE) ?
            champ->reg[champ->cmd_params[i] - 1] :
            get_direct_indirect(&offsets[i - 1], vm->memory, 1);
    }
    for (size_t i = 0; i != 4; i += 1) {
        vm->memory[STI_POS] = get_byte_array(reg_value, bytes_array)[i];
        vm->memory_proprio[STI_POS] = champ->champ_id;
    }
    return true;
}