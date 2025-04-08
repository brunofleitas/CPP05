/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 02:41:32 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/26 19:19:44 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const m_name;
        bool m_signed;
        int const m_gradeRequired;
        int const m_gradeToExecute;
    public:
        //Default Constructor
        AForm();
        //Parametric Constructor
        AForm(std::string const name, int m_gradeRequired, int m_gradeToExecute);
        //Copy Constructor
        AForm(AForm const &other);
        //Assignation Operator
        AForm &operator=(AForm const &other);
        //Destructor
        virtual ~AForm();

        //Getters
        std::string const getName() const;
        bool getSigned() const;
        int getGradeRequired() const;
        int getGradeToExecute() const;

        //Member functions
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;

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

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif