#ifndef NRW_ESTOQUE_H
#define NRW_ESTOQUE_H

#include <iostream>
#include <vector>
#include "Arquivos.h/Produto.h"

class Estoque {

private:
    std::vector<Produto> _produtos; //Revisar - RFZ

public:
    Estoque(Produto produto);

    void adicionar_produto(Produto produto, int quantidade); //Revisar - RFZ
    void excluir_produto(Produto produto, int quantidade); //Revisar - RFZ
    void exibir_estoque();

};

#endif 
