/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruction
*/

#include "war/war_fonc.h"
#include "instruction_tab.h"

bool lldi(UNUSED vm_t *vm, UNUSED champ_t *champ)
{
    int values[2] = {0, 0};
    int offsets[2] = {5, 3};

    champ->carry = true;
    if (OVERFLOW(champ->cmd_params[0], champ->cmd_params[1]) ||
        !REG(champ->cmd_params[2])) {
        champ->carry = false;
        return false;
    }
    for (int i = 0; i < op_tab[LLDI].nbr_args - 1; i += 1) {
        if (champ->params_type[i] == IND_SIZE) {
            values[i] =
                (int) vm->memory[((champ->pc_pose - offsets[i])
                + champ->cmd_params[i]) % MEM_SIZE];
        } else
            values[i] = champ->cmd_params[i];
    }
    champ->reg[champ->cmd_params[2] - 1] =
        vm->memory[(champ->pc_pose + (values[0] + values[1])) % MEM_SIZE];
    return true;
}