/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:48:59 by kwillian          #+#    #+#             */
/*   Updated: 2026/07/25 15:28:19 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {                           
        Bureaucrat bob("Bob", 1);
        Form form("TopSecret", 7, 6);
        bob.signForm(form);
        Bureaucrat alice("Alice", 5);
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