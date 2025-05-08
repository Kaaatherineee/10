#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string name;
    int id;
    int accessLevel;

public:
    User(const std::string& name, int id, int accessLevel);

    virtual void displayInfo() const;

    const std::string& getName() const { return name; }
    int getId() const { return id; }
    int getAccessLevel() const { return accessLevel; }

    void setName(const std::string& n);
    void setId(int i);
    void setAccessLevel(int level);
};

class Student : public User {
private:
    std::string group;

public:
    Student(const std::string& name, int id, int accessLevel, const std::string& group);
    void displayInfo() const override;
};

class Teacher : public User {
private:
    std::string department;

public:
    Teacher(const std::string& name, int id, int accessLevel, const std::string& department);
    void displayInfo() const override;
};

class Administrator : public User {
public:
    Administrator(const std::string& name, int id, int accessLevel);
    void displayInfo() const override;
};

#endif
