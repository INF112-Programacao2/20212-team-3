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
std::vector<Funcionario*> funcionarios;
std::vector<Gerente> gerentes;
std::vector<Caixa> caixas;
std::vector<Estoquista> estoquistas;
std::vector<Atendente> atendentes;
std::vector<Carrinho> carrinhos;
std::vector<Venda> vendas;

/* TELAS */
void tela_login(int *add_codigo, std::string *add_senha);
void encontrar_funcionario_logado(int *add_codigo, std::string *add_senha, Funcionario **funcionario_login);
void tela_inicial(Funcionario *funcionario_login);

int main(void) {

    // Inicializando objetos da classe Produto
    Produto *pr1 = new Produto(1, "Macarrao", 19.90, "09/22", "Barilla");
    Produto *pr2 = new Produto(2, "Arroz", 21.90, "04/23", "Rei Arthur");
    Produto *pr3 = new Produto(3, "Feijao", 25.90, "05/22", "Camil");
    Produto *pr4 = new Produto(4, "Sabao em Po", 11.00, "07/22", "Omo");
    Produto *pr5 = new Produto(5, "Oleo", 10.00, "10/22", "Soia");
    Produto *pr6 = new Produto(6, "Sabonete", 3.00, "05/22", "Lux");
    Produto *pr7 = new Produto(7, "File de Peito de Frango", 17.00, "12/22", "Uniaves");
    Produto *pr8 = new Produto(8, "Biscoito Recheado", 5.00, "11/22", "Oreo");
    Produto *pr9 = new Produto(9, "Pasta de Dente", 4.00, "10/22", "Colgate");
    Produto *pr10 = new Produto(10, "Cup Noodles", 10.00, "07/23", "Nissin");
    Produto *pr11 = new Produto(11, "Miojo", 2.00, "10/23", "Nissin");
    Produto *pr12 = new Produto(12, "Leite Condensado", 10.00, "03/22", "Piracanjuba");
    Produto *pr13 = new Produto(13, "Doce de Leite", 25.00, "10/22", "Vicosa");

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
    
    // Jeito 1: Nao consegui encontrar solucao para o funcionarios.push_back(*gr1), por isso esta comentado. - RFZ
    Gerente *gr1 = new Gerente(1, "Roberto Costa", 15000, "245987542-87", "Av. Castelo Branco, 43, Vicosa", "roberto.costa@gmail.com", "02/04/1983", "1roberto", true);
    gerentes.push_back(*gr1);
    // funcionarios.push_back(*gr1);

    //Jeito 2: Solucao para o jeito 1 - RFZ
    Gerente gr2(1, "Roberto Costa", 15000, "245987542-87", "Av. Castelo Branco, 43, Vicosa", "roberto.costa@gmail.com", "02/04/1983", "1roberto", true);
    funcionarios.push_back(&gr2);

    Caixa *cx1 = new Caixa(2, "Ana Clara", 3500, "165378930-72", "Av. Brasil, 12, Vicosa", "clara.lispector@gmail.com", "08/04/2000", "2ana", true);
    Caixa *cx2 = new Caixa(2, "Toli Ramos", 2000, "124528547-01", "Av. PH Rolfs, 56, Vicosa", "toli.ramos@yahoo.com", "20/06/1996", "2toli", false);

    caixas.push_back(*cx1);
    caixas.push_back(*cx2);
    // funcionarios.push_back(*cx1);
    // funcionarios.push_back(*cx2);

    Estoquista *es1 = new Estoquista(3, "Flavinho Pneu", 5000, "646233490-80", "Av. Santa Rita, 101, Vicosa", "flavio.pneu@yahoo.com", "01/01/1991", "3flavio", true);

    estoquistas.push_back(*es1);
    // funcionarios.push_back(*es1);

    Atendente *at1 = new Atendente(4, "Pedro Alves", 1200, "342765498-06", "Av. Santo Antonio, 234, Vicosa", "pedro.alves@hotmail.com", "29/02/1992", "3pedro", 20);
    Atendente *at2 = new Atendente(4, "Maria Catarina", 1350, "062506530-15", "Av. Papa Joao, 322, Vicosa", "maria.catarina@gmail.com", "29/02/1992", "3maria", 20);

    atendentes.push_back(*at1);
    atendentes.push_back(*at2);
    // funcionarios.push_back(*at1);
    // funcionarios.push_back(*at2);

    // Inicio do Software
    int add_codigo;
    std::string add_senha;
    Funcionario *funcionario_login;

    tela_login(&add_codigo, &add_senha);

    encontrar_funcionario_logado(&add_codigo, &add_senha, &funcionario_login);

    std::cout << "Bem Vindo(a), " << funcionario_login->get_nome() << std::endl;
    
    tela_inicial(funcionario_login);
}

