/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 23:59:43 by kwillian          #+#    #+#             */
/*   Updated: 2026/06/18 20:16:07 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
    const std::string _name;
    bool    _signed;
    const int   _grade;
    const int   _execute;    

    public:
    Form();
    ~Form();
    Form(const Form& other);
    Form(const std::string name, const int sign_grade, const int execute_grade);
    Form&operator=(const Form&other);
    void beSigned(const Bureaucrat &bureaucrat);
	std::string getName() const;
	bool getIsSigned() const;
	int	 getSignGrade() const;
	int	getExecuteGrade() const;

    class GradeTooHighException : public std::exception
    {
        private:
        const char * what() const throw()
        {
            return "GradeTooHighException";
        }
    };
    class GradeTooLowException : public std::exception
    {
        private:
        const char * what() const throw()
        {
            return "GradeTooLowException";
        }
    };
};

std::ostream&operator<<(std::ostream& out, const Form& Form);

#endif

/*
constant name.
•A boolean indicating whether it is signed (at construction, it is not).
•A constant grade required to sign it.
•A constant grade required to execute it.
*/