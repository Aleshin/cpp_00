#include "Contact.hpp"
#include <iostream>
#include <iomanip>

// Function to get valid input and ensure the field is not empty
int getValidInput(const std::string& prompt, std::string& field) {
    do {
        std::cout << prompt;
        std::getline(std::cin, field);

        // Check for EOF (Ctrl+D) to prevent input freeze
        if (std::cin.eof()) {
            std::cout << "EOF detected. Exiting input mode.\n";
            std::cin.clear();  // Reset EOF flag
            return 1;
        }

        if (field.empty()) {
            std::cout << "Field cannot be empty. Please try again.\n";
        }
    } while (field.empty());
    return 0;
}

int Contact::setContact() {
    if (getValidInput("Enter first name: ", firstName))
        return 1;
    getValidInput("Enter last name: ", lastName);
    getValidInput("Enter nickname: ", nickname);
    getValidInput("Enter phone number: ", phoneNumber);
    getValidInput("Enter darkest secret: ", darkestSecret);
    return 0;
}

void Contact::displaySummary(int index) const {
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|"
              << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|"
              << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << "|"
              << std::endl;
}

void Contact::displayDetails() const {
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}
