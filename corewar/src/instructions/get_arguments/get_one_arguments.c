/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** get arguments for instruction with one parameter
*/

#include <stddef.h>
#include "vm_struct.h"
#include "instruction_tab.h"
#include "war/war_fonc.h"
#include "enable_lib.h"

void extract_one_argument(vm_t *vm, champ_t *champ, int i)
{
    if (i == LIVE) {
        champ->cmd_params[0] =
        get_direct_indirect(&champ->instruction_pc, vm->memory, DIR_SIZE);
    }
    if (i == AFF) {
        champ->cmd_params[0] =
        get_reg(vm->memory[(champ->instruction_pc + 2) % MEM_SIZE],
        &champ->instruction_pc);
        champ->instruction_pc += 1;
    }
    if (i == ZJMP || i == FORK || i == LFORK) {
        champ->cmd_params[0] =
        get_direct_indirect(&champ->instruction_pc, vm->memory, T_INDEX);
    }
}