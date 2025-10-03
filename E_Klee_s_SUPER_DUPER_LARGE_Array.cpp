#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define MAXLINE 6

int main()
{
    int n,fdes[2];
    int pipe_ret = pipe(fdes);
    char line[MAXLINE];
    if(pipe_ret< 0)return 0;
    int pid;
    pid = fork();
    if(pid == 0)
    {
        close(fdes[1]);
        int ret = read(fdes[0],line,MAXLINE);
        write(STDOUT_FILENO,line,MAXLINE);
    }
    else
    {
        close(fdes[0]);
        write(fdes[1],"hello\n",6);
    }
    return 0;
}
