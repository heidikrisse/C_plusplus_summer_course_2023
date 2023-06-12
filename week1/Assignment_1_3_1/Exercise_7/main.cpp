#include <iostream>

struct StudentGrade
{
private:
    // Private member variable, has the lifetime of the struct object
    int gradeValue{};

public:
    void setGrade(int grade)
    {
        gradeValue = grade;
    }

    int getGrade()
    {
        return gradeValue;
    }
};

int main()
{
    // An object of StudentGrade is created
    StudentGrade student{}; // The lifetime of gradeValue begins
    student.setGrade(4);
    std::cout << "The student's grade is: " << student.getGrade() << "\n";

    // The student object is destroyed and the lifetime of gradeValue ends
    return 0;
}
