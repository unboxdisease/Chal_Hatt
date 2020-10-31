#include "headers.h"
void pinfo(char** input,char *home){
	char loc[1000]={0};
    char addr[10000],stat,residue[10000];
    int pid=0,pp;
    
	if(input[1]==NULL)
	{
		sprintf(addr,"/proc/%d/stat",getpid());
        pid = getpid();
	}
    else
    {
		sprintf(addr,"/proc/%s/stat",input[1]);
        pid = atoi(input[1]);
	}
    // printf("%s",addr);
    FILE* fd=fopen(addr ,"r"); 
    if(fd==NULL)
	{
		perror("ERROR");
		return ;
	}
    fscanf(fd,"%d",&pp);
	fscanf(fd,"%s",residue);
	fscanf(fd,"%s",&stat);
	printf("Process Id --> %d\n",pid);
    printf("Process Status --> %c\n",stat);

    fclose(fd);
	
	sprintf(addr,"%sm",addr);
	fd=fopen(addr,"r");
	if(fd==NULL)
	{
		perror("ERROR");
		return ;
	}
	int size;
	fscanf(fd,"%d",&size);
	printf("memory --> %d \n",size);
	fclose(fd);


    sprintf(addr,"/proc/%d/exe",pid);
    // printf("%s",addr);
    
	int flag=0;
	if(readlink(addr,loc,sizeof(loc))<0)
	{
		perror("readlink");
		return ;
	}
		// printf("Executable Path --> %s\n",loc);


	for(int i=0;i<strlen(home);i++)
	{
		if(home[i]!=loc[i])
		{
			flag=1;
			break;
		}
	}
	int l = strlen(home);
	if(flag){
		printf("Executable Path --> %s\n",loc );
	}
	else{
		printf("Executable Path --> ~%s\n",loc+l);
	}
}