/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** ncurse display
*/

#include <stddef.h>
#include <ncurses.h>
#include <stdio.h>
#include "vm_struct.h"
#include "war/war_fonc.h"
#include "enable_lib.h"
#include "prototype.h"
#include "list.h"
#include "ncurse_fonc.h"
#include "SFML/Audio.h"

void parcour_champ(vm_t *vm, champ_t *list_champ);

static void display_winner(champ_t *champs)
{
    sfMusic *end = sfMusic_createFromFile("assets/mortalkorewar.wav");

    if (champs == NULL) {
        sfMusic_destroy(end);
        return;
    }
    sfMusic_play(end);
    sfMusic_setVolume(end, 20);
    clear();
    refresh();
    mvprintw(LINES / 2, COLS / 2 - 26, "The player %d(%s)has won.",
        champs->champ_id,
        champs->data.header.prog_name);
    refresh();
    sleep(5);
    sfMusic_destroy(end);
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

void graphical_war_loop(vm_t *vm)
{
    champ_t *head_list = vm->champ_list;
    unsigned int move_in_cycle_to_die = 0;
    WINDOW *wind = init_window();
    sfMusic *theme = init_theme();

    vm->cycle_to_die = 10000;
    init_colors();
    while (list_size(head_list) > 2) {
        box(stdscr, '|', '_');
        if (vm->total_cycles == vm->dump_cycle) {
            print_memory(vm->memory, vm->memory_proprio);
            break;
        }
        move_in_cycle_to_die = get_cycle_to_die(move_in_cycle_to_die, vm);
        parcour_champ(vm, head_list->next);
        display_map(vm, wind);
    }
    sfMusic_stop(theme);
    display_winner(vm->last_alive);
    endwin();
    sfMusic_destroy(theme);
}