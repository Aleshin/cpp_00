#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

void PhoneBook::addContact() {
    if (contactCount < MAX_CONTACTS) {
        contacts[contactCount].setContact();
        contactCount++;
    } else {
        contacts[oldestIndex].setContact();
        oldestIndex = (oldestIndex + 1) % MAX_CONTACTS;
    }
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContacts() const {
    if (contactCount == 0) {
        std::cout << "No contacts available." << std::endl;
        return;
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
    std::cout << "Enter contact index: ";
    int index;
    std::cin >> index;
    std::cin.ignore();
    if (index >= 0 && index < contactCount) {
        contacts[index].displayDetails();
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}
