#ifndef NRW_CARRINHO_H
#define NRW_CARRINHO_H

#include <iostream>
#include <vector>

#include "Arquivos.h/Produto.h"

class Carrinho {

private:
    int _codigo;
    std::vector<Produto> _produtos;

public:
    Carrinho(int codigo, Produto produto); //Verificar Logica - RFZ

    int get_codigo();

    void set_codigo();

    void adicionar_produto(Produto produto, int quantidade);
    void remover_produto(Produto produto, int quantidade);
    void exibir_produtos();

};

#endif 