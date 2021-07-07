/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** init_war
*/

#include <stdlib.h>
#include "vm_struct.h"
#include "init_vm.h"
#include "macro_const.h"
#include "prototype.h"
#include "list.h"
#include "arg.h"

bool init_war(vm_t *vm, const char * const argv[], const int av)
{
    if (check_arg(argv, av))
        return EXIT_FAILURE;
    init_vm(vm);
    if (load_champ_list(vm, argv))
        return EXIT_FAILURE;
    if (dump_memory(vm))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}