all:
	gcc *.c -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit -o test

clean:
	rm -fv *.o

fclean: clean
	rm -fv test

test: all
	./test
