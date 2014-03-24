#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	char *filename;
	int offset, n;
	char buffer[512];
	FILE * fp;
	filename = argv[1];
	offset = atol(argv[2]);
	
	if (argc < 3)
		{
			fprintf(stderr,"Please run in the correct format: catfrom <filename> <offset>");
			return(1);
		}
	fp = fopen(filename, "r");
	if((fp) == NULL)
		{
				fprintf(stderr,"File does not exist!\n");
				return (1);
		}	
	fseek(fp, offset, SEEK_SET);
	do {
       n = fread(buffer,1,512, fp);		
	   setmode(fileno(stdout), O_BINARY);
	   fwrite(buffer, 1, n, stdout); 
		} while ( n > 0 );
  return 0;
}
