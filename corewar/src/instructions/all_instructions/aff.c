/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruction
*/

#include "war/war_fonc.h"
#include "instruction_tab.h"

bool aff(UNUSED vm_t *vm, champ_t *champ)
{
    if (!REG(champ->cmd_params[0]))
        return false;
    return true;
}