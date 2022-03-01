#ifndef NRW_ESTOQUISTA_H
#define NRW_ESTOQUISTA_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Funcionario.h"

class Estoquista : public Funcionario {

private:
    bool _informatica_basica;

public:
    Estoquista(int codigo, std::string nome, double salario, std::string cpf, std::string endereco, std::string email, std::string data_nascimento, std::string senha, bool informatica_basica);

    bool get_informatica_basica();

    void set_informatica_basica(bool informatica_basica);

    virtual void exibir_dados();
    
};

#endif 
