/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:00:56 by kwillian          #+#    #+#             */
/*   Updated: 2026/08/29 18:13:03 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class AForm;

class Intern
{
    public:
    Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();
    AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif