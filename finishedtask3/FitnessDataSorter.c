#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

int compareSteps(const void *a, const void *b) {
    return ((FITNESS_DATA*)b)->steps - ((FITNESS_DATA*)a)->steps;
}

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

    while (fgets(record, buffer_size, file) != NULL) {
        j++;
    }

    rewind(file);

    FITNESS_DATA data[j];

    for (int i = 0; i < j; i++) {
        fgets(record, buffer_size, file);
        int steps;
        tokeniseRecord(record, ',', data[i].date, data[i].time, &steps);
        data[i].steps = steps;
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