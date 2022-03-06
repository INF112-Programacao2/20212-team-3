#ifndef NRW_ESTOQUE_H
#define NRW_ESTOQUE_H

#include <iostream>
#include <vector>

#include "Produto.h"

class Estoque {

private:
    std::vector<Produto> _produtos; 
    std::vector<int> _quantidade;
    
public:
    void adicionar_produto(Produto *produto, int _quantidade); 
    void excluir_produto(int codigo, int _quantidade); 
    void exibir_estoque();
   
    bool procurar_produto(int codigo);
    bool verificar_codigo(int codigo);

};

#endif 
