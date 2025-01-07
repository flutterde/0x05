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
#include "Form.hpp"

int main() {
    try {
        Bureaucrat highRank("Alice", 1);
        Bureaucrat lowRank("Bob", 150);
        Form formA("Form-A", 50, 100);
        
        std::cout << highRank << std::endl;
        std::cout << lowRank << std::endl;
        std::cout << formA << std::endl;
        
        std::cout << "Attempting to sign form with low rank..." << std::endl;
        lowRank.signForm(formA);

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	std::cout << " ----------------------------------- " << std::endl;
    try {
        Form invalidForm("InvalidForm", 0, 200);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
