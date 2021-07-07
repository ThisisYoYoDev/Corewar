/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** try_list
*/

#include <stdlib.h>
#include "champ.h"

champ_t *try_list(champ_t *my_list, champ_t *post)
{
    champ_t *first = my_list;
    champ_t *next_name = my_list;

    next_name = next_name->next;
    for (int i = 0; next_name != NULL; i++) {
        if (my_list->champ_id > next_name->champ_id) {
            my_list->next = next_name->next;
            next_name->next = my_list;
            if (i == 0) {
                first = next_name;
            } else
                post->next = next_name;
            return first;
        }
        post = my_list;
        my_list = my_list->next;
        next_name = next_name->next;
    }
    return next_name;
}

void tri_list(champ_t *list)
{
    while (list != NULL) {
        list = try_list(list, NULL);
    }
}