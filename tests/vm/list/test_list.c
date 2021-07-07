/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** test_list
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests_func.h"

Test(list, remove_list, .init = cr_redirect_stderr)
{
    const int av = 4;
    const char * const argv[4] = {"./binary",
        "bonus/asm/result_asm_file/abel.cor",
        "bonus/asm/result_asm_file/abel.cor", NULL};
    vm_t vm = {0};

    init_war(&vm, argv, av);
    remove_cell(vm.champ_list, 1);
    cr_assert_eq(vm.champ_list->next->champ_id, 2);
}

Test(list_erro_2, remove_list_error, .init = cr_redirect_stderr)
{
    const int av = 4;
    const char * const argv[4] = {"./binary",
        "corewar/champ/abel.cor", "corewar/champ/abel.cor", NULL};
    vm_t vm = {0};

    init_war(&vm, argv, av);
    remove_cell(vm.champ_list, 3);
}

Test(list_erro_1, null_list, .init = cr_redirect_stderr)
{
    add_cell_list(NULL, NULL);
}
