/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** utils_corewar_free_part_two
*/

#include <stdlib.h>
#include "corewar_asm.h"

static void *utils_corewar_free_param(parameter_t *p)
{
    if (p) {
        for (int i = 0; p[i].msg_parameter; ++i)
            free(p[i].msg_parameter);
        free(p);
    }
    return NULL;
}

void *utils_asm_free_list_instruction(instruction_lnk_t *node)
{
    if (!node)
        return NULL;
    if (node->lnk_instruction_data) {
        if (node->lnk_instruction_data->instruction_name)
            free(node->lnk_instruction_data->instruction_name);
        utils_corewar_free_param(node->lnk_instruction_data->p_instruct);
        free(node->lnk_instruction_data);
    }
    free(node);
    return NULL;
}

instruction_lnk_t *utils_asm_free_list_node(void)
{
    instruction_lnk_t *node = malloc(sizeof(instruction_lnk_t));

    if (!node)
        return NULL;
    node->lnk_instruction_data = malloc(sizeof(instructions_t));
    if (!node->lnk_instruction_data)
        return utils_asm_free_list_instruction(node);
    node->next = NULL;
    node->lnk_instruction_data->instruction_name = NULL;
    node->lnk_instruction_data->p_instruct = NULL;
    node->lnk_instruction_data->instruct_id = 0;
    node->lnk_instruction_data->instruct_byte = 0;
    node->lnk_instruction_data->instruct_coord = 0;
    return node;
}

void *utils_asm_free_list_instruction_all(instruction_lnk_t *list)
{
    for (instruction_lnk_t *t = list; list; t = list) {
        list = list->next;
        utils_asm_free_list_instruction(t);
    }
    return NULL;
}