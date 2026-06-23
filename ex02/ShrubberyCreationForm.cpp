/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 00:00:02 by kwillian          #+#    #+#             */
/*   Updated: 2026/06/23 12:32:47 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file)
        throw std::runtime_error("ShrubberyCreationForm: unable to open file");
    else
    {
        file << "       |\n";
        file << "      /|\\\n";
        file << "     //|\\\\\n";
        file << "    ///|\\\\\\\n";
        file << "   ////|\\\\\\\\\n";
        file << "  /////|\\\\\\\\\\\n";
        file << " //////|\\\\\\\\\\\\\n";
        file << "       ||\n";
        file << "       ||\n";
        file << "     ===== \n";
    }
	

}
