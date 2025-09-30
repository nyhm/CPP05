#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; // Forward declaration

class AForm
{
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _gradeToSign;
    const int           _gradeToExecute;

public:
    // Orthodox Canonical Form
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    // Getters
    const std::string&  getName() const;
    bool                getIsSigned() const;
    int                 getGradeToSign() const;
    int                 getGradeToExecute() const;

    // Member functions
    void                beSigned(const Bureaucrat& bureaucrat);
    virtual void        execute(const Bureaucrat& executor) const = 0; // Pure virtual function

    // Exception classes
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class AFormNotSignedException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
