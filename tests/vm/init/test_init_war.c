/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** test_init_war
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests_func.h"

static void asser_champ(champ_t *champ, int id)
{
    cr_assert_eq(champ->champ_id, id);
    cr_assert_eq(champ->carry, 0);
    cr_assert_eq(champ->live_in_cycle_die, 0);
    cr_assert_eq(champ->live, 1);
}

Test(init_war_1, normal, .init = cr_redirect_stderr)
{
    const int av = 3;
    const char * const argv[4] = {"./binary",
        "bonus/asm/result_asm_file/abel.cor",
        "bonus/asm/result_asm_file/abel.cor", NULL};
    int exit_code;
    vm_t vm = {0};

    exit_code = init_war(&vm, argv, av);
    cr_assert_eq(exit_code, 0);
    asser_champ(vm.champ_list->next, 1);
}

Test(init_war_2, normal_two_champ, .init = cr_redirect_stderr)
{
    const int av = 3;
    const char * const argv[4] = {"./binary",
        "bonus/asm/result_asm_file/abel.cor",
        "bonus/asm/result_asm_file/abel.cor", NULL};
    int exit_code;
    vm_t vm = {0};

    exit_code = init_war(&vm, argv, av);
    cr_assert_eq(exit_code, 0);
    asser_champ(vm.champ_list->next, 1);
    asser_champ(vm.champ_list->next->next, 2);
}

Test(init_war_3, normal_two_champ_oneflag, .init = cr_redirect_stderr)
{
    const int av = 5;
    const char * const argv[6] = {"./binary", "-n", "2",
        "bonus/asm/result_asm_file/abel.cor",
        "bonus/asm/result_asm_file/abel.cor", NULL};
    int exit_code;
    vm_t vm = {0};

    exit_code = init_war(&vm, argv, av);
    cr_assert_eq(exit_code, 0);
    asser_champ(vm.champ_list->next, 2);
    asser_champ(vm.champ_list->next->next, 1);
}

Test(init_war_4, normal_two_champ_twoflag, .init = cr_redirect_stderr)
{
    const int av = 7;
    const char * const argv[8] = {"./binary", "-n", "2",
        "bonus/asm/result_asm_file/abel.cor", "-n", "4",
        "bonus/asm/result_asm_file/abel.cor", NULL};
    int exit_code;
    vm_t vm = {0};

    exit_code = init_war(&vm, argv, av);
    asser_champ(vm.champ_list->next, 2);
    asser_champ(vm.champ_list->next->next, 4);
    cr_assert_eq(exit_code, 0);
}

Test(init_war_5, normal_one_champ_oneflag, .init = cr_redirect_stderr)
{
    const int av = 5;
    const char * const argv[6] = {"./binary", "-a", "2",
        "bonus/asm/result_asm_file/abel.cor",
        "bonus/asm/result_asm_file/abel.cor", NULL};
    int exit_code;
    vm_t vm = {0};

    exit_code = init_war(&vm, argv, av);
    asser_champ(vm.champ_list->next, 1);
    cr_assert_eq(vm.champ_list->next->pc_pose, 2);
    cr_assert_eq(vm.memory_proprio[1], 0);
    cr_assert_eq(vm.memory_proprio[2], 1);
    cr_assert_eq(exit_code, 0);
}

Test(init_war_6, normal_one_champ_twoflag, .init = cr_redirect_stderr)
{
    const int av = 7;
    const char * const argv[8] = {"./binary", "-a", "2", "-n", "4",
        "bonus/asm/result_asm_file/abel.cor",
        "bonus/asm/result_asm_file/abel.cor", NULL};
    int exit_code;
    vm_t vm = {0};

    exit_code = init_war(&vm, argv, av);
    asser_champ(vm.champ_list->next, 4);
    cr_assert_eq(vm.champ_list->next->pc_pose, 2);
    cr_assert_eq(vm.memory_proprio[1], 0);
    cr_assert_eq(vm.memory_proprio[2], 4);
    cr_assert_eq(exit_code, 0);
}

Test(init_war_7, normal_two_champ_twoflag, .init = cr_redirect_stderr)
{
    const int av = 11;
    const char * const argv[12] = {"./binary", "-a", "2", "-n", "4",
        "bonus/asm/result_asm_file/abel.cor", "-a", "50", "-n", "2",
        "bonus/asm/result_asm_file/abel.cor", NULL};
    int exit_code;
    vm_t vm = {0};

    exit_code = init_war(&vm, argv, av);
    asser_champ(vm.champ_list->next, 4);
    cr_assert_eq(vm.champ_list->next->pc_pose, 2);
    cr_assert_eq(vm.memory_proprio[1], 0);
    cr_assert_eq(vm.memory_proprio[2], 4);
    cr_assert_eq(exit_code, 0);
    asser_champ(vm.champ_list->next->next, 2);
    cr_assert_eq(vm.champ_list->next->next->pc_pose, 50);
    cr_assert_eq(vm.memory_proprio[50], 2);
    cr_assert_eq(exit_code, 0);
}

