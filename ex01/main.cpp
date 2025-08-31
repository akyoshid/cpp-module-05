/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:32:50 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/29 18:38:54 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include "Bureaucrat.hpp"

int to_int(const std::string& s) {
    std::istringstream iss(s);
    int value;
    if (!(iss >> value) || !(iss.eof()))
        throw std::runtime_error("Invalid integer: " + s);
    return value;
}

void run_test(char *name, int grade) {
    Bureaucrat b1(name, grade);
    std::cout << b1 << std::endl;
    b1.incrementGrade();
    b1.decrementGrade();
    b1.decrementGrade();
    Bureaucrat b2(b1);
    b2.incrementGrade();
    Bureaucrat b3(b1);
    b3 = b2;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./a.out name grade" << std::endl;
        return 1;
    }
    try {
        run_test(argv[1], to_int(argv[2]));
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
    return 0;
}
