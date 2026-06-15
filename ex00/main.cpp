/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 00:05:26 by kwillian          #+#    #+#             */
/*   Updated: 2026/06/15 17:33:30 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat Buro1("kevin", 2);
        std::cout << "Buro Name::: " << Buro1 << std::endl;
    /* do some stuff with bureaucrats */
    }
    catch (std::exception & e)
    {
    /* handle exception */
    }
    //Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.
    
}

