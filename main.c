
#include "headers.h"
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
int main(int argc,char* argv[])
{   
    char old[10000];
    char new[10000];
    getcwd(old,10000);
    getcwd(new,10000);
    int cwd_size = strlen(old);

    makehistory(old);
    while (1)
    {
        prompt(cwd_size); // prompt for everyline
        char* a[1000];
        command(a); //converts a into list of commands and their args
        execute(a,old); 
        
        
    }
}
