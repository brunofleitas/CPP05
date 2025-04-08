/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:38:44 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/25 17:58:36 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "--- Testing Form Class ---" << std::endl;
    
    // Prueba 1: Creación de formulario válido
    try {
        std::cout << "\nTest 1: Creating a valid form" << std::endl;
        Form f1("Tax Return", 50, 25);
        std::cout << f1 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Prueba 2: Creación de formulario con grado para firmar demasiado alto
    try {
        std::cout << "\nTest 2: Creating a form with too high sign grade (0)" << std::endl;
        Form f2("Invalid Form", 0, 25);
        std::cout << f2 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Prueba 3: Creación de formulario con grado para ejecutar demasiado bajo
    try {
        std::cout << "\nTest 3: Creating a form with too low execute grade (151)" << std::endl;
        Form f3("Another Invalid Form", 50, 151);
        std::cout << f3 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Prueba 4: Firma exitosa de un formulario
    try {
        std::cout << "\nTest 4: Successfully signing a form" << std::endl;
        Bureaucrat b1("John", 30);
        Form f4("Application", 50, 25);
        std::cout << "Before signing: " << f4 << std::endl;
        b1.signForm(f4);
        std::cout << "After signing: " << f4 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Prueba 5: Firma fallida de un formulario (grado demasiado bajo)
    try {
        std::cout << "\nTest 5: Failed attempt to sign a form (grade too low)" << std::endl;
        Bureaucrat b2("Alice", 75);
        Form f5("High Security Clearance", 30, 15);
        std::cout << "Before signing attempt: " << f5 << std::endl;
        b2.signForm(f5);
        std::cout << "After signing attempt: " << f5 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Prueba 6: Intento de firma directa de un formulario
    try {
        std::cout << "\nTest 6: Direct attempt to sign a form" << std::endl;
        Bureaucrat b3("Bob", 100);
        Form f6("Permission Form", 90, 50);
        std::cout << "Before direct signing: " << f6 << std::endl;
        f6.beSigned(b3);
        std::cout << "After direct signing: " << f6 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Prueba 7: Intento de firma directa fallida
    try {
        std::cout << "\nTest 7: Failed direct attempt to sign a form" << std::endl;
        Bureaucrat b4("Charlie", 100);
        Form f7("High Level Form", 50, 25);
        std::cout << "Before failed direct signing: " << f7 << std::endl;
        f7.beSigned(b4);
        std::cout << "This line should not be reached" << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Prueba 8: Constructor de copia y operador de asignación para Form
    try {
        std::cout << "\nTest 8: Form copy constructor and assignment operator" << std::endl;
        Form f8("Original Form", 75, 40);
        Bureaucrat b5("David", 50);
        b5.signForm(f8);
        
        // Prueba del constructor de copia
        Form f9(f8);
        std::cout << "Original: " << f8 << std::endl;
        std::cout << "Copy: " << f9 << std::endl;
        
        // Prueba del operador de asignación
        Form f10;
        std::cout << "Default: " << f10 << std::endl;
        f10 = f8;
        std::cout << "After assignment: " << f10 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}