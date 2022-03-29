#include <iostream>
#include <vector>
#include <exception>
#include "Estoque.h"
#include "Produto.h"


void Estoque::adicionar_produto(Produto *produto, int quantidade) {
       _produtos.push_back(*produto);
       _quantidade.push_back(quantidade);                //adiciona o produto e sua quantidade
}

void Estoque::excluir_produto(int codigo, int quantidade) {  
                                           
    int contador;
    
    try{
        for (contador = 0; contador < _produtos.size(); contador++) {
            if (this->_produtos[contador].get_codigo() == codigo) {
                if(_quantidade[contador] - quantidade < 0){
                    throw std::invalid_argument("A quantidade digita é maior que a presente no estoque!"); //Se a quantidade que ele requer for maior que a presente,logo é mostrado um erro.
                }
                if (_quantidade[contador] - quantidade == 0){                 //procura o produto pelo codigo e entao se a quantidade a ser retirada é igual a quantidade presente,logo ele exclui o produto do catalogo.
                   _produtos.erase(_produtos.begin() + contador);  //procura o produto e exclui do vector _produtos.s
                }
                else if(_quantidade[contador] - quantidade > 0 ){
                    _quantidade[contador] -= quantidade;   //apenas diminui a quantidade
                } 
            }
        }
    }
    catch(std::invalid_argument &e){
        std::cerr << e.what() << std::endl;
    }
}

void Estoque::exibir_estoque() {
    for (int i = 0 ; i < _produtos.size(); i++) {
        _produtos[i].exibir_dados();
        std::cout << "quantidade: " <<  _quantidade[i] << std::endl;
    }
}

void Estoque::exibir_estoque_reduzido() {
    for (int i=0; i < _produtos.size(); i++) {
        std::cout << "Codigo: " << _produtos[i].get_codigo() << "  ---  Nome: " <<_produtos[i].get_nome() << "  ---  Preco: " << _produtos[i].get_preco() << "  ---  Quant: " << _quantidade[i] << std::endl;
        std::cout << std::endl;
    }
}

bool Estoque::procurar_produto(int codigo) {
         for(int i = 0; i < _produtos.size(); i++) {
             if(_produtos[i].get_codigo() == codigo) {
                 _produtos[i].exibir_dados();               //quando ele procura o produto,ele vê se tem o produto,exibi seus dados e quantidade e retorna verdadeiro,se nao tiver retorna falso;
                 std::cout << "quantidade: " <<  _quantidade[i] << std::endl;
                 return true;
             }
         }
         return false;
     }

bool Estoque::verificar_codigo(int codigo) {
    for (int i=0; i < _produtos.size(); i++) {
        if (_produtos[i].get_codigo() == codigo) { 
            return true;     //pesquisa o produto e caso tenha um produto com o codigo procurado,ele retorna true
        }
    }
    return false;
}
