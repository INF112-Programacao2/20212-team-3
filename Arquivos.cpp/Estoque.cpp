#include <vector>
#include "Arquivos.h/Estoque.h"
#include "Arquivos.h/Produto.h"
#include "iostream"

Estoque::Estoque(Produto produto):
    _produto(produto) {}


void Estoque::adicionar_produto(Produto produto, int quantidade) {
       for(int i = 0;i < quantidade;i++) {
           _produtos.pushback(produto);
       }

 }

 void Estoque::excluir_produto(Produto produto, int quantidade) {
                                            // Pensar em tratamento de erro(quantidade > estoque)-----WB
      for(int i = 0;i < quantidade;i++) {
          _produtos.erase(produto);
      }

}

 void Estoque::exibir_estoque() {
    for(int i = 0 ;i < _produtos.size();i++) {
        _produtos[i].exibir_dados(); 
    }
 }