#include "FitnessDataStruct.h"

int main() {
    char filename[100];


    int buffer_size = 100;
    char record[buffer_size];

    printf("Input filename: ");
    scanf("%s", filename);
    FILE * file = fopen(filename, "r");

    int j = 0;

    if (file == NULL) {
        printf("Error: invalid file\n");
        return 1;
    }
    
    while (fgets(record, buffer_size, file) != NULL) 
    {
        j++;
    }

    rewind (file);

    char date[11];
    char time[6];
    char steps[5];

    while (fgets(record, buffer_size, file) != NULL) 
    {
        tokeniseRecord(record, ",", date, time, steps);

        int hyphoncount = 0;
        for (int k = 0; k< 10 ; k++)
        {
            if(date[k] == '-')
            {
                hyphoncount++;
            }
        }
        if (hyphoncount != 2)
        {
            printf("Error: invalid file hyphon\n");
            return 1;
        }
        

        if(strlen(date) != 10)
        {
            printf("Error: invalid file date 10\n");
            return 1;
        }

        int digitcount = 0;

        for (int k = 0; k< 10 ; k++)
        {
            if(isdigit(date[k]))
            {
                digitcount++;
            }
        }
        if (digitcount < 8)
        {
            printf("Error: invalid file date digit\n");
            return 1;
        }

        digitcount = 0;

        for (int k = 0; k< 5 ; k++)
        {
            if(isdigit(time[k]))
            {
                digitcount++;
            }
        }
        if (digitcount < 4)
        {
            printf("Error: invalid file time digit\n");
            return 1;
        }

        for (int k = 0; k < (strlen(steps) - 2); k++) {
            if (!isdigit(steps[k])) {
                printf("Error: invalid file\n");
                return 1;
            }
        }

        if(strchr(time, ':') == NULL)
        {
            printf("Error: invalid file\n");
            return 1;
        }
        if(strlen(time) != 5)
        {
            printf("Error: invalid file\n");
            return 1;
        }
        

        if(strchr(steps, ':') != NULL)
        {
            printf("Error: invalid file\n");
            return 1;
        }
        if(strchr(steps, '-') != NULL)
        {
            printf("Error: invalid file\n");
            return 1;
        }
        if(strlen(steps) < 3)
        {
            printf("Error: invalid file\n");
            return 1;
        }
    }

    rewind(file);

    FITNESS_DATA data[j];

    for (int i = 0; i < j; i++) {
        fgets(record, buffer_size, file);
        tokeniseRecord(record, ",", data[i].date, data[i].time, steps);
        int stepsint = atoi(steps);
        data[i].steps = stepsint;
    }

    fclose(file);

    qsort(data, j, sizeof(FITNESS_DATA), compareSteps);

    char tsv[] = ".tsv";
    char newfilename[100];
    strcpy(newfilename, filename);
    strcat(newfilename, tsv);

    FILE * newfile = fopen(newfilename, "w");

    for (int i = 0; i < j; i++) {
        fprintf(newfile, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
    }
    printf("Data sorted and written to %s\n", newfilename);

    fclose(newfile);

    return 0;
}