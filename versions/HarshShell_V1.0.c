#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    
    char input[256];

    
    while(true) {

        printf("HarshShell > "); 
         

        fgets(input,sizeof(input),stdin);  

        if(strcmp(input,"exit\n")==0)
        {
            printf("Thankyou for using Harshshell :)\n");
            break;
        }
        else if(strcmp(input,"Version\n")==0)
        {
            printf("HarshShell v1.0\n");
        }
        else if(strcmp(input,"hello\n")==0)
        {
            printf("Hello there!\n");
            printf("say what u need :)\n");
        }
        else if(strcmp(input,"about\n")==0)
        {
            printf("this is a mini terminal shell project created by Harsh Rajput\n");
            printf("you can type what you want and the shell will provide the answer\n");
        }
        else if(strcmp(input,"help\n")==0)
        {
            printf(" === HarshShell Help === \n");
            printf("Available Commands:\n");  
            printf("hello  - Display a greeting\n");
            printf("help   - Show this help menu\n");
            printf("about  - Information about HarshShell\n");
            printf("exit   - Close the program\n");
            printf("version - Show current version\n");
        }
        else if(strcmp(input,"\n")==0)
        {
            printf("please enter something\n");  
        }
        else
        {
            printf("Unknown command\n");
            printf("please kindly type help to known about the commands\n");
        }
    }

    return 0;
}