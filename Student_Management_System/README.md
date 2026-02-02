# Student Management System

A comprehensive command-line based Student Management System written in C that allows users to manage student records efficiently with features like adding, updating, deleting, searching, sorting, and generating reports.

## Features

- **Add Student**: Add new student records with validation for duplicate roll numbers and marks range
- **Display Students**: View all student records with their complete information
- **Update Student**: Modify existing student information (name, age, course, or marks)
- **Search Student**: Find students by roll number or name
- **Delete Student**: Remove student records from the system
- **Sort Students**: Sort student records by roll number, name, or percentage
- **Generate Report**: View comprehensive statistics including:
  - Top performer details
  - Total number of students
  - Pass/fail statistics
  - Class average percentage
- **Data Persistence**: Automatic save and load functionality using file storage

## System Requirements

- GCC Compiler (or any C compiler)
- Terminal/Command Prompt
- Operating System: Windows/Linux/macOS

## Installation

### Clone the Repository

```bash
git clone https://github.com/yourusername/student-management-system.git
cd student-management-system
```

### Compile the Program

#### On Linux/macOS:
```bash
gcc student_management.c -o student_management
```

#### On Windows:
```bash
gcc student_management.c -o student_management.exe
```

## Usage

### Run the Program

#### On Linux/macOS:
```bash
./student_management
```

#### On Windows:
```bash
student_management.exe
```

### Menu Options

After running the program, you'll see the following menu:

```
1. Add Student
2. Display Students
3. Update Student
4. Search Student
5. Generate Student Report
6. Delete Student
7. Sort Students
8. Exit System
```

Simply enter the number corresponding to your desired operation.

## Data Structure

The system evaluates students based on 5 subjects:
1. Mathematics
2. Physics
3. Calculus
4. Chemistry
5. English

### Grading System

| Percentage | Grade |
|------------|-------|
| ≥ 90%      | A     |
| ≥ 70%      | B     |
| ≥ 60%      | C     |
| ≥ 40%      | D     |
| < 40%      | F     |

## File Storage

- Student data is automatically saved to `students.txt`
- Data persists between program sessions
- The file is created automatically on first use

## Example Workflow

1. **Adding a Student**:
   - Select option 1
   - Enter unique roll number
   - Enter student name, age, and course
   - Enter marks for all 5 subjects (0-100)
   - System automatically calculates total, percentage, and grade

2. **Searching for a Student**:
   - Select option 4
   - Choose search method (by roll number or name)
   - Enter the search criteria
   - View complete student details if found

3. **Generating a Report**:
   - Select option 5
   - View top performer, pass/fail statistics, and class average

## Technical Details

- **Language**: C
- **Maximum Students**: 100 (configurable via `MAX_STUDENTS` macro)
- **Data Validation**: 
  - Roll number uniqueness check
  - Marks range validation (0-100)
  - Input sanitization for strings
- **Sorting Algorithm**: Bubble Sort
- **File Handling**: Text-based file storage

## Code Structure

```
student_management.c
├── Data Structures
│   └── Students struct
├── Core Functions
│   ├── addStudent()
│   ├── displayStudents()
│   ├── updateStudent()
│   ├── deleteStudent()
│   ├── searchStudent()
│   └── sortStudents()
├── Utility Functions
│   ├── calculate()
│   ├── checkRollDuplicate()
│   ├── studentReport()
│   ├── loadFromFile()
│   └── SavefromFile()
└── Main Menu Loop
```

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes:

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## Known Issues

- None currently. Please report any bugs in the Issues section.

## License

This project is open source and available under the [MIT License](LICENSE).


## Acknowledgments

- Developed as part of C programming practice
- Thanks to the C programming community for inspiration and best practices

### Main Menu
```
==============---------------Student Management System---------------==============

1. Add Student
2. Display Students
3. Update Student
4. Search Student
5. Generate Student Report
6. Delete Student
7. Sort Students
8. Exit System

Enter Choice:
```

### Sample Student Report
```
============================================================================
                          STUDENT REPORT
============================================================================

---Top Performer---
Roll Number: 101
Name: John Doe
Course: Computer Science
Age: 20
Percentage: 95.60%
Grade: A

---Overall Statistics---
Total Students: 25
Passed Students: 23
Failed Students: 2
Class Average: 72.35%

============================================================================
```

## Support

If you encounter any problems or have suggestions, please:
- Open an issue on GitHub
- Contact the author via email

