 
#include "headers.h"

//making history here XD

void historyexec(char **c)
{
	int arg=10;
	if(c[1]!=NULL)
	{
		arg=atoi(c[1]);
	}
	
	for(int i=(0>hists-arg? 0:hists-arg);i<hists;i++)
	{
        if(i==0)
            printf("%s\n",hist[i]);
        else if(strcmp(hist[i],hist[i-1])!=0)
		    printf("%s\n",hist[i]);
	}
}

void add(char *c)
{
	FILE *fd=fopen(histp,"r");
	
	if(!(hists==20)==0)
	{
		for(int i=0;i<19;i++)
		{
			strcpy(hist[i],hist[i+1]);
		}
		hists--;
	}
	strcpy(hist[hists++],c);
	fd=fopen(histp,"w+");
	
	fseek(fd,0,SEEK_SET);
	fprintf(fd,"%d\n",hists);
	int i=0;
	while(i<hists)
	{
		fprintf(fd,"%s\n",hist[i]);
		i++;
	}
	fclose(fd);
}



