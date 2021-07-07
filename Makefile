##
## EPITECH PROJECT, 2021
## Makefile for antman
## File description:
## global makefile
##

SRC_TESTS 	= 	corewar/src/tests/ref_test.c							\
				corewar/src/arg/flags_check.c						\
				corewar/src/swap_endiant.c							\
				corewar/src/arg/check_arg.c							\
				corewar/src/usage/usage.c							\
				corewar/src/init/init_vm.c							\
				corewar/src/init/init_war.c 							\
				corewar/src/init/load_champ_in_memory.c				\
				corewar/src/init/dump_memory.c						\
				corewar/src/list/add_cell.c							\
				corewar/src/list/remove_cell.c						\
				corewar/src/list/size_list.c					\
				corewar/src/init/init_champ.c				 	\
				tests/vm/list/test_list.c						\
				tests/vm/game/test_ref.c						\
				tests/vm/usage/test_usage.c						\
				tests/vm/arg/test_flags_chek.c					\
				tests/vm/arg/test_check_arg.c					\
				tests/vm/init/test_init_war.c 					\

HEADER_LIB 	=	./corewar/lib/my/include
HEADER 		=	./corewar/include
LIB 		=	./corewar/lib/my
CPPFLAGS	+=	-I ${HEADER}
CPPFLAGS	+=	-I ${HEADER_LIB}
LDFLAGS		=	-L ${LIB} -lmy

all:
	make -C asm/
	make -C corewar/

clean:
	make clean -C asm/
	make clean -C corewar/
	${RM} *gc*

fclean: clean
	make fclean -C asm/
	make fclean -C corewar/
	${RM} unit_tests

re:
	make re -C asm/
	make re -C corewar/


tests_run:
		make -C ./corewar/lib/my
		gcc -o unit_tests  $(SRC_TESTS) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS) --coverage -lcriterion
		./unit_tests

coverage:
	gcc	bonus/display_coverage.c
	gcovr --exclude tests/ > out_cover
	./a.out out_cover;
	gcovr --exclude tests/ --branch > out_cover
	./a.out out_cover;
	make clean > out_cover
	rm -f a.out
	rm -f unit_tests
	rm -f out_cover

branches:
	gcc	bonus/display_coverage.c
	gcovr --exclude tests/ > out_cover
	./a.out out_cover;
	gcovr --exclude tests/ --branch > out_cover
	./a.out out_cover;
	make clean > out_cover
	rm -f a.out
	rm -f unit_tests
	rm -f out_cover

.PHONY: all clean fclean re tests_run coverage branches