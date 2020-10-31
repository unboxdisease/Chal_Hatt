#include "headers.h"
void command(char** input){
    char com[1000];
	fgets(com,1000,stdin);
	
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