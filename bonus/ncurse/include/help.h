/*
** EPITECH PROJECT, 2021
** COREWAR
** File description:
** usage
*/

#ifndef HELP_H_
#define HELP_H_

#include <stdbool.h>
#include "enable_lib.h"

static const char *HELP = "USAGE\n"\
    "./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address]"\
    " prog_name] ...\n\n"\
    "DESCRIPTION\n"\
    "\t-dump nbr_cycle dumps the memory after the nbr_cycle execution"\
    " (if the round isn’t\n\t\t"\
    "already over) with the following format: 32 bytes/line\n\t\t"\
    "in hexadecimal (A0BCDEFE1DD3...)\n"\
    "\t-n prog_number sets the next program’s number."\
    " By default, the first free number\n\t\t"\
    "in the parameter order\n"\
    "\t-a load_address sets the next program’s loading address. "\
    "When no address is\n\t\t"
    "specified, optimize the addresses so that the processes "\
    "are as far\n\t\taway from each other as possible. "\
    "The addresses are MEM_SIZE modulo.\n";

#endif /* !HELP_H_ */