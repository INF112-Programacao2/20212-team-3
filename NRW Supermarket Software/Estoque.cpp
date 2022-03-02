#include <iostream>
#include <vector>

#include "Estoque.h"
#include "Produto.h"

void Estoque::adicionar_produto(Produto produto, int quantidade) {
    int contador;

    for (contador = 0; contador < quantidade; contador++) {
        _produtos.push_back(produto);
    }
}

 void Estoque::excluir_produto(Produto produto, int quantidade) {  // Pensar em tratamento de erro(quantidade > estoque)-----WB
                                           
    int contador, contador2;

    for (contador2 = 0; contador2 < quantidade; contador2++) {
        for (contador = 0; contador < _produtos.size(); contador++) {
            if (this->_produtos[contador].get_codigo() == produto.get_codigo()) { 
                _produtos.erase(_produtos.begin() + (contador -1 ));
            }
        }
    }

}

 void Estoque::exibir_estoque() {
    for(int i = 0 ;i < _produtos.size();i++) {
        _produtos[i].exibir_dados(); 
    }
 }