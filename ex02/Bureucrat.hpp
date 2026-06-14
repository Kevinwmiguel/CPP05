/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureucrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 23:59:01 by kwillian          #+#    #+#             */
/*   Updated: 2026/06/15 00:37:21 by kwillian         ###   ########.fr       */
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
    std::string getName() const;
    int getGrade() const;
};

#endif