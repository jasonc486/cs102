#include <stdio.h>
char filename[1024];
char scratch[1024];
int print_file(char* filename);
int stringLength(char* string);
int wordCount(char* string);
int main(int argc, char** argv)
{
    int i, string;
    char filename[1024] = "argv[i]";
    if(argc == 1)
    {
        fprintf(stdout, "no arguments found!");
        
    }
    else
    {
        for(i=1; i < argc; i++)
        {
            print_file(argv[i]);
        }
    }
    fprintf(stdout, "\n");
    return 0;
}

int print_file(char* filename)
{
    FILE* file;
    file = fopen(filename, "r");
    int lineCount = 0;
    int byteCount = 0;
    int words = 0;
    if( file != NULL)
    {
        while (fgets(scratch, 1024, file) != NULL)
        {
            byteCount += stringLength(scratch);
            lineCount++;
            words += wordCount(scratch);
            fprintf( stdout, "%s", scratch);
        }
        fclose(file);
    fprintf(stdout, "The file: %s contains %d lines, %d words, and %d bytes.",filename, lineCount, words, byteCount);
    }
    else
    {
        fprintf( stdout, "Error! Cannot read %s!", filename);
    }
}

int wordCount(char* string)
{
    int i = 0;
    while(string[i] != '\0')
    {
        i++;
    }
    return i;
}

int stringLength(char* string)
{
    int i = 0;
    while(string[i] != '\0')
    {
        i++;
    }
    return i;
}
