/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "macro_const.h"

typedef struct {
    char    *msg_parameter;
    char    is_param_type;
    int     parameter_size;
    int     is_param_label;
} parameter_t;

typedef struct {
    parameter_t *p_instruct;
    char        *instruction_name;
    int         instruct_id;
    int         instruct_byte;
    int         instruct_coord;
} instructions_t;

typedef struct {
    char    *label_name;
    int     label_coord;
} label_t;

typedef struct label_linked_list_s {
    label_t                    *lnk_label_data;
    struct label_linked_list_s *next;
} label_lnk_t;

typedef struct instruction_linked_list_s {
    instructions_t                   *lnk_instruction_data;
    struct instruction_linked_list_s *next;
} instruction_lnk_t;

typedef char args_type_t;

typedef struct {
    char *op_mnemonique;
    char op_sizeof_arguments;
    args_type_t op_type[MAX_ARGS_NUMBER];
    char op_id;
    int nbr_cycles;
    char *comment;
} op_t;

typedef struct {
    char msg_programme_name[PROG_NAME_LENGTH];
    char msg_commentary[COMMENT_LENGTH];
    char msg_programme_len[PROG_LEN_LENGTH];
} header_t;

typedef struct {
    header_t            *h;
    char                **champ_file;
    label_lnk_t         *labels;
    instruction_lnk_t   *instruction;
    unsigned long       sizeof_program;
} corwar_t;

#endif /* !STRUCT_H_ */
