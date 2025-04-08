/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 02:41:50 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/26 11:54:13 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : m_name("No name"), m_signed(false), m_gradeRequired(150), m_gradeToExecute(150)
{

}

AForm::AForm(std::string const name, int gradeRequired, int gradeToExecute) : m_name(name), m_signed(false), m_gradeRequired(gradeRequired), m_gradeToExecute(gradeToExecute)
{
    if (gradeRequired < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeRequired > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &other) : m_name(other.m_name), m_signed(other.m_signed), m_gradeRequired(other.m_gradeRequired), m_gradeToExecute(other.m_gradeToExecute)
{

}

AForm &AForm::operator=(AForm const &other)
{
    if (this != &other)
    {
        this->m_signed = other.m_signed;
    }
    return (*this);
}

AForm::~AForm()
{

}

std::string const AForm::getName() const
{
    return (m_name);
}

bool AForm::getSigned() const
{
    return (m_signed);
}

int AForm::getGradeRequired() const
{
    return (m_gradeRequired);
}

int AForm::getGradeToExecute() const
{
    return (m_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= m_gradeRequired)
        m_signed = true;
    else
        throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high, the maximum grade is 1");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low, the minimum grade is 150");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &out, AForm const &AForm)
{
    out << "Form " << AForm.getName()
        << "\nSign Status: " << AForm.getSigned()
        << "\nGrade Required: " << AForm.getGradeRequired()
        << "\nGrade To Execute: " << AForm.getGradeToExecute()
        << std::endl;
    return out;
}
