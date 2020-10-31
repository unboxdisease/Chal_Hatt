#include "headers.h"
void ls(char **arg, int size, char *home)
{
	int l = 0;
	int a = 0;
	for (int i = 1; i < size; i++)
	{
		if (strcmp(arg[i], "-l") == 0)
		{
			l = 1;
			arg[i] = "";
		}
		if (strcmp(arg[i], "-a") == 0)
		{
			a = 1;
			arg[i] = "";
		}
		if (strcmp(arg[i], "-la") == 0 || strcmp(arg[i], "-al") == 0)
		{
			l = a = 1;
			arg[i] = "";
		}
	}
	int adr = 0;
	for (int i = 1; i < size; i++)
	{
		if (strcmp(arg[i], "") != 0)
		{
			adr = i;
			if (l && a)
			{
				list(arg[adr], 0);
			}
			else if (l)
			{
				list(arg[adr], 1);
			}
			else if (a)
			{
				dir(arg[adr], 0);
			}
			else
			{
				dir(arg[adr], 1);
			}
		}
	}
	if (!adr)
	{

		if (l && a)
		{
			list(home, 0);
		}
		else if (l)
		{
			list(home, 1);
		}
		else if (a)
		{
			dir(home, 0);
		}
		else
		{
			dir(home, 1);
		}
	}
}


void list(char *input, int a)
{
	struct stat permission;
	struct dirent *de;

	DIR *dr = opendir(input);
	if (!(dr == NULL)==0)
	{
		printf("Could not open current directory\n");
		return;
	}
	while ((de = readdir(dr)) != NULL)
	{
		
			if (de->d_name[0] != '.')
			{
				stat(de->d_name, &permission);
				char *g;
				struct passwd *getpwuid(), *pw_ptr;
				static char numstr[10],num[10];
				if ((pw_ptr = getpwuid(permission.st_uid)) == NULL)
				{
					sprintf(numstr, "%d", permission.st_uid);
					g =  numstr;
				}
				else
				{
					g = pw_ptr->pw_name;
				}
				char *n;
				struct group *getgrgid(), *grp_ptr;
				
				if ((grp_ptr = getgrgid(permission.st_gid)) == NULL)
				{
					sprintf(num, "%d",permission.st_gid);
					n =  num;
				}
				else
				{
					n =  grp_ptr->gr_name;
				}
				char *ctime();
				char *time = ctime(&permission.st_mtime);
				time[strlen(time) - 1] = ' ';

				// printf("\n");
				printf((permission.st_mode & S_IRUSR) ? "r" : "-");
				printf((permission.st_mode & S_IWUSR) ? "w" : "-");
				printf((permission.st_mode & S_IXUSR) ? "x" : "-");
				printf((permission.st_mode & S_IRGRP) ? "r" : "-");
				printf((permission.st_mode & S_IWGRP) ? "w" : "-");
				printf((permission.st_mode & S_IXGRP) ? "x" : "-");
				printf((permission.st_mode & S_IROTH) ? "r" : "-");
				printf((permission.st_mode & S_IWOTH) ? "w" : "-");
				printf((permission.st_mode & S_IXOTH) ? "x" : "-");
				
				printf(" %d %s %s %d %s %s\n", (int)permission.st_nlink, g, n, (int)permission.st_size, time, de->d_name);
			}
		
		if(!a)
		{
			if(de->d_name[0] == '.'){
				stat(de->d_name, &permission);
				char *ctime();
				char *time = ctime(&permission.st_mtime);
				time[strlen(time) - 1] = ' ';
				char *g;
				struct passwd *getpwuid(), *pw_ptr;
				static char numstr[10],num[10];
				if ((pw_ptr = getpwuid(permission.st_uid)) == NULL)
				{
					sprintf(numstr, "%d", permission.st_uid);
					g =  numstr;
				}
				else
				{
					g = pw_ptr->pw_name;
				}
				char *n;
				struct group *getgrgid(), *grp_ptr;
				
				if ((grp_ptr = getgrgid(permission.st_gid)) == NULL)
				{
					sprintf(num, "%d",permission.st_gid);
					n =  num;
				}
				else
				{
					n =  grp_ptr->gr_name;
				}
				
				printf((permission.st_mode & S_IRUSR) ? "r" : "-");
				printf((permission.st_mode & S_IWUSR) ? "w" : "-");
				printf((permission.st_mode & S_IXUSR) ? "x" : "-");
				printf((permission.st_mode & S_IRGRP) ? "r" : "-");
				printf((permission.st_mode & S_IWGRP) ? "w" : "-");
				printf((permission.st_mode & S_IXGRP) ? "x" : "-");
				printf((permission.st_mode & S_IROTH) ? "r" : "-");
				printf((permission.st_mode & S_IWOTH) ? "w" : "-");
				printf((permission.st_mode & S_IXOTH) ? "x" : "-");
				
				printf(" %d %s %s %d %s %s\n", (int)permission.st_nlink, g, n, (int)permission.st_size, time, de->d_name);
			}
		}
	}
	// printf("\n");
	closedir(dr);
}
void dir(char *input, int a)
{
	struct dirent *de;
	DIR *dr = opendir(input);
	if (!(dr == NULL)==0)
	{
		printf("Could not open directory \n");
		return;
	}
	while ((de = readdir(dr)) != NULL)
	{
		
			if (de->d_name[0] != '.')
			{
				printf("%s ", de->d_name);
			}
		
		if(!a)
		{
			if (de->d_name[0] == '.'){
				printf("%s ", de->d_name);
			}
		}
	}
	printf("\n");
	closedir(dr);
}