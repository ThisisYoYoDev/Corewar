/*
** EPITECH PROJECT, 2021
** tests
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

Test(check_arg_1, normal, .init = redirect_all_stdout)
{
    const int av = 7;
    const char * const argv[8] = {"./binary",
        "-a", "6", "-n", "2", "champ_path", "champ_path", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 0);
}

Test(check_arg_2, normal, .init = redirect_all_stdout)
{
    const int av = 7;
    const char * const argv[8] = {"./binary",
        "-n", "6", "-a", "2", "champ_path", "champ_path", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 0);
}

Test(check_arg_3, normal, .init = redirect_all_stdout)
{
    const int av = 5;
    const char * const argv[6] = {"./binary",
        "-n", "6", "champ_path", "champ_path", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 0);
}

Test(check_arg_4, normal, .init = redirect_all_stdout)
{
    const int av = 5;
    const char * const argv[6] = {"./binary",
        "-a", "6", "champ_path", "champ_path", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 0);
}

Test(check_arg_5, normal, .init = redirect_all_stdout)
{
    const int av = 3;
    const char * const argv[4] = {"./binary",
        "champ_path", "champ_path", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 0);
}

Test(check_arg_6, normal, .init = redirect_all_stdout)
{
    const int av = 4;
    const char * const argv[4] = {"./binary",
        "champ_path", "champ_path", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 0);
}

Test(check_arg_7, normal, .init = redirect_all_stdout)
{
    const int av = 6;
    const char * const argv[6] = {"./binary", "-a",
        "10", "champ_path", "champ_path", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 0);
}

Test(check_arg_8, normal, .init = redirect_all_stdout)
{
    const int av = 8;
    const char * const argv[8] = {"./binary", "-a",
        "10", "champ_path", "-n", "32", "champ_path", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 0);
}

Test(check_arg_9, normal, .init = redirect_all_stdout)
{
    const int av = 6;
    const char * const argv[6] = {"./binary", "champ_path",
        "-n", "32", "champ_path", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 0);
}

Test(check_arg_10, normal, .init = redirect_all_stdout)
{
    const int av = 8;
    const char * const argv[8] = {"./binary", "-n", "12",
        "champ_path", "-n", "32", "champ_path", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 0);
}

Test(check_arg_10, normal_dump, .init = redirect_all_stdout)
{
    const int av = 5;
    const char * const argv[6] = {"./binary", "-dump",
        "77", "champ_path", "champ_path", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 0);
}

Test(check_arg_error_1, error, .init = redirect_all_stdout)
{
    const int av = 3;
    const char * const argv[3] = {"./binary", "-n",  NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 1);
}

Test(check_arg_error_2, error, .init = redirect_all_stdout)
{
    const int av = 4;
    const char * const argv[4] = {"./binary", "-n", "2", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 1);
}

Test(check_arg_error_3, error, .init = redirect_all_stdout)
{
    const int av = 4;
    const char * const argv[4] = {"./binary", "-n", "-2", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 1);
}

Test(check_arg_error_4, error, .init = redirect_all_stdout)
{
    const int av = 4;
    const char * const argv[4] = {"./binary", "-n", "path_file", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 1);
}

Test(check_arg_error_5, error, .init = redirect_all_stdout)
{
    const int av = 3;
    const char * const argv[3] = {"./binary", "-a",  NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 1);
}

Test(check_arg_error_6, error, .init = redirect_all_stdout)
{
    const int av = 4;
    const char * const argv[4] = {"./binary", "-a", "2", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 1);
}

Test(check_arg_error_7, error, .init = redirect_all_stdout)
{
    const int av = 4;
    const char * const argv[4] = {"./binary", "-a", "-2", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 1);
}

Test(check_arg_error_8, error, .init = redirect_all_stdout)
{
    const int av = 4;
    const char * const argv[4] = {"./binary", "-a", "path_file", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 1);
}

Test(check_arg_error_9, error, .init = redirect_all_stdout)
{
    const int av = 7;
    const char * const argv[7] = {"./binary", "-a",
        "22", "-a", "33", "path_file", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 1);
}

Test(check_arg_error_10, error, .init = redirect_all_stdout, .exit_code = 84)
{
    const int av = 8;
    const char * const argv[8] = {"./binary", "-n", "22",
        "path_file", "-n", "22", "path_file", NULL};

    check_arg(argv, av);
}

Test(check_arg_error_11, error, .init = redirect_all_stdout)

{
    const int av = 8;
    const char * const argv[8] = {"./binary", "-n", "22",
        "-a", "-22", "path_file", "path_file", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 1);
}

Test(check_arg_error_12, error_dump, .init = redirect_all_stdout)
{
    const int av = 5;
    const char * const argv[5] = {"./binary", "-dump",
        "e", "champ_path", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 1);
}

Test(check_arg_error_13, error_dump, .init = redirect_all_stdout)
{
    const int av = 4;
    const char * const argv[4] = {"./binary", "-dump", "2", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 1);
}

Test(check_arg_error_14, error_dump, .init = redirect_all_stdout)
{
    const int av = 6;
    const char * const argv[6] = {"./binary", "-dump",
        "2", "-dump", "2", NULL};
    int exit_code;

    exit_code = check_arg(argv, av);
    cr_assert_eq(exit_code, 1);
}