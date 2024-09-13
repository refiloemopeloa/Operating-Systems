//
// Created by matth on 2024/08/27.
//

#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H
#include <stdio.h>
#include <string.h>


void generate_file(FILE *file_ptr, int n, double time_value, char file_name[], char mode[]) {
    if (strcmp(mode, "a") == 0) {
        file_ptr = fopen(file_name, mode);
        fprintf(file_ptr, "%d,%f\n", n, time_value);
        fclose(file_ptr);
    } else if (strcmp(mode, "w") == 0) {
        file_ptr = fopen(file_name, mode);
        fprintf(file_ptr, "input,time\n");
        fclose(file_ptr);
    }
}

char *get_file(FILE *file_ptr, char file_name[],  size_t length, char mode[]) {
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

#endif //FILE_HANDLING_H
