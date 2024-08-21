all: cpu arguments hello_world fork

hello_world: hello_world.c
	gcc hello_world.c -Wall -Wextra -pedantic -o hello_world

cpu: cpu.c
	gcc cpu.c -Wall -Wextra -pedantic -o cpu

arguments: arguments.c
	gcc arguments.c -Wall -Wextra -pedantic -o arguments

fork: fork.c
	gcc fork.c -Wall -Wextra -pedantic -o fork

wait: wait.c
	gcc wait.c -Wall -Wextra -pedantic -o wait

wait-return: wait-return.c
	gcc wait-return.c -Wall -Wextra -pedantic -o wait-return

zombies: zombies.c
	gcc zombies.c -Wall -Wextra -pedantic -o zombies

clone-process: clone-process.c
	gcc clone-process.c -Wall -Wextra -pedantic -o clone-process

catch-signal: catch-signal.c
	gcc catch-signal.c -Wall -Wextra -pedantic -o catch-signal

catch-throw: catch-throw.c
	gcc catch-throw.c -Wall -Wextra -pedantic -o catch-throw

catch-test: catch-test.c
	gcc catch-test.c -Wall -Wextra -pedantic -o catch-test

loop-fork: loop-fork.c
	gcc loop-fork.c -Wall -Wextra -pedantic -o loop-fork

clean:
	rm -f cpu arguments hello_world fork clone-process catch-test