/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:02:49 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/26 14:49:02 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45)
{
    m_target = "No target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("Robotomy Request", 72, 45), m_target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other), m_target(other.m_target)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        m_target = other.m_target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    std::cout << "Makes some drilling noises" << std::endl;

    srand(time(NULL));
    if (rand() % 2)
        std::cout << m_target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy of " << m_target << " has failed" << std::endl;
}
