#include"headers.h"
void piping(char *c,char *home)
{
	char *comm[10000];
	char *tok=strtok(c,"|");
    
	int pipenos=0;
	while(tok!=NULL)
	{
		comm[pipenos++]=tok;
		tok=strtok(NULL,"|");
	}
	int stdi=dup(0);
	int stdou=dup(1);
	int in1=dup(stdi);
	int out1;
	int i=0;
	while(i<pipenos-1)
	{
		if(dup2(in1,0)!=0)
		{
			perror("dup2 Failed\n");
		}

		close(in1);

		int inter[2];
		pipe(inter);
		
		in1=inter[0];

		out1=inter[1];
		

		if(!(dup2(out1,1)==1))
		{
			perror("dup2 Failed\n");
		}
		close(out1);
		char* tmp[100];
        int s;
		s = toke(comm[i],tmp);
        i++;
		execute(tmp,home,s);
	}
	out1=dup(stdou);
	if(dup2(in1,0)!=0)
	{
		perror("dup2 Failed\n");
	}

	close(in1);

	

	if(dup2(out1,1)!=1)
	{
		perror("dup2 Failed\n");
	}
	close(out1);
	char* tmp[100];
    int si;
	si = toke(comm[pipenos-1],tmp);
    
	execute(tmp,home,si);

	dup2(stdi,0);
	dup2(stdou,1);
	return;
}