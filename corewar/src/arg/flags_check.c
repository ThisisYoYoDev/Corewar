/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** flags_check
*/

#include <stdlib.h>
#include <stdbool.h>
#include "macro_const.h"
#include "lib_prototype.h"
#include "champ.h"

bool check_flag_a(const char * const argv[], int *i, int *r1_nb)
{
    (void)r1_nb;
    if (argv[*i + 1] == NULL || argv[*i + 2] == NULL) {
        write(2, "You must give champ file after flags\n", 37);
        return EXIT_FAILURE;
    }
    (*i)++;
    if (!my_str_isnum(argv[*i])) {
        write(2, "Wrong -a, loading adress must be positive integer\n", 41);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

bool check_flag_n(const char * const argv[], int *i, int *r1_nb)
{
    static int nbr = 0;

    if (argv[*i + 1] == NULL || argv[*i + 2] == NULL) {
        write(2, "You must give champ file after flags\n", 37);
        return EXIT_FAILURE;
    }
    (*i)++;
    if (!my_str_isnum(argv[*i])) {
        write(2, "Wrong -n, prog_number must be integer\n", 38);
        return EXIT_FAILURE;
    }
    r1_nb[nbr] = my_getnbr(argv[*i]);
    nbr += 1;
    return EXIT_SUCCESS;
}

void load_flags_a(int data, champ_t *new_champ)
{
    new_champ->pc_pose = data;
    new_champ->instruction_pc = new_champ->pc_pose;
}

void load_flags_n(int data, champ_t *new_champ)
{
    new_champ->champ_id = data;
}

bool check_flag_dump(const char * const argv[], int *i, int *r1_nb)
{
    static int nbr = 0;

    (void)r1_nb;
    if (argv[*i + 1] == NULL) {
        write(2, "Invalid option.\n", 16);
        return EXIT_FAILURE;
    }
    (*i)++;
    if (!my_str_isnum(argv[*i])) {
        write(2, "Wrong -dump, dump_cycle must be a positive integer\n", 51);
        return EXIT_FAILURE;
    }
    if (nbr != 0) {
        write(2, "You can give more than one -dump flags\n", 39);
        return EXIT_FAILURE;
    }
    nbr += 1;
    return EXIT_SUCCESS;
}