/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 00:05:26 by kwillian          #+#    #+#             */
/*   Updated: 2026/06/16 12:21:08 by kwillian         ###   ########.fr       */
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
        Bureaucrat Buro1("kevin", 152);
        std::cout << "Buro Name::: " << Buro1 << std::endl;
        Buro1.incrementGrade();
        std::cout << "Buro Name::: " << Buro1 << std::endl;
        //Changing the Bureaucrat grade.
        //Buro1.decrementGrade();
        std::cout << "Buro Name::: " << Buro1 << std::endl;
        //Copy assignment Constructor called.
        Bureaucrat buro2(Buro1);
        std::cout << "Buro Name::: " << buro2 << std::endl;
        buro2.incrementGrade();
        buro2.incrementGrade();
        buro2.incrementGrade();
        Buro1.decrementGrade();
        //assignament operator called
        Bureaucrat buro3;
        buro3 = buro2;
        std::cout << "Buro Name::: " << buro3 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << "\ncheguei aqui \n" << std::endl;
    }
}

