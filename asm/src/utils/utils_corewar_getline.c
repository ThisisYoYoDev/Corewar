/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** utils_corewar_getline
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "corewar_asm.h"

static int utils_corewar_file_name(char *champ_file)
{
    int i = my_strlen(champ_file);

    if (i < 3)
        return -1;
    return my_strcmp(".s", champ_file + i - 2);
}

static int utils_corewar_open_champ(char *champ_file)
{
    if (utils_corewar_file_name(champ_file))
        return -1;
    return open(champ_file, O_RDONLY);
}

char **utils_corewar_getline(char *champ_file)
{
    char *t = NULL;
    char **array = NULL;
    int fd = utils_corewar_open_champ(champ_file);
    int len = 0;
    int i = 0;

    if (fd == -1)
        return NULL;
    for (; (t = my_get_next_line(fd)) != NULL; ++len)
        free(t);
    (void) lseek(fd, 0, SEEK_SET);
    array = malloc(sizeof(char *) * (len + 1));
    if (!array)
        return NULL;
    for (array[len] = NULL; (t = my_get_next_line(fd)) != NULL; ++i)
        array[i] = t;
    return array;
}
