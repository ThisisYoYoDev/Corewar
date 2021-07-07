/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** vm_struct
*/

#ifndef VM_STRUCT_H_
#define VM_STRUCT_H_

#include "champ.h"

enum VM_CONSTS {
    MEM_SIZE = 6144,
    CYCLE_TO_DIE = 1536,
    CYCLE_DELTA = 5,
    NBR_LIVE = 40
};

typedef struct vm_s
{
    champ_t *champ_list;
    champ_t *last_alive;
    int alive;
    char memory_proprio[MEM_SIZE];
    unsigned char memory[MEM_SIZE];
    unsigned int cycle_to_die;
    int nbr_cycle_to_die;
    int total_cycles;
    int dump_cycle;
} vm_t;

#endif /* !VM_STRUCT_H_ */
