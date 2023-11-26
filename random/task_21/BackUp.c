#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

char date[11];
char time[10];
char steps [5];


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    char *inputCopy = strdup(input);
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    free(inputCopy);
}


int main()
{
    int j;
    int stepsint;

    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("");
        return 1;
    }

    int buffer_size = 100;
    char record[buffer_size];

    while (fgets(record, buffer_size, file) != NULL)
    {
        j++;
    }

    rewind (file);

    for (int i = 0; i < 3; i++)
    {
        fgets(record,buffer_size,file);
        tokeniseRecord(record, ",", date, time, steps);
        stepsint = atoi(steps);

    }

    char Menu;

    while (Menu != 'Q'&& Menu != 'A'&& Menu != 'B'&& Menu != 'C'&& Menu != 'D'&& Menu != 'E'&& Menu != 'F') {
        printf("Menu Options:\nA: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\n");

        printf("Enter Choice: ");
        scanf("%c", &Menu);

        switch (Menu)
        {
            case 'A' : printf("%s\n", filename);
            break;

            case 'B' : printf("Total Records: %d\n", j);
            break;

            case 'C' : printf("menu 3 \n");
            break;

            case 'D' : printf("menu 4 \n");
            break;

            case 'E' : printf("menu 5 \n");
            break;

            case 'F' : printf("menu 6 \n");
            break;

            case 'Q' : printf("menu 7 \n");
            break;

            default: printf("\nInvalid Choice. Try Again.\n");
        }
    }

    fclose(file);
    return 0;
    
}