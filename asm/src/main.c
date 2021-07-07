/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** main
*/

#include "corewar_asm.h"

int main(int ac, char **av)
{
    corwar_t *corewar = NULL;

    if (ac >= 2) {
        corewar = get_asm_champ(av[1]);
        if (corewar == NULL)
            return 84;
        if (utils_asm_create_corewar_file(corewar, av[1])) {
            utils_asm_free_all(corewar);
            return 84;
        }
        utils_asm_free_all(corewar);
        return 0;
    }
    return 84;
}