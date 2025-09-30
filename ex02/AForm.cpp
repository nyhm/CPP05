#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical Form
AForm::AForm() : _name("Unknown"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) 
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        // _name, _gradeToSign, _gradeToExecute are const, so we can't assign them
        // We only assign _isSigned
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm()
{
}

// Getters
const std::string& AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

// Member functions
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// Exception implementations
const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high (must be >= 1)";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low (must be <= 150)";
}

const char* AForm::AFormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form name: " << form.getName() 
       << ", signed: " << (form.getIsSigned() ? "true" : "false")
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}
