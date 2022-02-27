#ifndef NRW_CARRINHO_H
#define NRW_CARRINHO_H

#include <iostream>
#include <vector>

#include "Produto.h"

class Carrinho {

private:
    int _codigo;
    std::vector<Produto> _produtos;
    double _preco_total;

public:
    Carrinho(int codigo, Produto produto); //Verificar Logica - RFZ

    int get_codigo();
    double get_preco_total();

    void set_codigo(int codigo);
    void set_preco_total(double preco_total);

    void adicionar_produto(Produto produto, int quantidade);
    void remover_produto(Produto produto, int quantidade);
    void exibir_produtos();
    void calculo_preco_total();

};

#endif 