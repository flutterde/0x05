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
    try {
        Bureaucrat highRank("Alice", 1);
        ShrubberyCreationForm shForm("sh-tar");
        highRank.executeForm(shForm);
        highRank.signForm(shForm);
        highRank.signForm(shForm);
    } catch (std::exception& e) {
        std::cerr << "->Exception: " << e.what() << std::endl;
    }
	std::cout << " ----------------------------------- " << std::endl;
    try {
       Bureaucrat lowRank("Flash", 150);
       RobotomyRequestForm roForm("ro-tar");
       lowRank.signForm(roForm);
       lowRank.executeForm(roForm);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	std::cout << " ----------------------------------- " << std::endl;
    try {
       Bureaucrat medRank("Flash", 24);
       PresidentialPardonForm prPaform("pr-tar");
       medRank.signForm(prPaform);
       medRank.executeForm(prPaform);
       Bureaucrat tooLowRank("Flash", 240);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
