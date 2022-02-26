#include <iostream>
#include <string>

#include "Arquivos.h/Carrinho.h"

Carrinho::Carrinho(int codigo, Produto produto):
    _codigo(codigo), _produtos(produto) {}

int Carrinho::get_codigo() {
    return this->_codigo;
}

void Carrinho::set_codigo(int codigo) { //Codigos nao deveriam ser constantes/staticos? - RFZ
    this->_codigo = codigo;
}

void Carrinho::adicionar_produto(Produto produto, int quantidade) {
    int contador;
    
    for (contador = 0; contador < quantidade, contador++) {
        _produtos.pushback(produto);
    }
}

void remover_produto(Produto produto, int quantidade) { //Pensar 
    int contador;

    for (contador = 0; contador < quantidade, contador++) {
        _produtos.erase(produto); //Verificar logica - RFZ
    }    
}

void exibir_produtos() {
    int contador;

    for (contador = 0; contador < _produtos.size(), contador++) {
        std::cout << _produtos[contador] << std::endl; //Verificar logica - RFZ
    }    
}