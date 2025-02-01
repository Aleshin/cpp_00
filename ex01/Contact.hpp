#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    // Constructor and Destructor
    Contact() {}
    ~Contact() {}

    // Function to set contact details with input validation
    int setContact();

    // Function to display a summary of the contact (used in PhoneBook list)
    void displaySummary(int index) const;

    // Function to display full details of the contact
    void displayDetails() const;
};

#endif