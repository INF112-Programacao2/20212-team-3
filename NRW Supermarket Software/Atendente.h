#ifndef  NRW_ATENDENTE_H
#define NRW_ATENDENTE_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Funcionario.h"

// Atendente e subclasse da classe Funcionario
class Atendente : public Funcionario {

// Atributo privado (exclusivo da classe Atendente)
private:
    double _comissao;

public:
    // Construtor
    Atendente(int codigo, std::string nome, double salario, std::string cpf, std::string endereco, std::string email, std::string data_nascimento, std::string senha, double comissao);
    // Destrutor
    ~Atendente();

    // Metodo get do atributo privado
    double get_comissao();

    // Metodo set do atributo privado
    void set_comissao(double comissao);

    // Metodo virtual
    virtual void exibir_dados();
    
};

#endif 
