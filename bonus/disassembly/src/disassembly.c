/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** disassembly
*/

#include <sys/types.h>
#include <sys/stat.h>
#include "disassembly.h"

int iprintlol(char *d, op_t op, int fd)
{
    dprintf(fd, "\t%s ", op.op_mnemonique);
    if (op.loop_action_check) {
        return loop_option_diss(d, op, fd);
    } if (op.index) {
        dprintf(fd, "%c%d\n", '%', transformation_short(&d[1]));
        return 3;
    } else {
        dprintf(fd, "%c%d\n", '%', tranformation_int(&d[1]));
        return 5;
    }
}

void *super_malloc(size_t size)
{
    void *rt = malloc(size);

    if (!rt)
        return NULL;
    bzero(rt, size);
    return rt;
}

unsigned int swap(int x)
{
    unsigned int rev = (x >> 24) & 0xFF;

    rev += (x >> 8) & 0xFF00;
    rev += (x << 8) & 0xFF0000;
    rev += x << 24;
    return rev;
}

void disassembly(char *d, int size, int fd)
{
    int j = 0;

    for (int i = 0; i < size; ) {
        for (j = 0; j < (int) (sizeof(OP_ARRAY) / sizeof(op_t)); j++) {
            if (d[i] == OP_ARRAY[j].op_id) {
                i += iprintlol(&d[i], OP_ARRAY[j], fd);
                break;
            }
        }
        if (j >= (int) ((sizeof(OP_ARRAY) / sizeof(op_t)) - 1)) {
            handle_errors("Instruction inconnue");
        }
    }
}

long int find_size_cmp(const char *file_name)
{
    int fd = 0;
    int fs = 0;
    int ar = 0;
    char c = 0;

    if ((fd = open(file_name, O_RDONLY))) {
        for (fs = 0; (ar = read(fd, &c, 1)); fs++);
        close(fd);
        if (ar == 0)
            return fs;
    }
    handle_errors("bad size of file");
    return 84;
}