#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <errno.h>

#define MAX 32
char **PATH;
int path_args = 0;

char **split(size_t split_array_size, char *buffer, size_t *buffer_size, char *delimiter) {
    *(buffer_size) = 0;
    char **returned_array = (char **) malloc(sizeof(char *) * split_array_size);

    char *token = strtok(buffer, delimiter);

    while (token != NULL) {
        *(returned_array + *(buffer_size)) = token;
        *(buffer_size) = *(buffer_size) + 1;
        token = strtok(NULL, delimiter);
    }

    // while ((*(returned_array + *(buffer_size)) = strsep(&buffer, delimiter)) != NULL) {
    //     *(buffer_size) = *(buffer_size) + 1;
    // }
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

char *reform_string(int start,char **split_array, size_t split_array_size, size_t char_size) {
    char *new_string = (char *) malloc(char_size * sizeof(char));
    for (int i = start; i < split_array_size - 1; i++) {
        strcat(new_string, split_array[i]);
        strcat(new_string, " ");
    }
    strcat(new_string, split_array[split_array_size - 1]);
    return new_string;
}

char *valid_path(char *exe) {
    char *path = (char *) malloc(MAX * sizeof(char));
    strcpy(path, PATH[0]);
    strcat(path, exe);
    if (access(path, X_OK) == 0) {
        return path;
    }

    return "\0";
}

void command(char **arg_list) {
    char *path = valid_path(arg_list[0]);
    if (path[0] == '\0') {
        perror(arg_list[0]);
        return;
    }
    if (execv(path, arg_list) == -1) {
        perror(arg_list[0]);
        fprintf(stderr, "'%s' doesn't exist.\n", arg_list[0]);
    }
}

int write_to_file(int *original_array, char file_name[], char args[][256], int key) {
    int original_out = dup(STDOUT_FILENO); // save the current state of the stdout file descriptor
    int original_err = dup(STDERR_FILENO);

    int file_desc = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    //open the file with writing permissions or create the file if it doesnt exist

    if (file_desc != -1) {
        //open returns -1 if the open operation is unsuccessful
        fflush(stdout); //clear the stdout stream
        fflush(stderr); //clear the stderr stream

        dup2(file_desc, STDOUT_FILENO); //direct output from stdout to file
        dup2(file_desc, STDERR_FILENO); //direct output from stderr to file
        close(file_desc); //close file

        command(args);

        //original_array[0] = original_out;
        //original_array[1] = original_err;
        return 0;
    } else {
        perror("Error opening the file.\n");
        return -1;
    }
}

void close_file(int original_out, int original_err) {
    fflush(stdout); //clear stdout stream
    fflush(stderr); //clear stderr stream
    dup2(original_out,STDOUT_FILENO); //restore original stdout
    dup2(original_out,STDERR_FILENO); //restore original stderr
    close(original_out);
    close(original_err);
}

void redirect(char **split_array, int split_array_size, int key) {
    if (split_array_size - 1 != key + 1) {
        perror("Enter one file for redirection only.\n");
        return;
    }
    if (strcmp(split_array[key + 1], ">")==0) {
        perror("Enter \">\" followed by a file name.");
        return;
    }
    char **args = (char **) malloc(sizeof(char *)*(key+1));

    for (int i = 0; i < key; i++) {
        args[i] = split_array[i];
    }
    args[key] = NULL;

    int original_out[2] = {-1,-1};
    int original_out_result = write_to_file(original_out, split_array[key + 1], args, key);
    close_file(original_out[0], original_out[1]);
}

int *parallel_positions(char **split_array, int split_array_size, int count) {
    int *positions = (int *) malloc(count * sizeof(int));
    for (int i = 0, j=0; i < split_array_size; i++) {
        if (strcmp(split_array[i], "&")==0) {
            positions[j] = i;
            j++;
        }
    }
        return positions;
}

int parallel_check(char **split_array, int split_array_size) {
    int count = 0;
    for (int i = 0; i < split_array_size; i++) {
        if (strcmp(split_array[i], "&")==0) {
            count++;
        }
    }
    return count;
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

    split_array = split(split_array_size, buffer, &split_array_size, " \t");

    if (strcmp(split_array[0], "exit") == 0) {
        if (split_array_size > 1) {
            errno = E2BIG;
            perror("exit");
            fprintf(stderr, "exit accepts no arguments.\n");
            return;
        }
        free(split_array);
        exit(0);
    }


    if (strcmp(split_array[0], "cd") == 0) {
        char *apostrophe_str = apostrophe_string(reform_string(1,split_array, split_array_size, character_count),
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

    if (strcmp(split_array[0], "path") == 0) {
        if (split_array_size == 1) {
            if (path_args == 0)
                strcpy(PATH[0], "");
            else
                for (int i = 0; i < path_args; i++)
                    strcpy(PATH[i], "");
            path_args = split_array_size;
            return;
        } else {
            path_args = split_array_size - 1;
            for (int i = 1; i < split_array_size; i++) {
                strcpy(PATH[i - 1], split_array[i]);
                return;
            }
        }
    }

    int parallel_count = parallel_check(split_array, split_array_size);
    if (parallel_count < 1) {
        pid_t p = fork();
        if (p == 0) {
            for (int i = 0; i < split_array_size; i++) {
                if (strcmp(split_array[i], ">") == 0) {
                    redirect(split_array, split_array_size, i);
                    exit(0);
                }
            }
            command(split_array);
            exit(0);
        } else {
            waitpid(-1, status, 0);
        }
    }
    else if (parallel_count > 0) {
        int *parallel_pos = parallel_positions(split_array, split_array_size, parallel_count);
        char *reformed_string = reform_string(0,split_array,split_array_size, character_count);
        char **parallel_args = split(parallel_count+1,reformed_string, &parallel_count, " & ");

        for (int i=0; i<parallel_count;i++) {
            if (fork() == 0) {
                int current_arg_size=0;
                char **current_arg = split(MAX, parallel_args[i],&current_arg_size," \t");
                for (int i = 0; i < current_arg_size; i++) {
                    if (strcmp(current_arg[i], ">") == 0) {
                        redirect(current_arg, current_arg_size, i);
                        exit(0);
                    }
                }
                command(current_arg);
                exit(0);
            }
        }
        for (int i=0; i<parallel_count+1;i++) {
            waitpid(-1, status, 0);
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
    int split_array_size=MAX;
    char **split_array = (char **) malloc(sizeof(char *) * MAX);
    int status;

    PATH = (char **) malloc(sizeof(char *) * MAX);
    for (int i = 0; i < MAX; i++) {
        PATH[i] = (char *) malloc(sizeof(char) * 256);
    }
    strcpy(PATH[0], "/bin/");

    bool is_batch = false;
    if (MainArgc > 1) {
        is_batch = true;
    }
    if (!is_batch) {
        //interactive mode
        while (1) {
            printf("shell> ");
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
