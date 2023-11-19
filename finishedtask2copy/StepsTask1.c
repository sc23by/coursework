#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    char *inputCopy = strdup(input);
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {
        strcpy(date, token);
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

char steps[10];

int main() 
{
    char filename[] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int buffer_size = 100;
    char record[buffer_size];

    int numRecords = 0;

    while (fgets(record, buffer_size, file) != NULL) {
        numRecords++;
    }

    rewind(file);

    FITNESS_DATA data[numRecords];

    for (int i = 0; i < numRecords; i++) {
        fgets(record, buffer_size, file);
        tokeniseRecord(record, ",", data[i].date, data[i].time, steps);
        data[i].steps = atoi(steps);
    }


    for (int i = 0; i < 3; i++) 
    {
        printf("%s/%s/%d\n", data[i].date, data[i].time, data[i].steps);
    }

    fclose(file);

    return 0;
}