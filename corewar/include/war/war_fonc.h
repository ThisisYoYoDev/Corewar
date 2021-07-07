/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** war_fonc
*/

#ifndef WAR_FONC_H_
#define WAR_FONC_H_

#include <limits.h>
#include "vm_struct.h"

#define UNUSED __attribute__((unused))
#define OVERFLOW(a, b) ((a > 0 && b > 0 && a > (INT_MAX - b)) || \
    (a < 0 && b < 0 && a > (INT_MIN - b)))
#define NEG_OVERFLOW(a, b) ((a > 0 && b < 0 && a > (INT_MAX - (b * -1))) || \
    (a < 0 && b > 0 && a > (INT_MIN - (b * -1))))
#define REG(c) (c > 0 && c <= 16)
#define STI_POS ((champ->pc_pose + ((values[0] + values[1]) \
    % IDX_MOD) + i) % MEM_SIZE)
#define ST_POS ((champ->pc_pose + ((champ->cmd_params[1]) \
    % IDX_MOD) + i) % MEM_SIZE)
static const int ARENA_SIZE = 6144;

void start_war_loop(vm_t *vm);
void init_arena(vm_t *vm);
void check_if_alive(champ_t *champ_list);
void find_instruction(vm_t *vm, champ_t *champ);

// ____INSTRUCTIONS
bool live(vm_t *vm, champ_t *champ);
bool ld(vm_t *vm, champ_t *champ);
bool st(vm_t *vm, champ_t *champ);
bool add(vm_t *vm, champ_t *champ);
bool sub(vm_t *vm, champ_t *champ);
bool and(vm_t *vm, champ_t *champ);
bool or(vm_t *vm, champ_t *champ);
bool xor(vm_t *vm, champ_t *champ);
bool zjmp(vm_t *vm, champ_t *champ);
bool ldi(vm_t *vm, champ_t *champ);
bool sti(vm_t *vm, champ_t *champ);
bool fork_instruction(vm_t *vm, champ_t *champ);
bool lld(vm_t *vm, champ_t *champ);
bool lldi(vm_t *vm, champ_t *champ);
bool lfork(vm_t *vm, champ_t *champ);
bool aff(vm_t *vm, champ_t *champ);

// ____instruction_checker
int check_params(vm_t *vm, champ_t *champ, unsigned char cur_pos);
bool check_live(vm_t *vm, champ_t *champ, char current_pos);
bool check_ld(vm_t *vm, champ_t *champ, char current_pos);
bool check_st(vm_t *vm, champ_t *champ, char current_pos);
bool check_add(vm_t *vm, champ_t *champ, char current_pos);
bool check_sub(vm_t *vm, champ_t *champ, char current_pos);
bool check_and(vm_t *vm, champ_t *champ, char current_pos);
bool check_or(vm_t *vm, champ_t *champ, char current_pos);
bool check_xor(vm_t *vm, champ_t *champ, char current_pos);
bool check_zjmp(vm_t *vm, champ_t *champ, char current_pos);
bool check_ldi(vm_t *vm, champ_t *champ, char current_pos);
bool check_sti(vm_t *vm, champ_t *champ, char current_pos);
bool check_fork(vm_t *vm, champ_t *champ, char current_pos);
bool check_lld(vm_t *vm, champ_t *champ, char current_pos);
bool check_lldi(vm_t *vm, champ_t *champ, char current_pos);
bool check_lfork(vm_t *vm, champ_t *champ, char current_pos);
bool check_aff(vm_t *vm, champ_t *champ, char current_pos);

// _____get arguments foncs
int get_reg(unsigned char reg, unsigned int *pc);
int get_direct_indirect(unsigned int *pc,
    unsigned char *memory, int direct_indirect_index);
int *get_arguments_types(unsigned char descryption, int args_counter);
void extract_one_argument(vm_t *vm, champ_t *champ, int i);
void extract_arguments(vm_t *vm, champ_t *champ, int instruction);
unsigned char *get_byte_array(int number, unsigned char bytes[]);

#endif /* !WAR_FONC_H_ */