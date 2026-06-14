/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureucrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 00:28:37 by kwillian          #+#    #+#             */
/*   Updated: 2026/06/15 00:46:56 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP

#include <string>
#include <iostream>
#include <cctype>

class Bureaucrat
{
    private:
    std::string name;
    int         grade;

    public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat&operator=(const Bureaucrat& other);
    std::string getName() const;
    std::string setName(std::string name);
    std::string setGrade(int grade);
    int getGrade() const;
    void incrementGrade();
};

std::ostream&operator<<(std::ostream& out, const Bureaucrat& Bureaucrat);

#endif