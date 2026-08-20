/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 23:58:39 by kwillian          #+#    #+#             */
/*   Updated: 2026/06/23 13:22:47 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Bureaucrat high("Alice", 1);
    Bureaucrat low("Bob", 150);
    Bureaucrat mid("Clayton", 75);
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Marvin");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << "\n-- Signing phase --" << std::endl;
    low.signForm(shrub);
    high.signForm(shrub);
    high.signForm(robot);
    high.signForm(pardon);
    mid.signForm(shrub);
    mid.signForm(robot);
    mid.signForm(pardon);
    std::cout << "\n-- Execution phase --" << std::endl;
    low.executeForm(shrub);
    high.executeForm(shrub);
    high.executeForm(robot);
    high.executeForm(pardon);

    mid.executeForm(shrub);
    
    std::cout << "\n-- Invalid execute test --" << std::endl;
    low.executeForm(pardon);
    mid.executeForm(robot);
    mid.executeForm(pardon);

    return 0;
}

