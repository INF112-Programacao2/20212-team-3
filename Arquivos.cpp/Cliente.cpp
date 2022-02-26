#include <iostream>
#include <string>

#include "Arquivos.h/Cliente.h"

Cliente::Cliente(std::string nome, std::string cpf, std::string telefone, std::string endereco, int codigo):
    _nome(nome), _cpf(cpf), _telefone(telefone), _endereco(endereco), _codigo(codigo) {}

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
    std::cout << "Nome: " << get_nome() << std::endl;
    std::cout << "CPF: " << get_cpf() << std::endl;
    std::cout << "Telefone: " << get_telefone() << std::endl;
    std::cout << "Endereco: " << get_endereco() << std::endl;
    std::cout << "Codigo: " << get_codigo() << std::endl;
    std::cout << "------------------------------------------------\n";
}