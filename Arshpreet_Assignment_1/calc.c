#include <stdio.h>
#include <string.h>  
#include "spreadsheet.h"
#include "calc.h"
#include "data.h"

extern Student students[];
extern int studentCount;

extern GradeMapping gradeMapping;

void displayHistogram() {
    int gradeCounts[5] = {0}; 

    for (int i = 0; i < studentCount; i++) {
        double total = ((students[i].a1Grade + students[i].a2Grade + students[i].a3Grade) / 120.0) * 25.0 +
                       (students[i].midtermGrade / 25.0) * 25.0 +
                       (students[i].examGrade / 40.0) * 50.0;

        if (total >= gradeMapping.A) gradeCounts[0]++;
        else if (total >= gradeMapping.B) gradeCounts[1]++;
        else if (total >= gradeMapping.C) gradeCounts[2]++;
        else if (total >= gradeMapping.D) gradeCounts[3]++;
        else gradeCounts[4]++;
    }

    // Display the histogram
    clearScreen();
    printf("COMP 348 Grade Distribution\n");
    printf("A: ");
    for (int i = 0; i < gradeCounts[0]; i++) {
        printf("*");
    }
    printf("\nB: ");
    for (int i = 0; i < gradeCounts[1]; i++) {
        printf("*");
    }
    printf("\nC: ");
    for (int i = 0; i < gradeCounts[2]; i++) {
        printf("*");
    }
    printf("\nD: ");
    for (int i = 0; i < gradeCounts[3]; i++) {
        printf("*");
    }
    printf("\nF: ");
    for (int i = 0; i < gradeCounts[4]; i++) {
        printf("*");
    }
    printf("\n");

    printf("\nPress 'c' or 'C' to continue ");
    char proceed;
    do {
        while ((proceed = getchar()) != '\n' && proceed != EOF); 
    } while ((proceed = getchar()) != 'c' && proceed != 'C');
}

void updateLastName() {
    int id;
    char newName[50];

    printf("Enter Student ID: ");
    scanf("%d", &id);
    getchar(); 

    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == id) {
            printf("Current Last Name: %s\n", students[i].lastName);
            printf("Enter updated Last Name: ");
            fgets(newName, sizeof(newName), stdin);
            newName[strcspn(newName, "\n")] = 0;  
            strcpy(students[i].lastName, newName);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No student found with ID %d.\n", id);
    } else {
        printf("Last name updated successfully.\n");
        saveStudents("students.txt");  
    }

    printf("Press 'c' or 'C' to continue ");
    char proceed;
    do {
        while ((proceed = getchar()) != '\n' && proceed != EOF); 
    } while ((proceed = getchar()) != 'c' && proceed != 'C');
}

void updateExamGrade() {
    int id, newExamGrade;
    printf("Enter Student ID: ");
    scanf("%d", &id);
    getchar();  
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == id) {
            printf("Current Exam Grade: %d\n", students[i].examGrade);
            printf("Enter updated Exam Grade: ");
            scanf("%d", &newExamGrade);
            getchar();  

            if (newExamGrade < 0 || newExamGrade > 100) {
                printf("Invalid exam grade. Must be between 0 and 100.\n");
                return;
            }

            students[i].examGrade = newExamGrade;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No student found with ID %d.\n", id);
    } else {
        printf("Exam grade updated successfully.\n");
        saveStudents("students.txt"); 
    }

    printf("Press 'c' or 'C' to continue ");
    char proceed;
    do {
        while ((proceed = getchar()) != '\n' && proceed != EOF); 
    } while ((proceed = getchar()) != 'c' && proceed != 'C');
}

void updateGradeMapping() {
    printf("Current Mapping:\n");
    printf("A: >= %d\nB: >= %d\nC: >= %d\nD: >= %d\nF: < %d\n", 
           gradeMapping.A, gradeMapping.B, gradeMapping.C, gradeMapping.D, gradeMapping.D);

    printf("Enter new A baseline: ");
    scanf("%d", &gradeMapping.A);
    printf("Enter new B baseline: ");
    scanf("%d", &gradeMapping.B);
    printf("Enter new C baseline: ");
    scanf("%d", &gradeMapping.C);
    printf("Enter new D baseline: ");
    scanf("%d", &gradeMapping.D);

    printf("New Mapping:\n");
    printf("A: >= %d\nB: >= %d\nC: >= %d\nD: >= %d\nF: < %d\n", 
           gradeMapping.A, gradeMapping.B, gradeMapping.C, gradeMapping.D, gradeMapping.D);

    printf("Press 'c' or 'C' to continue ");
    char proceed;
    do {
        while ((proceed = getchar()) != '\n' && proceed != EOF); // Discard all characters until a newline or EOF
    } while ((proceed = getchar()) != 'c' && proceed != 'C');
}

void deleteStudent() {
    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    getchar(); 

    int index = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        studentCount--;
        printf("Student successfully deleted.\n");
        saveStudents("students.txt");  
    } else {
        printf("Student not found.\n");
    }

    printf("Press 'c' or 'C' to continue ");
    char proceed;
    do {
        while ((proceed = getchar()) != '\n' && proceed != EOF); 
    } while ((proceed = getchar()) != 'c' && proceed != 'C');
}
