/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:48:59 by kwillian          #+#    #+#             */
/*   Updated: 2026/06/16 19:05:37 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    try
    {                           
        Bureaucrat bob("Bob", 50);
        AForm form("TopSecret", 2, 2);
        bob.signForm(form);

        Bureaucrat alice("Alice", 1);
        alice.signForm(form);
        alice.signForm(form);

        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        std::cout << form << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}