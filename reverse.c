
#include<stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h> 
extern int errno; 

int main( int argc, char *argv[] ) 
{ 
    char print[500];
    if(argc == 1){
        sprintf(print,"provide input\n");
        write(1,print,strlen(print));
        return 0;
        
    }
       
    int fd = open(argv[1], O_RDONLY | O_CREAT); 
    long long fileLength = lseek(fd, 0, SEEK_END);
    int check;
    mkdir("Assignment",0700); 
    
    char s[120]="Assignment/";
	strcat(s,argv[1]);
    int fileOut = open(s, O_RDWR | O_APPEND |O_CREAT|O_TRUNC,0600);
    if (fd < 0 || fileOut < 0 )
    {
        sprintf(print,"Error in file operations : source error: %d dest error: %d", fd,fileOut);
        write(1,print,strlen(print));
        return 0;
        
    }
    lseek(fileOut, 0, SEEK_SET);
    lseek(fd, -1, SEEK_END);
    int chunk = 10000000; 
    char *c, *r;
    c = (char *)malloc(chunk);
    r = (char *)malloc(chunk);
    long long start = ((fileLength - 1) / chunk) * chunk;
    long long chunk2 = fileLength - start;
    lseek(fd, start, SEEK_SET);
    double percent = 0;
    int chunkcount=0;
    while (1)
    {
        chunkcount++;
        read(fd, c, chunk2);
        int end = chunk2 - 1;
        for (int begin = 0; begin < chunk2; begin++){
            r[begin] = c[end];
            end--;
        }
        r[chunk2] = '\0'; //add eof
        percent = (double)((double)chunkcount*chunk/(double)fileLength)*100;
        if(percent>100){   
            sprintf(print,"The file has been 100%% reversed\r");
            write(1,print,strlen(print));
            fflush(stdout);
        }
        else{
            sprintf(print,"The file has been %lf%% reversed\r", percent);
            write(1,print,strlen(print));
            fflush(stdout);
        }
        write(fileOut, r, chunk2);
    
        if (lseek(fd, 0, SEEK_CUR) - chunk - chunk2 < 0)
            break;

        lseek(fd, -chunk - chunk2, SEEK_CUR);
        chunk2 = chunk;
    }
    if(argc > 2){
        sprintf(print,"only one input is considered \n");
        write(1,print,strlen(print));
        
    } 
    


     close (fd);
     close(fileOut);
    return 0; 
}