/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** write_header
*/

#include <unistd.h>
#include "corewar_asm.h"

static void write_asm_program_length(int fd, corwar_t *corewar)
{
    char wr[PROG_LEN_LENGTH] = {0};
    char *bytes = (char *) &(corewar->sizeof_program);
    int i = 0;

    for (; i < PROG_LEN_LENGTH; ++i)
        wr[i] = bytes[PROG_LEN_LENGTH - 1 - i];
    write(fd, wr, PROG_LEN_LENGTH);
}

int write_asm_header(int fd, corwar_t *corewar)
{
    write(fd, "\0", 1);
    write(fd, COREWAR_EXEC_MAGIC_STR,
    my_strlen((char *) COREWAR_EXEC_MAGIC_STR));
    write(fd, corewar->h->msg_programme_name, PROG_NAME_LENGTH);
    write_asm_program_length(fd, corewar);
    write(fd, corewar->h->msg_commentary, COMMENT_LENGTH);
    write(fd, "\0\0\0\0", 4);
    return 0;
}

static int write_asm_param(int fd, parameter_t *p, label_lnk_t *label, int pos)
{
    int n = 0;

    for (int i = 0; p[i].msg_parameter; ++i) {
        if (p[i].is_param_label) {
            if (write_asm_label(fd, &(p[i]), label, pos))
                return 1;
        } else {
            n = sp_getnbr(p[i].msg_parameter, NULL);
            if (write_asm_val(fd, n, p[i].parameter_size))
                return 1;
        }
    }
    return 0;
}

static void write_asm_bytes(int fd, int id, int bytes)
{
    char s[1] = {0};

    s[0] = id;
    write(fd, s, 1);
    if (bytes != -1) {
        s[0] = bytes;
        write(fd, s, 1);
    }
}

int write_asm_instruction(int fd, corwar_t *corewar)
{
    for (; corewar->instruction; corewar->instruction =
    corewar->instruction->next) {
        write_asm_bytes(fd,
        corewar->instruction->lnk_instruction_data->instruct_id,
        corewar->instruction->lnk_instruction_data->instruct_byte);
        if (write_asm_param(fd,
        corewar->instruction->lnk_instruction_data->p_instruct,
        corewar->labels,
        corewar->instruction->lnk_instruction_data->instruct_coord))
            return 1;
    }
    return 0;
}