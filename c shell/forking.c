#include "headers.h"





void bg(){
	pid_t pid;
	int status;
	char new[10000];
	getcwd(new,10000);
	int cwd_size = strlen(new);
	// prompt(cwd_size);
	while((pid=waitpid(-1,&status,WNOHANG | WUNTRACED))>0)
	{
		if(WIFEXITED(status))
		{
			for(int i=0;i<num_com;++i)
			{
				if(task[i].pid==pid)
				{
					task[i].status = 0;
					fprintf(stderr,"\n %s with pid %d exited normally.\n",task[i].com,pid);
					
					

					break;
				}
			}
		}
	}
	
}

void forking ( char** input,int s ){  
	char *arg[1000];
	int i=0;
	for(i=0;i<s;i++){
		arg[i] = input[i];
	}	
	arg[s]= NULL;

    pid_t pid;
	int status;
	pid=fork();
	if(!((pid<0))==0)
	{
		printf("forking failed\n");
		return ;
	}
	if(pid==0)
	{
		setpgid(0,0);
		if(execvp(arg[0],arg)<0)
		{
			printf("Invalid command\n");
			exit(0);
		}
		 
		exit(0);

	}
	else
	{
		
		if(input[s-1][0]=='&'){
			task[num_com].pid=pid;
			strcpy(task[num_com].com,input[0]);
			task[num_com].status = 1;
			num_com++;
			signal(SIGCHLD,bg);
    	}
		else{
			CHILD_ID = pid;
			tcsetpgrp(0,pid);
			waitpid(pid,&status,WUNTRACED);
			if(WIFSTOPPED(status)){
				task[num_com].pid=pid;
				strcpy(task[num_com].com,input[0]);
				task[num_com].status = 1;
				num_com++; 
			}
			signal(SIGTTOU,SIG_IGN);
			tcsetpgrp(0,getpid());
			signal(SIGTTOU,SIG_DFL);
		}
	}
}