/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:39:05 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/25 17:46:09 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Form;

class Bureaucrat
{
    private:
        std::string const m_name;
        int m_grade;
    public:
        //Default constructor
        Bureaucrat();
        //Parametric constructor
        Bureaucrat(std::string const name, int grade);
        //Copy constructor
        Bureaucrat(Bureaucrat const &other);
        //Assignation operator
        Bureaucrat &operator=(Bureaucrat const &other);
        //Destructor
        ~Bureaucrat();

        //Getters
        std::string const getName() const;
        int getGrade() const;

        //Member functions
        void incrementGrade();
        void decrementGrade();

        void signForm(Form &form);

        //Exception classes
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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif