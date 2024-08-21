#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>

#define MAX 32

void split(char **split_array, char *buffer, int *buffer_size) {
    *(buffer_size) = 0;
    while ((*(split_array + *(buffer_size)) = strsep(&buffer, " ")) != NULL) {
        *(buffer_size) = *(buffer_size) + 1;
    }
}

int main(int MainArgc, char *MainArgv[]) {
    char *buffer;
    size_t buffer_size = 0;
    printf("witsshell> ");
    size_t character_count = getline(&buffer, &buffer_size, stdin);
    int split_array_size;
    char **split_array = (char **) malloc(sizeof(char *) * MAX);
    split(split_array, buffer, &split_array_size);
    for (int i = 0; i < split_array_size; i++) {
        printf("%s\n", split_array[i]);
    }

    while (strcmp(buffer, "exit\n") != 0) {
        // printf("You typed: %s", buffer);
        printf("witsshell> ");
        split(split_array, buffer, &split_array_size);
        for (int i = 0; i < split_array_size; i++) {
            printf("%s\n", split_array[i]);
        }

        // free(split_array);
        character_count = getline(&buffer, &buffer_size, stdin);
    }

    free(split_array);
    exit(0);
}
