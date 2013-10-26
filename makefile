CC=gcc
Sources := src/main.c

objs := $(patsubst src/%.c,obj/%.o,$(Sources))

all: obj/ depfile.mk gbh

.PHONY: depfile.mk
depfile.mk:
	@$(CC) -MM $(Sources) | sed 's/\(.*\)/obj\/\1/' > $@
-include depfile.mk

clean:
	rm -rf obj/
	rm -f gbh depfile.mk

gbh: $(objs)
	$(CC) $^ -o $@

obj/%.o: src/%.c
	$(CC) -ggdb -pedantic -Wall -Wextra --std=c99 -c $< -o $@

obj/:
	mkdir $@
