/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:02:24 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/26 14:53:30 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>   //rand() and srand()
#include <ctime>     //time()

class RobotomyRequestForm : public AForm
{
    private:
        std::string m_target;
    public:
        //Default Constructor
        RobotomyRequestForm();
        //Parametric Constructor
        RobotomyRequestForm(std::string const &target);
        //Copy Constructor
        RobotomyRequestForm(RobotomyRequestForm const &other);
        //Assignation Operator
        RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
        //Destructor
        ~RobotomyRequestForm();

        //Member functions
        void execute(Bureaucrat const &executor) const;
};

#endif