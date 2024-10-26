#include <stdio.h>
#include <string.h>

int movesubs(char videodir[], char subdir[])
{
	//Grab subtitles list, move it to video series with correct filename for videoplayers
	printf("Moving Subtitles from %s to %s\n", videodir, subdir);
	
	return 0;
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
		movesubs("/path/to/videos", "/path/to/subs");
		return 0;
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
	
	return -1;
}
