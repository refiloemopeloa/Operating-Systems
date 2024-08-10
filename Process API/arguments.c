#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    printf("Program name: %s\n", argv[0]);
    
    printf("Arguments: ");
    // TODO: Print all the arguments given to the program.
    //
    //       Separate multiple arguments using commas on one line.
    //       e.g. "Arguments: arg1,arg2,arg3"
    //
    //       Print "NONE" if no arguments are present.
    char str[128];


    if(argc <= 1) {
	/*COMPLETE HERE*/
        printf("NONE");

 
    } else {
        strcpy(str, argv[1]);
        for(int i = 2; i < argc; ++i) {
	    /*COMPLETE HERE*/
            if (i==argc-1) {
                strcat(str,",");
                strcat(str,argv[i]);
            }
            else {
                strcat(str,",");
                strcat(str,argv[i]);
            }
        }
    }
    printf("%s\n", str);

    return 0;
}
