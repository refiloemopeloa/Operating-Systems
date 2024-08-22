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
    char *buffer; //address of first character of string input
    size_t buffer_size = 0; //size of input buffer

    //printf("witsshell> ");      //shell input prompt

    //get input string and store in buffer, change size of input buffer
    size_t character_count;
    // = getline(&buffer, &buffer_size, stdin);     //number of characters stored in character_count

    //buffer[strcspn(buffer, "\n")] = 0;      // remove '\n' from end of line
    int split_array_size;
    char **split_array = (char **) malloc(sizeof(char *) * MAX);
    int status;
    //split(split_array, buffer, &split_array_size);
    //for (int i = 0; i < split_array_size; i++) {
    //    printf("%s\n", split_array[i]);
    //}

    while (1) {
        // printf("You typed: %s", buffer);
        printf("witsshell> ");
        character_count = getline(&buffer, &buffer_size, stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        if (strcmp(buffer, "exit") == 0) {
            free(split_array);
            exit(0);
        }
        split(split_array, buffer, &split_array_size);
        // for (int i = 0; i < split_array_size; i++) {
        //     printf("%s\n", split_array[i]);
        // }
        pid_t p = fork();
        if (p == 0) {
            if (strcmp(split_array[0], "echo") == 0) {
                if (split_array_size < 2) {
                    printf("\n");
                } else {
                    for (int i = 1; i < split_array_size - 1; i++) {
                        printf("%s ", split_array[i]);
                    }
                    printf("%s\n", split_array[split_array_size - 1]);
                }
            }
            exit(0);
        } else {
            waitpid(-1, &status, 0);
        }

        // free(split_array);
    }
}
