#include "Intern.hpp"
#include <iostream>
#include <map>

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

// Main function
Form* Intern::makeForm(const std::string& formName, const std::string& target)
{
    // Create a map of form names to creator functions
    typedef Form* (Intern::*FormCreator)(const std::string&);
    
    std::map<std::string, FormCreator> formCreators;
    formCreators["shrubbery creation"] = &Intern::createShrubberyCreationForm;
    formCreators["robotomy request"] = &Intern::createRobotomyRequestForm;
    formCreators["presidential pardon"] = &Intern::createPresidentialPardonForm;
    
    // Convert form name to lowercase for case-insensitive comparison
    std::string lowerFormName = formName;
    for (size_t i = 0; i < lowerFormName.length(); i++)
    {
        lowerFormName[i] = std::tolower(lowerFormName[i]);
    }
    
    // Find the creator function
    std::map<std::string, FormCreator>::iterator it = formCreators.find(lowerFormName);
    if (it != formCreators.end())
    {
        Form* form = (this->*(it->second))(target);
        std::cout << "Intern creates " << form->getName() << std::endl;
        return form;
    }
    else
    {
        std::cout << "Error: Form '" << formName << "' does not exist" << std::endl;
        return NULL;
    }
}

// Private helper functions
Form* Intern::createShrubberyCreationForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

Form* Intern::createRobotomyRequestForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

Form* Intern::createPresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}
