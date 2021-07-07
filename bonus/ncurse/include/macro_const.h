/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-minishell2-yoel.edery
** File description:
** macro_const
*/

#ifndef MACRO_CONST_H_
#define MACRO_CONST_H_

#include "struct.h"

static const int RETURN_ERROR       = -1;
static const int RETURN_TRUE        = 1;
static const int RETURN_FALSE       = 0;

enum {
    IDX_MOD = 512,
    MAX_ARGS_NUMBER = 4,
    COREWAR_EXEC_MAGIC = 0xea83f3,
    PROG_NAME_LENGTH = 128,
    COMMENT_LENGTH = 2048,
    PROG_LEN_LENGTH = 8,
    REG_NUMBER = 16,
    IND_SIZE = 2,
    DIR_SIZE = 4,
    REG_SIZE = 4,
    T_REG = 1,
    T_DIR = 2,
    T_IND = 4
};

static const char COREWAR_EXEC_MAGIC_STR[] = "\xea\x83\xf3";
static const char LABEL_CHARS[] = "abcdefghijklmnopqrstuvwxyz_0123456789";

#endif /* !MACRO_CONST_H_ */
