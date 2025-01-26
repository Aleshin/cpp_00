#include <iostream>
#include <cctype>

// Function to convert string to uppercase
std::string toUpperCase(const std::string& str)
{
    std::string result;
    size_t i = 0;
    while (i < str.length())
    {
        result += std::toupper(str[i]);
        ++i;
    }
    return result;
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
        {
            std::cout << toUpperCase(argv[i]);
            if (i < argc - 1)
                std::cout << " "; // Separate words with space
            ++i;
        }
        std::cout << std::endl;
    }
    return 0;
}
