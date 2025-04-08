/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:01:47 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/26 14:24:00 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string m_target;
    public:
        //Default Constructor
        ShrubberyCreationForm();
        //Parametric Constructor
        ShrubberyCreationForm(std::string const &target);
        //Copy Constructor
        ShrubberyCreationForm(ShrubberyCreationForm const &other);
        //Assignation Operator
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
        //Destructor
        ~ShrubberyCreationForm();

        //Member functions
        void execute(Bureaucrat const &executor) const;

        class FileNotOpenException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif