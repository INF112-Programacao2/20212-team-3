#include <iostream>
#include <string>

#include "Arquivos.h/Caixa.h"

Caixa::Caixa(std::string nome, int codigo, double salario, std::string cpf, std::string endereco, std::string email, std::string data_nascimento, std::string senha, bool ensino_medio_completo):
    Funcionario(nome, codigo, salario, cpf, endereco, email, data_nascimento, senha), _ensino_medio_completo(ensino_medio_completo) {}

bool Caixa::get_ensino_medio_completo() {
    return this->_ensino_medio_completo;
}

void Caixa::set_ensino_medio_completo(bool ensino_medio_completo) {
    this->_ensino_medio_completo = ensino_medio_completo;
}

void Caixa::exibir_dados() {
    std::cout << "------------------------------------------------\n";
    std::cout << "Dados do Operador de Caixa:\n";
    std::cout << "Nome: " << Funcionario::get_nome() << std::endl;
    std::cout << "Codigo: " << Funcionario::get_codigo() << std::endl; 
    std::cout << "Salario: " << Funcionario::get_salario() << std::endl;
    std::cout << "CPF: " << Funcionario::get_cpf() << std::endl;
    std::cout << "Endereco: " << Funcionario::get_endereco() << std::endl;
    std::cout << "E-mail: " << Funcionario::get_email() << std::endl;
    std::cout << "Data de Nascimento: " << Funcionario::get_data_nascimento() << std::endl;
    std::cout << "Senha: " << Funcionario::get_senha() << std::endl;
    std::cout << "Certificado de conclusao do ensino medio: " << Caixa::get_ensino_medio_completo() << std::endl;
    std::cout << "------------------------------------------------\n"; 
}