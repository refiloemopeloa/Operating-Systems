all: cpu arguments hello_world fork

hello_world: hello_world.c
	gcc hello_world.c -Wall -Wextra -pedantic -o hello_world

cpu: cpu.c
	gcc cpu.c -Wall -Wextra -pedantic -o cpu

arguments: arguments.c
	gcc arguments.c -Wall -Wextra -pedantic -o arguments

fork: fork.c
	gcc fork.c -Wall -Wextra -pedantic -o fork

clean:
	rm -f cpu arguments hello_world fork