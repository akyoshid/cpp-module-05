/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:32:50 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 02:17:53 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int to_int(const std::string& s) {
    std::istringstream iss(s);
    int value;
    if (!(iss >> value) || !(iss.eof()))
        throw std::runtime_error("Invalid integer: " + s);
    return value;
}

void run_test(char* bureName, int bureGrade,
    char* formName, int formGradeToSign, int formGradeToExec) {
    Bureaucrat b1(bureName, bureGrade);
    std::cout << b1 << std::endl;
    Form f1(formName, formGradeToSign, formGradeToExec);
    std::cout << f1 << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        std::cerr << "Usage: ./a.out BureaucratName BureaucratGrade "
            << "FormName FormGradeToSign FormGradeToExec" << std::endl;
        return 1;
    }
    try {
        run_test(argv[1], to_int(argv[2]),
            argv[3], to_int(argv[4]), to_int(argv[5]));
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
    return 0;
}
