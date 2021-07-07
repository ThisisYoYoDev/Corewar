/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** prototype
*/

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

#include "struct.h"

/* utils/utils_corewar_free.c */
void *utils_asm_free_label_list(label_lnk_t *label);
void utils_asm_free_array(char **array);
label_lnk_t *utils_asm_init_label_list(void);

/* utils/utils_corewar_free_part_two.c */
void *utils_asm_free_list_instruction_all(instruction_lnk_t *list);
instruction_lnk_t *utils_asm_free_list_node(void);
void *utils_asm_free_list_instruction(instruction_lnk_t *node);

parameter_t *utils_corewar_line_check_param(char *s);
int instruction_asm_checking(instructions_t *i);
void *utils_asm_free_label_node(label_lnk_t *label);
corwar_t *get_asm_champ(char *s);
int utils_asm_create_corewar_file(corwar_t *corewar, char *s);
void *utils_asm_free_all(corwar_t *corewar);
int write_asm_header(int fd, corwar_t *corewar);
int write_asm_instruction(int fd, corwar_t *corewar);
int utils_corewar_line_test(char *s);
corwar_t *utils_asm_init_corewar(void);
char **utils_corewar_getline(char *champ_file);
int label_asm_add_label_new(int i, corwar_t *corewar, label_lnk_t **mlb);
int instruction_asm_add(int i, corwar_t *corewar, instruction_lnk_t **si);
int get_asm_header(char **cf, header_t *h);
int get_asm_code(int i, corwar_t *corewar);
int label_asm_real_engine(label_lnk_t *label, instruction_lnk_t *i);
int write_asm_label(int fd, parameter_t *p, label_lnk_t *label, int pos);
int write_asm_val(int fd, int n, int len);
char get_asm_is_type_of_parameter(parameter_t *p);
int check_instruction_before_code_byte(
    instructions_t *i, int idx, char sizeof_arg);

#endif /* !PROTOTYPE_H_ */
