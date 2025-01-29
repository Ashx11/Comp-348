#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spreadsheet.h"
#include "data.h"

#define MAX_STUDENTS 100

Student students[MAX_STUDENTS];
int studentCount = 0;

void loadStudents(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) && studentCount < MAX_STUDENTS) {
        buffer[strcspn(buffer, "\n")] = 0; 
        Student s = {0};  
        char *token = strtok(buffer, "|");
        if (token) s.studentID = atoi(token);

        token = strtok(NULL, "|");
        if (token) strcpy(s.lastName, token);

        token = strtok(NULL, "|");
        if (token) strcpy(s.firstName, token);

        token = strtok(NULL, "|");
        if (token) s.a1Grade = atoi(token);

        token = strtok(NULL, "|");
        if (token) s.a2Grade = atoi(token);

        token = strtok(NULL, "|");
        if (token) s.a3Grade = atoi(token);

        token = strtok(NULL, "|");
        if (token) s.midtermGrade = atoi(token);

        token = strtok(NULL, "|");
        if (token) s.examGrade = atoi(token);

        students[studentCount++] = s;
    }
    fclose(file);
}

void saveStudents(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        Student s = students[i];
        fprintf(file, "%d|%s|%s|%d|%d|%d|%d|%d\n",
                s.studentID, s.lastName, s.firstName,
                s.a1Grade, s.a2Grade, s.a3Grade,
                s.midtermGrade, s.examGrade);
    }

    fclose(file);
}
