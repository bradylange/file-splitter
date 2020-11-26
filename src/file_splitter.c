#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/*
 * Brady Lange
 * 4/16/18
 * File name: file-splitter.c
 * This program splits a file into smaller chunks of data.
 */
 
//Main function
 int main(int argc, char * argv[]) 
 {
	//Variables
	FILE *writeFile;
	FILE *readFile;
	//Max size in bytes the file can be split
	char maxSize[atoi(argv[2])];
	char fileoutputname[15];
	//Keeping track of the amount of files
	int fileCount = 1;
	
	struct stat buffer;
	stat(argv[1], &buffer);
	

	//Opening the file to be read
	readFile = fopen(argv[1], "r");
	if(!readFile)
		return 1;

	sprintf(fileoutputname, "Split_File_%d", fileCount);
	//Writing to the file
	writeFile = fopen(fileoutputname, "w");

	while(fgets(maxSize, sizeof maxSize, readFile) != NULL) 
	{
		if(buffer.st_size == atoi(argv[2]))
		{
			fclose(writeFile);
			fileCount++;
			sprintf(fileoutputname, "Split_File_%d", fileCount);
			writeFile = fopen(fileoutputname, "w");
			if(!writeFile)
				return 1;
		}
		fprintf(writeFile,"%s\n", maxSize);
		
	}
	fclose(readFile);
	return 0;
}