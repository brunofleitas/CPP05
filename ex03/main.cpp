/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:38:44 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/26 19:23:21 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <memory> // For std::unique_ptr

void testFormCreation(Intern& intern, Bureaucrat& bureaucrat, const std::string& formName, const std::string& target) {
    std::cout << "\n=== Testing " << formName << " ===\n" << std::endl;
    
    try {
        AForm* form = intern.makeForm(formName, target);
        
        if (form) {
            // Use a unique_ptr to ensure memory is properly freed, even if an exception occurs
            std::unique_ptr<AForm> formPtr(form);
            
            std::cout << "Form details: " << std::endl;
            std::cout << *formPtr << std::endl;
            
            std::cout << "\nAttempting to sign form:" << std::endl;
            bureaucrat.signForm(*formPtr);
            
            std::cout << "\nAttempting to execute form:" << std::endl;
            bureaucrat.executeForm(*formPtr);
            
            // No need to manually delete form anymore, unique_ptr handles it
        }
    } catch (const Intern::FormNotFoundException& e) {
        std::cout << "Error: " << e.what() << " - \"" << formName << "\" is not a valid form type." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }
}

int main() {
    try {
        // Create bureaucrats with different authority levels
        std::cout << "Creating bureaucrats with different authority levels:" << std::endl;
        Bureaucrat intern("Intern Bob", 150);
        Bureaucrat officer("Officer Smith", 70);
        Bureaucrat manager("Manager Johnson", 30);
        Bureaucrat director("Director Garcia", 5);
        Bureaucrat president("President", 1);
        
        std::cout << intern << std::endl;
        std::cout << officer << std::endl;
        std::cout << manager << std::endl;
        std::cout << director << std::endl;
        std::cout << president << std::endl;
        
        // Create an intern
        std::cout << "\nCreating an intern with no name, no grade, no unique characteristics..." << std::endl;
        Intern someRandomIntern;
        
        // Test creating valid forms
        testFormCreation(someRandomIntern, president, "shrubbery creation", "Garden");
        testFormCreation(someRandomIntern, president, "robotomy request", "Bender");
        testFormCreation(someRandomIntern, president, "presidential pardon", "Douglas Adams");
        
        // Test with form names with case variations (shouldn't work with current implementation)
        testFormCreation(someRandomIntern, president, "Robotomy Request", "R2D2");
        
        // Test with an unknown form
        testFormCreation(someRandomIntern, president, "coffee making", "Office Kitchen");
        
        // Test execution with bureaucrats that don't have enough authority
        std::cout << "\n=== Testing bureaucrat authority levels ===\n" << std::endl;
        
        try {
            std::unique_ptr<AForm> shrubForm(someRandomIntern.makeForm("shrubbery creation", "Front Yard"));
            if (shrubForm) {
                std::cout << "Testing ShrubberyCreationForm with different bureaucrats:" << std::endl;
                officer.signForm(*shrubForm);
                officer.executeForm(*shrubForm);
            }
        } catch (const std::exception& e) {
            std::cout << "Error with ShrubberyCreationForm: " << e.what() << std::endl;
        }
        
        try {
            std::unique_ptr<AForm> robotForm(someRandomIntern.makeForm("robotomy request", "C-3PO"));
            if (robotForm) {
                std::cout << "\nTesting RobotomyRequestForm with different bureaucrats:" << std::endl;
                manager.signForm(*robotForm);
                manager.executeForm(*robotForm); // Manager can sign but not execute
                director.executeForm(*robotForm); // Director can execute
            }
        } catch (const std::exception& e) {
            std::cout << "Error with RobotomyRequestForm: " << e.what() << std::endl;
        }
        
        try {
            std::unique_ptr<AForm> pardonForm(someRandomIntern.makeForm("presidential pardon", "Arthur Dent"));
            if (pardonForm) {
                std::cout << "\nTesting PresidentialPardonForm with different bureaucrats:" << std::endl;
                director.signForm(*pardonForm);
                director.executeForm(*pardonForm); // Director can sign but not execute
                president.executeForm(*pardonForm); // Only president can execute
            }
        } catch (const std::exception& e) {
            std::cout << "Error with PresidentialPardonForm: " << e.what() << std::endl;
        }
        
        // Test Intern copy (should be trivial since it has no state)
        std::cout << "\n=== Testing Intern copy ===\n" << std::endl;
        Intern anotherIntern = someRandomIntern;
        
        try {
            std::unique_ptr<AForm> copyForm(anotherIntern.makeForm("robotomy request", "Copy Test"));
            if (copyForm) {
                std::cout << "The copied intern successfully created a form:" << std::endl;
                std::cout << *copyForm << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "Error with copied intern: " << e.what() << std::endl;
        }
        
        std::cout << "\nAll tests completed!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}