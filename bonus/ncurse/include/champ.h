/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** champ
*/

#ifndef CHAMP_H_
#define CHAMP_H_

#include <stdbool.h>
#include "macro_const.h"

typedef struct headers_s
{
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} headers_t;

typedef struct champ_data_s
{
    headers_t header;
    char *programe;
} champ_data_t;

typedef struct champ_s
{
    struct champ_s *next;
    champ_data_t data;
    unsigned int pc_pose;
    unsigned int instruction_pc;
    int reg[REG_NUMBER];
    unsigned char champ_id;
    int cycle_before_instruction;
    int cmd_params[4];
    int *params_type;
    bool carry;
    bool live_in_cycle_die;
    bool live;
} champ_t;

#endif /* !CHAMP_H_ */
