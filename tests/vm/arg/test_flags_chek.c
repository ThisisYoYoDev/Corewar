/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** check_arg
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests_func.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stderr();
}

Test(test_flag_a_1, one_arg, .init = redirect_all_stdout)
{
    const char * const argv[5] = {"./binary", "-a", "6", "champ_path", NULL};
    int index = 1;
    int exit_code;

    exit_code = check_flag_a(argv, &index, NULL);
    cr_assert_eq(exit_code, 0);
}

Test(test_flag_a_2, error_no_params, .init = redirect_all_stdout)
{
    const char * const argv[3] = {"./binary", "-a", NULL};
    int index = 1;
    int exit_code;

    exit_code = check_flag_a(argv, &index, NULL);
    cr_assert_stderr_eq_str("You must give champ file after flags\n");
    cr_assert_eq(exit_code, 1);
}

Test(test_flag_a_3, error_no_champ, .init = redirect_all_stdout)
{
    const char * const argv[4] = {"./binary", "-a", "2", NULL};
    int index = 1;
    int exit_code;

    exit_code = check_flag_a(argv, &index, NULL);
    cr_assert_stderr_eq_str("You must give champ file after flags\n");
    cr_assert_eq(exit_code, 1);
}

Test(test_flag_a_4, error_param_int, .init = redirect_all_stdout)
{
    const char * const argv[4] = {"./binary", "-a", "bad", "champ_path"};
    int index = 1;
    int exit_code;

    exit_code = check_flag_a(argv, &index, NULL);
    cr_assert_stderr_eq_str(
        "Wrong -a, loading adress must be positive integer\n");
    cr_assert_eq(exit_code, 1);
}

Test(test_flag_a_5, error_param_int, .init = redirect_all_stdout)
{
    const char * const argv[4] = {"./binary", "-a", "2bad", "champ_path"};
    int index = 1;
    int exit_code;

    exit_code = check_flag_a(argv, &index, NULL);
    cr_assert_stderr_eq_str(
        "Wrong -a, loading adress must be positive integer\n");
    cr_assert_eq(exit_code, 1);
}

Test(test_flag_a_6, error_param_int_neg, .init = redirect_all_stdout)
{
    const char * const argv[4] = {"./binary", "-a", "-2", "champ_path"};
    int index = 1;
    int exit_code;

    exit_code = check_flag_a(argv, &index, NULL);
    cr_assert_stderr_eq_str(
        "Wrong -a, loading adress must be positive integer\n");
    cr_assert_eq(exit_code, 1);
}

Test(test_flag_n_1, one_arg, .init = redirect_all_stdout)
{
    const char * const argv[5] = {"./binary", "-n", "6", "champ_path", NULL};
    int rn[16] = {0};
    int index = 1;
    int exit_code;

    exit_code = check_flag_n(argv, &index, rn);
    cr_assert_eq(exit_code, 0);
}

Test(test_flag_n_2, error_no_params, .init = redirect_all_stdout)
{
    const char * const argv[3] = {"./binary", "-n", NULL};
    int rn[16] = {0};
    int index = 1;
    int exit_code;

    exit_code = check_flag_n(argv, &index, rn);
    cr_assert_stderr_eq_str("You must give champ file after flags\n");
    cr_assert_eq(exit_code, 1);
}

Test(test_flag_n_3, error_no_champ, .init = redirect_all_stdout)
{
    const char * const argv[4] = {"./binary", "-n", "2", NULL};
    int rn[16] = {0};
    int index = 1;
    int exit_code;

    exit_code = check_flag_n(argv, &index, rn);
    cr_assert_stderr_eq_str("You must give champ file after flags\n");
    cr_assert_eq(exit_code, 1);
}

Test(test_flag_n_4, error_int_neg, .init = redirect_all_stdout)
{
    const char * const argv[5] = {"./binary", "-n", "-2", "champ", NULL};
    int rn[16] = {0};
    int index = 1;
    int exit_code;

    exit_code = check_flag_n(argv, &index, rn);
    cr_assert_stderr_eq_str("Wrong -n, prog_number must be integer\n");
    cr_assert_eq(exit_code, 1);
}

Test(test_flag_dump_1, one_arg, .init = redirect_all_stdout)
{
    const char * const argv[4] = {"./binary", "-dump", "44", NULL};
    int index = 1;
    int exit_code;

    exit_code = check_flag_dump(argv, &index, NULL);
    cr_assert_eq(exit_code, 0);
}

Test(test_flag_dump_error_1, no_arg, .init = redirect_all_stdout)
{
    const char * const argv[3] = {"./binary", "-dump", NULL};
    int index = 1;
    int exit_code;

    exit_code = check_flag_dump(argv, &index, NULL);
    cr_assert_eq(exit_code, 1);
}

Test(test_flag_dump_error_2, arg_int_neg, .init = redirect_all_stdout)
{
    const char * const argv[4] = {"./binary", "-dump", "-2", NULL};
    int index = 1;
    int exit_code;

    exit_code = check_flag_dump(argv, &index, NULL);
    cr_assert_stderr_eq_str(
        "Wrong -dump, dump_cycle must be a positive integer\n");
    cr_assert_eq(exit_code, 1);
}

Test(test_flag_dump_error_3, arg_int_bad, .init = redirect_all_stdout)
{
    const char * const argv[4] = {"./binary", "-dump", "bad", NULL};
    int index = 1;
    int exit_code;

    exit_code = check_flag_dump(argv, &index, NULL);
    cr_assert_stderr_eq_str(
        "Wrong -dump, dump_cycle must be a positive integer\n");
    cr_assert_eq(exit_code, 1);
}

Test(test_flag_dump_error_4, two_dump, .init = redirect_all_stdout)
{
    const char * const argv[5] = {"./binary", "-dump", "1", "-dump", "1"};
    int index = 1;
    int exit_code;

    exit_code = check_flag_dump(argv, &index, NULL);
    exit_code = check_flag_dump(argv, &index, NULL);
    cr_assert_eq(exit_code, 1);
}