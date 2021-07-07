/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** init_arena
*/

#include "vm_struct.h"
#include "list.h"
#include "war/war_fonc.h"

static void init_arena_proprio(vm_t *vm)
{
    champ_t *head = vm->champ_list;
    unsigned int nb_of_champ = list_size(vm->champ_list);
    int part = ARENA_SIZE / nb_of_champ;
    int memory_pos = 0;

    for (char now = 0; now < (char) nb_of_champ; now += 1) {
        head->champ_id = now;
        for (int index = 0; index < part; index += 1) {
            vm->memory_proprio[memory_pos] = head->champ_id;
            memory_pos += 1;
        }
        head = head->next;
    }
}

static void init_arena_memory(UNUSED vm_t *vm)
{

}

void init_arena(vm_t *vm)
{
    init_arena_proprio(vm);
    init_arena_memory(vm);
}