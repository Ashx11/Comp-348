#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <string.h> 

// Struct for Student
typedef struct {
    int studentID;
    char lastName[50];
    char firstName[50];
    int a1Grade;
    int a2Grade;
    int a3Grade;
    int midtermGrade;
    int examGrade;
} Student;

// Struct for Grade Mapping
typedef struct {
    int A;
    int B;
    int C;
    int D;
} GradeMapping;

extern GradeMapping gradeMapping;

int compareByStudentID(const void *a, const void *b);
int compareByLastName(const void *a, const void *b);
int compareByExamGrade(const void *a, const void *b);
int compareByTotal(const void *a, const void *b);


void clearScreen(); 
void displaySpreadsheet();
void displayMenu();
void deleteStudent();
void updateExamGrade();
void updateLastName();
void updateGradeMapping();
void setSortColumn();

#endif
