/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:58:26 by kwillian          #+#    #+#             */
/*   Updated: 2026/06/16 19:04:45 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(false), _grade(150), _execute(150)
{
    std::cout << "AForm Constructor has been called" << std::endl;    
}

AForm::~AForm()
{
    std::cout << "AForm Destructor has been called" << std::endl;    
}

AForm::AForm(const AForm& other) : _name(other._name), 
    _signed(other._signed), _grade(other._grade), _execute(other._execute)
{
}

AForm::AForm(const std::string name, const int sign_grade, const int execute_grade) : _name(name), 
    _signed(false), _grade(150), _execute(150)
{
    if (sign_grade < 1 || execute_grade < 1)
        throw GradeTooHighException();
    if (sign_grade > 150 || execute_grade > 150)
        throw GradeTooLowException();

}
AForm& AForm::operator=(const AForm& other)
{
    this->_signed = other._signed;
    return (*this);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= _grade)
		_signed = true;
	else
		throw GradeTooLowException();
}

std::string AForm::getName() const
{
    return (this->_name);
}

int AForm::getSignGrade() const
{
    return (this->_grade);
}

bool AForm::getIsSigned() const
{
    return (this->_signed);
}

int AForm::getExecuteGrade() const
{
    return (this->_execute);
}

std::ostream&operator<<(std::ostream& out, const AForm& AForm)
{
	out << "Name: " << AForm.getName() << " isSigned: " 
        << AForm.getIsSigned() << " SignGrade: "
        << AForm.getSignGrade() << " ExecuteGrade: " 
        << AForm.getExecuteGrade() << std::endl;
	return (out);
}