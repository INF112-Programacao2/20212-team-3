#ifndef NRW_CARRINHO_H
#define NRW_CARRINHO_H

#include <iostream>
#include <vector>

#include "Produto.h"

class Carrinho {

private:
    unsigned int _codigo; 
    std::vector<Produto> _produtos;
    double _preco_total;

public:
    // Construtor
    Carrinho();
    // Destrutor
    ~Carrinho();

    // Metodos get dos atributos privados
    unsigned int get_codigo();
    double get_preco_total();

    // Metodo set dos atributos privados
    void set_codigo(unsigned int codigo);
    void set_preco_total(double preco_total);

    void adicionar_produto(Produto *produto, int quantidade);
    void remover_produto(Produto *produto, int quantidade);
    void exibir_produtos();
    void calculo_preco_total();

};

#endif 