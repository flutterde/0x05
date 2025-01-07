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

int main() {
	std::cout << " ----------------------------------- " << std::endl;
    try {
        Bureaucrat highRank("Alice", 1);
        ShrubberyCreationForm shForm("sh-tar");
        highRank.executeForm(shForm);
    } catch (std::exception& e) {
        std::cerr << "->Exception: " << e.what() << std::endl;
    }
	std::cout << " ----------------------------------- " << std::endl;
    // try {
       
    // } catch (std::exception& e) {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    return 0;
}
