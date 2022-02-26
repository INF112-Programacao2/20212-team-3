#include <iostream>
#include <string>
#include <vector>

#include "Arquivos.h/Carrinho.h"

Carrinho::Carrinho(int codigo, Produto produto):
    _codigo(codigo), _produtos(produto) {}

int Carrinho::get_codigo() {
    return this->_codigo;
}

double Carrinho::get_preco_total() {
    return this->_preco_total;
}

void Carrinho::set_codigo(int codigo) { //Codigos nao deveriam ser constantes/staticos? - RFZ
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
    Carrinho::calculo_preco_total();
}

void Carrinho::remover_produto(Produto produto, int quantidade) { //Pensar 
    int contador;

    for (contador = 0; contador < quantidade;contador++) {
        _produtos.erase(produto); //Verificar logica - RFZ
    }    
}

void Carrinho::exibir_produtos() {
    int contador;

    for (contador = 0; contador < _produtos.size(); contador++) {
        std::cout << "Produto: " << _produtos[contador].get_nome() << " - " << "Preco: " << _produtos[contador].get_preco() << std::endl; //Verificar logica - RFZ
    }
    std::cout << "------------------------------------------------\n";
    std::cout << Carrinho::get_preco_total() << std::endl;
}

void Carrinho::calculo_preco_total() {
    int contador;
    for (contador = 0; contador < _produtos.size(); contador++) {
        _preco_total += _produtos[contador].get_preco();
}