/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 02:41:32 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/25 18:05:00 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const m_name;
        bool m_signed;
        int const m_gradeRequired;
        int const m_gradeToExecute;
    public:
        //Default Constructor
        Form();
        //Parametric Constructor
        Form(std::string const name, int m_gradeRequired, int m_gradeToExecute);
        //Copy Constructor
        Form(Form const &other);
        //Assignation Operator
        Form &operator=(Form const &other);
        //Destructor
        ~Form();

        //Getters
        std::string const getName() const;
        bool getSigned() const;
        int getGradeRequired() const;
        int getGradeToExecute() const;

        //Member functions
        void beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif