/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:36:28 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/06 10:36:28 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testShrubberyCreationForm() {
    std::cout << "\n=== ShrubberyCreationForm Tests ===\n";
    try {
        Bureaucrat alice("Alice", 1);
        ShrubberyCreationForm form("garden");

        std::cout << form;
        alice.signForm(form);
        alice.executeForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    try {
        Bureaucrat bob("Bob", 150);
        ShrubberyCreationForm form("backyard");

        bob.signForm(form);
        bob.executeForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}

void testRobotomyRequestForm() {
    std::cout << "\n=== RobotomyRequestForm Tests ===\n";
    try {
        Bureaucrat alice("Alice", 1);
        RobotomyRequestForm form("robot_lab");

        alice.signForm(form);
        for (int i = 0; i < 5; i++) {
            alice.executeForm(form);
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    try {
        Bureaucrat bob("Bob", 150);
        RobotomyRequestForm form("factory");

        bob.executeForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}

void testPresidentialPardonForm() {
    std::cout << "\n=== PresidentialPardonForm Tests ===\n";
    try {
        Bureaucrat alice("Alice", 1);
        PresidentialPardonForm form("CitizenX");

        alice.signForm(form);
        alice.executeForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    try {
        Bureaucrat bob("Bob", 150);
        PresidentialPardonForm form("CitizenY");

        bob.signForm(form);
        bob.executeForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}

void testInvalidBureaucrat() {
    std::cout << "\n=== Invalid Bureaucrat Tests ===\n";
    try {
        Bureaucrat invalid("Invalid", 0);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    try {
        Bureaucrat invalid("Invalid", 200);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}

int main() {
    testShrubberyCreationForm();
    testRobotomyRequestForm();
    testPresidentialPardonForm();
    testInvalidBureaucrat();
    return 0;
}
