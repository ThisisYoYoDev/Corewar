##
## EPITECH PROJECT, 2021
## B-CPE-201-PAR-2-1-corewar-nicolas.heude
## File description:
## Makefile
##

NAME 		=	ncurse_corewar

SRCS 		=	src/main.c																	\
				src/graphical_loop.c														\
				src/ncurse_live.c															\
				src/colors.c																\
				src/music.c																	\
				src/window.c																\
				../../corewar/src/war/war_loop.c 											\
				../../corewar/src/init/init_vm.c											\
				../../corewar/src/init/init_war.c 											\
				../../corewar/src/init/load_champ_in_memory.c								\
				../../corewar/src/init/dump_memory.c										\
				../../corewar/src/init/init_champ.c											\
				../../corewar/src/arg/check_arg.c											\
				../../corewar/src/arg/flags_check.c											\
				../../corewar/src/print/print_memory.c										\
				../../corewar/src/print/print_hexdump.c										\
				../../corewar/src/list/add_cell.c											\
				../../corewar/src/list/try_list.c											\
				../../corewar/src/list/remove_cell.c										\
				../../corewar/src/list/size_list.c											\
				../../corewar/src/usage/usage.c												\
				../../corewar/src/war/init_arena.c											\
				../../corewar/src/war/check_alive.c											\
				../../corewar/src/instructions/arguments_type.c								\
				../../corewar/src/instructions/arguments_checker/operators.c				\
				../../corewar/src/instructions/arguments_checker/aff.c						\
				../../corewar/src/instructions/arguments_checker/arg_root.c					\
				../../corewar/src/instructions/arguments_checker/first_instruction.c		\
				../../corewar/src/instructions/arguments_checker/hard_instructions.c		\
				../../corewar/src/instructions/get_arguments/get_one_arguments.c			\
				../../corewar/src/instructions/instructions_root.c							\
				../../corewar/src/swap_endiant.c											\
				../../corewar/src/instructions/get_arguments/get_multiple_arguments.c  		\
				../../corewar/src/instructions/get_arguments/get_byte_array.c				\
				../../corewar/src/instructions/all_instructions/fork.c						\
				../../corewar/src/instructions/all_instructions/aff.c						\
				../../corewar/src/instructions/all_instructions/ld.c						\
				../../corewar/src/instructions/all_instructions/st.c						\
				../../corewar/src/instructions/all_instructions/zjmp.c						\
				../../corewar/src/instructions/all_instructions/sti.c						\
				../../corewar/src/instructions/all_instructions/add.c						\
				../../corewar/src/instructions/all_instructions/and.c						\
				../../corewar/src/instructions/all_instructions/ldi.c						\
				../../corewar/src/instructions/all_instructions/lld.c						\
				../../corewar/src/instructions/all_instructions/lldi.c						\
				../../corewar/src/instructions/all_instructions/sub.c						\
				../../corewar/src/instructions/all_instructions/or.c						\
				../../corewar/src/instructions/all_instructions/xor.c						\
				../../corewar/src/instructions/all_instructions/lfork.c						\

HEADER_LIB 	=	../../corewar/lib/my/include
HEADER 		=	./include
LIB 		=	../../corewar/lib/my
OBJS 		=	${SRCS:.c=.o}

CC			=	gcc
CFLAGS		+=	-Wall
CFLAGS		+=	-Wextra
CPPFLAGS	+=	-I ${HEADER}
CPPFLAGS	+=	-I ${HEADER_LIB}
LDFLAGS		=	-L ${LIB} -lmy -lncurses -lcsfml-audio

all:			lib ${NAME}

lib:
				make -C ../../corewar/lib/my


${NAME}:		${OBJS}
				${CC} ${OBJS} ${LDFLAGS} -o ${NAME}

clean:
				make clean -C ../../corewar/lib/my
				${RM} ${OBJS}
				${RM} *vgcore*

fclean:			clean
				make fclean -C ../../corewar/lib/my
				${RM} ${NAME} unit_tests
				${RM} *.gc*

re:				fclean all

debug:			CPPFLAGS += -g3
debug:			${NAME}

debug_re:			CPPFLAGS += -g3
debug_re:			re

.PHONY: all lib clean fclean re
