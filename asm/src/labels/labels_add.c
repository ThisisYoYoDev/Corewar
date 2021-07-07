/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** labels_add
*/

#include "corewar_asm.h"

static void labels_asm_remove_label(char *s, int os)
{
    int i = 0;

    for (; s[i + os]; ++i)
        s[i] = s[i + os];
    s[i] = '\0';
}

static int labels_asm_check_char(char c)
{
    for (int i = 0; LABEL_CHARS[i]; ++i)
        if (LABEL_CHARS[i] == c)
            return 1;
    return 0;
}

static label_lnk_t *labels_asm_get_label(char *s, int lp)
{
    label_lnk_t *node = utils_asm_init_label_list();
    int i = 0;
    int j = 0;

    for (; s[i] && (s[i] == ' ' || s[i] == '\t'); ++i);
    for (j = i; labels_asm_check_char(s[j]); ++j);
    if (s[j] != ':' || !node)
        return utils_asm_free_label_node(node);
    node->lnk_label_data->label_name = my_strndup(s + i, j - i);
    if (!node)
        return utils_asm_free_label_node(node);
    node->lnk_label_data->label_coord = lp;
    labels_asm_remove_label(s, j + 1);
    return node;
}

static int label_asm_check_label(label_lnk_t *ck, label_lnk_t *label)
{
    for (; label; label = label->next)
        if (my_strcmp(ck->lnk_label_data->label_name,
            label->lnk_label_data->label_name) == 0)
            return 1;
    return 0;
}

int label_asm_add_label_new(int i, corwar_t *corewar, label_lnk_t **mlb)
{
    label_lnk_t *clabel =
        labels_asm_get_label(corewar->champ_file[i], corewar->sizeof_program);

    if (clabel) {
        if (label_asm_check_label(clabel, (*mlb)))
            return 1;
        if (corewar->labels == NULL) {
            corewar->labels = clabel;
        } else {
            corewar->labels->next = clabel;
            corewar->labels = corewar->labels->next;
        }
        if ((*mlb) == NULL)
            (*mlb) = clabel;
    }
    return 0;
}