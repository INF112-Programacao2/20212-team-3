#include <iostream>
#include <string>

#include "Atendente.h"
#include "Funcionario.h"

Atendente::Atendente(int codigo, std::string nome, double salario, std::string cpf, std::string endereco, std::string email, std::string data_nascimento, std::string senha, double comissao):
    Funcionario(codigo, nome, salario, cpf, endereco, email, data_nascimento,senha), _comissao(comissao) {};

Atendente::~Atendente() {

}

double Atendente::get_comissao(){
    return this->_comissao;
}

void Atendente::set_comissao(double comissao){
    this->_comissao = comissao;
}

//Metodo especializado para a classe Atendente (Polimorfismo)
void Atendente::exibir_dados() {
    std::cout << "------------------------------------------------\n";
    std::cout << "Dados do Atendente: \n";
    std::cout << "Nome: " << Funcionario::get_nome() << std::endl;
    std::cout << "Codigo: " << Funcionario::get_codigo() << std::endl; 
    std::cout << "Salario: " << Funcionario::get_salario() << std::endl;
    std::cout << "CPF: " << Funcionario::get_cpf() << std::endl;
    std::cout << "Endereco: " << Funcionario::get_endereco() << std::endl;
    std::cout << "E-mail: " << Funcionario::get_email() << std::endl;
    std::cout << "Data de Nascimento: " << Funcionario::get_data_nascimento() << std::endl;
    std::cout << "Senha: " << Funcionario::get_senha() << std::endl;
    std::cout << "Comissao: " << this->get_comissao() << std::endl;
    std::cout << "------------------------------------------------\n";
}


