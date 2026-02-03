#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 100

/* Global Variables */
int i, j;
int count = 0;
char subjects[5][20] = {"Mathematics", "Physics", "Calculus", "Chemistry", "English"};

/* Student Structure */
typedef struct
{
    int roll_number;
    int age;
    char name[100];
    char course[30];
    float marks[5];
    float total;
    float percentage;
    char grade;
} Students;

Students student[MAX_STUDENTS];

/* Function Prototypes */
void addStudent();
void calculate(Students *student);
void displayStudents();
void searchStudent();
int checkRollDuplicate();
void update_student();
void deleteStudent();
void loadFromFile();
void SavefromFile();
void studentReport();
void sortStudents();

int main()
{
    loadFromFile();
    int choice;
    printf("\n==============---------------Student Management System---------------==============\n");
    while(1)
    {
        printf("\n1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Update Student\n");
        printf("4. Search Student\n");
        printf("5. Generate Student Report\n");
        printf("6. Delete Student\n");
        printf("7. Sort Students\n");
        printf("8. Exit System\n");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: update_student(); break;
            case 4: searchStudent(); break;
            case 5: studentReport(); break;
            case 6: deleteStudent(); break;
            case 7: sortStudents(); break;
            case 8: 
                printf("\nThank you! Exiting.......\n");
                return 0;
            default: 
                printf("\nInvalid Choice! Try again\n");
                break;
        }
    }
    return 0;
}

/* Add a new student to the system */
void addStudent()
{
    if(count >= MAX_STUDENTS)
    {
        printf("\nLimit exceeded! Maximum %d students allowed.\n", MAX_STUDENTS);
        return;
    }

    int roll_number;
    do
    {
        printf("\n===ADD STUDENT NO: %d===\n", count + 1);
        printf("Enter Roll number: ");
        scanf("%d", &roll_number);
        
        if(checkRollDuplicate(roll_number))
        {
            printf("Student already exists with this roll number! Enter a unique roll number.\n");
        }
    }
    while(checkRollDuplicate(roll_number));
    
    student[count].roll_number = roll_number;
    getchar();

    printf("Enter Name: ");
    fgets(student[count].name, sizeof(student[count].name), stdin);
    student[count].name[strcspn(student[count].name, "\n")] = '\0';

    printf("Enter Age: ");
    scanf("%d", &student[count].age);
    getchar();

    printf("Enter Course: ");
    fgets(student[count].course, sizeof(student[count].course), stdin);
    student[count].course[strcspn(student[count].course, "\n")] = '\0';

    printf("\n---Enter Marks---\n");
    for(i = 0; i < 5; i++)
    {
        do
        {
            printf("Enter %s: ", subjects[i]);
            scanf("%f", &student[count].marks[i]);
            
            if(student[count].marks[i] < 0 || student[count].marks[i] > 100)
            {
                printf("Invalid! Marks must be between 0 and 100.\n");
            }
        }
        while(student[count].marks[i] < 0 || student[count].marks[i] > 100);
    }
    
    calculate(&student[count]);
    count++;
    SavefromFile();
    printf("\nStudent Added Successfully!\n");
}

/* Display all students in the system */
void displayStudents()
{
    if(count == 0)
    {
        printf("\nNo students to display!\n");
        return;
    }
    
    for(i = 0; i < count; i++)
    {
        printf("\n===STUDENT NO: %d===\n", i + 1);
        printf("Roll Number: %d\n", student[i].roll_number);
        printf("Name: %s\n", student[i].name);
        printf("Age: %d\n", student[i].age);
        printf("Course: %s\n", student[i].course);
        printf("\n---MARKS---\n");
        
        for(j = 0; j < 5; j++)
        {
            printf("%-15s: %.2f\n", subjects[j], student[i].marks[j]);
        }

        printf("\nTotal Marks: %.2f/500\n", student[i].total);
        printf("Percentage: %.2f%%\n", student[i].percentage);
        printf("Grade: %c\n", student[i].grade);
    }
    printf("\n----------------------------------------------------------------------------\n");
}

/* Calculate total, percentage, and grade for a student */
void calculate(Students *student)
{
    student->total = 0;
    
    for(i = 0; i < 5; i++)
    {
        student->total += student->marks[i];
    }
    
    student->percentage = student->total / 5;

    if(student->percentage >= 90)
        student->grade = 'A';
    else if(student->percentage >= 70)
        student->grade = 'B';
    else if(student->percentage >= 60)
        student->grade = 'C';
    else if(student->percentage >= 40)
        student->grade = 'D';
    else
        student->grade = 'F';
}

