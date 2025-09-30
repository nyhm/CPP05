#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <algorithm> // For std::transform

// Orthodox Canonical Form
Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other; // Suppress unused parameter warning
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other; // Suppress unused parameter warning
    return *this;
}

Intern::~Intern()
{
}

// Helper function to convert string to lowercase
std::string toLowerCase(const std::string& str)
{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Helper function to get form type enum
enum FormType
{
    SHRUBBERY_CREATION = 0,
    ROBOTOMY_REQUEST = 1,
    PRESIDENTIAL_PARDON = 2,
    UNKNOWN_FORM = -1
};

FormType getFormType(const std::string& formName)
{
    std::string lowerName = toLowerCase(formName);
    
    if (lowerName == "shrubbery creation")
        return SHRUBBERY_CREATION;
    else if (lowerName == "robotomy request")
        return ROBOTOMY_REQUEST;
    else if (lowerName == "presidential pardon")
        return PRESIDENTIAL_PARDON;
    else
        return UNKNOWN_FORM;
}

// Main function using switch statement
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    FormType formType = getFormType(formName);
    
    switch (formType)
    {
        case SHRUBBERY_CREATION:
            std::cout << "Intern creates " << formName << std::endl;
            return createShrubberyCreationForm(target);
            
        case ROBOTOMY_REQUEST:
            std::cout << "Intern creates " << formName << std::endl;
            return createRobotomyRequestForm(target);
            
        case PRESIDENTIAL_PARDON:
            std::cout << "Intern creates " << formName << std::endl;
            return createPresidentialPardonForm(target);
            
        case UNKNOWN_FORM:
        default:
            std::cout << "Error: Form '" << formName << "' does not exist" << std::endl;
            return NULL;
    }
}

// Private helper functions
AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}
