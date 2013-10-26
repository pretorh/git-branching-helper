CC=gcc

all: gbh

clean:
	rm -rf obj/
	rm -f gbh

gbh: obj/main.o
	$(CC) $^ -o $@

obj/main.o: src/main.c obj/
	$(CC) --pedantic --std=c99 -c $< -o $@

obj/:
	mkdir $@
