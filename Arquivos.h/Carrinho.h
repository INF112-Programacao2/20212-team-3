#ifdef NRW_CARRINHO_H
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

    int set_codigo();

    void adicionar_produto();
    void remover_produto();
    void exibir_produtos();

};


#endif 