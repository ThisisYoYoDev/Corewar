/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** size_list
*/

#include <stdlib.h>
#include "champ.h"

unsigned int list_size(champ_t *list)
{
    unsigned int i = 0;

    while (list != NULL) {
        list = list->next;
        i += 1;
    }
    return i;
}