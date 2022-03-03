#ifndef NRW_ESTOQUE_H
#define NRW_ESTOQUE_H

#include <iostream>
#include <vector>

#include "Produto.h"

class Estoque {

private:
    std::vector<Produto> _produtos; 
    
public:
    void adicionar_produto(Produto &produto, int quantidade); 
    void excluir_produto(Produto produto, int quantidade); 
    void exibir_estoque();
   
    // bool procurar_produto(int codigo);

};

#endif 
