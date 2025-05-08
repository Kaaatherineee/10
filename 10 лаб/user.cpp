#include "user.h"
#include <stdexcept>
#include <iostream>

User::User(const std::string& name, int id, int accessLevel)
    : name(name), id(id), accessLevel(accessLevel) {
    if (name.empty()) throw std::invalid_argument("Name cannot be empty");
    if (accessLevel < 0) throw std::invalid_argument("Access level must be >= 0");
}

void User::displayInfo() const {
    std::cout << "User: " << name << ", ID: " << id << ", Access Level: " << accessLevel << std::endl;
}

void User::setName(const std::string& n) {
    if (n.empty()) throw std::invalid_argument("Name cannot be empty");
    name = n;
}

void User::setId(int i) { id = i; }

void User::setAccessLevel(int level) {
    if (level < 0) throw std::invalid_argument("Access level must be >= 0");
    accessLevel = level;
}

// === Student ===
Student::Student(const std::string& name, int id, int accessLevel, const std::string& group)
    : User(name, id, accessLevel), group(group) {
}

void Student::displayInfo() const {
    User::displayInfo();
    std::cout << "Group: " << group << std::endl;
}

// === Teacher ===
Teacher::Teacher(const std::string& name, int id, int accessLevel, const std::string& department)
    : User(name, id, accessLevel), department(department) {
}

void Teacher::displayInfo() const {
    User::displayInfo();
    std::cout << "Department: " << department << std::endl;
}

// === Administrator ===
Administrator::Administrator(const std::string& name, int id, int accessLevel)
    : User(name, id, accessLevel) {
}

void Administrator::displayInfo() const {
    User::displayInfo();
    std::cout << "Role: Administrator" << std::endl;
}