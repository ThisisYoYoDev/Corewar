/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** get params for cmd
*/

#include "war/war_fonc.h"
#include "instruction_tab.h"

void get_st_params(vm_t *vm, champ_t *champ, int instruction)
{
    for (int i = 0; i < op_tab[instruction].nbr_args && i <= 3; i += 1) {
        if (champ->params_type[i] == DIR_SIZE) {
            champ->cmd_params[i] =
            get_direct_indirect(&champ->instruction_pc, vm->memory, DIR_SIZE);
        } else if (champ->params_type[i] == IND_SIZE) {
            champ->cmd_params[i] =
            get_direct_indirect(&champ->instruction_pc, vm->memory, T_INDEX);
        } else {
            champ->cmd_params[i] =
            get_reg(vm->memory[champ->instruction_pc % MEM_SIZE],
            &champ->instruction_pc);
        }
    }
}

void get_indexes_params(vm_t *vm, champ_t *champ, int instruction)
{
    for (int i = 0; i < op_tab[instruction].nbr_args; i += 1) {
        if (champ->params_type[i] == DIR_SIZE) {
            champ->cmd_params[i] =
            get_direct_indirect(&champ->instruction_pc, vm->memory, T_INDEX);
        } else if (champ->params_type[i] == IND_SIZE) {
            champ->cmd_params[i] =
            get_direct_indirect(&champ->instruction_pc, vm->memory, IND_SIZE);
        } else {
            champ->cmd_params[i] =
            get_reg(vm->memory[champ->instruction_pc % MEM_SIZE],
            &champ->instruction_pc);
        }
    }
}

void get_params(vm_t *vm, champ_t *champ, int instruction)
{
    for (int i = 0; i < op_tab[instruction].nbr_args && i <= 3; i += 1) {
        if (champ->params_type[i] == DIR_SIZE) {
            champ->cmd_params[i] =
            get_direct_indirect(&champ->instruction_pc, vm->memory, DIR_SIZE);
        } else if (champ->params_type[i] == IND_SIZE) {
            champ->cmd_params[i] =
            get_direct_indirect(&champ->instruction_pc, vm->memory, IND_SIZE);
        } else {
            champ->cmd_params[i] =
            get_reg(vm->memory[champ->instruction_pc % MEM_SIZE],
            &champ->instruction_pc);
        }
    }
}

void extract_arguments(vm_t *vm, champ_t *champ, int instruction)
{
    static int indexes_fonc[3] = {LDI, LLDI, STI};

    if (instruction == ST) {
        get_st_params(vm, champ, instruction);
        return;
    }
    for (int i = 0; i != 3; i += 1) {
        if (instruction == indexes_fonc[i]) {
            get_indexes_params(vm, champ, instruction);
            return;
        }
    }
    get_params(vm, champ, instruction);
}