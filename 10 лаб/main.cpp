#include <iostream>
#include <memory>
#include "user.h"
#include "resource.h"
#include "access_control_system.h"

int main() {
    try {
        AccessControlSystem<User, Resource> system;

        // Добавляем пользователей
        system.addUser(std::make_unique<Student>("Alice", 101, 2, "CS-101"));
        system.addUser(std::make_unique<Teacher>("Bob", 201, 5, "Computer Science"));
        system.addUser(std::make_unique<Administrator>("Charlie", 301, 10));

        // Добавляем ресурсы
        system.addResource(std::make_unique<Resource>("Library", 1));
        system.addResource(std::make_unique<Resource>("Lab", 4));
        system.addResource(std::make_unique<Resource>("Office", 8));

        // Вывод всех пользователей и ресурсов
        std::cout << "\n=== Users ===\n";
        system.displayAllUsers();

        std::cout << "\n=== Resources ===\n";
        system.displayAllResources();

        // Проверяем доступ
        if (!system.getUsers().empty() && !system.getResources().empty()) {
            const User& user = *system.getUsers()[0];           // Первый пользователь
            const Resource& resource = *system.getResources()[0]; // Первый ресурс

            std::cout << "\n=== Checking Access ===\n";
            system.checkAccessForUser(user, resource);
        }

        // Сортировка по уровню доступа
        std::cout << "\n=== Sorted by Access Level ===\n";
        system.sortUsersByAccessLevel();
        system.displayAllUsers();

    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}