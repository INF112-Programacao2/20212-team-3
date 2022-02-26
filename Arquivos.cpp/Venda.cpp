#include <iostream>
#include <string>

#include "Arquivos.h/Cliente.h"
#include "Arquivos.h/Atendente.h"
#include "Arquivos.h/Carrinho.h"

Venda::Venda(std::string forma_pagamento, std::string data, Cliente cliente_atendido, Atendente atendente_consultado, int quantidade_vendas, double desconto, double valor_final, double valor_recebido, double troco, Carrinho carrinho, double receita):
    _forma_pagamento(forma_pagamento), _data(data), _cliente_atendido(cliente_atendido), _atendente_consultado(atendente_consultado), _quantidade_vendas(quantidade_vendas), _desconto(desconto), _valor_final(valor_final), _valor_recebido(valor_recebido), _troco(troco), _carrinho(carrinho), _receita(receita) {}

std::string Venda::get_forma_pagamento() {
    return this->_forma_pagamento;
}

std::string Venda::get_data() {
    return this->_data;
}

Cliente Venda::get_cliente_atendido() { //Revisar - RFZ
    return Cliente::exibir_dados();
} 

Atendente Venda::get_atendente_consultado() { //Revisar - RFZ
    return Atendente::exibir_dados();
} 

int Venda::get_quantidade_vendas() {
    return this->_quantidade_vendas;
}

double Venda::get_desconto() {
    return this->_desconto;
}

double Venda::get_valor_final() {
    return this->_valor_final;
}

double Venda::get_valor_recebido() {
    return this->_valor_recebido;
}

double Venda::get_troco() {
    return this->_troco;
}

Carrinho Venda::get_carrinho() { //Revisar - RFZ
    return Carrinho::get_codigo();
} 

double Venda::get_receita() {
    return this->_receita;
}

void Venda::set_forma_pagamento(std::string forma_pagamento) {
    this->_forma_pagamento = forma_pagamento;
}

void Venda::set_data(std::string data) {
    this->_data = data;
}

void Venda::set_cliente_atendido(Cliente cliente_atendido) { //Revisar - RFZ
    this->_cliente_atendido = cliente_atendido;
} 

void Venda::set_atendente_consultado(Atendente atendente_consultado) {  //Revisar - RFZ
    this->_atendente_consultado = atendente_consultado;
}

void Venda::set_quantidade_vendas(int quantidade_vendas) {
    this->_quantidade_vendas = quantidade_vendas;
}

void Venda::set_desconto(double desconto) {
    this->_desconto = desconto;
}

void Venda::set_valor_final(double valor_final) {
    this->_valor_final = valor_final;
}

void Venda::set_valor_recebido(double valor_recebido) {
    this->_valor_recebido = valor_recebido;
}

void Venda::set_troco(double troco) {
    this->_troco = troco;
}

void Venda::set_carrinho(Carrinho carrinho) { //Revisar - RFZ
    this->_carrinho = carrinho;
}

void Venda::set_receita(double receita) {
    this->_receita = receita;
}    

void Venda::imprimir_nota_fiscal() { 
    std::cout << std::endl;
    std::cout << "NRW Supermarket" << std::endl;
    std::cout << "__________________________" << std::endl;
    std::cout << "CUPOM FISCAL" << std::endl;
    std::cout << "Numero do Cupom: " << Venda::get_quantidade_vendas() << std::endl; //Verificar - RFZ
    std::cout << "Data: " << Venda::get_data() << std::endl;
    std::cout << "__________________________" << std::endl;
    std::cout << "Dados do cliente: " << std::endl;
    std::cout << Venda::get_cliente_atendido() << std::endl;
    std::cout << "Dados do atendente: " << std::endl;
    std::cout << Venda::get_atendente_consultado() << std::endl;
    std::cout << "__________________________" << std::endl;
    std::cout << "Produtos Comprados:" << std::endl;
    std::cout << Carrinho::exibir_produtos() << std::endl; //Pensar em como colocar o preco na frente de cada produto - RFZ
    std::cout << "__________________________" << std::endl; 
    std::cout << "Valor a Pagar: " << Venda::get_valor_final() << std::endl; //Analisar a existencia dessa funcao, valor final deveria ser calculado automatico - RFZ
    std::cout << "Forma de Pagamento: " << Venda::get_forma_pagamento() << std::endl;
    std::cout << "Desconto: " << Venda::get_desconto() << std::endl; //Analisar funcao que calcula desconto - RFZ
    std::cout << "Valor Recebido: " << Venda::get_valor_recebido() << std::endl;
    std::cout << "Troco: " << Venda::get_troco() << std::endl; //Analisar funcao que calcula troco - RFZ
    std::cout << "__________________________" << std::endl; 
    std::cout << "Obrigado por comprar no nosso Supermercado!" << std::endl;
    std::cout << "Todos direitos reservados, NRW Supermerkat - 2022" << std::endl;
}

void Venda::exibir_vendas() {
    std::cout << "Quantidade de Vendas: " << Venda::get_quantidade_vendas() << std::endl;
    std::cout << "Receita total: " << Venda::get_receita() << std::endl;
}