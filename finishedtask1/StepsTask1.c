#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

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

    printf("Number of records in file: %d\n", j);

    rewind (file);

    for (int i = 0; i < 3; i++)
    {
        fgets(record,buffer_size,file);
        tokeniseRecord(record, ",", date, time, steps);
        stepsint = atoi(steps);
        printf("%s/%s/%d\n", date, time, stepsint);
    }

    fclose(file);
    return 0;
}