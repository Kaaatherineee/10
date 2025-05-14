#ifndef ACCESS_CONTROL_SYSTEM_H
#define ACCESS_CONTROL_SYSTEM_H

#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>

template<typename UserType, typename ResourceType>
class AccessControlSystem {
private:
    std::vector<std::unique_ptr<UserType>> users;
    std::vector<std::unique_ptr<ResourceType>> resources;

public:
    void addUser(std::unique_ptr<UserType> user) {
        if (!user) throw std::invalid_argument("User cannot be null");
        users.push_back(std::move(user));
    }

    void addResource(std::unique_ptr<ResourceType> resource) {
        if (!resource) throw std::invalid_argument("Resource cannot be null");
        resources.push_back(std::move(resource));
    }

    void displayAllUsers() const {
        for (const auto& user : users) {
            user->displayInfo();
        }
    }

    void displayAllResources() const {
        for (const auto& res : resources) {
            std::cout << "Resource: " << res->getName()
                << ", Required Access Level: " << res->getRequiredAccessLevel() << std::endl;
        }
    }

    void checkAccessForUser(const UserType& user, const ResourceType& resource) const {
        if (resource.checkAccess(user)) {
            std::cout << user.getName() << " has access to " << resource.getName() << std::endl;
        }
        else {
            std::cout << user.getName() << " does NOT have access to " << resource.getName() << std::endl;
        }
    }

    std::vector<std::unique_ptr<UserType>> findUsersByName(const std::string& name) const {
        std::vector<std::unique_ptr<UserType>> result;
        for (const auto& user : users) {
            if (user->getName() == name) {
                result.push_back(std::make_unique<UserType>(*user));
            }
        }
        return result;
    }

    std::vector<std::unique_ptr<UserType>> findUsersById(int id) const {
        std::vector<std::unique_ptr<UserType>> result;
        for (const auto& user : users) {
            if (user->getId() == id) {
                result.push_back(std::make_unique<UserType>(*user));
            }
        }
        return result;
    }

    void sortUsersByAccessLevel() {
        std::sort(users.begin(), users.end(),
            [](const std::unique_ptr<UserType>& a, const std::unique_ptr<UserType>& b) {
                return a->getAccessLevel() < b->getAccessLevel();
            });
    }

    const std::vector<std::unique_ptr<UserType>>& getUsers() const {
        return users;
    }

    const std::vector<std::unique_ptr<ResourceType>>& getResources() const {
        return resources;
    }
};

#endif