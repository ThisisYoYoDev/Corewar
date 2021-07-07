/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** tests_main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar_asm.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_reference, Asombra_test, .init = redirect_all_std)
{
    corwar_t *corewar = NULL;
    char *av[] = {"./asm", "../bonus/asm/file_test_asm/Asombra.s", NULL};
    void *res = NULL;

    corewar = get_asm_champ(av[1]);
    (void) utils_asm_create_corewar_file(corewar, av[1]);
    res = utils_asm_free_all(corewar);
    cr_assert_eq(res, NULL);
}

Test(test_reference, abel_test, .init = redirect_all_std)
{
    corwar_t *corewar = NULL;
    char *av[] = {"./asm", "../bonus/asm/file_test_asm/abel.s", NULL};
    void *res = NULL;

    corewar = get_asm_champ(av[1]);
    (void) utils_asm_create_corewar_file(corewar, av[1]);
    res = utils_asm_free_all(corewar);
    cr_assert_eq(res, NULL);
}

Test(test_reference, honeybadger_test, .init = redirect_all_std)
{
    corwar_t *corewar = NULL;
    char *av[] = {"./asm", "../bonus/asm/file_test_asm/_honeybadger.s", NULL};
    void *res = NULL;

    corewar = get_asm_champ(av[1]);
    (void) utils_asm_create_corewar_file(corewar, av[1]);
    res = utils_asm_free_all(corewar);
    cr_assert_eq(res, NULL);
}

Test(test_reference, big_feet_test, .init = redirect_all_std)
{
    corwar_t *corewar = NULL;
    char *av[] = {"./asm", "../bonus/asm/file_test_asm/big_feet.s", NULL};
    void *res = NULL;

    corewar = get_asm_champ(av[1]);
    (void) utils_asm_create_corewar_file(corewar, av[1]);
    res = utils_asm_free_all(corewar);
    cr_assert_eq(res, NULL);
}