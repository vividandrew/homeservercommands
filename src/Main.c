#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int movesubs(char videodir[], char subdir[])
{
	//Grab subtitles list, move it to video series with correct filename for videoplayers
	printf("Moving Subtitles from %s to %s\n", videodir, subdir);
	
	DIR *videos = NULL;
	DIR *subtitles = NULL;
	struct dirent *dir;
	
	char *nameconstruct[100][100];
	
	//verify video directory
	if(verify(videodir,".mp4") == 0)
	{
		//the files are an .mp4 type
		printf("Grabbing Videos .mp4 files\n");
		videos = opendir(videodir);
		if(videos)
		{
			unsigned short count = 0;
			
			while((dir = readdir(videos)) != NULL)
			{
				if(strlen(dir->d_name) > 4)
				{
					strncpy(nameconstruct[count], dir->d_name, strlen(dir->d_name)-4);
					nameconstruct[count][strlen(dir->d_name - 4)] = '\0';
				}
				count++;
			}
		}
		//end of reading videos
		closedir(videos);
	}
	//Checks that videos dir is available
	if(videos == NULL)
	{
		return -1;
	}
	
	//test to make sure it works
	for(int i = 0; i < strlen(nameconstruct); i++)
	{
		printf("%s\n",nameconstruct[i]);
	}
	
	//verify sub directory
	if(verify(subdir, ".srt") == 0)
	{
		//the subs are a .srt type
		printf("Grabbing Subtitles .srt files\n");
		subtitles = opendir(subdir);
		closedir(subtitles);
	}
	if(subtitles == NULL)
	{
		return -1;
	}
	
	
	//Sort directories
	
	
	
	return 0;
}

int verify(char inputdir[], char type[])
{
	DIR *d;
	struct dirent *dir;
	d = opendir(inputdir);
	if(d)
	{
		dir = readdir(d);
		while((dir = readdir(d)) != NULL)
		{
			char *filename = dir->d_name;
			short len = strlen(filename);
			
			if (len > 4)
			{
				char *ext = &filename[len-strlen(type)];
				if(strcmp(ext, type) == 0)
				{
					closedir(d);
					return 0;
				}
			}
		}
		closedir(d);
	}
	return -1;
}

int syncsubs(double syncby)
{
	//grab sub file and offset the sync time for all subtitles
	printf("Syncing Subtitles by %f\n", syncby);
	
	return 0;
}

int help()
{
	//help commands
	printf("Sample help file\n");
	
	return 0;
}


int main(int argc, char **argv)
{
	printf("Welcome to homeserver commands\n");
	
	if(strcmp(argv[1], "movsubs") == 0)
	{
		if (argc > 3)
		{
			movesubs(argv[2], argv[3]);
			return 0;
		}
	}else if(strcmp(argv[1],  "sync") == 0)
	{
		syncsubs(0.100);
		return 0;
	}else if(strcmp(argv[1], "--help") == 0)
	{
		help();
		return 0;			
	}else{
		if(strcmp(argv[1], "movsubs") == 0)
		{
			printf("You have made a command for movsubs,\nTo use this command you will need the video directory and subtitle directory\nExample: movesub /path/to/videos /path/to/subs\nplease see --help for commands\n");
		}else if(strcmp(argv[1],  "sync") == 0)
		{
			syncsubs(0.100);
			return 0;
		}else if(strcmp(argv[1], "--help") == 0)
		{
			help();
			return 0;			
		}else{
			printf("You have not input a valid command, please see --help for commands\n");
		}
	}
	
	return -1;
}
