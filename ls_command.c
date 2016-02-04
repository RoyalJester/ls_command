/* 	CS570, Assignment #1
*	Jesus Gonzalez
*	Shawn Chua
*/	
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] )
{
        DIR *dirp;
        struct dirent *currentFile;
		
	/*No command line arguments given to myls */
        if(argc == 1){    
		dirp = opendir(".");
			
		/* While given a real filename, 
		print it if it doesn't start with a period */
		while (currentFile = readdir(dirp)) { 
			if (currentFile->d_name[0] != '.') { 
				puts(currentFile->d_name);
                    	}
                }
		closedir(dirp);
        } // end if
	else{ 
		/* 2 or more command line arguments given to myls 
		if flag activated print all files including hidden */
		if(!strcmp(argv[1], "-h") && argc == 2){ 
	                dirp = opendir(".");
               	        while (currentFile = readdir(dirp)) {
                       		puts(currentFile->d_name);
               		}
		} // end if
          
		/* h flag activated on certain directories given, 
		print all files in all directories given */ 
		else if(!strcmp(argv[1], "-h") && argc > 2){ 
               		/* i is the place holder for each array iteration,
			this will allow the program to list the files in each directory
			by looping through each */
			int i; 
               		for(i = 2; i <= argc-1; i++){
               			if((dirp = opendir(argv[i])) == NULL){
					printf("myls: cannot access %s: No such file or directory\n", argv[i]);
					return -1;
				}
				else{
					if(argc > 3){
						printf("%s:\n", argv[i]);
					}
               				while (currentFile = readdir(dirp)){
               				 	puts(currentFile->d_name);
                       			}
					if(argc > 3){
						printf("\n");
					}
				}
			} // end for loop
		} // end else if
		
		/* Given directory names without h flag activated,
		print all files that are not hidden in them */
		else{ // myls and filenames 
			int i;
               		for(i = 1; i <= argc-1; i++){
				if((dirp = opendir(argv[i])) == NULL){
					printf("myls: cannot access %s: No such file or directory\n", argv[i]);
					return -1;
					}
				else{
					if(argc > 2){
						printf("%s:\n", argv[i]);
					}
                       			while (currentFile = readdir(dirp)){
						if (currentFile->d_name[0] != '.') {
							puts(currentFile->d_name);
                       				}					
                       			}
					if(argc > 2){
						printf("\n");
					}
				}
               		} // end for loop
		} // end else
		closedir(dirp);

	} // end else
	return 0;

} // end main
