/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** tests_func
*/

#ifndef TESTS_FUNC_H_
#define TESTS_FUNC_H_

#include "vm_struct.h"

void add_cell_list(champ_t *list, champ_t *cell);
void remove_cell(champ_t *list, unsigned int pos);
bool init_war(vm_t *vm, const char * const argv[], const int av);
bool init_war(vm_t *vm, const char * const argv[], const int av);
bool check_flag_a(const char * const argv[], int *i, int *r1_nb);
bool check_flag_n(const char * const argv[], int *i, int *r1_nb);
bool check_flag_dump(const char * const argv[], int *i, int *r1_nb);
bool check_arg(const char * const argv[], const int av);

#endif /* !TESTS_FUNC_H_ */
