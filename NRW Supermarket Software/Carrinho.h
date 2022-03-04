#ifndef NRW_CARRINHO_H
#define NRW_CARRINHO_H

#include <iostream>
#include <vector>


#include "Produto.h"

class Carrinho {

private:
    unsigned int _codigo; //Verificar no main se a geracao de codigo automatica esta funcionando
    std::vector<Produto> _produtos;
    double _preco_total;

public:
    Carrinho();

    unsigned int get_codigo();
    double get_preco_total();

    void set_codigo(unsigned int codigo);
    void set_preco_total(double preco_total);

    void adicionar_produto(Produto *produto, int quantidade);
    void remover_produto(Produto *produto, int quantidade);
    void exibir_produtos();
    void calculo_preco_total();

};

#endif 