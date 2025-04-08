/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:02:08 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/26 19:00:02 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const Intern::t_formCreator Intern::formCreators[3] = {
    &Intern::createShrubberyCreationForm,
    &Intern::createRobotomyRequestForm,
    &Intern::createPresidentialPardonForm
};

const std::string Intern::formNames[3] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
};

Intern::Intern()
{

}

Intern::Intern(Intern const &other)
{
    (void)other;
}

Intern &Intern::operator=(Intern const &other)
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{

}

AForm *Intern::createShrubberyCreationForm(const std::string &target) const
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) const
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) const
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            AForm *form = (this->*formCreators[i])(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return (form);
        }
    }
    throw FormNotFoundException();
    return (NULL);
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return ("Form not found");
}