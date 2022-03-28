#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

#include "Cliente.h"
#include "Atendente.h"
#include "Carrinho.h"
#include "Venda.h"

Venda::Venda(int codigo, int forma_pagamento, std::string data, Cliente *cliente_atendido, Atendente *atendente_consultado, double valor_recebido, Carrinho *carrinho):
    _codigo(codigo), _forma_pagamento(forma_pagamento), _data(data), _cliente_atendido(cliente_atendido), _atendente_consultado(atendente_consultado), _valor_recebido(valor_recebido), _carrinho(carrinho) {}

Venda::~Venda() {
    
}

int Venda::get_codigo() {
    return this->_codigo;
}

int Venda::get_forma_pagamento() {
    return this->_forma_pagamento;
}

std::string Venda::get_data() {
    return this->_data;
}

Cliente* Venda::get_cliente_atendido() { 
    return _cliente_atendido;
} 

Atendente* Venda::get_atendente_consultado() {
    return _atendente_consultado;
} 

double Venda::get_desconto() {
    //Pagamento com cartao de credito
    if (Venda::get_forma_pagamento() == 1) {
        this->_desconto = 0.05;
    } 
    //Pagamento a vista
    else {
        this->_desconto = 0.10;
    }

    return this->_desconto;
}

double Venda::get_valor_recebido() {
    return this->_valor_recebido;
}

double Venda::get_troco() {
    return this->_troco;
}

Carrinho* Venda::get_carrinho() {
    return _carrinho;
} 

double Venda::get_valor_total_pagar() { // Obtem o preco total do carrinho e aplica o desconto para gerar o valor total a pagar
    return Venda::get_carrinho()->get_preco_total() - (Venda::get_carrinho()->get_preco_total() * this->get_desconto());
}

void Venda::set_codigo(int codigo) {
    this->_codigo = codigo;
}

void Venda::set_forma_pagamento(int forma_pagamento) {
    this->_forma_pagamento = forma_pagamento;
}

void Venda::set_data(std::string data) {
    this->_data = data;
}

void Venda::set_cliente_atendido(Cliente *cliente_atendido) {
    this->_cliente_atendido = cliente_atendido;
} 

void Venda::set_atendente_consultado(Atendente *atendente_consultado) {  
    this->_atendente_consultado = atendente_consultado;
}

void Venda::set_desconto(double desconto) {
    this->_desconto = desconto;
}

void Venda::set_valor_recebido(double valor_recebido) {
    this->_valor_recebido = valor_recebido;
}

void Venda::set_troco(double troco) {
    this->_troco = troco;
}

void Venda::set_carrinho(Carrinho *carrinho) { 
    this->_carrinho = carrinho;
}

void Venda::set_valor_total_pagar(double valor_total_pagar) {
    this->_valor_total_pagar = valor_total_pagar;
}    

void Venda::imprimir_nota_fiscal() { 
    std::cout << std::endl;
    std::cout << "NRW Supermarket" << std::endl;
    std::cout << "------------------------------------------------\n"; 
    std::cout << "CUPOM FISCAL" << std::endl;
    std::cout << "Codigo: " << this->get_codigo() << std::endl;
    std::cout << "Data: " << this->get_data() << std::endl;
    this->get_cliente_atendido()->exibir_dados();
    std::cout << "Atendente responsavel: " << this->get_atendente_consultado()->get_nome() << std::endl;
    std::cout << "------------------------------------------------\n";
    std::cout << "Produtos Comprados:" << std::endl;
    (*_carrinho).exibir_produtos();
    std::cout << "------------------------------------------------\n";
    std::cout << "Valor a Pagar: R$" << this->get_valor_total_pagar() << std::endl; 
    std::cout << "Forma de Pagamento: " << this->get_forma_pagamento() << std::endl;
    std::cout << "Desconto: R$" << this->get_desconto() << std::endl; 
    std::cout << "Valor Recebido: R$" << this->get_valor_recebido() << std::endl;
    std::cout << "Troco: R$" << this->get_troco() << std::endl; 
    std::cout << "------------------------------------------------\n";
    std::cout << "Obrigado por comprar no nosso Supermercado!" << std::endl;
    std::cout << "Todos direitos reservados, NRW Supermarket - 2022" << std::endl;
    
}

void Venda::calcula_troco() { 

    double suporte_valor_total = this->get_valor_total_pagar();
    double suporte_valor_recebido = this->get_valor_recebido();

    suporte_valor_total -= suporte_valor_recebido;

    while (suporte_valor_total > 0) { //Enquanto o valor total for maior que 0, ira solicitar que a pessoa deposite mais dinheiro
        std::cout << "O dinheiro recebido ainda nao e suficiente para pagar o valor total, ainda e necessario pagar R$ " << suporte_valor_total << std::endl;
        std::cout << "Insira o restante do dinheiro: \n";
        std::cin >> suporte_valor_recebido;
        suporte_valor_total -= suporte_valor_recebido; 
    }

    if (suporte_valor_total == 0.00) {
        this->set_troco(0);
    }
    else {
        this->set_troco((-1)*(suporte_valor_total)); // Corrigi o valor negativo gerado no suporte_valor_total -= suporte_valor_recebido para gerar o troco
    }

    std::cout << "O valor do troco e: R$ " << std::fixed << std::setprecision(2) << this->get_troco() << std::endl;
    this->set_valor_recebido(this->get_valor_total_pagar());
}
