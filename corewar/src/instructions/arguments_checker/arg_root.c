/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** get arguments for instructions
*/

#include <stdbool.h>
#include "war/war_fonc.h"
#include "instruction_tab.h"
#include "enable_lib.h"

int check_params(vm_t *vm, champ_t *champ, unsigned char cur_pos)
{
    bool (*checker[16]) (vm_t *, champ_t *, char) = {check_live, check_ld,
        check_st, check_add, check_sub, check_and, check_or, check_xor,
        check_zjmp, check_ldi, check_sti, check_fork, check_lld, check_lldi,
        check_lfork, check_aff};

    for (int instruction = 0;
        instruction < INSTRUCTION_NUMBER; instruction += 1) {
        if (instruction == cur_pos) {
            return (checker[instruction](vm, champ, cur_pos)) ?
            instruction : -1;
        }
    }
    return -1;
}