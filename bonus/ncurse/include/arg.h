/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** arg
*/

#ifndef ARG_H_
#define ARG_H_

#include "vm_struct.h"
#include <stdbool.h>
#include <stdlib.h>
#include "champ.h"

typedef struct flag_fonc_s
{
    const char *fonc_id;
    bool (*check)(const char * const argv[], int *i, int *r1_nb);
    void (*load_arg)(int data, champ_t *new_champ);
} flag_fonc_t;

bool check_flag_a(const char * const argv[], int *i, int *r1_nb);
bool check_flag_n(const char * const argv[], int *i, int *r1_nb);
bool check_arg(const char * const argv[], const int av);
bool check_flag_dump(const char * const argv[], int *i, int *r1_nb);
void load_flags_a(int data, champ_t *new_champ);
void load_flags_n(int data, champ_t *new_champ);

static const flag_fonc_t flag_arg_tab[] = {
    {"-dump", check_flag_dump, NULL},
    {"-a", check_flag_a, load_flags_a},
    {"-n", check_flag_n, load_flags_n},
    {NULL, NULL, NULL}
};

enum FLAGS_NUM {
    FALG_DUMP,
    FLAG_A,
    FLAG_N,
    NBR_OF_FLAGS
};

#endif /* !ARG_H_ */