#ifndef NRW_ESTOQUISTA_H
#define NRW_ESTOQUISTA_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Funcionario.h"

// Estoquista e subclasse da classe Funcionario
class Estoquista : public Funcionario {

// Atributo privado (exclusivo da classe Estoquista)
private:
    bool _informatica_basica;

public:
    //  Construtor
    Estoquista(int codigo, std::string nome, double salario, std::string cpf, std::string endereco, std::string email, std::string data_nascimento, std::string senha, bool informatica_basica);

    // Destrutor
    ~Estoquista();

    // Metodo get do atributo privado
    bool get_informatica_basica();

    // Metodo set do atributo privado
    void set_informatica_basica(bool informatica_basica);

    // Metodo virtual
    virtual void exibir_dados();
    
};

#endif 
