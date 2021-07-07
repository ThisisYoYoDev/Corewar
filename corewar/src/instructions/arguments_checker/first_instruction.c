/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruction_checker_1
*/

#include <stdbool.h>
#include "war/war_fonc.h"
#include "instruction_tab.h"

bool check_live(UNUSED vm_t *vm,
    UNUSED champ_t *champ, UNUSED char current_pos)
{
    if (!champ->cycle_before_instruction) {
        return true;
    }
    return false;
}

bool check_ld(UNUSED vm_t *vm, UNUSED champ_t *champ, UNUSED char current_pos)
{
    return true;
}

bool check_st(UNUSED vm_t *vm, UNUSED champ_t *champ, UNUSED char current_pos)
{
    return true;
}

bool check_add(UNUSED vm_t *vm, UNUSED champ_t *champ, UNUSED char current_pos)
{
    return true;
}

bool check_sub(UNUSED vm_t *vm, UNUSED champ_t *champ, UNUSED char current_pos)
{
    return true;
}