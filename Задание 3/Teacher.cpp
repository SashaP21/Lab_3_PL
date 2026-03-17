#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Teacher.h"

using std::string;
using std::stringstream;
using std::vector;

string Teacher::Position_to_string(Position position){
    switch (position) {
        case Position::Assistant: return "Ассистент";
        case Position::SeniorLecturer: return "СтаршийПреподаватель";
        case Position::AssociateProfessor: return "Доцент";
        case Position::Professor: return "Профессор";
        default: return "Неизвестно";
    }
}

Teacher::Position Teacher::string_to_Position(string position) {
    if (position == "Ассистент") return Position::Assistant;
    if (position == "СтаршийПреподаватель") return Position::SeniorLecturer;
    if (position == "Доцент") return Position::AssociateProfessor;
    if (position == "Профессор") return Position::Professor;
    return Position::Unknown;
}

Teacher::Teacher(string name, string surname, string patronymic,
                 string position, const vector<string>& subjects)
                 :Human(name, surname, patronymic)
{
    this->position = string_to_Position(position);
    this->subjects = subjects;
}

void Teacher::addSubject(string subject) {
    subjects.push_back(subject);
}

string Teacher::getShortTeacherInfo() const {
    stringstream s;
    s << getSurnameAndInitials() << " "
      << Position_to_string(position) << ": "
      << subjects.size();
    return s.str();
}

string Teacher::getFullTeacherInfo() const {
    stringstream s;
    s << getFullName() << " " <<  Position_to_string(position) << ": ";
    for (int i = 0; i < subjects.size(); i++) {
        if (i > 0)
            s << ", ";
        s << subjects[i];
    }
    return s.str();
}

vector<Teacher> loadTeachersFromFile(string filename) {
    vector<Teacher> teachers;
    std::ifstream f_in(filename);
    string line;
    if (!f_in) {
        std::cout << "Не удалось открыть файл: " << filename << "\n";
        return teachers;
    }
    while (std::getline(f_in, line)) {
        vector<string> subjects;
        string name, surname, patronymic, position, subject;
        stringstream ss(line);
        ss >> surname >> name >> patronymic >> position;
        while (ss >> subject)
            subjects.push_back(subject);
        Teacher teacher(name, surname, patronymic, position, subjects);
        teachers.push_back(teacher);
    }
    f_in.close();
    return teachers;
}

vector<string> Teacher::getSubjects() const {
    return subjects;
}

void saveTeachersToFile(string filename, const vector<Teacher>& teachers) {
    std::ofstream f_out(filename);
    for (const Teacher& teacher : teachers) {
        f_out << teacher.getFullName() << " " << teacher.getPosition() << " ";
        for (const string& subject : teacher.getSubjects())
            f_out << subject << " ";
        f_out << "\n";
    }
}

std::string Teacher::getPosition() const {
    return Position_to_string(position);
}
