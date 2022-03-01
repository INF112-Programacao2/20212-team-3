#include <iostream>
#include <string>

#include "Cliente.h"

Cliente::Cliente(int codigo, std::string nome, std::string cpf, std::string telefone, std::string endereco):
    _codigo(codigo), _nome(nome), _cpf(cpf), _telefone(telefone), _endereco(endereco) {}

std::string Cliente::get_nome() {
    return this->_nome;
}

std::string Cliente::get_cpf() {
    return this->_cpf;
}

std::string Cliente::get_telefone() {
    return this->_telefone;
}

std::string Cliente::get_endereco() {
    return this->_endereco;
}

int Cliente::get_codigo() {
    return this->_codigo;
}

void Cliente::set_nome(std::string nome) {
    this->_nome = nome;
}

void Cliente::set_cpf(std::string cpf) {
    this->_cpf = cpf;
}

void Cliente::set_telefone(std::string telefone) {
    this->_telefone = telefone;
}

void Cliente::set_endereco(std::string endereco) {
    this->_endereco = endereco;
}

void Cliente::set_codigo(int codigo) {
    this->_codigo = codigo;
}

void Cliente::exibir_dados() {
    std::cout << "------------------------------------------------\n";
    std::cout << "Dados do Cliente:\n";
    std::cout << "Nome: " << this->get_nome() << std::endl;
    std::cout << "CPF: " << this->get_cpf() << std::endl;
    std::cout << "Telefone: " << this->get_telefone() << std::endl;
    std::cout << "Endereco: " << this->get_endereco() << std::endl;
    std::cout << "Codigo: " << this->get_codigo() << std::endl;
    std::cout << "------------------------------------------------\n";
}