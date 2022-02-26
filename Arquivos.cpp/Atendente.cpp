#include <iostream>
#include <string>

#include "Arquivos.h/Atendente.h"
#include "Arquivos.h/Funcionario.h"

Atendente::Atendente(std::string nome, int codigo, double salario, std::string cpf, std::string endereco, std::string email, std::string data_nascimento, std::string senha, double comissao):
Funcionario(nome, codigo, salario, cpf, endereco, email, data_nascimento,senha), _comissao(comissao) {};

double Atendente::get_comissao(){
    return this->_comissao;
}

void Atendente::set_comissao(double comissao){
    this->_comissao = comissao;
}

void Atendente::exibir_dados() {
    std::cout << "------------------------------------------------\n";
    std::cout << "Nome: " << Funcionario::get_nome() << std::endl;
    std::cout << "Codigo: " << Funcionario::get_codigo() << std::endl; 
    std::cout << "Salario: " << Funcionario::get_salario() << std::endl;
    std::cout << "CPF: " << Funcionario::get_cpf() << std::endl;
    std::cout << "Endereco: " << Funcionario::get_endereco() << std::endl;
    std::cout << "E-mail: " << Funcionario::get_email() << std::endl;
    std::cout << "Data de Nascimento: " << Funcionario::get_data_nascimento() << std::endl;
    std::cout << "Senha: " << Funcionario::get_senha() << std::endl;
    std::cout << "Comissao: " << Atendente::get_comissao() << std::endl;
    std::cout << "------------------------------------------------\n";
}


