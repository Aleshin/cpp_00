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
            std::cout << "EOF detected. Exiting program." << std::endl;
            break;
        } else {
        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContacts();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
        }
        }
    }
    return 0;
}
