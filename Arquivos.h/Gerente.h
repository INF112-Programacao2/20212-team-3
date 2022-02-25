#ifdef NRW_GERENTE_H
#define NRW_GERENTE_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Arquivos.h/Funcionario.h"

class Gerente : public Funcionario {

private:
    bool _curso_superior;

public:
    Gerente(std::string nome, int codigo, double salario, std::string cpf, std::string endereco, std::string email, std::string data_nascimento, std::string senha, bool curso_superior);

    bool get_curso_superior();

    void set_curso_superior(bool curso_superior);

    virtual exibir_dados() override;

};

#endif 