Test(init_war_8, normal_champ_dump, .init = cr_redirect_stderr)
{
    const int av = 11;
    const char * const argv[12] = {"./binary", "-dump", "2", "-a",
        "2", "bonus/asm/result_asm_file/abel.cor", "-a", "50",
        "-n", "2", "bonus/asm/result_asm_file/abel.cor", NULL};
    int exit_code;
    vm_t vm = {0};

    exit_code = init_war(&vm, argv, av);
    asser_champ(vm.champ_list->next, 1);
    cr_assert_eq(vm.champ_list->next->pc_pose, 2);
    cr_assert_eq(vm.dump_cycle, 2);
    cr_assert_eq(vm.memory_proprio[1], 0);
    cr_assert_eq(vm.memory_proprio[2], 1);
    cr_assert_eq(exit_code, 0);
    asser_champ(vm.champ_list->next->next, 2);
    cr_assert_eq(vm.champ_list->next->next->pc_pose, 50);
    cr_assert_eq(vm.memory_proprio[50], 2);
    cr_assert_eq(exit_code, 0);
}

Test(init_war_9, number_inverse, .init = cr_redirect_stderr)
{
    const int av = 5;
    const char * const argv[6] = {"./binary",
        "bonus/asm/result_asm_file/abel.cor",
        "-n", "1", "bonus/asm/result_asm_file/abel.cor", NULL};
    int exit_code;
    vm_t vm = {0};

    exit_code = init_war(&vm, argv, av);
    asser_champ(vm.champ_list->next, 2);
    asser_champ(vm.champ_list->next->next, 1);
    cr_assert_eq(exit_code, 0);
}

Test(init_war_10, normal_one_champ_twoflag_inverse, .init = cr_redirect_stderr)
{
    const int av = 7;
    const char * const argv[8] = {"./binary",
        "-n", "4", "-a", "2", "bonus/asm/result_asm_file/abel.cor",
        "bonus/asm/result_asm_file/abel.cor", NULL};
    int exit_code;
    vm_t vm = {0};

    exit_code = init_war(&vm, argv, av);
    asser_champ(vm.champ_list->next, 4);
    cr_assert_eq(vm.champ_list->next->pc_pose, 2);
    cr_assert_eq(vm.memory_proprio[1], 0);
    cr_assert_eq(vm.memory_proprio[2], 4);
    cr_assert_eq(exit_code, 0);
}

Test(init_war_eroro_1, wrong_path_name, .init = cr_redirect_stderr)
{
    const int av = 3;
    const char * const argv[4] = {"./binary", "so_bad", "so_bad", NULL};
    int exit_code;
    vm_t vm = {0};

    exit_code = init_war(&vm, argv, av);
    cr_assert_eq(exit_code, 1);
}

Test(init_war_erro_2, wrong_dump_memory, .init = cr_redirect_stderr)
{
    const int av = 5;
    const char * const argv[6] = {"./binary",
        "bonus/asm/result_asm_file/abel.cor",
        "-a", "10", "bonus/asm/result_asm_file/abel.cor", NULL};
    int exit_code;
    vm_t vm = {0};

    exit_code = init_war(&vm, argv, av);
    cr_assert_eq(exit_code, 1);
}

Test(init_war_erro_3, wrong_params, .init = cr_redirect_stderr)
{
    const int av = 5;
    const char * const argv[6] = {"./binary",
        "bonus/asm/result_asm_file/abel.cor", "-a", "e",
        "bonus/asm/result_asm_file/abel.cor", NULL};
    int exit_code;
    vm_t vm = {0};

    exit_code = init_war(&vm, argv, av);
    cr_assert_eq(exit_code, 1);
}

Test(init_war_erro_3, wrong_params_no_champ, .init = cr_redirect_stderr)
{
    const int av = 1;
    const char * const argv[2] = {"./binary", NULL};
    int exit_code;
    vm_t vm = {0};

    exit_code = init_war(&vm, argv, av);
    cr_assert_eq(exit_code, 1);
}

Test(init_war_erro_4, wrong_params_no_champ, .init = cr_redirect_stderr)
{
    const int av = 3;
    const char * const argv[4] = {"./binary",
        "bonus/asm/result_asm_file/abel.cor",
        "bonus/asm/result_asm_file/fluttershy_err_magic.cor", NULL};
    int exit_code;
    vm_t vm = {0};

    exit_code = init_war(&vm, argv, av);
    cr_assert_stderr_eq_str("Wrong binary file\n");
    cr_assert_eq(exit_code, 1);
}