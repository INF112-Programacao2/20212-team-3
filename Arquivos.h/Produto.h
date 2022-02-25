#ifdef NRW_PRODUTOS_H
#define NRW_PRODUTOS_H

#include <iostream>
#include <string>

class Produto {

private:
    std::string _nome;
    double _preco;
    std::string _validade;
    int _codigo;
    std::string _marca;

public:
    Produto(std::string nome, double preco, std::string validade, int codigo, std::string marca);

    std::string get_nome();
    double get_preco();
    std::string get_validade();
    int get_codigo();
    std::string get_marca();

    void set_nome(std::string nome);
    void set_preco(double preco);
    void set_validade(std::string validade);
    void set_codigo(int codigo);
    void set_marca(std::string marca);

    void exibir_dados();
    
};

#endif 
