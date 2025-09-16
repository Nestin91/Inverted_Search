SRC	:=	$(wildcard	*.c)

OBJ	:=	$(patsubst	%c,	%o,	$(SRC))

inverted_search.out : $(OBJ)
	gcc	-o	$@	$^

clean:
	rm	*.o	*.out