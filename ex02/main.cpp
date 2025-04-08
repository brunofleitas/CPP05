/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:38:44 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/26 15:00:49 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        // Crear burócratas con diferentes niveles
        Bureaucrat lowLevel("Intern", 140);
        Bureaucrat midLevel("Manager", 50);
        Bureaucrat highLevel("Director", 5);
        Bureaucrat ceo("CEO", 1);
        
        std::cout << "\n--- Testing ShrubberyCreationForm ---\n" << std::endl;
        
        // Crear formulario de arbusto
        ShrubberyCreationForm shrub("garden");
        std::cout << shrub << std::endl;
        
        // Intentar ejecutar sin firmar
        std::cout << "\nAttempting to execute without signing:" << std::endl;
        midLevel.executeForm(shrub);
        
        // Firmar y luego ejecutar
        std::cout << "\nSigning the form:" << std::endl;
        midLevel.signForm(shrub);
        
        std::cout << "\nExecuting the form:" << std::endl;
        midLevel.executeForm(shrub);
        
        std::cout << "\n--- Testing RobotomyRequestForm ---\n" << std::endl;
        
        // Crear formulario de robotomía
        RobotomyRequestForm robotomy("subject");
        std::cout << robotomy << std::endl;
        
        // Intentar que un burócrata de bajo nivel lo firme
        std::cout << "\nAttempting to sign with low-level bureaucrat:" << std::endl;
        lowLevel.signForm(robotomy);
        
        // Firmar con burócrata de nivel medio
        std::cout << "\nSigning with mid-level bureaucrat:" << std::endl;
        midLevel.signForm(robotomy);
        
        // Intentar ejecutar con burócrata de nivel medio (debería fallar)
        std::cout << "\nAttempting to execute with mid-level bureaucrat:" << std::endl;
        midLevel.executeForm(robotomy);
        
        // Ejecutar con burócrata de alto nivel
        std::cout << "\nExecuting with high-level bureaucrat:" << std::endl;
        highLevel.executeForm(robotomy);
        
        std::cout << "\n--- Testing PresidentialPardonForm ---\n" << std::endl;
        
        // Crear formulario de perdón presidencial
        PresidentialPardonForm pardon("criminal");
        std::cout << pardon << std::endl;
        
        // Intentar firmar con burócrata de nivel medio (debería fallar)
        std::cout << "\nAttempting to sign with mid-level bureaucrat:" << std::endl;
        midLevel.signForm(pardon);
        
        // Firmar con burócrata de alto nivel
        std::cout << "\nSigning with high-level bureaucrat:" << std::endl;
        highLevel.signForm(pardon);
        
        // Intentar ejecutar con burócrata de alto nivel (debería fallar)
        std::cout << "\nAttempting to execute with high-level bureaucrat:" << std::endl;
        highLevel.executeForm(pardon);
        
        // Ejecutar con CEO
        std::cout << "\nExecuting with CEO:" << std::endl;
        ceo.executeForm(pardon);
        
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}