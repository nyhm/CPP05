#include "Form.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical Form
Form::Form() : _name("Unknown"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) 
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        // _name, _gradeToSign, _gradeToExecute are const, so we can't assign them
        // We only assign _isSigned
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form()
{
}

// Getters
const std::string& Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

// Member functions
void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// Exception implementations
const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high (must be >= 1)";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low (must be <= 150)";
}

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form name: " << form.getName() 
       << ", signed: " << (form.getIsSigned() ? "true" : "false")
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}

