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


int main() {
    char filename[100];

    char steps[100];
    int buffer_size = 100;
    char record[buffer_size];
    int j = 0;

    printf("Input filename: ");
    scanf("%s", filename);
    FILE * file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: invalid file\n");
        return 1;
    }

    while (fgets(record, buffer_size, file) != NULL) {
        j++;
    }

    rewind(file);

    FITNESS_DATA data[j];

    for (int i = 0; i < j; i++) {
        fgets(record, buffer_size, file);
        tokeniseRecord(record, ",", data[i].date, data[i].time, steps);
        data[i].steps = atoi(steps);
    }

    fclose(file);
    int k, a;
    for (int i = 0; i < j; ++i) 
    {
        for (k = i + 1; k < j; ++k) 
        {
            if (data[i].steps < data[k].steps) 
            {
                a = data[i].steps;
                data[i].steps = data[k].steps;
                data[k].steps = a;
            }
        }
    }

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