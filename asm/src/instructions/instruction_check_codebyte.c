/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** instructions_checking
*/

#include "corewar_asm.h"
#include "op_array.h"

static int instruction_asm_code_byte(int id, parameter_t *p)
{
    int i = 0;
    int bytes = 0;

    if (id == 1 || id == 9 || id == 12 || id == 15)
        return -1;
    for (; p[i].msg_parameter; ++i)
        bytes = (bytes << 2) + ((p[i].is_param_type == T_REG) ? 1 :
            (p[i].is_param_type == T_DIR) ? 2 : 3);
    for (; i < 4; ++i)
        bytes <<= 2;
    return bytes;
}

int check_instruction_before_code_byte(
    instructions_t *i, int idx, char sizeof_arg)
{
    if (idx < sizeof_arg)
        return 1;
    i->instruct_byte =
        instruction_asm_code_byte(i->instruct_id, i->p_instruct);
    return 0;
}