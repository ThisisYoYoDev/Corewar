/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** utils_corewar_free
*/

#include <stdlib.h>
#include "corewar_asm.h"

void *utils_asm_free_label_node(label_lnk_t *label)
{
    if (!label)
        return NULL;
    if (label->lnk_label_data) {
        if (label->lnk_label_data->label_name)
            free(label->lnk_label_data->label_name);
        free(label->lnk_label_data);
    }
    free(label);
    return NULL;
}

void *utils_asm_free_label_list(label_lnk_t *label)
{
    for (label_lnk_t *t = label; label; t = label) {
        label = label->next;
        (void) utils_asm_free_label_node(t);
    }
    return NULL;
}

label_lnk_t *utils_asm_init_label_list(void)
{
    label_lnk_t *node = malloc(sizeof(label_lnk_t));

    if (!node)
        return NULL;
    node->lnk_label_data = malloc(sizeof(label_t));
    if (!node->lnk_label_data) {
        free(node);
        return NULL;
    }
    node->next = NULL;
    node->lnk_label_data->label_coord = 0;
    node->lnk_label_data->label_name = NULL;
    return node;
}

void utils_asm_free_array(char **array)
{
    int i = 0;

    if (array) {
        for (; array[i]; ++i)
            free(array[i]);
        free(array);
    }
}