/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:38:44 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/25 00:54:37 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "--- Testing Bureaucrat Class ---" << std::endl;
    
    // Prueba 1: Creación de burócrata válido
    try 
    {
        std::cout << "\nTest 1: Creating a valid bureaucrat" << std::endl;
        Bureaucrat b1("John", 75);
        std::cout << b1 << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Prueba 2: Creación de burócrata con grado demasiado alto
    try 
    {
        std::cout << "\nTest 2: Creating a bureaucrat with too high grade (0)" << std::endl;
        Bureaucrat b2("Alice", 0);
        std::cout << b2 << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Prueba 3: Creación de burócrata con grado demasiado bajo
    try 
    {
        std::cout << "\nTest 3: Creating a bureaucrat with too low grade (151)" << std::endl;
        Bureaucrat b3("Bob", 151);
        std::cout << b3 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Prueba 4: Incrementando el grado
    try
    {
        std::cout << "\nTest 4: Incrementing grade" << std::endl;
        Bureaucrat b4("Charlie", 10);
        std::cout << "Before: " << b4 << std::endl;
        b4.incrementGrade();
        std::cout << "After increment: " << b4 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Prueba 5: Decrementando el grado
    try
    {
        std::cout << "\nTest 5: Decrementing grade" << std::endl;
        Bureaucrat b5("David", 140);
        std::cout << "Before: " << b5 << std::endl;
        b5.decrementGrade();
        std::cout << "After decrement: " << b5 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Prueba 6: Incrementando más allá del límite máximo
    try
    {
        std::cout << "\nTest 6: Incrementing beyond maximum limit" << std::endl;
        Bureaucrat b6("Eve", 1);
        std::cout << "Before: " << b6 << std::endl;
        b6.incrementGrade(); // Esto lanzará una excepción
        std::cout << "After increment: " << b6 << std::endl;
    } 
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Prueba 7: Decrementando más allá del límite mínimo
    try 
    {
        std::cout << "\nTest 7: Decrementing beyond minimum limit" << std::endl;
        Bureaucrat b7("Frank", 150);
        std::cout << "Before: " << b7 << std::endl;
        b7.decrementGrade(); // Esto lanzará una excepción
        std::cout << "After decrement: " << b7 << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Prueba 8: Constructor de copia y operador de asignación
    try 
    {
        std::cout << "\nTest 8: Copy constructor and assignment operator" << std::endl;
        Bureaucrat b8("George", 42);
        std::cout << "Original: " << b8 << std::endl;
        
        // Prueba del constructor de copia
        Bureaucrat b9(b8);
        std::cout << "Copy: " << b9 << std::endl;
        
        // Prueba del operador de asignación
        Bureaucrat b10;
        std::cout << "Default: " << b10 << std::endl;
        b10 = b8;
        std::cout << "After assignment: " << b10 << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}