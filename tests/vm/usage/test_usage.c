/*
** EPITECH PROJECT, 2021
** tests.c
** File description:
** HEUDE Nicolas
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "test.h"

Test(test_usage, valide_usage, .init = redirect_all_std)
{
    int av = 2;
    const char * const argv[] = {"program", "-h"};

    cr_assert_eq(check_usage(av, argv), true);
}

Test(test_usage, wrong_usage, .init = redirect_all_std)
{
    int av = 2;
    const char * const argv[] = {"program", "-i"};

    cr_assert_eq(check_usage(av, argv), false);
}

Test(test_usage, wrong_av, .init = redirect_all_std)
{
    int av = 1;
    const char * const argv[] = {"program"};

    cr_assert_eq(check_usage(av, argv), false);
}