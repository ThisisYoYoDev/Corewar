/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** get_code
*/

#include "corewar_asm.h"

int get_asm_code(int i, corwar_t *corewar)
{
    label_lnk_t *sl = NULL;
    instruction_lnk_t *st = NULL;

    for (; corewar->champ_file[i]; ++i)
        if ((utils_corewar_line_test(corewar->champ_file[i]) &&
            label_asm_add_label_new(i, corewar, &sl)) ||
            (utils_corewar_line_test(corewar->champ_file[i]) &&
            instruction_asm_add(i, corewar, &st)))
            return 1;
    corewar->instruction = st;
    corewar->labels = sl;
    return 0;
}

static int get_asm_os(char *s)
{
    int rt = 0;

    for (; s[rt] && (s[rt] == ' ' || s[rt] == '\t'); ++rt);
    return rt;
}

static int get_asm_filler_header(char *s, char *pm, char *id, int ms)
{
    int i = get_asm_os(s);

    if (my_strncmp(s + i, id, my_strlen(id)))
        return 1;
    i += my_strlen(id);
    i += get_asm_os(s + i);
    if (s[i++] != '"')
        return 2;
    for (int j = 0; s[i] && s[i] != '"'; pm[j++] = s[i++])
        if (j >= ms)
            return 2;
    if (!s[i])
        return 2;
    if (utils_corewar_line_test(s + ++i))
        return 1;
    return 0;
}

int get_asm_header(char **cf, header_t *h)
{
    int status = 0;
    int i = 0;

    for (int ret = 0; status != 2 && cf[i]; ++i) {
        if (utils_corewar_line_test(cf[i])) {
            ret = (status == 0) ?
            get_asm_filler_header(cf[i], h->msg_programme_name,
            ".name", PROG_NAME_LENGTH) :
            get_asm_filler_header(cf[i], h->msg_commentary,
            ".comment", COMMENT_LENGTH);
            if ((ret != 0 && status == 0) || (ret == 2 && status == 1))
                return -1;
            if (ret == 1 && status == 1)
                return i;
            status++;
        }
    }
    return (status < 1) ? -1 : i;
}