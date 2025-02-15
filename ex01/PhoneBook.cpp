#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

int PhoneBook::addContact() {
    if (contactCount < MAX_CONTACTS) {
        if (contacts[contactCount].setContact())
            return 1;
        contactCount++;
    } else {
        if (contacts[oldestIndex].setContact())
            return 1;
        oldestIndex = (oldestIndex + 1) % MAX_CONTACTS;
    }
    std::cout << "Contact added successfully!" << std::endl;
    return 0;
}

int PhoneBook::searchContacts() const {
    if (contactCount == 0) {
        std::cout << "No contacts available." << std::endl;
        return 0;
    }
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|"
              << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (int i = 0; i < contactCount; ++i) {
        contacts[i].displaySummary(i);
    }

    std::string input;
    int index;

    // First attempt to enter an index
    std::cout << "Enter contact index: ";
    if (!std::getline(std::cin, input))
        return 1;

    while (true) {
        if (std::cin.eof()) {
            std::cout << std::endl;
            return 1;
        }

        std::stringstream ss(input);
        if (ss >> index && index >= 0 && index < contactCount) {
            contacts[index].displayDetails();
            return 0;
        }

        // Invalid input, ask for a retry or exit
        std::cout << "Invalid index. Enter a valid index or type 'exit' to cancel: ";
        if (!std::getline(std::cin, input))
            return 1;

        if (input == "exit") {
            std::cout << "Search cancelled." << std::endl;
            return 0;
        }
    }
    return 0;
}