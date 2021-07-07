/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** check_arg
*/

#include <stdlib.h>
#include <stdbool.h>
#include "macro_const.h"
#include "lib_prototype.h"
#include "arg.h"

static void free_tab(int **data)
{
    int *tab = *data;

    for (int i = 0; tab[i] != 0; i++) {
        for (int b = i + 1; tab[b] != 0; b++) {
            if (tab[b] == tab[i]) {
                write(2, "Prog number must be differente\n", 31);
                exit(84);
            }
        }
    }
    free(tab);
}

static int check_if_flag(const char *arg)
{
    if (!my_strcmp(flag_arg_tab[FLAG_A].fonc_id, arg))
        return FLAG_A;
    if (!my_strcmp(flag_arg_tab[FLAG_N].fonc_id, arg)) {
        return FLAG_N;
    }
    return 0;
}

bool parce_champ_flags(const char * const argv[], int *i, int *r1_nb, \
int *nbr_champ)
{
    int flags_code_1 = check_if_flag(argv[*i]);
    int flags_code_2;

    (*nbr_champ)++;
    if (!flags_code_1)
        return EXIT_SUCCESS;
    if (flag_arg_tab[flags_code_1].check(argv, i, r1_nb))
        return EXIT_FAILURE;
    (*i)++;
    flags_code_2 = check_if_flag(argv[*i]);
    if (flags_code_1 == flags_code_2) {
        write(2, "Flags must be diferente\n", 24);
        return EXIT_FAILURE;
    }
    if (!flags_code_2)
        return EXIT_SUCCESS;
    if (flag_arg_tab[flags_code_2].check(argv, i, r1_nb))
        return EXIT_FAILURE;
    (*i)++;
    return EXIT_SUCCESS;
}

bool check_arg(const char * const argv[], const int av)
{
    int *rnb __attribute__((__cleanup__(free_tab))) = malloc(sizeof(int) * av);
    int nbr_champ = 0;

    my_memset(rnb, 0, sizeof(int) * av);
    for (int i = 1; argv[i] != NULL; i += 1) {
        if (!my_strcmp(flag_arg_tab[FALG_DUMP].fonc_id, argv[i])) {
            if (flag_arg_tab[FALG_DUMP].check(argv, &i, rnb))
                return EXIT_FAILURE;
            continue;
        }
        if (parce_champ_flags(argv, &i, rnb, &nbr_champ))
            return EXIT_FAILURE;
    }
    if (nbr_champ < 2) {
        write(2, "You must give at list 2 champion\n", 33);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}