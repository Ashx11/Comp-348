#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spreadsheet.h"
#include "data.h"
#include "ordering.h"
#include "calc.h"

#define MAX_STUDENTS 100

extern Student students[];
extern int studentCount;

GradeMapping gradeMapping = {80, 70, 60, 50};  

void clearScreen() {
    #ifdef _WIN32
    system("cls");  
    #else
    system("clear");  
    #endif
}

void displaySpreadsheet() {
    clearScreen();  
    printf("\nCOMP 348 GRADE SHEET\n");
    printf("ID\tLast\t\tFirst\tA1\tA2\tA3\tMidterm\tExam\tTotal\tGrade\n");
    printf("-----------------------------------------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        Student s = students[i];
        
        double total = ((s.a1Grade + s.a2Grade + s.a3Grade) / 120.0) * 25.0 +
                       (s.midtermGrade / 25.0) * 25.0 +
                       (s.examGrade / 40.0) * 50.0;

        
        char grade;
        if (total >= gradeMapping.A) grade = 'A';
        else if (total >= gradeMapping.B) grade = 'B';
        else if (total >= gradeMapping.C) grade = 'C';
        else if (total >= gradeMapping.D) grade = 'D';
        else grade = 'F';

        
        printf("%d\t%-10s\t%-10s\t%d\t%d\t%d\t%d\t%d\t%.2f\t%c\n",
               s.studentID, s.lastName, s.firstName,
               s.a1Grade, s.a2Grade, s.a3Grade,
               s.midtermGrade, s.examGrade, total, grade);
    }
    printf("\nPress 'c' or 'C' to continue ");
    char proceed;
    do {
        while ((proceed = getchar()) != '\n' && proceed != EOF); 
    } while ((proceed = getchar()) != 'c' && proceed != 'C');
}

void displayMenu() {
    printf("\nSpreadsheet Menu\n");
    printf("-----------------\n");
    printf("1. Display Spreadsheet\n");
    printf("2. Display Histogram\n");
    printf("3. Set sort column\n");
    printf("4. Update Last Name\n");
    printf("5. Update Exam Grade\n");
    printf("6. Update Grade Mapping\n");
    printf("7. Delete Student\n");
    printf("8. Exit\n");
}

int main() {
    loadStudents("students.txt");

    int option;
    do {
        displayMenu();
        printf("Selection: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                displaySpreadsheet();
                break;
            case 2:
                displayHistogram();
                break;
            case 3:
                setSortColumn();
                break;
            case 4:
                updateLastName();
                break;
            case 5:
                updateExamGrade();
                break;
            case 6:
                updateGradeMapping();
                break;
            case 7:
                deleteStudent();
                break;
            case 8:
                printf("Goodbye and thanks for using our spreadsheet app");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }

    } while (option != 8);

    return 0;
}
