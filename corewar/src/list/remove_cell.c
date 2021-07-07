/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** remove_cell
*/

#include <stdlib.h>
#include "champ.h"

void remove_cell(champ_t *list, unsigned int pos)
{
    champ_t *temp;

    for (unsigned int i = 0; i < pos; i += 1, list = list->next) {
        temp = list;
        if (list->next == NULL)
            return;
    }
    temp->next = list->next;
    free(list);
}