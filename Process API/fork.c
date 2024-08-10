//
// Created by matth on 2024/08/10.
//
#include <stdio.h>
#include <unistd.h>
int main(){
    int pid = fork();
    printf("pid = %d\n" , pid);
    return 0;
}