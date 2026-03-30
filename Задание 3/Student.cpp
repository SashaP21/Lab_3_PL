#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
#include "Student.h"

using std::string;
using std::stringstream;
using std::vector;

Student::Student(string name, string surname,
                 string patronymic, const vector<int>& scores)
                 :Human(name, surname, patronymic)
{
    this->scores = scores;
}

void Student::addScore(int score) {
    scores.push_back(score);
}

double Student::getAverageScore() const {
    if (scores.empty())
        return 0.0;
    double sum = 0;
    for (int score : scores)
        sum += score;
    return sum / scores.size();
}

string Student::getShortStudentInfo() const {
    stringstream s;
    s << getSurnameAndInitials() << ": " << getAverageScore();
    return s.str();
}

string Student::getFullStudentInfo() const {
    stringstream s;
    s << getFullName() << ": ";
    for (int score : scores)
        s << score << " ";
    s << "- " << getAverageScore();
    return s.str();
}

vector<Student> loadStudentsFromFile(string filename) {
    vector<Student> students;
    std::ifstream f_in(filename);
    string line;
    if (!f_in) {
       std::cout << "Не удалось открыть файл: " << filename << "\n";
        return students;
    }
    while (std::getline(f_in, line)) {
        vector<int> scores;
        int score;
        string name, surname, patronymic;
        stringstream ss(line);
        ss >> surname >> name >> patronymic;
        while (ss >> score)
            scores.push_back(score);
        Student student(name, surname, patronymic, scores);
        students.push_back(student);
    }
    f_in.close();
    return students;
}

std::vector<int> Student::getScores() const {
    return scores;
}

void saveStudentsToFile(string filename, const vector<Student> &students) {
    std::ofstream f_out(filename);
    for (const Student& student : students) {
        f_out << student.getFullName() << " ";
        for (int score : student.getScores())
            f_out << score << " ";
        f_out << "\n";
    }
}
