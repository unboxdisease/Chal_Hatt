#include "headers.h"
void jobs(){
    char c1[100];
    char c2[100];
    char name[100];
    int i=0;
	while(i<num_com)
	{
		
		sprintf(name,"/proc/%d/stat",task[i].pid);
		FILE *p=fopen(name,"r");
		if(p==NULL || task[i].status==0)
		{
			task[i].status=0;
            i++;
			continue;
		}
		fscanf(p,"%s %s %s",c1,c1,c2);
		if(strcmp(c2,"T")==0)
		{
			printf("[%d] Stopped %s [%d]\n",i+1,c1,task[i].pid);
		}
		else
		{
			printf("[%d] Running %s [%d]\n",i+1,c1,task[i].pid);
		}
        i++;
	}
}
void kjobs(char **c,int size)
{
	if(size !=3)
	{
		printf("Invalid number of arguements\n");
		return ;
	}
	int i;
	int flag=1;
	for(i=0 ; i<num_com ; i++)
	{
		if(i+1==atoi(c[1]))
		{
			flag=0;
			
			if(kill(task[i].pid,atoi(c[2]))<0)
			{
				perror("kill");
			}
			else{
				printf("Killed process [%d]\n",i+1);
			}
			break;
		}
	}
	if(flag)
	{
		printf("Job with jobid %s doesn't exist\n",c[1]);
		return ;
	}
	// jobs();
	
}
void fg(char **c,int size)
{
	if(size!=2)
	{
		printf("Invalid input\n");
		return ;
	}
	int f=1;
	int i;
	pid_t p = atoi(c[1]);
	for(i=0; i<num_com;i++)
	{
		if(i+1==p && task[i].status == 1)
		{
			f=0;
			int status;
			p=task[i].pid;
			CHILD_ID = p;
			
			kill(p,SIGCONT);
			tcsetpgrp(0,p);
			waitpid(p,&status,WUNTRACED);
			if(task[i].status == 0){
				task[i].pid =p;
				printf("debug fg");
			}
			

			signal(SIGTTOU,SIG_IGN);
			tcsetpgrp(0,getpid());
			signal(SIGTTOU,SIG_DFL);
			break;
		}
	}
	if(f)
	{
		printf("Process with jobid %d doesn't exist\n",p);
	}
}
void bg2(char **c,int size)
{
	if(size!=2)
	{
		printf("Invalid no. of arguements\n");
		return ;
	}
	int flag=1;
	int i;
	pid_t p=atoi(c[1]);
	for(i=0;i<num_com;i++)
	{
		if(i+1==p && task[i].status == 1)
		{
			flag=0;
			printf("The process (%s) with PID %d is running now\n",task[i].com,task[i].pid);
			kill(task[i].pid,SIGCONT);
			break;
		}
	}
	if(flag)
	{
		printf("Process with jobid %d doesn't exist\n",p);	
	}

}
void overkill()
{
	int i;
	int flag=1;
	for(i=0 ; i<num_com ; i++)
	{
		if(task[i].status == 1)
		{
			task[i].status = 0;
			if(kill(task[i].pid,9)<0)
			{
				perror("kill");
			}
			// else{
			// 	printf("Killed process [%d]\n",i+1);
			// }
			
		}
	}
	
}


