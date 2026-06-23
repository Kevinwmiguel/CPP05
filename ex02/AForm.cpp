/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 23:59:20 by kwillian          #+#    #+#             */
/*   Updated: 2026/06/23 11:46:06 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("Default"), _signed(false), _signGrade(150), _executeGrade(150)
{
    std::cout << "AForm default constructor has been called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm destructor has been called" << std::endl;
}

AForm::AForm(const AForm& other)
    : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
}

AForm::AForm(const std::string name, const int sign_grade, const int execute_grade)
    : _name(name), _signed(false), _signGrade(sign_grade), _executeGrade(execute_grade)
{
    if (sign_grade < 1 || execute_grade < 1)
        throw GradeTooHighException();
    if (sign_grade > 150 || execute_grade > 150)
        throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= _signGrade)
        _signed = true;
    else
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _executeGrade)
        throw GradeTooLowException();
    executeAction();
}

std::string AForm::getName() const
{
    return _name;
}

int AForm::getSignGrade() const
{
    return _signGrade;
}

bool AForm::getIsSigned() const
{
    return _signed;
}

int AForm::getExecuteGrade() const
{
    return _executeGrade;
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << "Name: " << form.getName()
        << " isSigned: " << form.getIsSigned()
        << " SignGrade: " << form.getSignGrade()
        << " ExecuteGrade: " << form.getExecuteGrade();
    return out;
}
