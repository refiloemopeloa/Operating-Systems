#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>

#define MAX 32
char **PATH;
int path_args = 0;

char **split(size_t split_array_size, char *buffer, size_t *buffer_size, char *delimiter) {
    *(buffer_size) = 0;
    char **returned_array = (char **) malloc(sizeof(char *) * split_array_size);
    while ((*(returned_array + *(buffer_size)) = strsep(&buffer, delimiter)) != NULL) {
        *(buffer_size) = *(buffer_size) + 1;
    }
    return returned_array;
}

char *get_file(FILE *file_ptr, char file_name[], size_t length, char mode[]) {
    if (strcmp(mode, "rb") == 0) {
        file_ptr = fopen(file_name, mode);
        if (file_ptr) {
            fseek(file_ptr, 0, SEEK_END);
            length = ftell(file_ptr);
            fseek(file_ptr, 0, SEEK_SET);
            char *file_contents = (char *) malloc(length * sizeof(char));
            if (file_contents) {
                fread(file_contents, sizeof(char), length, file_ptr);
            }
            fclose(file_ptr);
            return file_contents;
        } else {
            fprintf(stderr, "%s does not exist.", file_name);
            fclose(file_ptr);
            // return;
        }
    } else {
        fprintf(stderr, "Please use te get_file() method with ""rb"" mode");
        // return;
    }
}


char *apostrophe_string(char *reformed_string, size_t string_size) {
    char *token = strchr(reformed_string, '\'');
    char *token_string = (char *) malloc(sizeof(char) * string_size);
    char *returned_string = (char *) malloc(sizeof(char) * string_size);
    strcpy(token_string, reformed_string);
    token_string = strtok(token_string, "\'");
    if (token == NULL)
        return NULL;
    if (token_string != NULL)
        strcat(returned_string, token_string);
    int count = 0;
    while (token != NULL) {
        count++;
        token = token + 1;
        token_string = strtok(NULL, "\'");
        if (token_string != NULL)
            strcat(returned_string, token_string);
        token = strchr(token, '\'');
    }

    if (count % 2 != 0) {
        return NULL;
    }

    return returned_string;
}

char *reform_string(char **split_array, size_t split_array_size, size_t char_size) {
    char *new_string = (char *) malloc(char_size * sizeof(char));
    for (int i = 1; i < split_array_size - 1; i++) {
        strcat(new_string, split_array[i]);
        strcat(new_string, " ");
    }
    strcat(new_string, split_array[split_array_size - 1]);
    return new_string;
}


void shell(size_t character_count, char *buffer, size_t *buffer_size, char **split_array, int split_array_size,
           int *status, char *mode) {
    if (strcmp(mode, "interactive") == 0) {
        buffer = NULL;
        character_count = getline(&buffer, buffer_size, stdin);
        if (character_count == -1) {
            exit(0);
        }
        // character_count = *buffer_size;
        buffer[strcspn(buffer, "\n")] = 0;
    }

    split_array = split(split_array_size, buffer, &split_array_size, " ");

    if (strcmp(buffer, "exit") == 0) {
        free(split_array);
        exit(0);
    }


    if (strcmp(split_array[0], "cd") == 0) {
        char *apostrophe_str = apostrophe_string(reform_string(split_array, split_array_size, character_count),
                                                 character_count);
        if (apostrophe_str != NULL) {
            if (chdir(apostrophe_str) != 0) {
                fprintf(stderr, "The specified directory does not exist.\n");
            }
            free(apostrophe_str);
            return;
        } else {
            if (split_array_size == 2) {
                if (chdir(split_array[1]) != 0) {
                    fprintf(stderr, "The specified directory does not exist.\n");
                }
                return;
            } else if (split_array_size != 2) {
                fprintf(
                    stderr,
                    "Please enter cd folllowed by a directory. For directories with spaces, please surround the directory string with ''.\n");
                return;
            }
        }
    }
}


int main(int MainArgc, char *MainArgv[]) {
    char *buffer; //address of first character of string input
    size_t buffer_size = 0; //size of input buffer

    //get input string and store in buffer, change size of input buffer
    size_t character_count;
    // = getline(&buffer, &buffer_size, stdin);     //number of characters stored in character_count

    //buffer[strcspn(buffer, "\n")] = 0;      // remove '\n' from end of line
    int split_array_size;
    char **split_array = (char **) malloc(sizeof(char *) * MAX);
    int status;


    bool is_batch = false;
    if (MainArgc > 1) {
        is_batch = true;
    }
    if (!is_batch) {
        //interactive mode
        while (1) {
            printf("witsshell> ");
            shell(character_count, buffer, &buffer_size, split_array, split_array_size, &status, "interactive");
        }
    } else {
        //batch mode
        FILE *batch_file;
        char *file_name = MainArgv[1];
        size_t argument_length;
        char *file_contents = get_file(batch_file, file_name, character_count, "rb");
        char **argument_list = (char **) malloc(sizeof(char *) * MAX);
        split(argument_list, file_contents, &argument_length, "\n");
        int i = 0;
        while (1) {
            shell(character_count, argument_list[i], &buffer_size, split_array, split_array_size, &status, "batch");
            i++;
        }
        free(argument_list);
    }
    free(split_array);
}
