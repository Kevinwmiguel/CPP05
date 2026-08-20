/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:48:59 by kwillian          #+#    #+#             */
/*   Updated: 2026/08/20 22:36:19 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {                           
        Bureaucrat bob("Bob", 150);
        Form form("TopSecret", 150, 150);
        bob.signForm(form);

        Bureaucrat alice("Alice", 1);
        alice.signForm(form);

        std::cout << "\n " << bob << std::endl;
        std::cout << alice << std::endl;
        std::cout << form << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}