#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void showhello(){                 //hello  - Display a greeting
    printf("Hello there!\n");
    printf("say what u need :)\n");
}

void showexit(){                //exit  - Close the program
    printf("Thankyou for using Harshshell :)\n");
}

void showhelp(){                 //help   - Show this help menu
    printf(" === HarshShell Help === \n");
    printf("Available Commands:\n");  
    printf("hello  - Display a greeting\n");
    printf("help   - Show this help menu\n");
    printf("about  - Information about HarshShell\n");
    printf("quote  - Display a motivational quote\n");
    printf("version  - Show current version\n");
    printf("age  - Age utility\n");
    printf("calc  - calculate two numbers\n");
    printf("exit  - Close the program\n");
}

void showabout(){          //about  - Information about HarshShell
    printf("this is a mini terminal shell project created by Harsh Rajput\n");
    printf("you can type what you want and the shell will provide the answer\n");
}

void showenter(){         //enter  - shows whitespaces
    printf("please enter something\n");
}

void showuc(){           //UC  - shows unknown command
    printf("Unknown command\n");
    printf("please Enter 'help' to known about the commands\n");
}

void showversion(){      //version  - Show current version
    printf("HarshShell v2.0\n");
}

void showquote(){       //quote  - Display a motivational quote
    printf("Never stop learning.\n");
}

void showage(){         //age  - Age utility
    int age;
    printf("enter your age: \n");
    scanf("%d",&age);
    getchar();
    if(age>0 && age<13){
        printf("you are %d years old.\n",age);
        printf("you are so young!\n");
    }
    else if(age>=13 && age<18){
        printf("you are %d years old.\n",age);
        printf("you are teenager!\n");
        printf("you can not drive vehicle!\n");
    }
    else if(age<=0 || age>100){
        printf("invalid age entered!\n");
    }
    
    else{
        printf("you are %d years old.\n",age);
        printf("you are Adult!\n");
        printf("you can drive vehicle!\n");
    }
}
void showcalc(){            //calc  - calculate two numbers
    int a,b,result;
    char op;
    printf("Enter first number: \n");
    scanf("%d",&a);
    getchar();
    printf("Enter second number: \n");
    scanf("%d",&b);
    getchar();
    printf("choose the operation to perform: + - * / \n");
    scanf("%c",&op);
    getchar();
    
    if(op=='+'){
        result=a+b;
        printf("The addition of %d and %d is %d.\n",a,b,result);
    }
    else if(op=='-'){
        result=a-b;
        printf("The subtraction of %d and %d is %d.\n",a,b,result);
    }
    else if(op=='*'){
        result=a*b;
        printf("The multiplication of %d and %d is %d.\n",a,b,result);
    }
    else if(op=='/'){
        if(b==0){
            printf("Cannot divide by zero.\n");
        }
        else{
            result=a/b;
            printf("The division of %d and %d is %d.\n",a,b,result);
        }
    }
    else{
        printf("invalid input\n");
        printf("please try: +,-,*,/\n");
    }
}  


int main() {
    
    char input[256];

    
    while(true) {

        printf("HarshShell > "); 
         

        fgets(input,sizeof(input),stdin);  

        if(strcmp(input,"exit\n")==0)
        {
            showexit();
            break;
        }
        else if(strcmp(input,"version\n")==0)
        {
            showversion();
        }
        else if(strcmp(input,"hello\n")==0)
        {
            showhello();
        }
        else if(strcmp(input,"about\n")==0)
        {
            showabout();
        }
        else if(strcmp(input,"help\n")==0)
        {
            showhelp();
        }
        else if(strcmp(input,"\n")==0)
        {
            showenter();  
        }
        else if(strcmp(input,"quote\n")==0)
        {
            showquote();
        }
        else if(strcmp(input,"age\n")==0)
        {
            showage();
        }
        else if(strcmp(input,"calc\n")==0)
        {
            showcalc();
        }
        else
        {
            showuc();
        }
    }

    return 0;
}