#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "Atendente.h"
#include "Caixa.h"
#include "Carrinho.h"
#include "Cliente.h"
#include "Estoque.h"
#include "Estoquista.h"
#include "Funcionario.h"
#include "Produto.h"
#include "Venda.h"
#include "Gerente.h"

/* BASE DE DADOS */
Estoque estoque;
std::vector<Cliente> clientes;
std::vector<Funcionario> funcionarios;
std::vector<Gerente> gerentes;
std::vector<Caixa> caixas;
std::vector<Estoquista> estoquistas;
std::vector<Atendente> atendentes;
std::vector<Carrinho> carrinhos;
std::vector<Venda> vendas;

/* TELAS */
void encontrar_funcionado_logado(int add_codigo, int add_senha, Funcionario *funcionario_login) {}
void tela_inicial(Funcionario *funcionario_login) {}

int main(void) {

    // Inicializando objetos da classe Produto
    Produto *pr1 = new Produto(1, "Macarrao", 19.90, "09/22", "Barilla");
    Produto *pr2 = new Produto(2, "Arroz", 21.90, "04/23", "Rei Arthur");
    Produto *pr3 = new Produto(3, "Feijao", 25.90, "05/22", "Camil");

    //estoque.adicionar_produto(pr1, 3);
    //estoque.adicionar_produto(pr2, 5);
    //estoque.adicionar_produto(pr3, 6);

    // Inicializando objetos da classe Cliente
    Cliente *cl1 = new Cliente(1, "Viviane Silva", "325678435-16", "31 99415-6278", "Av. PH Holfs, 174, Vicosa");
    Cliente *cl2 = new Cliente(2, "Rafael Zardo", "158205782-00", "28 99983-7469", "Rua Estudante, 65, Vicosa");
    Cliente *cl3 = new Cliente(3, "Walter Bueno", "143784539-42", "77 99956-0568", "Av. Santa Rita, 168, Vicosa");

    clientes.push_back(*cl1);
    clientes.push_back(*cl2);
    clientes.push_back(*cl3);

    // Codigos dos gerentes = 1, dos caixas = 2, dos estoquistas = 3, dos atendentes = 4
    // Inicializando os objetos das subclasses de Funcionario
    Gerente *gr1 = new Gerente(1, "Roberto Costa", 15000, "245987542-87", "Av. Castelo Branco, 43, Vicosa", "roberto.costa@gmail.com", "02/04/1983", "1roberto", true);

    gerentes.push_back(*gr1);
    funcionarios.push_back(*gr1);

    Caixa *cx1 = new Caixa(2, "Ana Clara", 3500, "165378930-72", "Av. Brasil, 12, Vicosa", "clara.lispector@gmail.com", "08/04/2000", "2ana", true);
    Caixa *cx2 = new Caixa(2, "Toli Ramos", 2000, "124528547-01", "Av. PH Rolfs, 56, Vicosa", "toli.ramos@yahoo.com", "20/06/1996", "2toli", false);

    caixas.push_back(*cx1);
    caixas.push_back(*cx2);
    funcionarios.push_back(*cx1);
    funcionarios.push_back(*cx2);

    Estoquista *es1 = new Estoquista(3, "Flavinho Pneu", 5000, "646233490-80", "Av. Santa Rita, 101, Vicosa", "flavio.pneu@yahoo.com", "01/01/1991", "3flavio", true);

    estoquistas.push_back(*es1);
    funcionarios.push_back(*es1);

    Atendente *at1 = new Atendente(4, "Pedro Alves", 1200, "342765498-06", "Av. Santo Antonio, 234, Vicosa", "pedro.alves@hotmail.com", "29/02/1992", "3pedro", 20);
    Atendente *at2 = new Atendente(4, "Maria Catarina", 1350, "062506530-15", "Av. Papa Joao, 322, Vicosa", "maria.catarina@gmail.com", "29/02/1992", "3maria", 20);

    atendentes.push_back(*at1);
    atendentes.push_back(*at2);
    funcionarios.push_back(*at1);
    funcionarios.push_back(*at2);

    // Inicio do Software
    int add_codigo;
    std::string add_senha;
    Funcionario *funcionario_login;

    std::cout << "Bem Vindo ao sistema NRW Supermarket: \n";
    std::cout << "Digite seu codigo e senha: \n";

    // Tratamento de execao - Nt
    std::cin >> add_codigo;
    std::cin >> add_senha;

    encontrar_funcionado_logado(add_codigo, add_senha, funcionario_login);

    std::cout << "Bem Vindo(a), " << funcionario_login->get_nome();

    tela_inicial(funcionario_login);
}

void encontrar_funcionado_logado(int add_codigo, std::string add_senha, Funcionario *funcionario_login) {
    for (int i=0; i < funcionarios.size(); i++) {
        if (funcionarios[i].get_senha() == add_senha) {
            funcionario_login = &funcionarios[i];
            break;
        }
    }
}

void tela_inicial(Funcionario *funcionario_login) {
    int opcao_escolhida;
    std::cout << "----------Tela Inicial----------\n";
    do {
        if (funcionario_login->get_codigo() == 1) {        // Gerente
            std::cout << "[1] - Administrar Funcionario(a) \n";
            std::cout << "[2] - Adiministrar Estoque \n";
            std::cout << "[3] - Adiministrar Clientes \n";
            std::cout << "[4] - Adiministrar Vendas \n";
            std::cout << "[0] - Sair \n";
        }
        else if (funcionario_login->get_codigo() == 2) {        // Caixa
            std::cout << "[3] - Adiministrar Clientes \n";
            std::cout << "[4] - Adiministrar Vendas \n";
            std::cout << "[0] - Sair \n";
        }
        else if (funcionario_login->get_codigo() == 3) {        // Estoquista
            std::cout << "[2] - Adiministrar Estoque \n";
            std::cout << "[0] - Sair \n";
        }
        else if (funcionario_login->get_codigo() == 4) {        // Atendente
            std::cout << "[5] - Consultar Estoque \n";
            std::cout << "[6] - Consultar Comissao \n";
            std::cout << "[0] - Sair \n";
        }
        // tratamento de execao
        std::cin >> opcao_escolhida;

        

    } while (opcao_escolhida != 0);
}