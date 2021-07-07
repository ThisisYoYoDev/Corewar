/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** op
*/

#ifndef _OP_H_
#define _OP_H_

#include "macro_const.h"

typedef struct {
    char *mnemonique;
    char nbr_args;
    char type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
} op_t;

typedef struct {
    int  magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int  prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

#endif /* !_OP_H_ */