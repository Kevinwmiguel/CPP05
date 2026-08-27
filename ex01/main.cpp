/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:48:59 by kwillian          #+#    #+#             */
/*   Updated: 2026/08/20 22:36:19 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== TESTE 1: Construtores Inválidos de Form ===" << std::endl;
    try {
        std::cout << "A tentar criar Form com nota de assinatura 0..." << std::endl;
        Form f1("Contrato A", 0, 50);
    } catch (std::exception &e) {
        std::cerr << "Exceção apanhada: " << e.what() << std::endl;
    }
    try {
        std::cout << "A tentar criar Form com nota de execução 151..." << std::endl;
        Form f2("Contrato B", 50, 151);
    } catch (std::exception &e) {
        std::cerr << "Exceção apanhada: " << e.what() << std::endl;
    }
    std::cout << "\n=== TESTE 2: Assinatura com Sucesso ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 25);
        Form formA("Formulário de Impostos", 50, 50);
        std::cout << formA << std::endl;
        std::cout << alice << std::endl;
        std::cout << "Alice tenta assinar..." << std::endl;
        alice.signForm(formA);
        std::cout << formA << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }
    std::cout << "\n=== TESTE 3: Falha por Nota Insuficiente ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 150);
        Form formB("Autorização Secreta", 10, 10);
        std::cout << formB << std::endl;
        std::cout << bob << std::endl;
        std::cout << "Bob tenta assinar..." << std::endl;
        bob.signForm(formB);
        std::cout << formB << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Erro inesperado (signForm não deve deixar a exceção escapar do main): " << e.what() << std::endl;
    }
    std::cout << "\n=== TESTE 4: Assinar um formulário já assinado ===" << std::endl;
    try {
        Bureaucrat chefe("Chefe", 1);
        Bureaucrat subchefe("Sub-Chefe", 5);
        Form formC("Alvará Comercial", 10, 10);

        chefe.signForm(formC);
        std::cout << "Tentando assinar novamente..." << std::endl;
        subchefe.signForm(formC);
    } catch (std::exception &e) {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }
    return 0;
}
