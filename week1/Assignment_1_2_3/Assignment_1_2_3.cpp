#include <iostream>
#include <vector>
#include <string>

// Define a struct to hold student data
struct Student
{
    std::string name{};
    int age{};
    double grade{};
};

// Function to get data for each student
// The function asks for the number of students and reads the name, age, and grade for each student from the user.
std::vector<Student> inputStudentData()
{
    std::cout << "How many students do you want to input?\n";
    std::size_t numStudents{};
    std::cin >> numStudents;

    std::vector<Student> students(numStudents);
    for (std::size_t i{0}; i < numStudents; ++i)
    {
        std::cout << "Enter name for student " << i + 1 << ":\n";
        std::cin >> students[i].name;

        std::cout << "Enter age for student " << i + 1 << ":\n";
        std::cin >> students[i].age;

        std::cout << "Enter grade for student " << i + 1 << ":\n";
        std::cin >> students[i].grade;
    }
    return students;
}

// Function to calculate the average grade of the students
double calculateAverage(std::vector<Student> students)
{
    double totalGrade{0.0};
    for (std::size_t i{0}; i < students.size(); i++)
    {
        totalGrade += students[i].grade;
    }

    return totalGrade / students.size();
}

// Function to find the student with the highest grade
std::string calculateHighestGrade(std::vector<Student> students)
{
    double highestGrade{-1.0};
    std::string studentWithHighestGrade;
    for (std::size_t i{0}; i < students.size(); i++)
    {
        if (students[i].grade > highestGrade)
        {
            highestGrade = students[i].grade;
            studentWithHighestGrade = students[i].name;
        }
    }

    return studentWithHighestGrade;
}

// Function to print the results: the average grade and the student with the highest grade of the class
void printResults(double average, std::string highestGradeStudent)
{
    std::cout << "\nThe average grade of the class: " << average << "\n";
    std::cout << "The student with the highest grade: " << highestGradeStudent << "\n";
}

int main()
{
    std::vector<Student> students{inputStudentData()};

    double averageGrade{calculateAverage(students)};

    std::string highestGradeStudent{calculateHighestGrade(students)};

    printResults(averageGrade, highestGradeStudent);

    return 0;
}
