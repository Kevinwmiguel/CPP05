/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 23:58:39 by kwillian          #+#    #+#             */
/*   Updated: 2026/08/29 18:14:56 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	std::cout << "===== INTERN TESTS =====" << std::endl;

	Intern intern;
	AForm *form;

	// --------------------------------------------------
	// Test 1: Shrubbery Creation
	// --------------------------------------------------
	std::cout << "\n--- Test 1: Shrubbery Creation ---" << std::endl;

	form = intern.makeForm("shrubbery creation", "Home");

	if (form)
	{
		std::cout << "Form successfully created!" << std::endl;
		std::cout << *form << std::endl;

		Bureaucrat bob("Bob", 1);
		bob.signForm(*form);
		bob.executeForm(*form);

		delete form;
	}

	// --------------------------------------------------
	// Test 2: Robotomy Request
	// --------------------------------------------------
	std::cout << "\n--- Test 2: Robotomy Request ---" << std::endl;

	form = intern.makeForm("robotomy request", "Bender");

	if (form)
	{
		std::cout << "Form successfully created!" << std::endl;
		std::cout << *form << std::endl;

		Bureaucrat bob("Bob", 1);
		bob.signForm(*form);
		bob.executeForm(*form);

		delete form;
	}

	// --------------------------------------------------
	// Test 3: Presidential Pardon
	// --------------------------------------------------
	std::cout << "\n--- Test 3: Presidential Pardon ---" << std::endl;

	form = intern.makeForm("presidential pardon", "Arthur");

	if (form)
	{
		std::cout << "Form successfully created!" << std::endl;
		std::cout << *form << std::endl;

		Bureaucrat bob("Bob", 1);
		bob.signForm(*form);
		bob.executeForm(*form);

		delete form;
	}

	// --------------------------------------------------
	// Test 4: Invalid form
	// --------------------------------------------------
	std::cout << "\n--- Test 4: Invalid Form ---" << std::endl;

	form = intern.makeForm("coffee request", "Bender");

	if (form == NULL)
		std::cout << "Correctly returned NULL for invalid form."
				  << std::endl;
	else
	{
		std::cout << "ERROR: Invalid form was created!" << std::endl;
		delete form;
	}

	// --------------------------------------------------
	// Test 5: Another invalid form
	// --------------------------------------------------
	std::cout << "\n--- Test 5: Another Invalid Form ---" << std::endl;

	form = intern.makeForm("robotomy", "Bender");

	if (form == NULL)
		std::cout << "Correctly returned NULL for invalid form."
				  << std::endl;
	else
	{
		std::cout << "ERROR: Invalid form was created!" << std::endl;
		delete form;
	}

	std::cout << "\n===== ALL TESTS FINISHED =====" << std::endl;

	return 0;
}