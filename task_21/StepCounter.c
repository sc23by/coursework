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

    char filename [50];

    int buffer_size = 100;
    char record[buffer_size];

    int minsteps = 10000;
    char mindate[11];
    char mintime[10];

    int maxsteps = 0;
    char maxdate[11];
    char maxtime[10];
    
    int totalsteps = 0;
    int meansteps;

    char startdate;
    char starttime;
    char enddate;
    char endtime;
    int currentsteps = 0;
    int currentlongeststeps;

    char Menu;


    while (Menu != 'Q'&& Menu != 'A'&& Menu != 'B'&& Menu != 'C'&& Menu != 'D'&& Menu != 'E'&& Menu != 'F') {
        printf("Menu Options:\nA: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\n");

        printf("Enter Choice: ");
        scanf("%c", &Menu);
    }
    switch (Menu)
    {
        case 'A' : printf("Input filename: ");
        scanf("%s", filename);
        FILE *file = fopen(filename, "r");
        if (file == NULL)
        {
            printf("Error: Could not find or open the file.\n");
            return 1;

        }
        else
        {
            printf("File sucessfully loaded.\n");
        }
        fclose(file);

        break;

        case 'B' : 
        while (fgets(record, buffer_size, file) != NULL)
        {
            j++;
        }

        printf("Total Records: %d\n", j);
        break;

        case 'C' : 
        while (fgets(record, buffer_size, file) != NULL)
        {
            fgets(record,buffer_size,file);
            tokeniseRecord(record, ",", date, time, steps);
            stepsint = atoi(steps);
            if (stepsint < minsteps)
            {
            minsteps = stepsint;
            strcpy(mindate, date);
            strcpy(mintime, time);
            }

        }            

        printf("Fewest Steps: %s %s\n", mindate, mintime);
        rewind (file);
        break;

        case 'D' : 
        while (fgets(record, buffer_size, file) != NULL)
        {
            fgets(record,buffer_size,file);
            tokeniseRecord(record, ",", date, time, steps);
            stepsint = atoi(steps);
            if (stepsint > maxsteps)
            {
            maxsteps = stepsint;
            strcpy(maxdate, date);
            strcpy(maxtime, time);
            }
        }            

        printf("Fewest Steps: %s %s\n", maxdate, maxtime);   
        rewind (file);     
        break;

        case 'E' :
        for (int i = 0; i < j; i++)
        {
            fgets(record,buffer_size,file);
            tokeniseRecord(record, ",", date, time, steps);
            stepsint = atoi(steps);
            totalsteps = totalsteps + stepsint;
            meansteps = totalsteps/j;
        }

        printf("Total Steps: %d\n", totalsteps);   
        printf("Mean Steps: %d\n", meansteps);   
        rewind (file);           
        break;

        case 'F':
            currentsteps = 0;
            currentlongeststeps = 0;

            while (fgets(record, buffer_size, file) != NULL) {
                tokeniseRecord(record, ",", date, time, steps);
                stepsint = atoi(steps);

                if (stepsint >= 500) {
                    currentsteps++;

                    if (currentsteps == 1) {
                        strcpy(startdate, date);
                        strcpy(starttime, time);
                    }
                } else {
                    if (currentsteps > currentlongeststeps) {
                        currentlongeststeps = currentsteps;
                    }

                    currentsteps = 0;
                }
            }

            // Check if the last period is the longest
            if (currentsteps > currentlongeststeps) {
                currentlongeststeps = currentsteps;
            }

            // Assign enddate and endtime based on the last period
            if (currentlongeststeps > 0) {
                strcpy(enddate, date);
                strcpy(endtime, time);
            }

            printf("Longest period start: %s %s\n", startdate, starttime);
            printf("Longest period end: %s %s\n", enddate, endtime);

        rewind(file);
        break;

        case 'Q' : printf("menu 7 \n");
        break;

        default: printf("\nInvalid Choice. Try Again.\n");
    }

    


    return 0;
    
}