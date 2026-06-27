#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct Task {
	char name[100];
	bool completed;
};

struct Task *tasks;
int taskcount=0;


void showtask() {
	if(taskcount==0) {
		printf("No task available!\n");
		return;
	}
	for(int i=0; i<taskcount; i++) {
		printf("%d. [%s] %s\n",i+1,tasks[i].completed ? "X" : " ",tasks[i].name);
	}
}

void showhello() {
	printf("Hello there!\n");
	printf("say what u need :)\n");
}

void showexit() {
	printf("Thankyou for using Harshshell :)\n");
}

void showhelp() {
    printf(" === HarshShell Help === \n");
    printf("Available Commands:\n");
    printf("hello         - Display a greeting\n");
    printf("help          - Show this help menu\n");
    printf("about         - Information about HarshShell\n");
    printf("quote         - Display a motivational quote\n");
    printf("version       - Show current version\n");
    printf("age           - Age utility\n");
    printf("calc          - Calculate two numbers\n");
    printf("savenote      - Save a note\n");
    printf("readnote      - Display saved notes\n");
    printf("addtask       - Add a task to todo list\n");
    printf("showtask      - Show all tasks with status\n");
    printf("markcomplete  - Mark a task as completed\n");
    printf("deletetask    - Delete a task\n");
    printf("exit          - Close the program\n");
}

void showabout() {
	printf("this is a mini terminal shell project created by Harsh Rajput\n");
	printf("you can type what you want and the shell will provide the answer\n");
}

void showenter() {
	printf("please enter something\n");
}

void showuc() {
	printf("Unknown command\n");
	printf("please Enter 'help' to known about the commands\n");
}

void showversion() {
	printf("HarshShell v5.0\n");
}

void showquote() {
	printf("Never stop learning.\n");
}

void showage() {
	int age;
	printf("enter your age: \n");
	scanf("%d",&age);
	getchar();
	if(age>0 && age<13) {
		printf("you are %d years old.\n",age);
		printf("you are so young!\n");
	}
	else if(age>=13 && age<18) {
		printf("you are %d years old.\n",age);
		printf("you are teenager!\n");
		printf("you can not drive vehicle!\n");
	}
	else if(age<=0 || age>100) {
		printf("invalid age entered!\n");
	}

	else {
		printf("you are %d years old.\n",age);
		printf("you are Adult!\n");
		printf("you can drive vehicle!\n");
	}
}
void showcalc() {
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

	if(op=='+') {
		result=a+b;
		printf("The addition of %d and %d is %d.\n",a,b,result);
	}
	else if(op=='-') {
		result=a-b;
		printf("The subtraction of %d and %d is %d.\n",a,b,result);
	}
	else if(op=='*') {
		result=a*b;
		printf("The multiplication of %d and %d is %d.\n",a,b,result);
	}
	else if(op=='/') {
		if(b==0) {
			printf("Cannot divide by zero.\n");
		}
		else {
			result=a/b;
			printf("The division of %d and %d is %d.\n",a,b,result);
		}
	}
	else {
		printf("invalid input\n");
		printf("please try: +,-,*,/\n");
	}
}
void showSN() {
	FILE *file;
	char note[256];
	file=fopen("notes.txt","a");
	printf("Enter your note:\n");
	fgets(note,sizeof(note),stdin);
	fprintf(file,"%s",note);
	fclose(file);
	printf("note saved successfully!\n");
}
void showRN() {
	char note[256];
	FILE *file;
	if(file == NULL){
    printf("No notes found!\n");
    return;
	}
	file=fopen("notes.txt","r");
	while(fgets(note,sizeof(note),file)) {
		printf("%s",note);
	}
	fclose(file);
}
void savetask(){
    FILE *file = fopen("todo.txt","w");

    for(int i=0;i<taskcount;i++)
    {
        fprintf(file,"%d|%s\n",tasks[i].completed,tasks[i].name);
    }

    fclose(file);
}
void showaddtask()
{
	FILE *file;
	char task[100];

	printf("Enter Task:\n");
	fgets(task, sizeof(task), stdin);

	strcpy(tasks[taskcount].name, task);
    tasks[taskcount].completed = false;

	
	if(taskcount >= 100){
    printf("Task list full!\n");
    return;
	}

	taskcount++;
	savetask();

	printf("Task added!\n");
}
void loadtasks() {
	FILE *file;
	char task[100];

	file = fopen("todo.txt", "r");

	if(file == NULL) {
		return;
	}

	while(fscanf(file,"%d|%[^\n]\n",&tasks[taskcount].completed,tasks[taskcount].name) == 2)
    {
    taskcount++;
    }

	fclose(file);
}
void markcomplete() {
	int num;

	showtask();

	printf("Enter task number to mark complete:\n");
	scanf("%d",&num);
	getchar();

	if(num > 0 && num <= taskcount)
	{
		tasks[num-1].completed = true;
        savetask();
		printf("Task marked complete!\n");
	}
	else
	{
		printf("Invalid task number!\n");
	}
}
void deletetask() {
	int num;

	showtask();

	printf("Enter task number to delete:\n");
	scanf("%d",&num);
	getchar();

	if(num > 0 && num <= taskcount)
	{
		for(int i=num-1; i<taskcount-1; i++)
		{
			tasks[i] = tasks[i+1];
		}

		taskcount--;
        savetask();

		printf("Task deleted!\n");
	}
	else
	{
		printf("Invalid task number!\n");
	}
}


int main() {

	char input[256];
	tasks = malloc(100 * sizeof(struct Task));
	loadtasks();


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
		else if(strcmp(input,"markcomplete\n")==0)
		{
			markcomplete();
		}
		else if(strcmp(input,"deletetask\n")==0)
		{
			deletetask();
		}
		else
		{
			showuc();
		}
	}
	free(tasks);

	return 0;
}