void tela_login(int *add_codigo, std::string *add_senha) {

    int codigo;
    std::string senha;

    std::cout << "Bem Vindo ao sistema NRW Supermarket: \n";
    std::cout << "Digite seu codigo e senha: \n";

    // Tratamento de execao - Nt
    std::cin >> codigo;
    std::cin >> senha;

    *add_codigo = codigo;
    *add_senha = senha;

}

void encontrar_funcionario_logado(int *add_codigo, std::string *add_senha, Funcionario **funcionario_login) {
    for (int i=0; i < funcionarios.size(); i++) {
        if (funcionarios[i]->get_senha() == *add_senha) {
            *funcionario_login = funcionarios[i];
            break;
        }
    }
}

void tela_inicial(Funcionario *funcionario_login) {
    int opcao_escolhida;
    int opcao_escolhida2;
    do {
        if (funcionario_login->get_codigo() == 1) {        // Gerente
            std::cout << "---------- Tela Inicial Gerente ----------\n";
            std::cout << "[1] - Administrar Funcionario(a) \n";
            std::cout << "[2] - Adiministrar Estoque \n";
            std::cout << "[3] - Adiministrar Clientes \n";
            std::cout << "[4] - Adiministrar Vendas \n";
            std::cout << "[0] - Sair \n";

            std::cin >> opcao_escolhida;   // tratamento de excecao

            switch (opcao_escolhida) {
            case 1:
                std::cout << "---------- Administrar Funcionario(a) ----------\n";
                std::cout << "[1] - Cadastrar Funcionario(a) \n";
                std::cout << "[2] - Excluir Funcionario(a) \n";
                std::cout << "[3] - Exibir Dados \n";
                std::cout << "[4] - Atualizar Dados \n";
                std::cout << "[0] - Voltar \n";

                std::cin >> opcao_escolhida2;  // tratamento de excecao

                switch (opcao_escolhida2) {
                case 1:
                    std::cout << "---------- Cadastrar Funcionario(a) ----------\n";  // tratamento de excecao
                    break;

                case 2:
                    std::cout << "---------- Excluir Funcionario(a) ----------\n";
                    break;

                case 3:
                    std::cout << "---------- Exibir Dados ----------\n";
                    break;

                case 4:
                    std::cout << "---------- Atualizar Dados ----------\n";
                    break;

                case 0:
                    break;
                
                default:
                    break;
                }

                break;

            case 2:
                std::cout << "---------- Administrar Estoque ----------\n";
                std::cout << "[1] - Adicionar Produto \n";
                std::cout << "[2] - Excluir Produto \n";
                std::cout << "[3] - Exibir Estoque \n";
                std::cout << "[4] - Procurar Produto \n";
                std::cout << "[0] - Voltar \n";

                std::cin >> opcao_escolhida2;

                switch (opcao_escolhida2) {
                case 1:
                    std::cout << "---------- Adicionar Produto ----------\n";
                    break;
                
                case 2:
                    std::cout << "---------- Excluir Produto ----------\n";
                    break;

                case 3:
                    std::cout << "---------- Exibir Estoque ----------\n";
                    break;
                
                case 4:
                    std::cout << "---------- Procurar Produto ----------\n";
                    break;
                
                case 0:
                    break;
                
                default:
                    break;
                }
                break;                

            case 3:
                std::cout << "---------- Administrar Clientes ----------\n";
                std::cout << "[1] - Cadastrar Cliente \n";
                std::cout << "[2] - Excluir Cliente \n";
                std::cout << "[3] - Exibir Dados \n";
                std::cout << "[4] - Atualizar Dados \n";
                std::cout << "[0] - Voltar \n";

                std::cin >> opcao_escolhida2;

                switch (opcao_escolhida2) {
                case 1:
                    std::cout << "---------- Cadastrar Cliente ----------\n";
                    break;
                
                case 2:
                    std::cout << "---------- Excluir Cliente ----------\n";
                    break;

                case 3:
                    std::cout << "---------- Exibir Dados ----------\n";
                    break;
                
                case 4:
                    std::cout << "---------- Atualizar Dados ----------\n";
                    break;
                
                case 0:
                    break;
                
                default:
                    break;
                }
                break;                

            case 4:
                std::cout << "---------- Administrar Vendas ----------\n";
                std::cout << "[1] - Cadastrar Venda \n";
                std::cout << "[2] - Excluir Venda \n";
                std::cout << "[3] - Exibir Vendas \n";
                std::cout << "[0] - Voltar \n";

                std::cin >> opcao_escolhida2;

                switch (opcao_escolhida2) {
                case 1:
                    std::cout << "---------- Cadastrar Venda ----------\n";
                    break;
                
                case 2:
                    std::cout << "---------- Excluir Venda ----------\n";
                    break;

                case 3:
                    std::cout << "---------- Exibir Vendas ----------\n";
                    break;
                
                case 0:
                    break;
                
                default:
                    break;
                }
                break;                
            
            default:
                break;
            }
        }
        else if (funcionario_login->get_codigo() == 2) {        // Caixa
            std::cout << "---------- Tela Inicial Caixa ----------\n";        
            std::cout << "[1] - Adiministrar Clientes \n";
            std::cout << "[2] - Adiministrar Vendas \n";
            std::cout << "[0] - Sair \n";

            std::cin >> opcao_escolhida;

            switch (opcao_escolhida) {
            case 1:
                std::cout << "---------- Administrar Clientes ----------\n";
                std::cout << "[1] - Cadastrar Cliente \n";
                std::cout << "[2] - Excluir Cliente \n";
                std::cout << "[3] - Exibir Dados \n";
                std::cout << "[4] - Atualizar Dados \n";
                std::cout << "[0] - Voltar \n";

                std::cin >> opcao_escolhida2;

                switch (opcao_escolhida2) {
                case 1:
                    std::cout << "---------- Cadastrar Cliente ----------\n";
                    break;
                
                case 2:
                    std::cout << "---------- Excluir Cliente ----------\n";
                    break;

                case 3:
                    std::cout << "---------- Exibir Dados ----------\n";
                    break;
                
                case 4:
                    std::cout << "---------- Atualizar Dados ----------\n";
                    break;
                
                case 0:
                    break;
                
                default:
                    break;
                }
                break;
            
            case 2:
                std::cout << "---------- Administrar Vendas ----------\n";
                std::cout << "[1] - Cadastrar Venda \n";
                std::cout << "[2] - Excluir Venda \n";
                std::cout << "[3] - Exibir Vendas \n";
                std::cout << "[0] - Voltar \n";

                std::cin >> opcao_escolhida2;

                switch (opcao_escolhida2) {
                case 1:
                    
                    std::cout << "---------- Cadastrar Venda ----------\n";
                    break;
                
                case 2:
                    std::cout << "---------- Excluir Venda ----------\n";
                    break;

                case 3:
                    std::cout << "---------- Exibir Vendas ----------\n";
                    break;
                
                case 0:
                    break;
                
                default:
                    break;
                }
                break;                
            
            default:
                break;
            }
        }
        else if (funcionario_login->get_codigo() == 3) {        // Estoquista
            std::cout << "---------- Tela Inicial Estoquista ----------\n";        
            std::cout << "[1] - Adiministrar Estoque \n";
            std::cout << "[0] - Sair \n";

            std::cin >> opcao_escolhida;

            if (opcao_escolhida == 1) {
                std::cout << "---------- Administrar Estoque ----------\n";
                std::cout << "[1] - Adicionar Produto \n";
                std::cout << "[2] - Excluir Produto \n";
                std::cout << "[3] - Exibir Estoque \n";
                std::cout << "[4] - Procurar Produto \n";
                std::cout << "[0] - Voltar \n";

                std::cin >> opcao_escolhida2;

                switch (opcao_escolhida2) {
                case 1:
                    std::cout << "---------- Adicionar Produto ----------\n";
                    break;
                
                case 2:
                    std::cout << "---------- Excluir Produto ----------\n";
                    break;

                case 3:
                    std::cout << "---------- Exibir Estoque ----------\n";
                    break;
                
                case 4:
                    std::cout << "---------- Procurar Produto ----------\n";
                    break;
                
                case 0:
                    break;
                
                default:
                    break;
                }
            }
            else {
                break;
            }
        }
        else if (funcionario_login->get_codigo() == 4) {        // Atendente
            std::cout << "---------- Tela Inicial Atendente ----------\n";        
            std::cout << "[1] - Exibir Estoque \n";
            std::cout << "[2] - Procurar Produto \n";
            std::cout << "[0] - Sair \n";

            std::cin >> opcao_escolhida;

            switch (opcao_escolhida) {
            case 1:
                std::cout << "---------- Exibir Estoque ----------\n";
                break;
            
            case 2:
                std::cout << "---------- Procurar Produto ----------\n";
                break;
            
            default:
                break;
            }
        }

    } while (opcao_escolhida != 0);
    
}