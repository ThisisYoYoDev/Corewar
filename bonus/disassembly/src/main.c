/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** main
*/

#include "disassembly.h"

void *read_all(char *file, int *size)
{
    int ar = 0;
    int fd = 0;
    char *tmp = NULL;

    if (!file) {
        handle_errors("Fichier introuvable");
    } else if ((*size = find_size_cmp(file)) == -1) {
        handle_errors("Taille du fichier inconnue");
    } else if (!(tmp = super_malloc(*size + 1))) {
        handle_errors("malloc impossible");
    } else if ((fd = open(file, O_RDONLY))) {
        ar = read(fd, tmp, *size);
        close(fd);
        if (ar == *size) {
            return tmp;
        }
    }
    handle_errors("Fichier non lisible");
    return NULL;
}

void main_dasm(char *input, char *output)
{
    int size = 0;
    int fd = 0;
    char *data = read_all(input, &size);
    header_t *h = (header_t *) data;

    if (swap(h->magic) != COREWAR_EXEC_MAGIC) {
        handle_errors("Mauvais magic number");
    } if ((fd = open(output, O_WRONLY | O_CREAT, 0644)) == -1) {
        handle_errors("Creation de fichier .s impossible");
    }
    dprintf(fd, "%s \"%s\"\n", NAME_CMD_STRING, h->prog_name);
    dprintf(fd, "%s \"%s\"\n\n", COMMENT_CMD_STRING, h->comment);
    disassembly(&data[sizeof(header_t)], swap(h->prog_size), fd);
    free(data);
}

static char *checking_file(char *file, char *tf, char *fn)
{
    char *output = NULL;

    if (strcmp(strchr(file, '.'), tf))
        return NULL;
    output = super_malloc(strlen(file) - strlen(tf) + strlen(fn) + 1);
    strncpy(output, file, strlen(file) - strlen(tf));
    strncpy(output + strlen(output), fn, strlen(fn));
    return output;
}

int main(int ac, char *av[])
{
    char *output = NULL;

    if (ac == 2) {
        if (!(output = checking_file(av[1], ".cor", ".s")))
            handle_errors("Impossible a read");
        main_dasm(av[1], output);
        return 0;
    }
    handle_errors("usage: ./disassembly \"file.cor\"\n");
    return 84;
}