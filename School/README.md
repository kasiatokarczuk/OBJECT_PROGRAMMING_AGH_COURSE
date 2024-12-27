# School Management System

## Project Overview
This is a system designed to manage a private school's data, including students, teachers, and administrative employees. The system handles the identification of students, their grades, and various functionalities related to school staff.

### Features
1. **Students**:
   - A student is identified by a unique ID, which is generated based on a base ID (`baseID`) starting at 10000. 
   - Male students are prefixed with `M_`, while female students are prefixed with `F_` (e.g., M_00100 or F_12345).
   - The system stores grades for the following subjects: Polish, Mathematics, Physics, Chemistry, Informatics, English, and German. Grades can range from 2 to 5, including half-grades.
   - Students can have an average grade calculated, and the system can print student details such as ID, name, age, and average grade.
   - Students' outfits are defined in virtual methods and can differ for male and female students.
   
2. **Teachers**:
   - Teachers are associated with specific subjects and can be a class tutor (e.g., "2b").
   - The system calculates the teacher's salary based on the following:
     - 80% of the salary is considered as income, with 50% of costs applied.
     - The system adjusts the salary for years of experience (from 5 to 20 years).
     - An additional bonus is given for teachers who are class tutors.
     - Taxes are calculated on the gross salary based on defined formulas.
   
3. **Administrative Staff**:
   - The system stores the position of administrative staff (e.g., Junior Specialist, Specialist, Senior Specialist).
   - Administrative staff salaries are calculated based on a formula that includes a tax deduction.

4. **Salary Calculations**:
   - Administrative staff: The system calculates taxes on their salary based on a defined tax formula.
   - Teachers: The system applies a special rule for salary calculation, including years of experience and additional allowances for being a class tutor.

5. **Employee List**:
   - The system can print a list of employees, including their names, positions, and specific details for teachers (such as the subjects they teach).

### Classes and Methods
- **Pupil Class**: Represents a student, storing their grades and ID. Methods include:
  - Setting grades for each subject.
  - Calculating the average grade.
  - Printing the student’s data, including their outfit (depending on whether they are a male or female student).
- **Teacher Class**: Represents a teacher, with details like the subject they teach, years of experience, and whether they are a class tutor.
- **Admin Class**: Represents administrative staff, with position and salary details.
- **Salary Calculation**: Each employee has a method to calculate their salary after applying deductions and taxes.

### Usage
1. Create instances of students, teachers, and administrative staff.
2. Assign grades to students for different subjects.
3. Print detailed information about students, including their grades, ID, and outfits.
4. Calculate the salaries for teachers and administrative staff, considering experience and specific roles (e.g., class tutor).
