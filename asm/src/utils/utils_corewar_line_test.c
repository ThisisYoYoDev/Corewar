/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** utils_corewar_line_test
*/

#include "corewar_asm.h"

static int utils_corewar_param_count(char *s)
{
    int wc = 0;

    for (; *s && *s != '#'; ) {
        if (*s != ' ' && *s != ',' && *s != '\t' && *s != '#') {
            for (wc++; *s && *s != ' ' && *s != ','
                && *s != '\t' && *s != '#'; s++);
        } else
            s++;
    }
    return wc;
}

static void utils_corewar_param_check(parameter_t *p, char *s, int size)
{
    int i = 0;
    int ws = 0;

    for (; i < size; ) {
        if (*s != ',' && *s != ' ' && *s != '\t' && *s != '#') {
            for (; *s && *s != ' ' && *s != ','
                && *s != '#' && *s != '\t'; ws++)
                s++;
            p[i].msg_parameter = my_strndup(s - ws, ws);
            ws = 0;
            i++;
        } else
            s++;
    }
    p[i].msg_parameter = NULL;
}

parameter_t *utils_corewar_line_check_param(char *s)
{
    int i = utils_corewar_param_count(s);
    parameter_t *array = malloc(sizeof(parameter_t) * (i + 1));

    if (!array)
        return NULL;
    utils_corewar_param_check(array, s, i);
    return array;
}

int utils_corewar_line_test(char *s)
{
    for (int i = 0; s[i]; ++i) {
        if (s[i] != ' ' && s[i] != '\t') {
            if (s[i] == '#')
                return 0;
            return 1;
        }
    }
    return 0;
}