/* Search for a student by roll number or name */
void searchStudent()
{
    int choice;
    int roll_number, found = 0;
    char name[100];
    
    printf("\n---Search Student---\n");
    printf("1. By Roll Number\n");
    printf("2. By Name\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            printf("Enter Roll Number: ");
            scanf("%d", &roll_number);
            found = 0;
            
            for(i = 0; i < count; i++)
            {
                if(student[i].roll_number == roll_number)
                {
                    printf("\n---Student Found---\n");
                    printf("Roll Number: %d\n", student[i].roll_number);
                    printf("Name: %s\n", student[i].name);
                    printf("Age: %d\n", student[i].age);
                    printf("Course: %s\n", student[i].course);
                    printf("\n---MARKS---\n");
                    
                    for(j = 0; j < 5; j++)
                    {
                        printf("%-15s: %.2f\n", subjects[j], student[i].marks[j]);
                    }

                    printf("\nTotal Marks: %.2f/500\n", student[i].total);
                    printf("Percentage: %.2f%%\n", student[i].percentage);
                    printf("Grade: %c\n", student[i].grade);
                    found = 1;
                    break;
                }
            }
            
            if(!found)
                printf("\nStudent not found!\n");
            break;

        case 2:
            getchar();
            printf("Enter Name: ");
            fgets(name, 100, stdin);
            name[strcspn(name, "\n")] = '\0';
            found = 0;
            
            for(i = 0; i < count; i++)
            {
                if(strcmp(student[i].name, name) == 0)
                {
                    printf("\n---Student Found---\n");
                    printf("Roll Number: %d\n", student[i].roll_number);
                    printf("Name: %s\n", student[i].name);
                    printf("Age: %d\n", student[i].age);
                    printf("Course: %s\n", student[i].course);
                    printf("\n---MARKS---\n");
                    
                    for(j = 0; j < 5; j++)
                    {
                        printf("%-15s: %.2f\n", subjects[j], student[i].marks[j]);
                    }

                    printf("\nTotal Marks: %.2f/500\n", student[i].total);
                    printf("Percentage: %.2f%%\n", student[i].percentage);
                    printf("Grade: %c\n", student[i].grade);
                    found = 1;
                    break;
                }
            }
            
            if(!found)
                printf("\nStudent not found!\n");
            break;
            
        default:
            printf("\nInvalid choice!\n");
            break;
    }
    printf("\n----------------------------------------------------------------------------\n");
}

/* Check if a roll number already exists */
int checkRollDuplicate(int roll_number)
{
    for(i = 0; i < count; i++)
    {
        if(student[i].roll_number == roll_number)
        {
            return 1;
        }
    }
    return 0;
}

/* Update student information */
void update_student()
{
    printf("\n---Update Student---\n");
    int roll_number, choice;
    int found = 0;
    
    printf("Enter Roll Number of student: ");
    scanf("%d", &roll_number);
    
    for(i = 0; i < count; i++)
    {
        if(student[i].roll_number == roll_number)
        {
            found = 1;
            printf("\nWhat do you want to update?\n");
            printf("1. Name\n");
            printf("2. Age\n");
            printf("3. Course Name\n");
            printf("4. Marks\n");
            printf("Enter Choice: ");
            scanf("%d", &choice);
            
            switch(choice)
            {
                case 1:
                    getchar();
                    printf("Enter New Name: ");
                    fgets(student[i].name, sizeof(student[i].name), stdin);
                    student[i].name[strcspn(student[i].name, "\n")] = '\0';
                    printf("Name updated successfully!\n");
                    break;
                    
                case 2:
                    printf("Enter New Age: ");
                    scanf("%d", &student[i].age);
                    printf("Age updated successfully!\n");
                    break;
                    
                case 3:
                    getchar();
                    printf("Enter New Course Name: ");
                    fgets(student[i].course, sizeof(student[i].course), stdin);
                    student[i].course[strcspn(student[i].course, "\n")] = '\0';
                    printf("Course updated successfully!\n");
                    break;
                    
                case 4:
                    printf("\n---Enter New Marks---\n");
                    for(j = 0; j < 5; j++)
                    {
                        do
                        {
                            printf("Enter %s: ", subjects[j]);
                            scanf("%f", &student[i].marks[j]);
                            
                            if(student[i].marks[j] < 0 || student[i].marks[j] > 100)
                            {
                                printf("Invalid! Marks must be between 0 and 100.\n");
                            }
                        }
                        while(student[i].marks[j] < 0 || student[i].marks[j] > 100);
                    }
                    printf("Marks updated successfully!\n");
                    break;
                    
                default:
                    printf("Invalid choice!\n");
                    break;
            }
            
            calculate(&student[i]);
            SavefromFile();
            break;
        }
    }
    
    if(!found)
        printf("\nStudent not found!\n");
    
    printf("\n----------------------------------------------------------------------------\n");
}

/* Delete a student from the system */
void deleteStudent()
{
    int found = 0;
    printf("\n---Delete Student---\n");
    int roll_number;
    
    printf("Enter Roll Number of student: ");
    scanf("%d", &roll_number);
    
    for(i = 0; i < count; i++)
    {
        if(student[i].roll_number == roll_number)
        {
            for(j = i; j < count - 1; j++)
            {
                student[j] = student[j + 1];
            }
            count--;
            found = 1;
            printf("\nStudent Deleted Successfully!\n");
            SavefromFile();
            printf("\n----------------------------------------------------------------------------\n");
            return;
        }
    }
    
    if(!found)
        printf("\nStudent Not found!\n");
    
    printf("\n----------------------------------------------------------------------------\n");
}

