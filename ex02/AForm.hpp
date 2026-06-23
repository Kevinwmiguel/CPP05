/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 23:59:43 by kwillian          #+#    #+#             */
/*   Updated: 2026/06/23 11:27:33 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
    const std::string _name;
    bool    _signed;
    const int   _signGrade;
    const int   _executeGrade;

    protected:
    virtual void executeAction() const = 0;

    public:
    AForm();
    virtual ~AForm();
    AForm(const AForm& other);
    AForm(const std::string name, const int sign_grade, const int execute_grade);
    AForm& operator=(const AForm& other);
    void beSigned(const Bureaucrat &bureaucrat);
    void execute(Bureaucrat const & executor) const;
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    class GradeTooHighException : public std::exception
    {
        public:
        virtual const char *what() const throw()
        {
            return "AForm::GradeTooHighException";
        }
    };
    class GradeTooLowException : public std::exception
    {
        public:
        virtual const char *what() const throw()
        {
            return "AForm::GradeTooLowException";
        }
    };
    class FormNotSignedException : public std::exception
    {
        public:
        virtual const char *what() const throw()
        {
            return "AForm::FormNotSignedException";
        }
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
