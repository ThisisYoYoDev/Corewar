/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** music_foncs
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

sfMusic *init_theme(void)
{
    sfMusic *theme = sfMusic_createFromFile("assets/eiffel-65-blue-da-ba-dee.ogg");

    sfMusic_play(theme);
    sfMusic_setLoop(theme, sfTrue);
    sfMusic_setVolume(theme, 20);
    return theme;
}