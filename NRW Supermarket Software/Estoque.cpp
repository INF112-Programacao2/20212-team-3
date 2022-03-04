#include <iostream>
#include <vector>

#include "Estoque.h"
#include "Produto.h"

void Estoque::adicionar_produto(Produto *produto, int quantidade) {
       _produtos.push_back(*produto);
       _quantidade.push_back(quantidade);
}

 void Estoque::excluir_produto(int codigo, int quantidade) {  // Pensar em tratamento de erro(quantidade > estoque)-----WB
                                           
    int contador;
    
        for (contador = 0; contador < _produtos.size(); contador++) {
            if (this->_produtos[contador].get_codigo() == codigo) {
                if (_quantidade[contador] - quantidade == 0){
                   _produtos.erase(_produtos.begin() + contador);
                }
                else if(_quantidade[contador] - quantidade > 0 ){
                    _quantidade[contador] -= quantidade;
                } 
            }
        }
    

}

 void Estoque::exibir_estoque() {
    for (int i = 0 ; i < _produtos.size(); i++) {
        _produtos[i].exibir_dados();
        std::cout << "quantidade: " <<  _quantidade[i] << std::endl;
    }
 }

 bool Estoque::procurar_produto(int codigo) {
         for(int i = 0;i < _produtos.size();i++) {
             if(_produtos[i].get_codigo() == codigo) {
                 _produtos[i].exibir_dados();
                 std::cout << "quantidade: " <<  _quantidade[i] << std::endl;
                 return true;
             }
         }
         return false;
     }
