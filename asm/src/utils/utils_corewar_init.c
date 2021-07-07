/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** utils_corewar_init
*/

#include <stdlib.h>
#include <fcntl.h>
#include "corewar_asm.h"

header_t *utils_asm_init_header(void)
{
    header_t *h = malloc(sizeof(header_t));

    if (!h)
        return NULL;
    my_memset(h->msg_programme_name, 0, PROG_NAME_LENGTH);
    my_memset(h->msg_commentary, 0, COMMENT_LENGTH);
    my_memset(h->msg_programme_len, 0, PROG_LEN_LENGTH);
    return h;
}

void *utils_asm_free_all(corwar_t *corewar)
{
    if (corewar) {
        if (corewar->h)
            free(corewar->h);
        utils_asm_free_label_list(corewar->labels);
        utils_asm_free_list_instruction_all(corewar->instruction);
        utils_asm_free_array(corewar->champ_file);
        free(corewar);
    }
    return NULL;
}

corwar_t *utils_asm_init_corewar(void)
{
    corwar_t *corewar = malloc(sizeof(corwar_t));

    if (!corewar)
        return NULL;
    corewar->h = utils_asm_init_header();
    if (!corewar->h)
        return utils_asm_free_all(corewar);
    corewar->champ_file = NULL;
    corewar->labels = NULL;
    corewar->instruction = NULL;
    corewar->sizeof_program = 0;
    return corewar;
}

static char *utils_asm_create_file(char *s)
{
    int len = my_strlen(s);
    int j = 0;
    char *fp = NULL;

    for (; len > 0 && s[len] != '/'; --len);
    for (len = (!len) ? len : len + 1; s[len + j] != '.'; ++j);
    fp = malloc(sizeof(char) * (j + 5));
    if (!fp)
        return NULL;
    for (j = 0; s[len++] != '.'; ++j)
        fp[j] = s[len - 1];
    fp[j] = '.';
    fp[j + 1] = 'c';
    fp[j + 2] = 'o';
    fp[j + 3] = 'r';
    fp[j + 4] = '\0';
    return fp;
}

int utils_asm_create_corewar_file(corwar_t *corewar, char *s)
{
    char *fp = utils_asm_create_file(s);
    int fd = open(fp, O_CREAT | O_WRONLY, 0640);

    if (!fp || fd == -1)
        return 1;
    free(fp);
    if (write_asm_header(fd, corewar) == 0) {
        if (write_asm_instruction(fd, corewar) == 0) {
            close(fd);
            return 0;
        }
    }
    close(fd);
    return 1;
}