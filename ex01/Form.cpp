/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:58:26 by kwillian          #+#    #+#             */
/*   Updated: 2026/07/20 17:32:40 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(false), _grade(75), _execute(75)
{
    std::cout << "Form Constructor has been called" << std::endl;    
}

Form::~Form()
{
    std::cout << "Form Destructor has been called" << std::endl;    
}

Form::Form(const Form& other) : _name(other._name), 
    _signed(other._signed), _grade(other._grade), _execute(other._execute)
{
}

Form::Form(const std::string name, const int sign_grade, const int execute_grade) : _name(name), 
    _signed(false), _grade(75), _execute(75)
{
    if (sign_grade < 1 || execute_grade < 1)
        throw GradeTooHighException();
    if (sign_grade > 150 || execute_grade > 150)
        throw GradeTooLowException();

}
Form& Form::operator=(const Form& other)
{
    this->_signed = other._signed;
    return (*this);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= _grade)
		_signed = true;
	else
		throw GradeTooLowException();
}

std::string Form::getName() const
{
    return (this->_name);
}

int Form::getSignGrade() const
{
    return (this->_grade);
}

bool Form::getIsSigned() const
{
    return (this->_signed);
}

int Form::getExecuteGrade() const
{
    return (this->_execute);
}

std::ostream&operator<<(std::ostream& out, const Form& Form)
{
	out << "Name: " << Form.getName() << " is signed: " 
        << Form.getIsSigned() << " SignGrade: "
        << Form.getSignGrade() << " ExecuteGrade: " 
        << Form.getExecuteGrade() << std::endl;
	return (out);
}