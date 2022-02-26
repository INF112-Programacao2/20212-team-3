#ifndef NRW_CAIXA_H
#define NRW_CAIXA_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Arquivos.h/Funcionario.h"

class Caixa : public Funcionario {

private:
    bool _ensino_medio_completo;

public:
    Caixa(std::string nome, int codigo, double salario, std::string cpf, std::string endereco, std::string email, std::string data_nascimento, std::string senha, bool ensino_medio_completo);

    bool get_ensino_medio_completo();

    void set_ensino_medio_completo(bool ensino_medio_completo);

    virtual void exibir_dados();
    
};

#endif 
