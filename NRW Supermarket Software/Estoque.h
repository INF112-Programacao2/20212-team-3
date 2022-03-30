#ifndef NRW_ESTOQUE_H
#define NRW_ESTOQUE_H

#include <iostream>
#include <vector>

#include "Produto.h"

class Estoque {

private:
    std::vector<Produto> _produtos; 
    std::vector<int> _quantidade;           //dois vectors,um que contem os dados do produto,e o outro que terá sua quantidade
    
public:
    std::vector<Produto> get_produtos();
    std::vector<int> get_quantidade();

    void adicionar_produto(Produto *produto, int quantidade); 
    void excluir_produto(int codigo, int quantidade); 
    void exibir_estoque();
    void exibir_estoque_reduzido();

    bool procurar_produto(int codigo);
    bool verificar_codigo(int codigo);

};

#endif 
