/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** init_champ
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include "vm_struct.h"
#include "lib_prototype.h"
#include "prototype.h"
#include "list.h"
#include "arg.h"
#include "macro_const.h"

bool read_header(int fd, headers_t *header)
{
    read(fd, header, sizeof(headers_t));
    header->magic = swap_endian_color(header->magic);
    if (header->magic != COREWAR_EXEC_MAGIC)
        return EXIT_FAILURE;
    header->prog_size = swap_endian_color(header->prog_size);
    return EXIT_SUCCESS;
}

void read_instruction(int fd, int size, char **programe)
{
    *programe = malloc(size);
    read(fd, *programe, size);
}

static void load_flags(const char * const argv[], int *i, champ_t *new_champ)
{
    int pose = 0;

    if (!my_strcmp(argv[*i], flag_arg_tab[FLAG_N].fonc_id)) {
        flag_arg_tab[FLAG_N].load_arg(my_getnbr(argv[*i + 1]), new_champ);
        pose += 2;
    }
    if (!my_strcmp(argv[*i], flag_arg_tab[FLAG_A].fonc_id)) {
        flag_arg_tab[FLAG_A].load_arg(my_getnbr(argv[*i + 1]), new_champ);
        pose += 2;
    }
    if (pose && !my_strcmp(argv[*i + 2], flag_arg_tab[FLAG_N].fonc_id)) {
        flag_arg_tab[FLAG_N].load_arg(my_getnbr(argv[*i + 3]), new_champ);
        pose += 2;
    }
    if (pose && !my_strcmp(argv[*i + 2], flag_arg_tab[FLAG_A].fonc_id)) {
        flag_arg_tab[FLAG_A].load_arg(my_getnbr(argv[*i + 3]), new_champ);
        pose += 2;
    }
    (*i) += pose;
}

static void init_champ_status(champ_t *new_champ)
{
    new_champ->carry = false;
    new_champ->live = true;
    new_champ->live_in_cycle_die = false;
    new_champ->cycle_before_instruction = -1;
}

bool init_champ(vm_t *vm, const char * const argv[], int *i)
{
    champ_t *new_champ = malloc(sizeof(champ_t));
    int fd = 0;

    my_memset(new_champ, 0, sizeof(champ_t));
    load_flags(argv, i, new_champ);
    fd = open(argv[*i], O_RDONLY);
    if (fd == -1) {
        write(2, "Wrong champ filepath\n", 21);
        return EXIT_FAILURE;
    }
    if (read_header(fd, &new_champ->data.header)) {
        write(2, "Wrong binary file\n", 18);
        return EXIT_FAILURE;
    }
    read_instruction(fd, new_champ->data.header.prog_size,
        &new_champ->data.programe);
    init_champ_status(new_champ);
    add_cell_list(vm->champ_list, new_champ);
    close(fd);
    return EXIT_SUCCESS;
}