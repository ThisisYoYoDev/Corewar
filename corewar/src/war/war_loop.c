/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** war_loop
*/

#include <stddef.h>
#include "vm_struct.h"
#include "war/war_fonc.h"
#include "enable_lib.h"
#include "prototype.h"
#include "list.h"

static void display_winner(champ_t *champs)
{
    if (champs == NULL)
        return;
    my_printf("The player %d(%s)has won.\n",
        champs->champ_id,
        champs->data.header.prog_name);
}

static int get_cycle_to_die(unsigned int move_in_cycle_to_die, vm_t *vm)
{
    if (vm->cycle_to_die == 0 ||
        (!((vm->total_cycles + 1) % vm->cycle_to_die))) {
        check_if_alive(vm->champ_list);
        vm->alive = 0;
    }
    vm->total_cycles += 1;
    return move_in_cycle_to_die;
}

void parcour_champ(vm_t *vm, champ_t *list_champ)
{
    for (int i = list_size(list_champ); i > 0 && list_champ != NULL; i--) {
        find_instruction(vm, list_champ);
        list_champ = list_champ->next;
    }
}

void start_war_loop(vm_t *vm)
{
    champ_t *head_list = vm->champ_list;
    unsigned int move_in_cycle_to_die = 0;

    head_list->champ_id = 0;
    tri_list(head_list);
    while (list_size(head_list) > 2) {
        if (vm->total_cycles == vm->dump_cycle) {
            print_memory(vm->memory, vm->memory_proprio);
            break;
        }
        move_in_cycle_to_die =
            get_cycle_to_die(move_in_cycle_to_die, vm);
        parcour_champ(vm, head_list->next);
    }
    display_winner(vm->last_alive);
}