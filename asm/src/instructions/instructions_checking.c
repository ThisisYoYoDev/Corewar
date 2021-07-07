/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** instructions_checking
*/

#include "corewar_asm.h"
#include "op_array.h"

static int instruction_asm_op_array_node(char *s)
{
    int nd = 0;

    for (; OP_ARRAY[nd].op_mnemonique && \
    my_strcmp(OP_ARRAY[nd].op_mnemonique, s) != 0; ++nd);
    if (OP_ARRAY[nd].op_mnemonique == NULL)
        return -1;
    return nd;
}

static int instruction_asm_param_size(int type, int id)
{
    return (type == 1 ? 1 : type == 4 ||
        ((id >= 9 && id <= 15) && id != 13) ? 2 : 4);
}

static void instruction_asm_clear_param(parameter_t *p)
{
    int i = 0;
    int os = 1;

    if (!p->is_param_label && p->is_param_type == T_IND)
        return;
    if (p->is_param_label && p->is_param_type == T_DIR)
        os = 2;
    for (; p->msg_parameter[i + os]; ++i)
        p->msg_parameter[i] = p->msg_parameter[i + os];
    p->msg_parameter[i] = '\0';
}

int instruction_asm_checking(instructions_t *i)
{
    int idx = 0;
    int j = instruction_asm_op_array_node(i->instruction_name);
    char type = 0;

    if (j == -1)
        return -1;
    for (i->instruct_id = j + 1; i->p_instruct[idx].msg_parameter; ++idx) {
        type = get_asm_is_type_of_parameter(i->p_instruct + idx);
        if (type == -1)
            return -1;
        i->p_instruct[idx].is_param_type = type;
        i->p_instruct[idx].parameter_size =
            instruction_asm_param_size(type, i->instruct_id);
        instruction_asm_clear_param(i->p_instruct + idx);
        if ((type ^ OP_ARRAY[j].op_type[idx])
            != (OP_ARRAY[j].op_type[idx] - type))
            return 1;
    }
    return (check_instruction_before_code_byte(
        i, idx, OP_ARRAY[j].op_sizeof_arguments)) ? 1 : 0;
}