/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** instructions_add
*/

#include "corewar_asm.h"

static int instruction_asm_calc_len(instructions_t *i)
{
    int len = 1;
    int idx = 0;

    for (len += (i->instruct_byte != -1) ? 1 : 0;
        i->p_instruct[idx].msg_parameter; idx++) {
        if (i->p_instruct[idx].is_param_type == T_REG) {
            len += 1;
        } else if (i->p_instruct[idx].is_param_type == T_IND ||
            ((i->instruct_id >= 9 && i->instruct_id <= 15) &&
                i->instruct_id != 13)) {
            len += 2;
        } else
            len += 4;
    }
    return len;
}

static char *instruction_asm_get_name(char *s, int i)
{
    char *nm = NULL;
    int j = 0;

    for (; s[i + j] && (s[i + j] != ' ' && s[i + j] != '\t'); j++);
    nm = my_strndup(s + i, j);
    if (nm == NULL)
        return NULL;
    return nm;
}

static instruction_lnk_t *instruction_asm_get(char *s, int pos)
{
    instruction_lnk_t *node = utils_asm_free_list_node();
    int i = 0;

    for (; s[i] && (s[i] == ' ' || s[i] == '\t'); ++i);
    if (node == NULL)
        return NULL;
    node->lnk_instruction_data->instruction_name =
        instruction_asm_get_name(s, i);
    if (node->lnk_instruction_data->instruction_name == NULL)
        return utils_asm_free_list_instruction(node);
    i += my_strlen(node->lnk_instruction_data->instruction_name);
    node->lnk_instruction_data->p_instruct =
        utils_corewar_line_check_param(s + i);
    if (node->lnk_instruction_data->p_instruct == NULL)
        return utils_asm_free_list_instruction(node);
    if (instruction_asm_checking(node->lnk_instruction_data))
        return utils_asm_free_list_instruction(node);
    node->lnk_instruction_data->instruct_coord = pos;
    return node;
}

int instruction_asm_add(int i, corwar_t *corewar, instruction_lnk_t **si)
{
    instruction_lnk_t *cr = instruction_asm_get(corewar->champ_file[i],
        corewar->sizeof_program);

    if (cr == NULL)
        return 1;
    if (corewar->instruction == NULL)
        corewar->instruction = cr;
    else {
        corewar->instruction->next = cr;
        corewar->instruction = corewar->instruction->next;
    }
    if ((*si) == NULL)
        (*si) = cr;
    corewar->sizeof_program +=
        instruction_asm_calc_len(corewar->instruction->lnk_instruction_data);
    return 0;
}