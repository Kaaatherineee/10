#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include "user.h"

class Resource {
private:
    std::string name;
    int requiredAccessLevel;

public:
    Resource(const std::string& name, int requiredAccessLevel);

    const std::string& getName() const { return name; }
    int getRequiredAccessLevel() const { return requiredAccessLevel; }

    bool checkAccess(const User& user) const;
};

#endif
