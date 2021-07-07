/*
** EPITECH PROJECT, 2021
** coverage_etst
** File description:
** coverage_color add
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

char *my_gets(char *buffer, int *i)
{
    char *str = malloc(32000);
    int place = 0;

    while (buffer[*i] != '\0' && buffer[*i] != '\n') {
        str[place] =  buffer[*i];
        (*i)++;
        place++;
    }
    str[place] =  '\0';
    return str;
}

char *fill_buffer_from_file(char *argv)
{
    int file = open(argv, O_RDONLY);;
    char *buffer;
    struct stat buf;

    if (file == -1) {
        printf("%s\n", strerror(errno));
        exit(84);
    }
    stat(argv, &buf);
    buffer = malloc(buf.st_size + 2);
    read(file, buffer, buf.st_size);
    buffer[buf.st_size] = '\0';
    close(file);
    return buffer;
}

void check_percentage(char *line)
{
    int i = 0;
    int nbr;
    char *color = "\e[1;31m";
    int save;

    for(;line[i] != '%'; i++, save = i);
    for(i--; line[i] >= '0' && line[i] <= '9' && line[i]; i--);
    printf("%.*s", i, line);
    nbr = atoi(&line[i]);
    if (line[i + 1] != '%')
        if (nbr > 80)
            color = "\e[1;32m";
        else if (nbr > 50)
            color = "\e[1;33m";
        else
            color = "\e[5;91m";
    printf("%s%d%%\e[0;31m\e[1;31m%s\e[1;39m\n", color, nbr, &line[save + 1]);
}

void print_line(char *buffer_cover)
{
    int i = 0;
    char *line;

    for (; buffer_cover[i]; i++) {
        line = my_gets(buffer_cover, &i);
        if (strstr(line, "GCC "))
            printf("\e[1;91m");
        else if (strstr(line, "File"))
            printf("\e[1;33m");
        else if (strstr(line, "Directory:"))
            printf("\e[1;34m");
        if (strstr(line, "%"))
            check_percentage(line);
        else
            printf("%s\e[0;33m\e[1;39m\n", line);
        free(line);
    }
}

int main(int av, char **argv)
{
    char *buffer_cover = fill_buffer_from_file(argv[1]);

    printf("\e[1;39m");
    print_line(buffer_cover);
    printf("\e[0;39m");
    free(buffer_cover);
}
