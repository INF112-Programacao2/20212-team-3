#include <iostream>
#include <string>

#include "Funcionario.h"

Funcionario::Funcionario(int codigo, std::string nome, double salario, std::string cpf, std::string endereco, std::string email, std::string data_nascimento, std::string senha):
    _codigo(codigo), _nome(nome), _salario(salario), _cpf(cpf), _endereco(endereco), _email(email), _data_nascimento(data_nascimento), _senha(senha) {}

Funcionario::~Funcionario() {
    
}

std::string Funcionario::get_nome() {
    return this->_nome;
}

int Funcionario::get_codigo() {
    return this->_codigo;
}

double Funcionario::get_salario() {
    return this->_salario;
}

std::string Funcionario::get_cpf() {
    return this->_cpf;
}

std::string Funcionario::get_endereco() {
    return this->_endereco;
}

std::string Funcionario::get_email() {
    return this->_email;
}

std::string Funcionario::get_data_nascimento() {
    return this->_data_nascimento;
}

std::string Funcionario::get_senha() {
    return this->_senha;
}

void Funcionario::set_nome(std::string nome) {
    this->_nome = nome;
}

void Funcionario::set_email(std::string email) {
    this->_email = email;
}

void Funcionario::set_endereco(std::string endereco) {
    this->_endereco = endereco;
}

void Funcionario::set_data_nascimento(std::string data_nascimento) {
    this->_data_nascimento = data_nascimento;
}

void Funcionario::set_cpf(std::string cpf) {
    this->_cpf = cpf;
}

void Funcionario::set_senha(std::string senha) {
    this->_senha = senha;
}

void Funcionario::set_salario(double salario) {
    this->_salario = salario;
}

void Funcionario::set_codigo(int codigo) {
    this->_codigo = codigo;
}
