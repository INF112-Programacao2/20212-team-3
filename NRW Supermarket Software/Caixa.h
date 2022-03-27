#ifndef NRW_CAIXA_H
#define NRW_CAIXA_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Funcionario.h"

// Caixa e subclasse da classe Funcionario
class Caixa : public Funcionario {

// Atributo privado (exclusivo da classe Caixa)
private:
    bool _ensino_medio_completo;

public:
    // Construtor
    Caixa(int codigo, std::string nome, double salario, std::string cpf, std::string endereco, std::string email, std::string data_nascimento, std::string senha, bool ensino_medio_completo);
    // Destrutor
    ~Caixa();

    // Metodo get do atributo privado
    bool get_ensino_medio_completo();

    // Metodo set do atributo privado
    void set_ensino_medio_completo(bool ensino_medio_completo);

    // Metodo virtual
    virtual void exibir_dados();
    
};

#endif 
