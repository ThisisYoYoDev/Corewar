/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** get_parameter
*/

#include "corewar_asm.h"

static int get_asm_dir(parameter_t *p)
{
    int rt = 0;

    if (my_strcmp(p->msg_parameter, "%") == 0) {
        return 0;
    }
    if (p->msg_parameter[0] == '%') {
        if (p->msg_parameter[1] == ':') {
            p->is_param_label = 1;
            return 2;
        }
        sp_getnbr(p->msg_parameter + 1, &rt);
        if (rt == 0)
            return 2;
    }
    return 0;
}

static int get_asm_indir(parameter_t *p)
{
    int rt = 0;

    if (p->msg_parameter[0] == ':') {
        p->is_param_label = 1;
        return 4;
    }
    sp_getnbr(p->msg_parameter, &rt);
    if (rt == 0)
        return 4;
    return 0;
}

static int get_asm_register(parameter_t *p)
{
    int rt = 0;
    int n = 0;

    if (p->msg_parameter[0] == 'r') {
        n = sp_getnbr(p->msg_parameter + 1, &rt);
        if (rt != 0 || n <= 0 || n > 16)
            return -1;
        return 1;
    }
    return 0;
}

char get_asm_is_type_of_parameter(parameter_t *p)
{
    int rt = 0;

    p->is_param_label = 0;
    rt = get_asm_indir(p);
    if (rt != 0)
        return (char) rt;
    rt = get_asm_dir(p);
    if (rt != 0)
        return (char) rt;
    rt = get_asm_register(p);
    if (rt != 0)
        return (char) rt;
    return -1;
}

corwar_t *get_asm_champ(char *s)
{
    corwar_t *corewar = utils_asm_init_corewar();
    int rt = 0;

    if (corewar == NULL)
        return NULL;
    corewar->champ_file = utils_corewar_getline(s);
    if (corewar->champ_file == NULL)
        return utils_asm_free_all(corewar);
    rt = get_asm_header(corewar->champ_file, corewar->h);
    if (rt == -1)
        return utils_asm_free_all(corewar);
    if (get_asm_code(rt, corewar))
        return utils_asm_free_all(corewar);
    if (label_asm_real_engine(corewar->labels, corewar->instruction))
        return utils_asm_free_all(corewar);
    return corewar;
}