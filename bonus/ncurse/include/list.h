/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** list
*/

#ifndef LIST_H_
#define LIST_H_

#include "champ.h"

void add_cell_list(champ_t *list, champ_t *cell);
void remove_cell(champ_t *list, unsigned int pos);
unsigned int list_size(champ_t *list);
champ_t *try_list(champ_t *my_list, champ_t *post);
void tri_list(champ_t *list);

#endif /* !LIST_H_ */
