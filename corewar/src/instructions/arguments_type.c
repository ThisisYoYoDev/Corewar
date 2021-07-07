/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** get arguments for instructions
*/

#include <stdbool.h>
#include "war/war_fonc.h"
#include "instruction_tab.h"
#include "enable_lib.h"
#include "prototype.h"

static char *hex_to_bin_str(unsigned char descryption)
{
    char *bin_str = my_calloc(9, sizeof(char));

    for (int i = 7; i >= 0; i -= 1) {
        bin_str = my_strcat(bin_str, (descryption & (1 << i) ? "1" : "0"));
    }
    return bin_str;
}

int get_reg(unsigned char reg, unsigned int *pc)
{
    *pc += 1;
    return (int) reg;
}

int get_direct_indirect(unsigned int *pc,
    unsigned char *memory, int direct_indirect_index)
{
    int value = 0;
    unsigned char mem[4] = {0};

    if (direct_indirect_index == DIR_SIZE) {
        for (int i = 0; i < 4; i += 1)
            mem[i] = memory[(*pc + i) % MEM_SIZE];
        value = swap_endian_color(*((int *)mem));
        *pc += 4;
    } else if (direct_indirect_index == IND_SIZE) {
        for (int i = 2; i < 4; i += 1)
            mem[i] = memory[(*pc + i - 2) % MEM_SIZE];
        value = swap_endian_color(*((int *)mem));
        value = (short) memory[(*pc + value) % MEM_SIZE];
        *pc += 2;
    } else {
        for (int i = 2; i < 4; i += 1)
            mem[i] = memory[(*pc + i - 2) % MEM_SIZE];
        value = swap_endian_color(*((int *)mem));
        *pc += 2;
    }
    return value;
}

int *get_arguments_types(unsigned char descryption, int args_counter)
{
    int *types = my_calloc(4, sizeof(int));
    char *bin_str = hex_to_bin_str(descryption);
    int types_index = 0;

    for (size_t i = 0; i < 8 && types_index < args_counter; i += 2) {
        if (bin_str[i] == '0' && bin_str[i + 1] == '1')
            types[types_index] = 1;
        if (bin_str[i] == '1' && bin_str[i + 1] == '1')
            types[types_index] = 2;
        if (bin_str[i] == '1' && bin_str[i + 1] == '0')
            types[types_index] = 4;
        types_index += 1;
    }
    free(bin_str);
    return types;
}