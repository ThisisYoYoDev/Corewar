/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** champions is alive
*/

#include <stddef.h>
#include "vm_struct.h"
#include "war/war_fonc.h"
#include "enable_lib.h"
#include "list.h"

void check_if_alive(champ_t *champ_list)
{
    int i = 1;
    champ_t *head = champ_list;
    champ_t *prec = champ_list;

    for (champ_t *champs = champ_list->next; head->next != NULL
        && champs != NULL; champs = champs->next) {
        if (champs->live_in_cycle_die == false) {
            prec->next = champs->next;
            i -= 1;
            champs->live = false;
            champs = prec;
        }
        champs->live_in_cycle_die = false;
        prec = champs;
        i += 1;
    }
}