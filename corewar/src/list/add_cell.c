/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** add_cell
*/

#include <stdlib.h>
#include "champ.h"

void add_cell_list(champ_t *list, champ_t *cell)
{
    if (list == NULL)
        return;
    while (list->next != NULL)
        list = list->next;
    list->next = cell;
    cell->next = NULL;
}