#include<stdio.h> 
#include<string.h> 
#include<fcntl.h> 
#include<errno.h> 
#include<unistd.h> 
#include<stdlib.h> 
#include<dirent.h>
#include<time.h>
#include<sys/stat.h> 
#include<sys/wait.h>
#include<pwd.h>
#include<grp.h>
#include<termios.h>
#include<sys/select.h>

char hist[25][10000];
int hists;
char histp[10000];
void prompt(int size);
void execute(char** input,char *home);
void echo(char** input,int size);
void command(char** input);
void dir(char* input , int a);
void list( char* input , int a);
char *gid_to_name(gid_t gid);
char *uid_to_name(uid_t uid);
void ls(char** arg,int size,char* home);
void pinfo(char** input,char *home);
void forking ( char** input ,int s);
void bg();
void makehistory(char *h);
void historyexec(char **c);
void add(char *inp);
