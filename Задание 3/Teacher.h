#ifndef _3_TEACHER_H
#define _3_TEACHER_H

#include <vector>
#include <string>
#include "Human.h"

class Teacher : public Human {
    enum class Position {Assistant, SeniorLecturer,
AssociateProfessor, Professor, Unknown};
    Position position = Position::Unknown;
    std::vector<std::string> subjects;
    static std::string Position_to_string(Position position);
    static Position string_to_Position(std::string position);
public:
    Teacher() = default;
    Teacher(std::string name,
            std::string surname,
            std::string patronymic,
            std::string position,
            const std::vector<std::string>& subjects);
    void addSubject(std::string subject);
    std::string getShortTeacherInfo() const;
    std::string getFullTeacherInfo() const;
    std::vector<std::string> getSubjects() const;
    std::string getPosition() const;
};

std::vector<Teacher> loadTeachersFromFile(std::string filename);
void saveTeachersToFile(std::string filename, const std::vector<Teacher>& teachers);

#endif //_3_TEACHER_H