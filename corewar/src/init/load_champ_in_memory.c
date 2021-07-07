/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** load_camp_in_memory
*/

#include <stdlib.h>
#include "vm_struct.h"
#include "prototype.h"
#include "list.h"
#include "lib_prototype.h"

bool init_champ(vm_t *vm, const char * const argv[], int *id);

bool load_champ_list(vm_t *vm, const char * const argv[])
{
    for (int i = 1; argv[i] != NULL; i += 1) {
        if (!my_strcmp("-dump", argv[i])) {
            i++;
            vm->dump_cycle = my_getnbr(argv[i]);
            continue;
        }
        if (init_champ(vm, argv, &i))
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}