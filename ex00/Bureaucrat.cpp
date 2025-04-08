/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:39:19 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/25 00:42:35 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("No name"), m_grade(150)
{

}

Bureaucrat::Bureaucrat(std::string const name, int grade) : m_name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    m_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : m_name(other.m_name), m_grade(other.m_grade)
{

}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    if (this != &other)
    {
        m_grade = other.m_grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{

}

std::string const Bureaucrat::getName() const
{
    return (m_name);
}

int Bureaucrat::getGrade() const
{
    return (m_grade);
}

void Bureaucrat::incrementGrade()
{
    if (m_grade - 1 < 1)
        throw GradeTooHighException();
    m_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (m_grade + 1 > 150)
        throw GradeTooLowException();
    m_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high, the maximum grade is 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low, the minimum grade is 150");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (out);
}