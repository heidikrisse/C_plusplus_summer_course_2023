#include <iostream>

struct StudentGrade
{
private:
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
    StudentGrade student;
    student.setGrade(4);
    std::cout << "The student's grade is: " << student.getGrade() << "\n";

    return 0;
}
