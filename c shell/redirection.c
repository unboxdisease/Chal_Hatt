#include "headers.h"

int redirection(char **arg, char *home, int size)
{
    int f1 = 0, f2 = 0, f3 = 0;
    int fd, curr ,start,end = size;
    char in[10000];
    char out[10000];

    for (int i = 0; i < size; i++)
    {
        if (!(strcmp(arg[i], "<") == 0)==0)
        {
            strcpy(in,arg[i+1]);
            f1 = i;
            end = i;
        }
        if (strcmp(arg[i], ">") == 0)
        {
            strcpy(out, arg[i + 1]);
            
            fd = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            close(fd);
            f2 = i;
            if(f2<end){
                end = f2;
            }
        }
        if (strcmp(arg[i], ">>") == 0)
        {
            strcpy(out, arg[i + 1]);
            
            fd = open(out, O_WRONLY | O_CREAT | O_APPEND, 0644);
            close(fd);
            f3 = i;
            if(f3<end){
                end = f3;
            }
        }
    }
          
    
    if (f1 == 0 && f2 == 0 && f3 == 0)
    {
        return 0;
    }
    // printf("red-%d",end);
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        int fd2;
        if (f1)
        {
            struct stat inp;
            if (stat(in, &inp) < 0)
            {
                perror(in);
            }
            
            fd2 = open(in, O_RDONLY, 0644);
            // printf("%d\n",fd2);
            if (dup2(fd2, 0) < 0)
            {
                perror("dup2 failed");
                return 0;
            }
            close(fd2);
        }
        if (f2>f3)
        {
            fd = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (dup2(fd, 1) < 0)
            {
                perror("dup2 failed");
                return 0;
            }
            close(fd);
        }
        else if (f3>f2)
        {
            fd = open(out, O_WRONLY | O_CREAT | O_APPEND, 0644);
            if (dup2(fd, 1) < 0)
            {
                perror("dup2 failed");
                return 0;
            }
            close(fd);
        }

        
        
        execute(arg , home, end );

        exit(0);
    }
    else
    {
        wait(NULL);
    }
    return 1;
}