/* Load student data from file */
void loadFromFile()
{
    FILE *file;
    file = fopen("students.txt", "r");
    
    if(!file)
        return;
    
    fscanf(file, "%d", &count);
    
    for(i = 0; i < count; i++)
    {
        fscanf(file, "%d", &student[i].roll_number);
        fgetc(file);
        fgets(student[i].name, sizeof(student[i].name), file);
        student[i].name[strcspn(student[i].name, "\n")] = '\0';
        fgets(student[i].course, sizeof(student[i].course), file);
        student[i].course[strcspn(student[i].course, "\n")] = '\0';
        fscanf(file, "%d", &student[i].age);
        
        for(j = 0; j < 5; j++)
            fscanf(file, "%f", &student[i].marks[j]);
            
        fscanf(file, "%f", &student[i].total);
        fscanf(file, "%f", &student[i].percentage);
        fscanf(file, " %c", &student[i].grade);
    }
    
    fclose(file);
}

/* Save student data to file */
void SavefromFile()
{
    FILE *file;
    file = fopen("students.txt", "w");
    
    if(!file)
    {
        printf("\nError: Unable to save data to file!\n");
        return;
    }
    
    fprintf(file, "%d\n", count);
    
    for(i = 0; i < count; i++)
    {
        fprintf(file, "%d\n%s\n%s\n%d\n", student[i].roll_number, student[i].name, 
                student[i].course, student[i].age);
        
        for(j = 0; j < 5; j++)
            fprintf(file, "%.2f\n", student[i].marks[j]);
            
        fprintf(file, "%.2f\n", student[i].total);
        fprintf(file, "%.2f\n", student[i].percentage);
        fprintf(file, " %c\n", student[i].grade);
    }
    
    fclose(file);
}

/* Generate a comprehensive student report */
void studentReport()
{
    int pass = 0, fail = 0;
    float total = 0;
    
    if(count == 0)
    {
        printf("\nNo Students Available!\n");
        return;
    }
    
    Students *top = &student[0];
    
    for(i = 0; i < count; i++)
    {
        if(student[i].percentage > top->percentage)
            top = &student[i];
            
        if(student[i].percentage >= 40)
            pass++;
        else
            fail++;
            
        total += student[i].percentage;
    }
    
    float average = total / count;
    
    printf("\n============================================================================\n");
    printf("                          STUDENT REPORT                                    \n");
    printf("============================================================================\n");
    
    printf("\n---Top Performer---\n");
    printf("Roll Number: %d\n", top->roll_number);
    printf("Name: %s\n", top->name);
    printf("Course: %s\n", top->course);
    printf("Age: %d\n", top->age);
    printf("Percentage: %.2f%%\n", top->percentage);
    printf("Grade: %c\n", top->grade);
    
    printf("\n---Overall Statistics---\n");
    printf("Total Students: %d\n", count);
    printf("Passed Students: %d\n", pass);
    printf("Failed Students: %d\n", fail);
    printf("Class Average: %.2f%%\n", average);
    
    printf("\n============================================================================\n");
}

/* Sort students by different criteria */
void sortStudents()
{
    if(count == 0)
    {
        printf("\nNo students to sort!\n");
        return;
    }
    
    int choice;
    Students temp;
    
    printf("\n---Sort Students---\n");
    printf("1. By Roll Number\n");
    printf("2. By Name\n");
    printf("3. By Percentage\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1: // Sort by Roll Number
            for(i = 0; i < count - 1; i++)
            {
                for(j = 0; j < count - i - 1; j++)
                {
                    if(student[j].roll_number > student[j + 1].roll_number)
                    {
                        temp = student[j];
                        student[j] = student[j + 1];
                        student[j + 1] = temp;
                    }
                }
            }
            printf("\nStudents sorted by Roll Number successfully!\n");
            break;
            
        case 2: // Sort by Name
            for(i = 0; i < count - 1; i++)
            {
                for(j = 0; j < count - i - 1; j++)
                {
                    if(strcmp(student[j].name, student[j + 1].name) > 0)
                    {
                        temp = student[j];
                        student[j] = student[j + 1];
                        student[j + 1] = temp;
                    }
                }
            }
            printf("\nStudents sorted by Name successfully!\n");
            break;
            
        case 3: // Sort by Percentage
            for(i = 0; i < count - 1; i++)
            {
                for(j = 0; j < count - i - 1; j++)
                {
                    if(student[j].percentage < student[j + 1].percentage)
                    {
                        temp = student[j];
                        student[j] = student[j + 1];
                        student[j + 1] = temp;
                    }
                }
            }
            printf("\nStudents sorted by Percentage (Highest to Lowest) successfully!\n");
            break;
            
        default:
            printf("\nInvalid Choice!\n");
            return;
    }
    
    SavefromFile();
    printf("\n----------------------------------------------------------------------------\n");
}
