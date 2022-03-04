#ifndef NRW_VENDA_H
#define NRW_VENDA_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Cliente.h"
#include "Atendente.h"
#include "Carrinho.h"

class Venda {

private:
    int _codigo;
    int _forma_pagamento;
    std::string _data;
    Cliente *_cliente_atendido; //Revisar - RFZ
    Atendente *_atendente_consultado; //Revisar - RFZ
    static int _quantidade_vendas;
    double _desconto;
    double _valor_recebido;
    double _troco;
    Carrinho *_carrinho; //Revisar - RFZ
    double _receita;
    double _valor_total_pagar;

public:
    Venda(int codigo, int forma_pagamento, std::string data, Cliente *cliente_atendido, Atendente *atendente_consultado, double valor_recebido, Carrinho *carrinho); //Revisar - RFZ

    int get_codigo();
    int get_forma_pagamento();
    std::string get_data();
    Cliente *get_cliente_atendido(); //Revisar - RFZ
    Atendente *get_atendente_consultado(); //Revisar - RFZ
    int get_quantidade_vendas();
    double get_desconto();
    double get_valor_recebido();
    double get_troco();
    Carrinho *get_carrinho(); //Revisar - RFZ
    double get_receita();
    double get_valor_total_pagar();

    void set_codigo(int codigo);
    void set_forma_pagamento(int forma_pagamento);
    void set_data(std::string data);
    void set_cliente_atendido(Cliente *cliente_atendido); //Revisar - RFZ
    void set_atendente_consultado(Atendente *atendente_consultado); //Revisar - RFZ
    void set_quantidade_vendas(int quantidade_vendas);
    void set_desconto(double desconto);
    void set_valor_recebido(double valor_recebido);
    void set_troco(double troco);
    void set_carrinho(Carrinho *carrinho); //Revisar - RFZ
    void set_receita(double receita);   
    void set_valor_total_pagar(double valor_total_pagar); 

    void imprimir_nota_fiscal();
    void calcula_troco();
    void exibir_vendas();
    
};

#endif 
