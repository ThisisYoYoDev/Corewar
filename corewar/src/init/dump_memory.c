/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** dump_memory
*/

#include <stdlib.h>
#include "vm_struct.h"
#include "list.h"
#include "lib_prototype.h"

void give_prog_number(unsigned char *prog_nbr, \
unsigned char *champs_nbr, champ_t *head)
{
    champ_t *list;

    if (*prog_nbr != 0)
        return;
    while (1) {
        for (list = head; list != NULL && list->champ_id != *champs_nbr;
            list = list->next);
        if (list == NULL)
            break;
        (*champs_nbr)++;
    }
    *prog_nbr = *champs_nbr;
    (*champs_nbr)++;
}

bool fill_prog_in_memory(vm_t *vm, const champ_t *champ)
{
    for (int i = 0; i < champ->data.header.prog_size; i++) {
        if (vm->memory[(champ->pc_pose + i) % MEM_SIZE] != 0)
            return write(2, "Champ can't overlap during loading\n", 35);
        vm->memory[(champ->pc_pose + i) % MEM_SIZE] = champ->data.programe[i];
        vm->memory_proprio[(champ->pc_pose + i) % MEM_SIZE] = champ->champ_id;
    }
    return EXIT_SUCCESS;
}

bool dump_memory(vm_t *vm)
{
    champ_t *list = vm->champ_list->next;
    unsigned char champ_nb = 1;
    int dec = MEM_SIZE / list_size(list);
    int nbr = 0;

    while (list != NULL) {
        give_prog_number(&list->champ_id, &champ_nb, vm->champ_list->next);
        list->reg[0] = list->champ_id;
        if (list->pc_pose == 0) {
            list->pc_pose = dec * (nbr);
            list->instruction_pc = list->pc_pose;
        }
        if (fill_prog_in_memory(vm, list))
            return EXIT_FAILURE;
        list = list->next;
        nbr++;
    }
    return EXIT_SUCCESS;
}