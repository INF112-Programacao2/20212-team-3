#include <iostream>
#include <string>

#include "Arquivos.h/Estoquista.h"

Estoquista::Estoquista(std::string nome, int codigo, double salario, std::string cpf, std::string endereco, std::string email, std::string data_nascimento, std::string senha, bool informatica_basica):
    Funcionario(nome, codigo, salario, cpf, endereco, email, data_nascimento, senha), _informatica_basica(informatica_basica) {}

bool Estoquista::get_informatica_basica() {
    return this->_informatica_basica;
}

void Estoquista::set_informatica_basica(bool informatica_basica) {
   this->_informatica_basica = informatica_basica;
}

void Estoquista::exibir_dados() {
    std::cout << "------------------------------------------------\n";
    std::cout << "Dados do Estoquista:\n";
    std::cout << "Nome: " << Funcionario::get_nome() << std::endl;
    std::cout << "Codigo: " << Funcionario::get_codigo() << std::endl; 
    std::cout << "Salario: " << Funcionario::get_salario() << std::endl;
    std::cout << "CPF: " << Funcionario::get_cpf() << std::endl;
    std::cout << "Endereco: " << Funcionario::get_endereco() << std::endl;
    std::cout << "E-mail: " << Funcionario::get_email() << std::endl;
    std::cout << "Data de Nascimento: " << Funcionario::get_data_nascimento() << std::endl;
    std::cout << "Senha: " << Funcionario::get_senha() << std::endl;
    std::cout << "Certificado de informatica basica: " << Estoquista::get_informatica_basica() << std::endl;
    std::cout << "------------------------------------------------\n";
}