/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruction
*/

#include "enable_lib.h"
#include "war/war_fonc.h"
#include "instruction_tab.h"
#include "list.h"

static void check_whos_alive(champ_t *champ_list, champ_t *cur_champ, vm_t *vm)
{
    int nb_player = cur_champ->cmd_params[0];
    int i = 0;

    while (champ_list != NULL) {
        if ((int)champ_list->reg[0] == nb_player && !i) {
            my_printf("The player %d(%s)is alive.\n",
            champ_list->champ_id, champ_list->data.header.prog_name);
        }
        if ((int)champ_list->reg[0] == nb_player && vm->alive == 0) {
            vm->alive = 1;
            vm->last_alive = cur_champ;
        }
        if ((int)champ_list->reg[0] == nb_player) {
            champ_list->live_in_cycle_die = true;
            i++;
        }
        champ_list = champ_list->next;
    }
}

bool live(vm_t *vm, champ_t *cur_champ)
{
    static int nb_of_turn = -1;

    cur_champ->carry = false;
    nb_of_turn += 1;
    if (nb_of_turn == NBR_LIVE) {
        nb_of_turn = 0;
        if (vm->cycle_to_die >= CYCLE_DELTA)
            vm->cycle_to_die -= CYCLE_DELTA;
        else
            vm->cycle_to_die = 0;
    }
    check_whos_alive(vm->champ_list->next, cur_champ, vm);
    return true;
}