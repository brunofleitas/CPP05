/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:01:59 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/26 19:00:06 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        typedef AForm *(Intern::*t_formCreator)(const std::string &target) const;
        static const t_formCreator formCreators[3];
        static const std::string formNames[3];

        AForm *createShrubberyCreationForm(const std::string &target) const;
        AForm *createRobotomyRequestForm(const std::string &target) const;
        AForm *createPresidentialPardonForm(const std::string &target) const;
    public:
        //Default Constructor
        Intern();
        //Copy Constructor
        Intern(Intern const &other);
        //Assignation Operator
        Intern &operator=(Intern const &other);
        //Destructor
        ~Intern();

        //Member functions
        AForm *makeForm(const std::string &formName, const std::string &target) const;

        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif