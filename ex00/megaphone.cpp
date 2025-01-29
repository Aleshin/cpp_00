#include <iostream>
#include <cctype>
#include <string>

// Function to convert string to uppercase
std::string toUpperCase(std::string str)
{
    size_t i = 0;
    while (i < str.length())
    {
        str[i] = std::toupper(str[i]);
        ++i;
    }
    return str;
}

int main(int argc, char **argv)
{
    int i = 1;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else
    {
        while (i < argc)
            std::cout << toUpperCase(argv[i++]);
        std::cout << std::endl;
    }
    return 0;
}
