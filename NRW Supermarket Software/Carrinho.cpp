#include <iostream>
#include <string>
#include <vector>

#include "Carrinho.h"
#include "Produto.h"

unsigned int codigo_suporte = 1;

Carrinho::Carrinho() {
    this->_codigo = codigo_suporte;
    codigo_suporte++;
}

Carrinho::~Carrinho() {
    
}

unsigned int Carrinho::get_codigo() {
    return this->_codigo;
}

double Carrinho::get_preco_total() {
    return this->_preco_total;
}

void Carrinho::set_codigo(unsigned int codigo) {
    this->_codigo = codigo;
}

void Carrinho::set_preco_total(double preco_total) {
    this->_preco_total = preco_total;
}

void Carrinho::adicionar_produto(Produto *produto, int quantidade) {

    for (int i = 0; i < quantidade; i++) {
        this->_produtos.push_back(*produto);
    }
    calculo_preco_total();

}

void Carrinho::remover_produto(Produto *produto, int quantidade) {

    for (int i = 0; i < quantidade; i++) {
        for (int j = 0; j < _produtos.size(); j++) {
            if (this->_produtos[j].get_codigo() == produto->get_codigo()) { 
                _produtos.erase(_produtos.begin() + (j));
                break;
            }
        }
    }

}

void Carrinho::exibir_produtos() {

    for (int i = 0; i < this->_produtos.size(); i++) {
        std::cout << "Nome: " << this->_produtos[i].get_nome() << " - Preco: R$ " << this->_produtos[i].get_preco() << std::endl; 
    }

}

void Carrinho::calculo_preco_total() {

    double preco_total_suporte;

    this->set_preco_total(0);

    for (int i = 0; i < this->_produtos.size(); i++) {
        preco_total_suporte += this->_produtos[i].get_preco();
    }
    
    this->set_preco_total(preco_total_suporte);

}   