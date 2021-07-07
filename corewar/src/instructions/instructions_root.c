/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruction checkpoint
*/

#include <stddef.h>
#include "vm_struct.h"
#include "instruction_tab.h"
#include "war/war_fonc.h"
#include "enable_lib.h"

void reset_champ_params(champ_t *champ)
{
    champ->cmd_params[0] = 0;
    champ->cmd_params[1] = 0;
    champ->cmd_params[2] = 0;
    champ->cmd_params[3] = 0;
    free(champ->params_type);
}

static bool accomplish_instruction(vm_t *vm, champ_t *champ, int instruction)
{
    static bool (*instructions[16]) (vm_t *, champ_t *) = {live, ld, st,
        add, sub, and, or, xor, zjmp, ldi, sti, fork_instruction, lld,
        lldi, lfork, aff};
    bool status = true;

    if (op_tab[instruction].nbr_args > 1) {
        champ->instruction_pc += 1;
        champ->params_type =
        get_arguments_types(vm->memory[(champ->instruction_pc) % MEM_SIZE],
        op_tab[instruction].nbr_args);
        champ->instruction_pc += 1;
        extract_arguments(vm, champ, instruction);
    } else {
        champ->instruction_pc += 1;
        extract_one_argument(vm, champ, instruction);
    }
    status = instructions[instruction](vm, champ);
    if (op_tab[instruction].nbr_args > 1)
        reset_champ_params(champ);
    return status;
}

static void check_instruction(vm_t *vm, champ_t *champ, int instruction)
{
    if (accomplish_instruction(vm, champ, instruction - 1)) {
        champ->pc_pose = champ->instruction_pc;
        champ->instruction_pc = champ->pc_pose;
    } else {
        champ->pc_pose += 1;
    }
}

void find_instruction(vm_t *vm, champ_t *champ)
{
    int instruction = (int) vm->memory[champ->pc_pose % MEM_SIZE];

    if (instruction > INSTRUCTION_NUMBER || instruction == 0) {
        champ->pc_pose += 1;
        return;
    }
    if (champ->cycle_before_instruction == -1)
        champ->cycle_before_instruction = op_tab[instruction - 1].nbr_cycles;
    if (champ->cycle_before_instruction > 1) {
        champ->cycle_before_instruction -= 1;
        return;
    }
    champ->instruction_pc = champ->pc_pose;
    check_instruction(vm, champ, instruction);
    champ->cycle_before_instruction = -1;
    return;
}