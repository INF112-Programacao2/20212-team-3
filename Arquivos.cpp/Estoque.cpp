#include <vector>
#include "Arquivos.h/Estoque.h"
#include "Arquivos.h/Produto.h"
#include "iostream"

Estoque::Estoque(Produto produtos)
{


}

void Estoque::adicionar_produto(Produto produto, int codigo)
 {
       

 }

 void Estoque::excluir_produto(Produto produto, int codigo)
 {


 }

 void Estoque::exibir_estoque()
 {
    for(int i = 0 ;i < _produtos.size();i++)
    {
        _produtos[i].exibir_dados(); 
    }
 }