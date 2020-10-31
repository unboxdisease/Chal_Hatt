
#include "headers.h"
void command(char** input){
    char com[1000];
	if(fgets(com,1000,stdin)==0){
		quit1 = 1;
	}
	
	com[strlen(com)-1] = '\0';
	if(strlen(com)!=0)
		add(com);
    char *tok = strtok(com,";");
	int i=0;
	while(tok!=NULL)
	{
		input[i]=tok;
		i++;
		tok=strtok(NULL,";");
	}
	
	input[i]=NULL;

}
int toke(char *a,char** b){
    char delim[3]=" \t";
    char *tok=strtok(a,delim);
    int j=0;
    while(tok!=NULL)
    {
        b[j] = tok;
        j++;
        tok=strtok(NULL,delim);
    }
    b[j] = NULL;
    return j;
}
int itspipe(char **c,int size)
{
	int f=0;
	int arr[10004];
	int i=0;
	while(i<size)
	{
		if(strcmp(c[i],"|")==0)
		{
			arr[f++]=i;
		}
		i++;
	}
	if(f>0)
	{
		if(arr[0]==0 || arr[f-1]==size-1)
		{
			return -1;
		}
		else{
			return 1;
		}
	}
	return 0;
}
void makehistory(char *hom)
{
	sprintf(histp,"%s/history.txt",hom);
	FILE *fd=fopen(histp,"r");
	if(fd==NULL)
	{
		fd=fopen(histp,"w");
		fprintf(fd,"0\n");
	}
	
	fseek(fd,0,SEEK_SET);
	fscanf(fd,"%d",&hists);
	
	char lineend,temp[10000];
    int nom;
	fseek(fd,0,SEEK_SET);
    fscanf(fd,"%d",&nom);
	fscanf(fd,"%c",&lineend);
	for(int i=1;i<=hists;i++)
	{
		fscanf(fd,"%[^\n]s",temp);
		fscanf(fd,"%c",&lineend);	
		strcpy(hist[i-1],temp);
		
	}
	fclose(fd);
}
void sigintHandler(int sig_num){


}
void STPhandeler(int sig_num){

}
int main(int argc,char* argv[])
{  
	ID = getpid();
    char old[10000];
    char new[10000];
    getcwd(old,10000);
    getcwd(new,10000);
    int cwd_size = strlen(old);
	quit1 =0;
    makehistory(old);
	signal(SIGINT, sigintHandler);
	signal(SIGTSTP, STPhandeler);
    while (1)
    {
		if(quit1==1){
			overkill();
			exit(0);
		}
		
        prompt(cwd_size); // prompt for everyline
        char* a[1000];
        command(a);
		int i=0; //converts a into command
        while(a[i] != NULL){
        // arg is an array of arrays containing one command ( arg[0] ) and its arguements 
			int tt,size ;
			
			char* arg[1000];
			char a_copy[1000];
			strcpy(a_copy,a[i]);
			// printf("%s",a_copy);
			size = toke(a[i],arg);
			tt=itspipe(arg,size);
			
			if(tt<0)
			{
				printf("Invalid Command\n");
				continue;
			}
			if(tt>0)
			{
				
				piping(a_copy,old);
				i++;
				continue;
			}
			
			execute(arg,old,size); 
			i++;
		}
        
    }
}
