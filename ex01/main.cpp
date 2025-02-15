#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (std::cin.eof()) {
            break;
        } else {
        if (command == "ADD") {
            if (phoneBook.addContact())
                return 1;
        } else if (command == "SEARCH") {
            if (phoneBook.searchContacts())
                return 1;
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
        }
        }
    }
    return 0;
}
