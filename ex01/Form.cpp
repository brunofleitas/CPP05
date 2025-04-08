/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 02:41:50 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/25 18:27:41 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : m_name("No name"), m_signed(false), m_gradeRequired(150), m_gradeToExecute(150)
{

}

Form::Form(std::string const name, int gradeRequired, int gradeToExecute) : m_name(name), m_signed(false), m_gradeRequired(gradeRequired), m_gradeToExecute(gradeToExecute)
{
    if (gradeRequired < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeRequired > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &other) : m_name(other.m_name), m_signed(other.m_signed), m_gradeRequired(other.m_gradeRequired), m_gradeToExecute(other.m_gradeToExecute)
{

}

Form &Form::operator=(Form const &other)
{
    if (this != &other)
    {
        this->m_signed = other.m_signed;
    }
    return (*this);
}

Form::~Form()
{

}

std::string const Form::getName() const
{
    return (m_name);
}

bool Form::getSigned() const
{
    return (m_signed);
}

int Form::getGradeRequired() const
{
    return (m_gradeRequired);
}

int Form::getGradeToExecute() const
{
    return (m_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= m_gradeRequired)
        m_signed = true;
    else
        throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high, the maximum grade is 1");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low, the minimum grade is 150");
}

std::ostream &operator<<(std::ostream &out, Form const &Form)
{
    out << "Form " << Form.getName()
        << "\nSign Status: " << Form.getSigned()
        << "\nGrade Required: " << Form.getGradeRequired()
        << "\nGrade To Execute: " << Form.getGradeToExecute()
        << std::endl;
    return out;
}
