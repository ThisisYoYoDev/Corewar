/*
** EPITECH PROJECT, 2021
** tests.c
** File description:
** HEUDE Nicolas
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "test.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_reference, validation_for_ref, .init = redirect_all_std)
{
    int number = 0;
    int temp = ref_for_test(number);

    cr_assert_eq(temp, number);
}

Test(test_reference, validation_for_r, .init = redirect_all_std)
{
    int number = 1;
    int temp = ref_for_test(number);

    cr_assert_eq(temp, number);
}