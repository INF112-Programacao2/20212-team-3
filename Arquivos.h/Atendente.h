#ifndef  NRW_ATENDENTE_H
#define NRW_ATENDENTE_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Arquivos.h/Funcionario.h"

class Atendente : public Funcionario {

private:
    double _comissao;

public:
    Atendente(std::string nome, int codigo, double salario, std::string cpf, std::string endereco, std::string email, std::string data_nascimento, std::string senha, double comissao);

    double get_comissao();

    void set_comissao(double comissao);

    virtual void exibir_dados();
    
};

#endif 
