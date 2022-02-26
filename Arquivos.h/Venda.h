#ifndef NRW_VENDA_H
#define NRW_VENDA_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Arquivos.h/Cliente.h"
#include "Arquivos.h/Atendente.h"
#include "Arquivos.h/Carrinho.h"

class Venda {

private:
    std::string _forma_pagamento;
    std::string _data;
    Cliente *_cliente_atendido; //Revisar - RFZ
    Atendente *_atendente_consultado; //Revisar - RFZ
    int _quantidade_vendas;
    double _desconto;
    double _valor_final;
    double _valor_recebido;
    double _troco;
    Carrinho *_carrinho; //Revisar - RFZ
    double _receita;

public:
    Venda(std::string forma_pagamento, std::string data, Cliente *cliente_atendido, Atendente *atendente_consultado, int quantidade_vendas, double desconto, double valor_final, double valor_recebido, double troco, Carrinho *carrinho, double receita); //Revisar - RFZ

    std::string get_forma_pagamento();
    std::string get_data();
    Cliente *get_cliente_atendido(); //Revisar - RFZ
    Atendente *get_atendente_consultado(); //Revisar - RFZ
    int get_quantidade_vendas();
    double get_desconto();
    double get_valor_final();
    double get_valor_recebido();
    double get_troco();
    Carrinho *get_carrinho(); //Revisar - RFZ
    double get_receita();

    void set_forma_pagamento(std::string forma_pagamento);
    void set_data(std::string data);
    void set_cliente_atendido(Cliente *cliente_atendido); //Revisar - RFZ
    void set_atendente_consultado(Atendente *atendente_consultado); //Revisar - RFZ
    void set_quantidade_vendas(int quantidade_vendas);
    void set_desconto(double desconto);
    void set_valor_final(double valor_final);
    void set_valor_recebido(double valor_recebido);
    void set_troco(double troco);
    void set_carrinho(Carrinho *carrinho); //Revisar - RFZ
    void set_receita(double receita);    

    void imprimir_nota_fiscal();
    void exibir_vendas();
    
};

#endif 
