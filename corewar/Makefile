##
## EPITECH PROJECT, 2021
## B-CPE-201-PAR-2-1-corewar-nicolas.heude
## File description:
## Makefile
##

NAME 		=	corewar

SRCS 		=	src/main.c													\
				src/war/war_loop.c 											\
				src/init/init_vm.c											\
				src/init/init_war.c 										\
				src/init/load_champ_in_memory.c								\
				src/init/dump_memory.c										\
				src/init/init_champ.c										\
				src/arg/check_arg.c											\
				src/arg/flags_check.c										\
				src/list/try_list.c											\
				src/print/print_memory.c									\
				src/print/print_hexdump.c									\
				src/list/add_cell.c											\
				src/list/remove_cell.c										\
				src/list/size_list.c										\
				src/usage/usage.c											\
				src/war/init_arena.c										\
				src/war/check_alive.c										\
				src/instructions/arguments_type.c							\
				src/instructions/arguments_checker/operators.c				\
				src/instructions/arguments_checker/aff.c					\
				src/instructions/arguments_checker/arg_root.c				\
				src/instructions/arguments_checker/first_instruction.c		\
				src/instructions/arguments_checker/hard_instructions.c		\
				src/instructions/get_arguments/get_one_arguments.c			\
				src/instructions/instructions_root.c						\
				src/swap_endiant.c											\
				src/instructions/get_arguments/get_multiple_arguments.c  	\
				src/instructions/get_arguments/get_byte_array.c				\
				src/instructions/all_instructions/live.c					\
				src/instructions/all_instructions/fork.c					\
				src/instructions/all_instructions/aff.c						\
				src/instructions/all_instructions/ld.c						\
				src/instructions/all_instructions/st.c						\
				src/instructions/all_instructions/zjmp.c					\
				src/instructions/all_instructions/sti.c						\
				src/instructions/all_instructions/add.c						\
				src/instructions/all_instructions/and.c						\
				src/instructions/all_instructions/ldi.c						\
				src/instructions/all_instructions/lld.c						\
				src/instructions/all_instructions/lldi.c					\
				src/instructions/all_instructions/sub.c						\
				src/instructions/all_instructions/or.c						\
				src/instructions/all_instructions/xor.c						\
				src/instructions/all_instructions/lfork.c					\

SRC_TESTS 	= 	src/tests/ref_test.c								\
				src/arg/flags_check.c								\
				src/swap_endiant.c									\
				src/arg/check_arg.c									\
				src/usage/usage.c									\
				src/init/init_vm.c									\
				src/init/init_war.c 								\
				src/init/load_champ_in_memory.c						\
				src/init/dump_memory.c								\
				src/list/add_cell.c									\
				src/list/remove_cell.c								\
				src/list/size_list.c								\
				src/init/init_champ.c								\
				../tests/vm/list/test_list.c						\
				../tests/vm/game/test_ref.c							\
				../tests/vm/usage/test_usage.c						\
				../tests/vm/arg/test_flags_chek.c					\
				../tests/vm/arg/test_check_arg.c					\
				../tests/vm/init/test_init_war.c 					\

HEADER_LIB 	=	./lib/my/include
HEADER 		=	./include
LIB 		=	./lib/my
OBJS 		=	${SRCS:.c=.o}

CC			=	gcc
CFLAGS		+=	-Wall
CFLAGS		+=	-Wextra
CPPFLAGS	+=	-I ${HEADER}
CPPFLAGS	+=	-I ${HEADER_LIB}
LDFLAGS		=	-L ${LIB} -lmy

all:			lib ${NAME}

lib:
				make -C ./lib/my


${NAME}:		${OBJS}
				${CC} ${OBJS} ${LDFLAGS} -o ${NAME}

clean:
				make clean -C ./lib/my
				${RM} ${OBJS}
				${RM} *vgcore*

fclean:			clean
				make fclean -C ./lib/my
				${RM} ${NAME} unit_tests
				${RM} *.gc*

re:				fclean all

tests_run:
				make -C ./lib/my
				gcc -o unit_tests  $(SRC_TESTS) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS) --coverage -lcriterion
				./unit_tests

tests_cover :
	gcc	../bonus/display_coverage.c
	gcovr --exclude ../tests/ > out_cover
	./a.out out_cover;
	gcovr --exclude ../tests/ --branch > out_cover
	./a.out out_cover;
	make clean > out_cover
	rm -f a.out
	rm -f unit_tests
	rm -f out_cover

coverage: 		tests_run
				gcovr --exclude tests/

branches: 		tests_run
				gcovr --exclude tests/ --branches

debug:			CPPFLAGS += -g3
debug:			${NAME}

debug_re:			CPPFLAGS += -g3
debug_re:			re

.PHONY: all lib clean fclean re
