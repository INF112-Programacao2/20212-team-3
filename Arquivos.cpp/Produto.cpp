#include "string"
#include "Arquivos.h/Produto.h"
#include <iostream>


Produto::Produto(std::string nome, double preco, std::string validade, int codigo, std::string marca):
_nome(nome),_preco(preco),_validade(validade),_codigo(codigo),_marca(marca) {};

std::string Produto::get_nome(){
    return this->_nome;
}

double Produto::get_preco(){
    return this->_preco;
}

std::string Produto::get_validade(){
    return this->_validade;
}

int Produto::get_codigo(){
    return this->_codigo;
}

std::string Produto::get_marca(){
    return this->_marca;
}

void Produto::set_nome(std::string nome){
    this->_nome = nome;
}

void Produto::set_preco(double preco){
    this->_preco = preco;
}

void Produto::set_validade(std::string validade){
    this->_validade = validade;
}

void Produto::set_codigo(int codigo){
    this->_codigo = codigo;
}

void Produto::set_marca(std::string marca){
    this->_marca = marca;
}

void Produto::exibir_dados(){
    std::cout << std::endl;
    std::cout << "Nome: " << Produto::get_nome() << std::endl;
    std::cout << "Preco " << Produto::get_preco() << std::endl; 
    std::cout << "Validade: " << Produto::get_validade() << std::endl;
    std::cout << "Codigo: " << Produto::get_codigo() << std::endl;
    std::cout << "Marca: " << Produto::get_marca() << std::endl;
    std::cout << std::endl;
}