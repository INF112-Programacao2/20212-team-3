#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Carrinho.h"

unsigned int codigo_suporte = 1;

Carrinho::Carrinho() {
    this->_codigo = codigo_suporte;
    codigo_suporte++;
}

unsigned int Carrinho::get_codigo() {
    return this->_codigo;
}

double Carrinho::get_preco_total() {
    return this->_preco_total;
}

void Carrinho::set_codigo(unsigned int codigo) { //Codigos nao deveriam ser constantes/staticos? - RFZ
    this->_codigo = codigo;
}

void Carrinho::set_preco_total(double preco_total) {
    this->_preco_total = preco_total;
}

void Carrinho::adicionar_produto(Produto produto, int quantidade) {
    int contador;

    for (contador = 0; contador < quantidade; contador++) {
        _produtos.push_back(produto);
    }
    calculo_preco_total();
}

void Carrinho::remover_produto(Produto produto, int quantidade) { 

    int contador;

    for (contador = 0; contador < _produtos.size(); contador++) {
        if (this->_produtos[contador].get_codigo() == produto.get_codigo()) { 
            _produtos.erase(_produtos.begin() + (contador - 1 ));
        }
    }    
}

void Carrinho::exibir_produtos() {
    int contador;

    for (contador = 0; contador < _produtos.size(); contador++) {
        std::cout << "Produto: " << _produtos[contador].get_nome() << " - " << "Preco: " << _produtos[contador].get_preco() << std::endl; //Verificar logica - RFZ
    }
    std::cout << "------------------------------------------------\n";
    std::cout << get_preco_total() << std::endl;
}

void Carrinho::calculo_preco_total() {
    int contador;
    for (contador = 0; contador < _produtos.size(); contador++) {
        this->_preco_total += _produtos[contador].get_preco();
    }
}   