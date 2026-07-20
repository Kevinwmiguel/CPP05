/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 00:05:26 by kwillian          #+#    #+#             */
/*   Updated: 2026/07/20 16:06:42 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::string getError(int grade)
{
    std::string error;

    if (grade < 0)
        error = "Bureaucrat::GradeTooLowException";
    else if (grade > 150)
        error = "Bureaucrat::GradeTooHighException";
    return error;
}

int main()
{
    try
    {
        Bureaucrat Buro1("kevin", 130);
        std::cout << Buro1 << std::endl;
        Buro1.incrementGrade();
        std::cout << Buro1 << std::endl;
        //Buro1.decrementGrade();
        Buro1.decrementGrade();
        Buro1.decrementGrade();
        std::cout  << Buro1 << std::endl;
        Bureaucrat buro2(Buro1);
        std::cout  << buro2 << std::endl;
        buro2.incrementGrade();
        buro2.incrementGrade();
        buro2.incrementGrade();
        Bureaucrat buro3;
        buro3 = buro2;
        std::cout << buro3 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}

