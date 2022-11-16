BS = BUFFER_SIZE=

SIZE = 7483646

SRCS = get_next_line.c \
	get_next_line_utils.c \
	main.c

SRCS_BONUS = get_next_line_bonus.c \
	get_next_line_utils_bonus.c \
	main_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

m: clean
	gcc -D ${BS}${SIZE} ${SRCS} -c
	gcc ${OBJS} -o test.out
	./test.out
	make clean

b: clean
	gcc -D ${BS}${SIZE} ${SRCS_BONUS} -c
	gcc ${OBJS_BONUS} -o test.out
	./test.out
	make clean

clean:
	rm -f *.o *.out *.gch

bench: clean
	gcc -D ${BS}${SIZE} ${SRCS} -c
	gcc ${OBJS} -o test.out
	time -p ./test.out
	make clean

bbench: clean
	gcc -D ${BS}${SIZE} ${SRCS_BONUS} -c
	gcc ${OBJS_BONUS} -o test.out
	time -p ./test.out
	make clean

valgrind: clean
	gcc -D ${BS}${SIZE} ${SRCS} -c
	gcc ${OBJS} -o test.out
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./test.out 
	make clean

bvalgrind: clean
	gcc -D ${BS}${SIZE} ${SRCS_BONUS} -c
	gcc ${OBJS_BONUS} -o test.out
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./test.out 
	make clean

libasan: clean
	gcc -D ${BS}${SIZE} -g ${SRCS} -c
	gcc ${OBJS} -fsanitize=address -o test.out
	./test.out 
	make clean

blibasan: clean
	gcc -D ${BS}${SIZE} -g ${SRCS_BONUS} -c
	gcc ${OBJS_BONUS} -fsanitize=address -o test.out
	./test.out 
	make clean