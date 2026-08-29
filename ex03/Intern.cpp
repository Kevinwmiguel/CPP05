/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:01:19 by kwillian          #+#    #+#             */
/*   Updated: 2026/08/29 18:19:23 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

static AForm* createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string& formName,
						const std::string& target)
{
	const std::string names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*create[])(const std::string&) = {
		&createShrubbery,
		&createRobotomy,
		&createPardon
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return create[i](target);
		}
	}

	std::cout << "Error: Form \"" << formName
			  << "\" does not exist." << std::endl;

	return NULL;
}

