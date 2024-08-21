//
// Created by matth on 2024/08/10.
//
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
    int pid;
    int x = 123;
    pid = fork();
    if(pid == 0){
        printf("child: x is %d\n", x);
        x = 42;
        double c = 12.0;
        int y = 9;
        sleep(1);
        printf("child: x is %d\n", x);
        printf("child: y is %p and value is %d\n", &y, y);
        printf("child: c is %p and value is %f\n", &c, c);
        printf("child : x is %d and the address is %p\n" , x , &x);
    }
    else{
        printf("mother: x is %d\n", x);
        x = 13;
        int y = 5;
        sleep(1);
        printf("mother: x is %d\n", x);
        printf("mother: y is %p and value is %d\n", &y, y);
        printf("mother : x is %d and the address is %p\n" , x , &x);
        wait(NULL);
    }
    return 0;
}