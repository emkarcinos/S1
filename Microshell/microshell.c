/* Code by Marcin Kostrzewski */
/* Linux shell project */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

/* DEFINITIONS */

#define HISTORY_SIZE 1024
#define MAX_DIR 128
#define TXT_SIZE 1024
#define ARG_SIZE 64
#define DELIMETER " \n\t\r\a"

/* COLOURS */

#define C_RED "\x1B[31m"
#define C_GREEN "\x1B[32m"
#define C_WHITE "\x1B[0m"


/* SIGNAL HANDLERS */

static int pid_global=0;

void sigcaller(int signum){
    if(pid_global==0){
        printf("\nExiting...\n");
        exit(1);
    }
}

void child_sigcalled(int signum){
    if(pid_global==0){
        printf("\nExiting program...\n");
        exit(1);
    }
}

/* HISTORY HANDLER */

static int last_history_line=0;
static char history_mem[TXT_SIZE][HISTORY_SIZE];

void history_add(char *line){
    strcpy(history_mem[last_history_line], line);
    ++last_history_line;
    if(last_history_line>=HISTORY_SIZE)
        last_history_line=0;
}

void history_print(char *lines_count){
    int count=atoi(lines_count);
    if(count>last_history_line)
            count=last_history_line;
    for(int i=last_history_line-2; count>0; i--){
        printf("%s", history_mem[i]);
        count--;
    }
}

/* BUILT IN FUNCTIONS */

void my_cd(char **arg){
    if (arg[1]==NULL){
        printf("No arguments to cd, type 'help' for more information. \n");
    } else if (arg[1][0]=='~') {
        chdir("/home");
    } else {
        int status=chdir(arg[1]);
        if(status!=0)
            perror("cd error");
    }
}

void my_exit(){
    printf("Exiting...\n");
    exit(EXIT_SUCCESS);
}

void my_touch(char **arg){
    if(access(arg[1], F_OK)!=-1){
        printf("Touch error: File alredy exists\n");
        return;
    } else {
        int fd=creat(arg[1], 0666);
        close(fd);
        if(fd==-1)
            perror("Touch error");
    }
}

void my_mkdir(char **arg){
    int status=mkdir(arg[1], 0700);
    if(status!=0)
        perror("Mkdir error");
}

void my_calc(){
    printf("Welcome to SimpleCalc by Marcin Kostrzewski\n");
    printf("Separate numbers and operators using whitespaces.\n");
    printf("Type 'exit' to end the program.\n\n");
    printf("Example syntax:\n");
    printf("'2 + 2', '5 - 4', '8*2', 7 / 2'\n");
    while(1){ 
        char line[3][50]={};
        scanf("%s", line[0]);
        if(strcmp(line[0], "exit")==0)
            exit(EXIT_SUCCESS);
        scanf("%s", line[1]);
        scanf("%s", line[2]);
        int a=atoi(line[0]), b=atoi(line[2]);
        if(strcmp(line[1], "+")==0)
            printf("%d\n", a+b); 
        if(strcmp(line[1], "-")==0)
            printf("%d\n", a-b); 
        if(strcmp(line[1], "*")==0)
            printf("%d\n", a*b); 
        if(strcmp(line[1], "/")==0)
            printf("%0.4f\n", (float)a/b); 
    }
}

void my_login(){
    char *login=getlogin();
    printf("%s\n", login);
}

void my_hist(char *arg){
    history_print(arg);
}

void my_help(){
    printf(C_GREEN "Microshell project, written by Marcin Kostrzewski.\n");
    printf("This is a functional linux shell.\n");
    printf("It can execute programs from PATH, and some of its own programs that are built in.\n\n");
    printf("Built in functions:\n");
    printf("cd [path] - changes the directory.\n");
    printf("touch [path] - creates an empty file in a given path.\n");
    printf("mkdir [path] - creates an empty directory in a given path.\n");
    printf("calc - a simple calculator program.\n");
    printf("mylogin - prints current username.\n");
    printf("help - prints this message.\n");
    printf("history [lines] - prints last X lines of history.\n");
    printf("exit - exits the shell.\n\n");
    printf("SIGINT signal is also supported (ctrl + c).\n" C_WHITE);
}

/* MAIN SHELL FUNCTIONS */

int myfunc_caller(char **arg){      /* calls built in functions */
    if(strcmp(arg[0], "cd")==0){
        my_cd(arg);
        return 0;
    } else if(strcmp(arg[0], "exit")==0){
        my_exit();
        return 0;
    } else if(strcmp(arg[0], "touch")==0){
        my_touch(arg);
        return 0;
    } else if(strcmp(arg[0], "mkdir")==0){
        my_mkdir(arg);
        return 0;
    } else if(strcmp(arg[0], "help")==0){
        my_help();
        return 0;
    } else if(strcmp(arg[0], "mylogin")==0){
        my_login();
        return 0;
    } else if(strcmp(arg[0], "history")==0){
        if(arg[1]==NULL){
            printf("Execution error: expected an argument.\n");
            return 0;
        } else {
            my_hist(arg[1]);
            return 0;
        }
    } else
    return 1;
}

int myfunc_executor_prog(char **arg){   /* same as calling, but happens in a separate, forked process */
    if(strcmp(arg[0], "calc")==0){
        my_calc();
    }
    return 1;
}

void print_current_dir(){           /* prints current working directory */  
    char dir[MAX_DIR];
    getcwd(dir, sizeof(dir));
    printf(C_RED "[%s]", dir);
    printf(C_WHITE "(msh)" C_GREEN "$ " C_WHITE);
}

char **argumentator(char* line){    /*splits a line into an array of arguments */
    char **args=(char**)malloc(sizeof(char*)*ARG_SIZE);
    char *temp;
    temp=strtok(line, DELIMETER);
    int i=0;
    while(temp!=NULL){
        args[i]=temp;
        i++;
        temp=strtok(NULL, DELIMETER);
    }
    args[i]=NULL;
    if(args[1][0]=='"' || args[1][0]=='\'')
        args[1]++;
        int lastarg_len=strlen(args[i-1])-1;
        if(args[i-1][lastarg_len]=='\'' || args[i-1][lastarg_len]=='"')
            args[i-1][lastarg_len]=NULL;
    return args;
}

void exec_(char **arg){                     /* executes an order */      
    pid_t pid;
    int status;
    pid=fork();
    pid_global=pid;
    signal(SIGINT, child_sigcalled);
    if (pid==0) {  
        if(myfunc_executor_prog(arg)!=0){       
            execvp(arg[0], arg);
            perror("Error executing a program:");
            exit(EXIT_FAILURE);
        }
    } else if (pid==-1){
        perror ("fork error");
    } else {
        wait(&status);
        pid_global=0;
    }
}

void do_instruction(){                      /* gets an order */
    char *line=(char*)malloc(sizeof(char)*TXT_SIZE);
    char **arg=(char**)malloc(sizeof(char*)*ARG_SIZE);
    char temp=*fgets(line, TXT_SIZE, stdin);
    if(temp=='\n')
        return;
    else if(temp==' ')
        temp++;
    history_add(line);
    arg=argumentator(line);
    if(myfunc_caller(arg)!=0)  
        exec_(arg);
}

int main(){                                 /* main infinite loop function */
    printf(C_GREEN "Microshell by Marcin Kostrzewski.\n Type 'help' for more info.\n" C_WHITE);
    while(1){
        signal(SIGINT, sigcaller);
        print_current_dir();
        do_instruction();
    }
    return EXIT_SUCCESS;
}