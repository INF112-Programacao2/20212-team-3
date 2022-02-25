#ifdef NRW_ESTOQUE_H
#define NRW_ESTOQUE_H

#include <iostream>
#include <vector>

#include "Arquivos.h/Produto.h"

class Estoque {

private:
    std::vector<Produto> _produtos; //Revisar - RFZ

public:
    Produto(Produto produtos);

    void adicionar_produto(Produto produto, int codigo); //Revisar - RFZ
    void excluir_produto(Produto produto, int codigo); //Revisar - RFZ
    void exibir_estoque();

};

#endif 
