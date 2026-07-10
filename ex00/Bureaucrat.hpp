/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 00:28:37 by kwillian          #+#    #+#             */
/*   Updated: 2026/07/10 17:55:40 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <exception>

class Bureaucrat
{
    private:
    std::string const _name;
    int         _grade;

    public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat&operator=(const Bureaucrat& other);
    std::string getName() const;
    //void setName(std::string name);
    void setGrade(int grade);
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    class gradeTooHighException : public std::exception
    {
    private:
        virtual const char *what() const throw()
        {
            return "Bureaucrat::GradeTooHighException";
        }
    };
    class gradeTooLowException : public std::exception
    {
    private:
        virtual const char *what() const throw()
        {
            return "Bureaucrat::GradeTooLowException";
        }
    };
};

std::ostream&operator<<(std::ostream& out, const Bureaucrat& Bureaucrat);

#endif