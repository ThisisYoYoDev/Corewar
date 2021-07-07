/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** disassembly
*/

#ifndef DISASSEMBLY_H_
#define DISASSEMBLY_H_

#define T_REG 1
#define T_DIR 2
#define T_IND 4
#define IND_SIZE   2
#define REG_SIZE   4
#define DIR_SIZE   REG_SIZE

#define REG_CODE   1
#define DIR_CODE   2
#define IND_CODE   3
#define PROG_NAME_LENGTH   (128)
#define COMMENT_LENGTH (2048)
#define COREWAR_EXEC_MAGIC 0xea83f3
#define NAME_CMD_STRING    ".name"
#define COMMENT_CMD_STRING ".comment"

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char *op_mnemonique;
    int op_sizeof_arguments;
    int useless1[4];
    int op_id;
    int useless2;
    char *description;
    int loop_action_check;
    int index;
} op_t;

typedef struct
{
    unsigned int    magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    unsigned int    prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

static const op_t OP_ARRAY[17] =
{
    {"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
    "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
    "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
    "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
    "load index", 1, 1},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
    "store index", 1, 1},
    {"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
    "long load index", 1, 1},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
    {"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
    {0, 0, {0}, 0, 0, 0, 0, 0}
};

int tranformation_int(char *s);
unsigned short transformation_short(char *s);
long int find_size_cmp(const char *file_name);
int loop_option_diss(char *d, op_t op, int fd);
void handle_errors(char *s);
void disassembly(char *d, int size, int fd);
void *super_malloc(size_t size);
int iprintlol(char *d, op_t op, int fd);
unsigned int swap(int x);

#endif /* !DISASSEMBLY_H_ */
