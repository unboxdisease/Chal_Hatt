
#include "headers.h"

void prompt(int size) {
    
    char *name;
    name = getlogin();
    char host[1023] ;
    gethostname(host,1023);
    char dir[100000];
    getcwd(dir,100000);
    
    
    int home = strlen(dir);
    char* h = dir;
    h += size;
    
    
    // printf("%d %d",home,size);
    if(size <= home)    
        printf("<%s@%s:~%s>",name,host,h);
    else{
        printf("<%s@%s:%s>",name,host,dir);
    }

}
