#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(int argc, char *argv[])
{
    int inputSize = argc - 1;
    int openFiles[inputSize];
    char buf[3];
    if (argc < 2)
        (printf("Zero input"));

    else
    {
        //open files
        int i;
        for (i = 0; i < inputSize; i++)
        {
            openFiles[i] = open(argv[i + 1], O_RDONLY, 0400);
        }
        //check existance of all files
        for (i = 0; i < inputSize; i++)
        {
            if (openFiles[i] == -1)
            {
                printf("\nFile not found!: %s\n", argv[i + 1]);
                exit(1);
            }
        }
        //creat output file
        int out = open("context.txt", O_CREAT | O_WRONLY, 0700); // if file does not exist create it
        if (out == -1)
        {
            printf("Failed to create file");
            exit(1);
        }
        //read and write
        for (i = 0; i < inputSize; i++)
        {
            //reading file 10 signs at once, size of the buffer could be adjasted for performance
            while (1)
            {
                int reading = read(openFiles[i], buf, 3);
                if (reading < 3)
                {
                    buf[reading] = '\0';
                    break;
                }
                else
                    write(out, buf, 3);
            }
        }

        //close files
        for (i = 0; i < inputSize; i++)
        {
            close(openFiles[i]);
        }
        close(out);
    }
}