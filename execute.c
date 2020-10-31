#include "headers.h"
void execute(char** input,char *home){
    int i = 0;
    char h[10000];
    getcwd(h,10000);
    while(input[i] != NULL){
        // arg is an array of arrays containing one command ( arg[0] ) and its arguements 
        char delim[]=" \t";
        char *tok=strtok(input[i],delim);
        
        int j=0;
        
        char* arg[1000];
        while(tok!=NULL)
        {
            arg[j] = tok;
            j++;
            tok=strtok(NULL,delim);
        }
        arg[j] = NULL;
        int size = j ;
        if(strcmp(arg[0],"echo")==0){
            echo(arg,size);
        }
        else if(strcmp(arg[0],"pwd")==0){
            
            
            printf("%s\n",h);
        }
        else if(strcmp(arg[0],"cd")==0){
            if(strcmp(arg[1],"~")==0||arg[1]==NULL){
                strcpy(arg[1],home);
            }
            
            int a = chdir(arg[1]);
            if(a<0)
            {
                perror(arg[1]);
            }
        }
        else if(strcmp(arg[0],"ls")==0){
            ls(arg,size,h);

        }
        else if(strcmp(arg[0],"pinfo")==0){
            pinfo(arg,home);

        }
        else if(strcmp(arg[0],"history")==0){
            historyexec(arg);
        }
        else{
            forking(arg,j);
        }
        i++;
    }
        
}

    
