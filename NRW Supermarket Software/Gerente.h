#ifndef NRW_GERENTE_H
#define NRW_GERENTE_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Funcionario.h"

// Gerente é subclasse da classe Funcionario
class Gerente : public Funcionario {

// Atributo privado (exclusivo da classe Gerente)
private:
    bool _curso_superior;

public:
    // Construtor com os atributos da Superclasse (classe mae) + os seus atributos exclusivos da classe Gerente
    Gerente(int codigo, std::string nome, double salario, std::string cpf, std::string endereco, std::string email, std::string data_nascimento, std::string senha, bool curso_superior);
    // Destrutor
    ~Gerente();

    // Metodo get para seu unico atributo exclusivo da classe Gerente
    bool get_curso_superior();

    // Metodo set para o atributo private (exclusivo a classe Gerente)
    void set_curso_superior(bool curso_superior);

    // Metodo virtual
    virtual void exibir_dados();

};

#endif 
