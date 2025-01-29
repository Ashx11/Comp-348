# Spreadsheet Application - COMP 348 Assignment 1

## Overview
This is a simple spreadsheet application written in C for managing student grades. It allows basic operations like displaying student data, sorting, updating grades, and deleting records.

## How to Compile and Run
### Using Docker
If you have a Dockerfile and want to use Docker to compile and run the code, follow these steps:

1. **Build Docker Image (if not already built)**:
   ```sh
   docker build -t comp348_image .
   ```

2. **Start Docker Container**:
   ```sh
   docker container start -a -i comp348
   ```

3. **Navigate to Assignment Directory Inside the Container**:
   ```sh
   cd /root/assignment
   ```

4. **Compile Your Code**:
   ```sh
   gcc spreadsheet.c data.c ordering.c calc.c -o spreadsheet -Wall -g
   ```

5. **Run Your Program**:
   ```sh
   ./spreadsheet
   ```

If you have already compiled the code and only need to run it, you can skip the compilation step.

### Compiling and Running Locally (Without Docker)
1. **Compile**: Use the following command to compile the program:
   ```sh
   gcc spreadsheet.c data.c ordering.c calc.c -o spreadsheet -Wall -g -gdwarf-4
   ```
   ```sh
   gcc spreadsheet.c data.c ordering.c calc.c -o spreadsheet -Wall
   ```
2. **Run**: After compiling, run the program with:
   ```sh
   ./spreadsheet
   ```
   Ensure the input file (`students.txt`) is in the same directory.

## Input File Format
The input file (`students.txt`) should have the following format:
```
<studentID>|<lastName>|<firstName>|<a1Grade>|<a2Grade>|<a3Grade>|<midtermGrade>|<examGrade>
```
Example:
```
123|Smith|John|85|90|78|88|92
456|Doe|Jane|70|75|80|85|88
```

## Menu Options
1. **Display Spreadsheet**: Shows all student records.
2. **Display Histogram**: Displays the grade distribution.
3. **Set Sort Column**: Sort records by different fields.
4. **Update Last Name**: Update a student's last name.
5. **Update Exam Grade**: Update a student's exam grade.
6. **Update Grade Mapping**: Modify grade boundaries.
7. **Delete Student**: Delete a student record.
8. **Exit**: Exit the application.

## Notes
- **Error Handling**: Handles basic input errors.
- **Debugging**: Use tools like `gdb` or `valgrind` for troubleshooting.

## Author
- **Kirubel**