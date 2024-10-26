#include <stdio.h>

int movesubs(char videodir[], char subdir[])
{
	//Grab subtitles list, move it to video series with correct filename for videoplayers
	printf("Moving Subtitles from %s to %s\n", videodir, subdir);
	
	return 0;
}

int syncsubs(double syncby)
{
	//grab sub file and offset the sync time for all subtitles
	printf("Syncing Subtitles by %d\n", syncby)
	
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
	for int i = 0; i < argc; ++i)
	{
		switch(argv[0]
		{
			case "movsubs":
				movesubs('/path/to/videos', '/path/to/subs');
				return 0;
				break;
			
			case "sync":
				syncsubs(0.100);
				return 0;
				break;
			
			case "--help":
				help();
				return 0;
				break;
				
			default:
				printf("You have not input a valid command, please see --help for commands\n");
				break;
		}
	}
	
	return 0;
}
