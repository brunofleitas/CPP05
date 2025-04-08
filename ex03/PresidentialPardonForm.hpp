/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:03:35 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/26 11:46:36 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string m_target;
    public:
        //Default Constructor
        PresidentialPardonForm();
        //Parametric Constructor
        PresidentialPardonForm(std::string const &target);
        //Copy Constructor
        PresidentialPardonForm(PresidentialPardonForm const &other);
        //Assignation Operator
        PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
        //Destructor
        ~PresidentialPardonForm();

        //Member functions
        void execute(Bureaucrat const &executor) const;
};

#endif