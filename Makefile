DEPS=funciones.h

programa: main.o funciones.o $(DEPS)
	gcc -o programa main.o funciones.o

%.o: %.c $(DEPS)
	gcc -c -o $@ $<

.PHONY: clean run
clean:
	rm -f programa *.o

run: programa
	./programa
