#include "FitnessDataStruct.h"









char date[11];
char time[10];
char steps[5];


int stepsint;

int buffer_size = 100;

int main()
{
    char record[buffer_size];

    char filename [100];
    FILE *file;

    printf("Input filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error: Could not find or open the file.\n");
        return 1;
    }
    else
    {
        printf("File sucessfully loaded.\n");
    }
    break;

    fclose(file);
    return 0;
}

        
    
    

    