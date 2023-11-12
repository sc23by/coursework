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




    for (int i = 0; i < 3; i++)
    {
        fgets(record,buffer_size,file);
        tokeniseRecord(record, ",", date, time, steps);
        stepsint = atoi(steps);
    }

    rewind (file);

    int minsteps = 10000;
    char mindate[11];
    char mintime[10];

    int maxsteps = 0;
    char maxdate[11];
    char maxtime[10];
    
    float totalsteps = 0;
    float meansteps;
    int intmeansteps;

    char startdate[11];
    char starttime[10];
    char enddate[11];
    char endtime[10];
    int currentsteps = 0;
    int currentlongeststeps;
    char prevenddate[11];
    char prevendtime[10];
    char prevstartdate[11];
    char prevstarttime[10];    

    char Menu;


    while (1)
    {
        printf("Menu Options:\nA: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\n");

        printf("Enter choice: ");
        scanf(" %c", &Menu);

        switch (Menu)
        {
            case 'A' : 
            fclose (file);

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


            case 'B' : 
            j = 0;
                while (fgets(record, buffer_size, file) != NULL)
            {
                j++;
            }
            printf("Total records: %d\n", j);
            rewind (file);
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

            printf("Fewest steps: %s %s\n", mindate, mintime);
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

            printf("Largest steps: %s %s\n", maxdate, maxtime);   
            rewind (file);     
            break;


            case 'E' :
            totalsteps = 0;
            j = 0;
            
                while (fgets(record, buffer_size, file) != NULL)
            {
                j++;
            }

            rewind (file);  

            for (int i = 0; i < j; i++)
            {
                fgets(record,buffer_size,file);
                tokeniseRecord(record, ",", date, time, steps);
                stepsint = atoi(steps);
                totalsteps = totalsteps + stepsint;
                meansteps = totalsteps/j;
            }

            intmeansteps = (int)(meansteps < 0 ? (meansteps - 0.5) : (meansteps + 0.5));
            printf("Mean step count: %d\n", (intmeansteps)); 
            rewind (file);           
            break;


            case 'F':
            currentsteps = 0;
            currentlongeststeps = 0;

            while (fgets(record, buffer_size, file) != NULL) 
            {
                tokeniseRecord(record, ",", date, time, steps);
                stepsint = atoi(steps);

                if (stepsint > 500) 
                {
                    currentsteps++;
                    if (currentsteps == 1)
                    {
                        strcpy(prevstartdate, date);
                        strcpy(prevstarttime, time);
                    }
                
                    
                } 
                else 
                {
                    if (currentsteps > currentlongeststeps) 
                    {
                        currentlongeststeps = currentsteps;

                        strcpy(enddate, prevenddate);  // Use the previous date
                        strcpy(endtime, prevendtime);  // Use the previous time
                        strcpy(startdate, prevstartdate);
                        strcpy(starttime, prevstarttime);
                    }

                    currentsteps = 0;
                }
                strcpy(prevenddate, date);
                strcpy(prevendtime, time);
            }

            printf("Longest period start: %s %s\n", startdate, starttime);
            printf("Longest period end: %s %s\n", enddate, endtime);

            rewind(file);
            break;

            case 'Q' :
            return 0;

            default: printf("Invalid Choice. Try Again.\n");
        }
    }

    fclose(file);
    return 0;
}

        
    
    

    