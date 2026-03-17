#include <iostream>
#include <vector>
#include <algorithm>
#include "windows.h"
#include "Student.h"
#include "Teacher.h"

using std::cout;
using std::vector;
using std::string;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "russian");

    vector<Student> students = loadStudentsFromFile("students.txt");
    cout << "Полный список студентов:\n";
    for (const Student& student : students)
        cout << student.getFullStudentInfo() << "\n";
    cout << "\n";

    vector<Teacher> teachers = loadTeachersFromFile("teachers.txt");
    cout << "Полный список преподавателей:\n";
    for (const Teacher& teacher : teachers)
        cout << teacher.getFullTeacherInfo() << "\n";

    saveStudentsToFile("students2.txt", students);
    saveTeachersToFile("teachers2.txt", teachers);

    cout << "1)	краткая информация обо всех студентах, у которых средний балл больше 4:\n";
    for (const Student& student : students) {
        if (student.getAverageScore() > 4)
            cout << student.getShortStudentInfo() << "\n";
    }
    cout << "\n";

    cout << "2)	краткая информация обо всех студентах, у которых средний балл меньше 3:\n";
    for (const Student& student : students) {
        if (student.getAverageScore() < 3)
            cout << student.getShortStudentInfo() << "\n";
    }
    cout << "\n";

    cout << "3)	полная информация о студенте, у которого больше всего оценок:\n";
    int max_scores_amount = 0;
    Student st;
    for (const Student& student : students) {
        if (student.getScores().size() >= max_scores_amount) {
            max_scores_amount = student.getScores().size();
            st = student;
        }
    }
    cout << st.getFullStudentInfo() << "\n\n";

    cout << "4)	краткая информация обо всех доцентах:\n";
    for (const Teacher& teacher : teachers) {
        if (teacher.getPosition() == "Доцент")
            cout << teacher.getShortTeacherInfo() << "\n";
    }
    cout << "\n";

    cout << "5)	полная информация о профессоре, у которого больше всего предметов:\n";
    int max_subject_amount = 0;
    Teacher t;
    for (const Teacher& teacher : teachers) {
        if ((teacher.getPosition() == "Профессор") && (teacher.getSubjects().size() >= max_subject_amount)) {
            max_subject_amount = teacher.getSubjects().size();
            t = teacher;
        }
    }
    cout << t.getFullTeacherInfo() << "\n\n";

    cout << "6)	полная информация обо всех преподавателях, которые ведут информатику:\n";
    for (const Teacher& teacher : teachers) {
        vector<string> subjects = teacher.getSubjects();
        if (std::find(subjects.begin(), subjects.end(), "Информатика") != subjects.end())
            cout << teacher.getFullTeacherInfo() << "\n";
    }
}