#include "headers.h"
void execute(char** arg,char *home,int size){
    if(redirection(arg,home,size)){
        return;
    }
    int i = 0;
    char h[10000];
    getcwd(h,10000);
    
        if(strcmp(arg[0],"echo")==0){
            echo(arg,size);
        }
        else if(strcmp(arg[0],"pwd")==0){
            
            
            printf("%s\n",h);
        }
        else if(strcmp(arg[0],"cd")==0){
            char prev[1000];
            if(strcmp(arg[1],"~")==0||arg[1]==NULL){
                strcpy(arg[1],home);
            }
            if(strcmp(arg[1],"-")==0){
                int size_ = strlen(home);
                char *j = prev;
                j += size_;
    
    
                // printf("%d %d",home,size);
                if(size_ <= strlen(prev))    
                    printf("~%s\n",j);
                else{
                    printf("%s\n",prev);
                }
            }
            else{
                int a = chdir(arg[1]);
                if(a<0)
                {
                    perror(arg[1]);
                }
                else{
                    strcpy(prev,h);
                }
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
        else if(strcmp(arg[0],"setenv")==0){
            if(setenv(arg[1],arg[1],1)<0 || size>2){
                perror("error");
            }
        }
        else if(strcmp(arg[0],"unsetenv")==0){
            if(unsetenv(arg[1])<0 || size>2){
                perror("error");
            }
        }
        else if(strcmp(arg[0],"jobs")==0){
            jobs();
        }
        else if(strcmp(arg[0],"kjob")==0){
            kjobs(arg,size);
        }
        else if(strcmp(arg[0],"fg")==0){
            fg(arg,size);
        }
         else if(strcmp(arg[0],"bg")==0){
            bg2(arg,size);
        }
        else if(strcmp(arg[0],"overkill")==0){
            overkill();
        }
        else if(strcmp(arg[0],"quit")==0 || quit1 == 1){
            quit1=1;
        }
        
        else{
            forking(arg,size);
        }
        
        
}

    
