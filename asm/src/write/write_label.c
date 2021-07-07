/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** write_label
*/

#include <unistd.h>
#include "corewar_asm.h"

int write_asm_val(int fd, int n, int len)
{
    char *wr = malloc(sizeof(char) * len);
    char *bytes = (char *) &n;

    if (!wr)
        return 1;
    my_memset(wr, 0, len);
    for (int i = 0; i < len; ++i)
        wr[i] = bytes[len - 1 - i];
    write(fd, wr, len);
    free(wr);
    return 0;
}

static int write_asm_diff(int fd, parameter_t *p, int d)
{
    int m = (p->parameter_size == 2) ? 255 : 65535;

    if (d >= 0) {
        write_asm_val(fd, 0 + (d / m), p->parameter_size / 2);
        write_asm_val(fd, d, p->parameter_size / 2);
    } else {
        write_asm_val(fd, m + (d / m), p->parameter_size / 2);
        write_asm_val(fd, m + d + 1, p->parameter_size / 2);
    }
    return 0;
}

int write_asm_label(int fd, parameter_t *p, label_lnk_t *label, int pos)
{
    for (; label; label = label->next)
        if (!my_strcmp(p->msg_parameter, label->lnk_label_data->label_name))
            return write_asm_diff(fd, p,
            label->lnk_label_data->label_coord - pos);
    return 1;
}