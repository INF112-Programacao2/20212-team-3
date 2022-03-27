#ifndef NRW_CLIENTE_H
#define NRW_CLIENTE_H

#include <string>

class Cliente {

// Metodos privados (exclusivo da classe Cliente)
private:
    std::string _nome;
    std::string _cpf;
    std::string _telefone;
    std::string _endereco;
    int _codigo;

public:
    // Construtor
    Cliente(int codigo, std::string nome, std::string cpf, std::string telefone, std::string endereco);
    // Destrutor
    ~Cliente();

    // Metodos get dos atributos privados
    std::string get_nome();
    std::string get_cpf();
    std::string get_telefone();
    std::string get_endereco();
    int get_codigo();

    // Metodo set dos atributos privados
    void set_nome(std::string nome);
    void set_cpf(std::string cpf);
    void set_telefone(std::string telefone);
    void set_endereco(std::string endereco);
    void set_codigo(int codigo);

    void exibir_dados();

};

#endif