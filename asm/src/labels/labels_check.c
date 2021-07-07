/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** labels_check
*/

#include "corewar_asm.h"

static int labels_asm_check_exist(label_lnk_t *label, char *prm)
{
    for (; label != NULL; label = label->next)
        if (my_strcmp(prm, label->lnk_label_data->label_name) == 0)
            return 1;
    return 0;
}

static int labal_asm_reduce_check(label_lnk_t *label, instruction_lnk_t *i)
{
    for (int idx = 0;
        i->lnk_instruction_data->p_instruct[idx].msg_parameter; ++idx) {
        if (i->lnk_instruction_data->p_instruct[idx].is_param_label) {
            if (!labels_asm_check_exist(label,
                i->lnk_instruction_data->p_instruct[idx].msg_parameter))
                return 1;
        }
    }
    return 0;
}

int label_asm_real_engine(label_lnk_t *label, instruction_lnk_t *i)
{
    for (; i; i = i->next) {
        if (labal_asm_reduce_check(label, i) == 1)
            return 1;
    }
    return 0;
}