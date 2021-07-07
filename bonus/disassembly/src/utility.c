/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** utility
*/

#include <stdint.h>
#include "disassembly.h"

void handle_errors(char *s)
{
    exit(84);
}

int tranformation_int(char *s)
{
    int translation = (unsigned char) s[3];

    translation += (unsigned char) s[2] * 256;
    translation += (unsigned char) s[1] * 256 * 256;
    translation += (unsigned char) s[0] * 256 * 256 * 256;
    return translation;
}

unsigned short transformation_short(char *s)
{
    unsigned short translation = (unsigned char) s[1];

    translation += (unsigned char) s[0] * 256;
    return translation;
}

void checking_idx(int fd, int idx, char *s, int *j)
{
    if (idx == 1) {
        dprintf(fd, "%c%d", '%', transformation_short(&s[*j]));
        *j += 2;
    } else {
        dprintf(fd, "%c%d", '%', tranformation_int(&s[*j]));
        *j += 4;
    }
}

int loop_option_diss(char *d, op_t op, int fd)
{
    int j = 2;

    for (int i = 0; i < op.op_sizeof_arguments; ) {
        if (((d[1] >> (6 - (i * 2))) & 3) == REG_CODE) {
            dprintf(fd, "r%d", d[j++]);
        } else if (((d[1] >> (6 - (i * 2))) & 3) == IND_CODE) {
            dprintf(fd, "%d", transformation_short(&d[j]));
            j += 2;
        } else if (((d[1] >> (6 - (i * 2))) & 3) == DIR_CODE) {
            checking_idx(fd, op.index, d, &j);
        }
        (++i < op.op_sizeof_arguments) ? dprintf(fd, ", ") : dprintf(fd, "\n");
    }
    return j;
}