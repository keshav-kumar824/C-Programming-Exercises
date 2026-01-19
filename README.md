# C Programming Exercises

A growing collection of C programs demonstrating fundamental programming concepts including string manipulation, array operations, and algorithmic problem-solving.

## 🎯 About This Repository

This repository contains my solutions to various C programming challenges as I strengthen my programming fundamentals. Each program is well-commented and demonstrates specific concepts.

## 📚 Programs Included

### Problem 1: Full Name Analysis
**File**: `problem_01_name_analysis.c`

A program that performs comprehensive analysis on a user's full name:
- ✅ Counts occurrences of a user-specified letter (case-insensitive)
- ✅ Capitalizes the first letter of each word
- ✅ Counts total consonants in the name

**Key Concepts**: String manipulation, character classification, function modularity

**Sample Output**:
Enter Name: john smith
Enter Letter: h
Letter 'h' appears: 2 times
Capitalized Name: John Smith
Total consonants: 6

**Functions Implemented**:
- `charFrequency()` - Counts letter occurrences with case-insensitive matching
- `upperCase()` - Converts string to title case format
- `countConst()` - Counts consonants by checking against vowel set

---

# Problem 2: Task Management System
File: `problem_02_task_management.c`

A comprehensive menu-driven task management application that allows users to organize and track their tasks:
* ✅ Input multiple tasks with title, description, priority, and status
* ✅ Update task completion status (0 = Incomplete, 1 = Complete)
* ✅ Modify and auto-adjust task priority levels (0-10 scale)
* ✅ Display all tasks with formatted output
* ✅ Recursive priority validation to ensure values stay within range

**Key Concepts:** Structures, menu-driven interface, recursive validation, array manipulation, user input handling

**Sample Output:**
```
No of task: 2

=====To do list=====
1. Input
2. Update Status
3. Update priority
4. Display
5. Exit
Enter Choice (1-5): 1

Title: Complete Assignment
Description: Finish C programming project
Priority: 8
Task Status (0 or 1): 0

=====Task 1=====
Title: Complete Assignment
Description: Finish C programming project
Priority: 8
Task Status: Incomplete
```

**Functions Implemented:**
* `input()` - Captures task details using `fgets()` for safe string input with newline handling
* `updateStatus()` - Modifies task completion status with user confirmation
* `modifyPriority()` - Updates priority value and triggers validation
* `adjustPriority()` - Recursively adjusts priority to valid range (0-10) if out of bounds
* `display()` - Formats and presents all tasks with proper status labeling

**Structure Definition:**
```c
struct Task {
    char title[100];        // Task name
    char description[200];  // Detailed description
    int priority;           // Priority level (0-10)
    int taskStatus;         // Completion status (0/1)
};
```

**Technical Highlights:**
- Uses `strcspn()` to remove trailing newlines from `fgets()` input
- Implements recursive boundary checking for priority validation
- Menu loop continues until user explicitly exits
- Proper use of `getchar()` to handle input buffer clearing


## 🛠️ How to Use

### Compilation
```bash
gcc problem_01_name_analysis.c -o name_analyzer
```

### Execution
```bash
./name_analyzer
```

### Requirements
- GCC compiler (or any standard C compiler)
- C99 or later standard

---

## 💡 What I'm Learning

Through these exercises, I'm developing skills in:
- **String Processing**: Working with character arrays, `fgets()`, string functions
- **Memory Management**: Proper buffer handling and null termination
- **Function Design**: Creating modular, reusable functions
- **Algorithm Development**: Implementing search and counting algorithms
- **Input Validation**: Handling user input safely

---

## 🔄 Future Programs

Coming soon:
- Course title analysis with advanced string operations
- Array-based data tracking systems
- Recursive validation programs
- Temperature and sales analysis tools

---

## 📖 Technical Details

- **Language**: C
- **Standard**: C99+
- **Libraries**: `stdio.h`, `string.h`
- **Code Style**: Clean, commented, beginner-friendly

---

## 🤝 Contributing

This is a personal learning repository, but feedback and suggestions are always welcome!

---

## 📫 Connect

Feel free to explore, learn, and suggest improvements!

---

**Status**: 🟢 Active Development | Last Updated: January 2026

⭐ **Star this repo if you find it helpful!**
