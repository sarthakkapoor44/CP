#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main (int argc, char *argv[])
{
    printf("the current pid %d\n",getpid());
    int rc = fork();
    // int pid = -100;
    // printf("*%d*",pid);
    if(rc<0){
        printf("process not created\n");
        exit(1);
    }
    else if(rc==0){
        printf(" we are in the child process with the pid %d\n",getpid());
    }
    else if(rc>0){
        // pid = wait(NULL);
        printf("we are in the parent process of %d (parent:%d)\n",rc,getpid());
    }

}