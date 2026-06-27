#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Task{
    char name[100];
};

struct Task tasks[100];
int taskcount=0;

void showaddtask(){
    char task[100];
    printf("Enter Task:\n");
    fgets(task,sizeof(task),stdin);
    strcpy(tasks[taskcount].name,task);
    taskcount++;
    printf("Task added!\n");
}

void showtask(){
    if(taskcount==0){
        printf("No task available!\n");
        return;
    }
    for(int i=0;i<taskcount;i++){
        printf("%d.%s",i + 1,tasks[i].name);
    }
}

void showhello(){                 
    printf("Hello there!\n");
    printf("say what u need :)\n");
}

void showexit(){                
    printf("Thankyou for using Harshshell :)\n");
}

void showhelp(){                
    printf(" === HarshShell Help === \n");
    printf("Available Commands:\n");  
    printf("hello  - Display a greeting\n");
    printf("help   - Show this help menu\n");
    printf("about  - Information about HarshShell\n");
    printf("quote  - Display a motivational quote\n");
    printf("version  - Show current version\n");
    printf("age  - Age utility\n");
    printf("calc  - calculate two numbers\n");
    printf("savenote  - save the note from user\n");
    printf("readnote  - display saved note to the user\n");
    printf("addtask  - add a task to todo list\n");
    printf("showtask  - display all tasks\n");
    printf("exit  - Close the program\n");
}

void showabout(){          
    printf("this is a mini terminal shell project created by Harsh Rajput\n");
    printf("you can type what you want and the shell will provide the answer\n");
}

void showenter(){         
    printf("please enter something\n");
}

void showuc(){           
    printf("Unknown command\n");
    printf("please Enter 'help' to known about the commands\n");
}

void showversion(){      
    printf("HarshShell v4.0\n");
}

void showquote(){       
    printf("Never stop learning.\n");
}

void showage(){        
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
void showcalc(){            
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
void showSN(){
    FILE *file;
    char note[256];
    file=fopen("notes.txt","a");
    printf("Enter your note:\n");
    fgets(note,sizeof(note),stdin);
    fprintf(file,"%s",note);
    fclose(file);
    printf("note saved successfully!\n");
}
void showRN(){
    char note[256];
    FILE *file;
    file=fopen("notes.txt","r");
    while(fgets(note,sizeof(note),file)){
        printf("%s",note);
    }
    fclose(file);
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
        else if(strcmp(input,"savenote\n")==0)
        {
            showSN();
        }
        else if(strcmp(input,"readnote\n")==0)
        {
            showRN();
        }
        else if(strcmp(input,"addtask\n")==0)
        {
            showaddtask();
        }
        else if(strcmp(input,"showtask\n")==0)
        {
            showtask();
        }
        else
        {
            showuc();
        }
    }

    return 0;
}

