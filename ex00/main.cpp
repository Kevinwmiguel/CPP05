/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 00:05:26 by kwillian          #+#    #+#             */
/*   Updated: 2026/07/20 16:06:42 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::string getError(int grade)
{
    std::string error;

    if (grade < 0)
        error = "Bureaucrat::GradeTooLowException";
    else if (grade > 150)
        error = "Bureaucrat::GradeTooHighException";
    return error;
}

int main()
{
    std::cout << "=== TESTE 1: Funcionamento Normal ===" << std::endl;
    try
    {
        Bureaucrat buro1("Kevin", 130);
        std::cout << buro1 << std::endl;
        
        buro1.incrementGrade(); // Passa para 129
        std::cout << "Após incremento: " << buro1 << std::endl;
        
        buro1.decrementGrade(); // Passa para 130
        buro1.decrementGrade(); // Passa para 131
        std::cout << "Após dois decrementos: " << buro1 << std::endl;

        // Teste de Cópia e Atribuição
        Bureaucrat buro2(buro1);
        std::cout << "Cópia (buro2): " << buro2 << std::endl;

        Bureaucrat buro3;
        buro3 = buro1;
        std::cout << "Atribuição (buro3): " << buro3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n=== TESTE 2: Nota demasiado Alta (Grau < 1) ===" << std::endl;
    try
    {
        Bureaucrat herói("Chefe", 1);
        std::cout << herói << std::endl;
        std::cout << "A tentar incrementar o Chefe além do limite..." << std::endl;
        herói.incrementGrade(); // Deve lançar exceção GradeTooHighException
        std::cout << "Isto não deve ser impresso!" << std::endl;
    }
    catch (Bureaucrat::gradeTooHighException &e)
    {
        std::cerr << "Exceção capturada com sucesso: " << e.what() << std::endl;
    }

    std::cout << "\n=== TESTE 3: Nota demasiado Baixa (Grau > 150) ===" << std::endl;
    try
    {
        Bureaucrat estagiario("Estagiário", 150);
        std::cout << estagiario << std::endl;
        std::cout << "A tentar decrementar o Estagiário além do limite..." << std::endl;
        estagiario.decrementGrade(); // Deve lançar exceção GradeTooLowException
        std::cout << "Isto não deve ser impresso!" << std::endl;
    }
    catch (Bureaucrat::gradeTooLowException &e)
    {
        std::cerr << "Exceção capturada com sucesso: " << e.what() << std::endl;
    }

    std::cout << "\n=== TESTE 4: Construtor com Valores Inválidos ===" << std::endl;
    try
    {
        std::cout << "A tentar criar um Bureaucrat com nota 0..." << std::endl;
        Bureaucrat invalido1("Fantasma", 0); 
    }
    catch (std::exception &e)
    {
        std::cerr << "Exceção no construtor: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "A tentar criar um Bureaucrat com nota 151..." << std::endl;
        Bureaucrat invalido2("Zombi", 151); 
    }
    catch (std::exception &e)
    {
        std::cerr << "Exceção no construtor: " << e.what() << std::endl;
    }

    return 0;
}
