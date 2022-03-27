#ifndef NRW_PRODUTOS_H
#define NRW_PRODUTOS_H

#include <iostream>
#include <string>

class Produto {

// Atributos privados (exclusivos da classe Produto)
private:
    std::string _nome;
    double _preco;
    std::string _validade;
    int _codigo;
    std::string _marca;

public:
    // Construtor
    Produto(int codigo, std::string nome, double preco, std::string validade, std::string marca);

    // Metodos gets dos atributos privados
    std::string get_nome();
    double get_preco();
    std::string get_validade();
    int get_codigo();
    std::string get_marca();

    //Metodos sets dos atributos privados
    void set_nome(std::string nome);
    void set_preco(double preco);
    void set_validade(std::string validade);
    void set_codigo(int codigo);
    void set_marca(std::string marca);

    // Metodo para exibir todas as informacoes do produto
    void exibir_dados();
    
};

#endif 
