#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spreadsheet.h"
#include "ordering.h"

extern Student students[];
extern int studentCount;

void sortStudents(int column) {
    switch (column) {
        case 0:
            qsort(students, studentCount, sizeof(Student), compareByStudentID);
            break;
        case 1:
            qsort(students, studentCount, sizeof(Student), compareByLastName);
            break;
        case 2:
            qsort(students, studentCount, sizeof(Student), compareByExamGrade);
            break;
        case 3:
            qsort(students, studentCount, sizeof(Student), compareByTotal);
            break;
    }
}

int compareByStudentID(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return studentA->studentID - studentB->studentID;
}

int compareByLastName(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return strcmp(studentA->lastName, studentB->lastName);
}

int compareByExamGrade(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return studentB->examGrade - studentA->examGrade; // For descending order
}

int compareByTotal(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    double totalA = ((studentA->a1Grade + studentA->a2Grade + studentA->a3Grade) / 120.0) * 25 +
                    (studentA->midtermGrade / 25.0) * 25 +
                    (studentA->examGrade / 40.0) * 50;
    double totalB = ((studentB->a1Grade + studentB->a2Grade + studentB->a3Grade) / 120.0) * 25 +
                    (studentB->midtermGrade / 25.0) * 25 +
                    (studentB->examGrade / 40.0) * 50;

    return (totalB > totalA) - (totalB < totalA); // For descending order
}

void setSortColumn() {
    int column;
    printf("\nColumn Options\n");
    printf("--------------\n");
    printf("1. Student ID\n");
    printf("2. Last name\n");
    printf("3. Exam\n");
    printf("4. Total\n");
    printf("Sort Column: ");
    scanf("%d", &column);
    getchar(); 

    column--;

    if (column < 0 || column > 3) {
        printf("Invalid column. Defaulting to sort by Student ID.\n");
        column = 0;  
    }

    sortStudents(column);

    printf("Sort column updated\n");
    printf("Press 'c' or 'C' to continue ");
    char proceed;
    do {
        scanf(" %c", &proceed);
    } while (proceed != 'c' && proceed != 'C');
}
