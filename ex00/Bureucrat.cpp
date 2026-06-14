/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureucrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 00:28:41 by kwillian          #+#    #+#             */
/*   Updated: 2026/06/15 00:48:12 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureucrat default constructor has been called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureucrat default destructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    this->name = other.name;
    this->grade = other.grade;
    std::cout << "Bureucrat copy assignament constructor has been called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->name = other.getName();
        this->grade = other.getGrade();
    }
    return *this;
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}
    
int Bureaucrat::getGrade() const
{
    return (this->grade);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat)
{
    out << Bureaucrat;
    return out;
}

std::string Bureaucrat::setName(std::string name)
{
    this->name = name;
}

std::string Bureaucrat::setGrade(int grade)
{
    this->grade = grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->grade > 1)
        this->grade = grade - 1;
}