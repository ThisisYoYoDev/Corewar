/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** init_vm
*/

#ifndef INIT_VM_H_
#define INIT_VM_H_

#include "vm_struct.h"

void init_vm(vm_t *vm);
bool load_champ_list(vm_t *vm, const char * const argv[]);
bool dump_memory(vm_t *vm);

#endif /* !INIT_VM_H_ */
