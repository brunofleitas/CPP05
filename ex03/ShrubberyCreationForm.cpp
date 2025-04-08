/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:01:44 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/26 14:32:39 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137)
{
    m_target = "No target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("Shrubbery Creation", 145, 137), m_target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), m_target(other.m_target)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        m_target = other.m_target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    std::string filename = this->m_target + "_shrubbery";
    std::ofstream newfile(filename.c_str());

    if(!newfile.is_open())
        throw ShrubberyCreationForm::FileNotOpenException();

    newfile << "my-app/" << std::endl;
    newfile << "├─ node_modules/" << std::endl;
    newfile << "├─ public/" << std::endl;
    newfile << "│  ├─ favicon.ico" << std::endl;
    newfile << "│  ├─ index.html" << std::endl;
    newfile << "│  ├─ robots.txt" << std::endl;
    newfile << "├─ src/" << std::endl;
    newfile << "│  ├─ index.css" << std::endl;
    newfile << "│  ├─ index.js" << std::endl;
    newfile << "├─ .gitignore" << std::endl;
    newfile << "├─ package.json" << std::endl;
    newfile << "├─ README.md" << std::endl;

    newfile.close();
    std::cout << "Shrubbery has been created" << std::endl;
}

const char *ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
    return ("Error opening file");
}