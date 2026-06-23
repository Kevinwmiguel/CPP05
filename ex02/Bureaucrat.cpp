/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 00:28:41 by kwillian          #+#    #+#             */
/*   Updated: 2026/06/18 20:00:49 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat default constructor has been called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    this->_name = other._name;
    this->_grade = other._grade;
    std::cout << "Bureaucrat copy constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    if (grade < 1)
        throw gradeTooHighException();
    else if (grade > 150)
        throw gradeTooLowException();
    this->_name = name;
    this->_grade = grade;
    std::cout << "Bureaucrat constructor has been called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->_name = other.getName();
        this->_grade = other.getGrade();
    }
    return *this;
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}
    
int Bureaucrat::getGrade() const
{
    return this->_grade;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName()
        << ", bureaucrat grade "
        << bureaucrat.getGrade();
    return out;
}

void Bureaucrat::setName(std::string name)
{
    this->_name = name;
}

void Bureaucrat::setGrade(int grade)
{
    this->_grade = grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade > 1)
        this->_grade -= 1;
    else if (this->_grade == 1)
        std::cout << "The grade is at the maximum!" << std::endl;
    else
        std::cout << "out of range " << std::endl;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade < 150)
        this->_grade += 1;
    else if (this->_grade == 150)
        std::cout << "The grade is at the minimum!" << std::endl;
    else
        std::cout << "out of range " << std::endl;
}

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn't sign " << form.getName()
        << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn't execute " << form.getName()
        << " because " << e.what() << std::endl;
    }
}
