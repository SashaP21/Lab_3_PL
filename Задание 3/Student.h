#ifndef _3_STUDENT_H
#define _3_STUDENT_H

#include <vector>
#include <string>
#include "Human.h"

class Student : public Human {
    std::vector<int> scores;
public:
    Student() = default;
    Student(std::string name,
            std::string surname,
            std::string patronymic,
            const std::vector<int>& scores);
    void addScore(int score);
    double getAverageScore() const;
    std::string getShortStudentInfo() const;
    std::string getFullStudentInfo() const;
    std::vector<int> getScores() const;
};

std::vector<Student> loadStudentsFromFile(std::string filename);
void saveStudentsToFile(std::string filename, const std::vector<Student> &students);

#endif //_3_STUDENT_H