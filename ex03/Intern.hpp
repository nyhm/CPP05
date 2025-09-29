#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern
{
public:
    // Orthodox Canonical Form
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    // Main function
    Form* makeForm(const std::string& formName, const std::string& target);

private:
    // Private helper functions for creating specific forms
    Form* createShrubberyCreationForm(const std::string& target);
    Form* createRobotomyRequestForm(const std::string& target);
    Form* createPresidentialPardonForm(const std::string& target);
};

#endif
