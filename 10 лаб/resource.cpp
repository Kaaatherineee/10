#include "resource.h"
#include <stdexcept>

Resource::Resource(const std::string& name, int requiredAccessLevel)
    : name(name), requiredAccessLevel(requiredAccessLevel) {
    if (name.empty()) throw std::invalid_argument("Resource name cannot be empty");
    if (requiredAccessLevel < 0) throw std::invalid_argument("Access level must be >= 0");
}

bool Resource::checkAccess(const User& user) const {
    return user.getAccessLevel() >= requiredAccessLevel;
}