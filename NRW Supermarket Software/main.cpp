#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <exception>

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
std::vector<Gerente*> gerentes;
std::vector<Caixa*> caixas;
std::vector<Estoquista*> estoquistas;
std::vector<Atendente*> atendentes;
std::vector<Carrinho> carrinhos;
std::vector<Venda> vendas;

/* TELAS */
void tela_iniciar_software();
void tela_login(int *add_codigo, std::string *add_senha);
void encontrar_funcionario_logado(int *add_codigo, std::string *add_senha, Funcionario **funcionario_login);
void tela_inicial(Funcionario *funcionario_login);
void tela_encerrar_software();

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

    estoque.adicionar_produto(pr1, 3); 
    estoque.adicionar_produto(pr2, 5);
    estoque.adicionar_produto(pr3, 6);

    // Inicializando objetos da classe Cliente
    Cliente *cl1 = new Cliente(1, "Viviane Silva", "325678435-16", "31 99415-6278", "Av. PH Holfs, 174, Vicosa");
    Cliente *cl2 = new Cliente(2, "Rafael Zardo", "158205782-00", "28 99983-7469", "Rua Estudante, 65, Vicosa");
    Cliente *cl3 = new Cliente(3, "Walter Bueno", "143784539-42", "77 99956-0568", "Av. Santa Rita, 168, Vicosa");

    clientes.push_back(*cl1);
    clientes.push_back(*cl2);
    clientes.push_back(*cl3);

    // Codigos dos gerentes = 1, dos caixas = 2, dos estoquistas = 3, dos atendentes = 4
    // Inicializando os objetos das subclasses de Funcionario

    //Jeito 2: Solucao para o jeito 1 - RFZ
    Gerente gr1(1, "Roberto Costa", 15000, "245987542-87", "Av. Castelo Branco, 43, Vicosa", "roberto.costa@gmail.com", "02/04/1983", "1roberto", true);
    
    gerentes.push_back(&gr1);
    funcionarios.push_back(&gr1);

    Caixa cx1(2, "Ana Clara", 3500, "165378930-72", "Av. Brasil, 12, Vicosa", "clara.lispector@gmail.com", "08/04/2000", "2ana", true);
    Caixa cx2(2, "Toli Ramos", 2000, "124528547-01", "Av. PH Rolfs, 56, Vicosa", "toli.ramos@yahoo.com", "20/06/1996", "2toli", false);

    caixas.push_back(&cx1);
    caixas.push_back(&cx2);
    funcionarios.push_back(&cx1);
    funcionarios.push_back(&cx2);

    Estoquista es1(3, "Flavinho Pneu", 5000, "646233490-80", "Av. Santa Rita, 101, Vicosa", "flavio.pneu@yahoo.com", "01/01/1991", "3flavio", true);

    estoquistas.push_back(&es1);
    funcionarios.push_back(&es1);

    Atendente at1(4, "Pedro Alves", 1200, "342765498-06", "Av. Santo Antonio, 234, Vicosa", "pedro.alves@hotmail.com", "29/02/1992", "4pedro", 20);
    Atendente at2(4, "Maria Catarina", 1350, "062506530-15", "Av. Papa Joao, 322, Vicosa", "maria.catarina@gmail.com", "29/02/1992", "4maria", 20);

    atendentes.push_back(&at1);
    atendentes.push_back(&at2);
    funcionarios.push_back(&at1);
    funcionarios.push_back(&at2);

    // Carrinho *cr1 = new Carrinho();
    // carrinhos.push_back(*cr1);
    // cr1->adicionar_produto(pr1,1);
    // cr1->adicionar_produto(pr2,3);

    // Carrinho *cr2 = new Carrinho();
    // carrinhos.push_back(*cr2);
    // cr2->adicionar_produto(pr1,1);
    // cr2->adicionar_produto(pr2,3);

    // Carrinho *cr3 = new Carrinho();
    // carrinhos.push_back(*cr3);
    // cr2->adicionar_produto(pr1,1);
    // cr2->adicionar_produto(pr2,3);    

    // for (int i = 0; i < carrinhos.size(); i++) {
    //     std::cout << carrinhos[i].get_codigo() << std::endl;
    //     carrinhos[i].exibir_produtos();
    // }

    // Inicio do Software
    int add_codigo;
    std::string add_senha;
    Funcionario *funcionario_login;

    while (true) {

        tela_iniciar_software();

        tela_login(&add_codigo, &add_senha);

        encontrar_funcionario_logado(&add_codigo, &add_senha, &funcionario_login);
        
        tela_inicial(funcionario_login);

    }

}

void tela_iniciar_software() {

    int verificar_acessar_sistema;

    std::cout << "Deseja entrar no sistema NRW Supermarket: \n";
    std::cout << "[1] - Sim \n";
    std::cout << "[2] - Nao\n";
    std::cin >> verificar_acessar_sistema;

    if (verificar_acessar_sistema == 2) {
        tela_encerrar_software();
        exit(0); //Cancela todo programa
    }
}

void tela_encerrar_software() {
    std::cout << "==================\n";
    std::cout << "Obrigado por utilizar nossso Software, volte sempre!\n";
    std::cout << "==================\n";
}

void tela_login(int *add_codigo, std::string *add_senha) {

    int codigo;
    std::string senha;

    std::cout << "Bem Vindo ao sistema NRW Supermarket: \n";
    std::cout << "Digite seu codigo: \n";
    std::cin >> codigo;
    std::cout << "Digite sua senha: \n";
    std::cin >> senha;

    *add_codigo = codigo;
    *add_senha = senha;

}

void encontrar_funcionario_logado(int *add_codigo, std::string *add_senha, Funcionario **funcionario_login) {
    for (int i=0; i < funcionarios.size(); i++) {
        if (funcionarios[i]->get_senha() == *add_senha) {
            *funcionario_login = funcionarios[i];
            std::cout << "Bem Vindo(a), " << (*funcionario_login)->get_nome() << std::endl;
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
            std::cout << "-------------------------------------------\n";

            std::cin >> opcao_escolhida;   // tratamento de excecao

            switch (opcao_escolhida) {
            case 1:
                std::cout << "---------- Administrar Funcionario(a) ----------\n";
                std::cout << "[1] - Cadastrar Funcionario(a) \n";
                std::cout << "[2] - Excluir Funcionario(a) \n";
                std::cout << "[3] - Exibir Dados \n";
                std::cout << "[0] - Voltar \n";
                std::cout << "-------------------------------------------\n";

                std::cin >> opcao_escolhida2;  // tratamento de excecao

                switch (opcao_escolhida2) {
                case 1: {
                    
                    std::cout << "---------- Cadastrar Funcionario(a) ----------\n";  // tratamento de excecao
                    try {
                        int codigo;
                        std::string nome, cpf, endereco, email, data_nascimento, senha, num1;
                        double salario, informacao_extra_comissao;
                        int informacao_extra;
                        bool informacao_extra_construtor;

                        std::cout << "Digite o codigo: \n";
                        std::cout << "[1] - Gerente \n";
                        std::cout << "[2] - Caixa \n";
                        std::cout << "[3] - Estoquista \n";
                        std::cout << "[4] - Atendente \n";
                        std::cin >> codigo;
                        std::cout << "Digite o nome: \n";
                        std::cin >> nome;
                        std::cout << "Digite o salario: \n";
                        std::cin >> salario; 
                        std::cout << "Digite o CPF: \n";
                        std::cin >> cpf;                                       
                        std::cout << "Digite o endereco: \n";
                        std::cin >> endereco;                    
                        std::cout << "Digite o e-mail: \n";
                        std::cin >> email;                    
                        std::cout << "Digite a data de nascimento: \n";
                        std::cin >> data_nascimento;      
                        std::cout << "Digite o senha: \n";
                        std::cin >> senha;

                        if (codigo == 1) {
                            std::cout << "Possui curso superior? \n";
                            std::cout << "[1] - Sim \n";
                            std::cout << "[2] - Nao \n";                        
                            std::cin >> informacao_extra;
                            if (informacao_extra == 1) {
                                informacao_extra_construtor = true;
                            }                        
                            else {
                                informacao_extra_construtor = false;
                            }                                   
                            std::cout << "Digite gr+numero: (ex: gr2) \n";
                            std::cin >> num1;
                            Gerente num1(codigo, nome, salario, cpf, endereco, email, data_nascimento, senha, informacao_extra_construtor);
                            gerentes.push_back(&num1);
                            funcionarios.push_back(&num1);
                        }
                        else if (codigo == 2) {
                            std::cout << "Possui ensino medio completo? (true/false) \n";
                            std::cout << "[1] - Sim \n";
                            std::cout << "[2] - Nao \n";                        
                            std::cin >> informacao_extra;
                            if (informacao_extra == 1) {
                                informacao_extra_construtor = true;
                            }                        
                            else {
                                informacao_extra_construtor = false;
                            }                  
                            std::cout << "Digite cx+numero: (ex: cx2) \n";
                            std::cin >> num1;
                            Caixa num1(codigo, nome, salario, cpf, endereco, email, data_nascimento, senha, informacao_extra_construtor);
                            caixas.push_back(&num1);
                            funcionarios.push_back(&num1);                        
                        }          
                        else if (codigo == 3) {
                            std::cout << "Possui certificado de informatica basica? (true/false) \n";
                            std::cout << "[1] - Sim \n";
                            std::cout << "[2] - Nao \n";                        
                            std::cin >> informacao_extra;
                            if (informacao_extra == 1) {
                                informacao_extra_construtor = true;
                            }                        
                            else {
                                informacao_extra_construtor = false;
                            }                 
                            std::cout << "Digite es+numero: (ex: es2)";
                            std::cin >> num1;
                            Estoquista num1(codigo, nome, salario, cpf, endereco, email, data_nascimento, senha, informacao_extra_construtor);
                            estoquistas.push_back(&num1);
                            funcionarios.push_back(&num1);                        
                        }     
                        else if (codigo == 4) {
                            std::cout << "Qual a comissao? \n";
                            std::cin >> informacao_extra_comissao;
                            std::cout << "Digite at+numero: (ex: at2) \n";
                            std::cin >> num1;
                            Atendente num1(codigo, nome, salario, cpf, endereco, email, data_nascimento, senha, informacao_extra_comissao);
                            atendentes.push_back(&num1);
                            funcionarios.push_back(&num1);                        
                        }
                        else {
                            throw std::invalid_argument("Erro: Nao foi possivel cadastrar esse funcionario! O codigo deve ser somente 1,2,3 ou 4. \n");
                        }
                    }
                    catch (std::invalid_argument &error) {
                        std::cerr << error.what();
                    }                                                                      
                    break;
                }
                case 2: {
                    int codigo, contador;
                    std::string senha;
                    int contador2;

                    try {
                        std::cout << "---------- Excluir Funcionario(a) ----------\n";
                        std::cout << "Digite o codigo do funcionario que deseja exluir: \n";
                        std::cin >> codigo;
                        std::cout << "Digite a senha do funcionario que deseja excluir: \n";
                        std::cin >> senha;

                        for (contador = 0; contador < funcionarios.size(); contador++) {
                            if (funcionarios[contador]->get_senha() == senha) {
                                funcionarios.erase(funcionarios.begin() + contador);
                                std::cout << "Funcionario deleteado com sucesso! \n";
                                break;
                            }
                        }

                        if (codigo == 1) {
                            for (contador = 0; contador < gerentes.size(); contador++) {
                                if (gerentes[contador]->get_senha() ==  senha) {
                                    gerentes.erase(gerentes.begin() + contador);
                                    break;
                                }
                            }
                        }
                        else if (codigo == 2) {
                            for (contador = 0; contador < caixas.size(); contador++) {
                                if (caixas[contador]->get_senha() ==  senha) {
                                    caixas.erase(caixas.begin() + contador);
                                    break;
                                }
                            }
                        }
                        else if (codigo == 3) {
                            for (contador = 0; contador < estoquistas.size(); contador++) {
                                if (estoquistas[contador]->get_senha() ==  senha) {
                                    estoquistas.erase(estoquistas.begin() + contador);
                                    break;
                                }
                            }
                        }
                        else if (codigo == 4) {
                            for (contador = 0; contador < atendentes.size(); contador++) {
                                if (atendentes[contador]->get_senha() ==  senha) {
                                    atendentes.erase(atendentes.begin() + contador);
                                    break;
                                }
                            }
                        }
                        else {
                            throw std::invalid_argument("Erro: Nao foi possivel excluir esse funcionario! O codigo deve ser somente 1,2,3 ou 4. \n");
                        }

                    }
                    catch (std::invalid_argument &error) {
                        std::cerr << error.what();
                    }                    
                    break;
                }

                case 3: {

                    std::cout << "---------- Exibir Dados ----------\n";

                    for (int contador = 0; contador < funcionarios.size(); contador++) {
                            funcionarios[contador]->exibir_dados();
                            std::cout << std::endl;
                    }
                    break;
                }

                case 0:
                    break;
                
                default:
                    break;
                }

                break;

            case 2:{
                std::cout << "---------- Administrar Estoque ----------\n";
                std::cout << "[1] - Adicionar Produto \n";
                std::cout << "[2] - Excluir Produto \n";
                std::cout << "[3] - Exibir Estoque \n";
                std::cout << "[4] - Procurar Produto \n";
                std::cout << "[0] - Voltar \n";
                std::cout << "-------------------------------------------\n";
                  
                std::cin >> opcao_escolhida2;
                 int quantidade1 = 0;
                switch (opcao_escolhida2) {
                case 1: {
                    std::cout << "---------- Adicionar Produto ----------\n"; //tratamento de erro associado a digitaçao errada de dados;
                      int __codigo;
                        std::string __nome,__validade,__marca;
                        double __preco;
                        
                        
                        std::cout << "Digite o codigo do produto: " << std::endl;
                        std::cin >> __codigo;
                        std::cout << "Digite o nome do produto: " << std::endl;
                        std::cin >> __nome;
                        std::cout << "Digite o preco do produto: " << std::endl;  
                        std::cin >> __preco;
                        std::cout << "Digite a marca do produto: " << std::endl;
                        std::cin >> __marca;
                        std::cout << "Digite a validade do produto: " << std::endl;
                        std::cin >> __validade;
                        std::cout << "Digite a quantidade: " << std::endl;
                        std::cin >> quantidade1;
                        
                        Produto *pr = new Produto(__codigo,__nome,__preco,__marca,__validade);
                        
                        estoque.adicionar_produto(pr,quantidade1); //Seria melhor passar no Estoque.h para passar por &,ja que é um ponteiro;
                }
                    break;
                
                case 2:{
                    std::cout << "---------- Excluir Produto ----------\n"; //pensando a respeito disso ainda
                    int _codigo,quantidade;
                    std::cout << "Digite o codigo e a quantidade do produto que deseja excluir" << std::endl;
                     std::cin >> _codigo;
                     std::cin >> quantidade;
                     estoque.excluir_produto(_codigo,quantidade);

                }
                    break;

                case 3:
                    std::cout << "---------- Exibir Estoque ----------\n";
                    estoque.exibir_estoque();
                    break;
                
                case 4:{
                    std::cout << "---------- Procurar Produto ----------\n";//tratar erro associado a digitaçao errada de dados
                    int _codigo1; 
                    std::cout << "Digite o codigo do produto que deseja procurar: " << std::endl;
                    std::cin >> _codigo1;
                    bool existir = estoque.procurar_produto(_codigo1);
                     if(!(existir)){
                        std::cout << "Produto inexistente no estoque" << std::endl;
                     }
                }
                    break;
                
                case 0:
                    break;
                
                default:
                    break;
                }
                break;                
            }
            case 3:
                std::cout << "---------- Administrar Clientes ----------\n";
                std::cout << "[1] - Cadastrar Cliente \n";
                std::cout << "[2] - Excluir Cliente \n";
                std::cout << "[3] - Exibir Dados \n";
                std::cout << "[0] - Voltar \n";
                std::cout << "-------------------------------------------\n";

                std::cin >> opcao_escolhida2;

                switch (opcao_escolhida2) {
                case 1: {
                    std::cout << "---------- Cadastrar Cliente ----------\n";

                    try {
                        int codigo2;
                        std::string nome2, cpf2, telefone, endereco2, _num2;

                        std::cout << "Digite o codigo: \n";
                        std::cin >> codigo2;
                        std::cout << "Digite o nome: \n";
                        std::cin >> nome2;
                        std::cout << "Digite o CPF: \n";
                        std::cin >> cpf2;
                        std::cout << "Digite o telefone: \n";
                        std::cin >> telefone;
                        std::cout << "Digite o endereco: \n";
                        std::cin >> endereco2;
                        std::cout << "Digite cl+numero: (ex: cl4) \n";
                        std::cin >> _num2;

                        for (int i=0; i < clientes.size(); i++) {
                            if (clientes[i].get_codigo() == codigo2) {
                                throw std::invalid_argument("Codigo invalido! Ja esta sendo utilizado por outro cliente. \n");
                            }
                        }

                        Cliente *num2 = new Cliente(codigo2, nome2, cpf2, telefone, endereco2);
                        clientes.push_back(*num2);

                    } 
                    catch(std::invalid_argument &error) {
                        std::cerr << error.what();
                    }

                    break;
                }
                
                case 2: {
                    std::cout << "---------- Excluir Cliente ----------\n";

                    try {
                        int codigo, contador;
                        std::string senha;
                        int contador2;

                        std::cout << "Digite o codigo do cliente que deseja exluir: \n";
                        std::cin >> codigo;

                        for (int i=0; i < clientes.size(); i++) {
                            if (clientes[i].get_codigo() != codigo) {
                                throw std::invalid_argument("Codigo invalido! Nao existe um cliente com esse codigo. \n");
                            }
                        }

                        for (contador = 0; contador < clientes.size(); contador++) {
                            if (clientes[contador].get_codigo() == codigo) {
                                clientes.erase(clientes.begin() + contador);
                                std::cout << "Cliente deleteado com sucesso! \n";
                                break;
                            }
                        }
                    }
                    catch(std::invalid_argument &error) {
                        std::cerr << error.what();
                    }

                    break;
                }

                case 3:
                    std::cout << "---------- Exibir Dados ----------\n";

                    for (int contador = 0; contador < clientes.size(); contador++) {
                            clientes[contador].exibir_dados();
                            std::cout << std::endl;
                    }

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
                std::cout << "[4] - Imprimir Nota Fiscal \n";
                std::cout << "[0] - Voltar \n";
                std::cout << "-------------------------------------------\n";

                std::cin >> opcao_escolhida2;

                switch (opcao_escolhida2) {
                case 1: {
                    std::cout << "---------- Cadastrar Venda ----------\n";

                    int forma_pagamento, cliente_atendido_codigo, carrinho_codigo, codigo;
                    double valor_recebido;
                    std::string data, atendente_consultado_senha, numero_venda;
                    Cliente *cliente_atendido;
                    Atendente *atendente_consultado;
                    Carrinho *carrinho;

                    std::cout << "Digite o codigo da venda: \n";
                    std::cin >> codigo;
                    std::cout << "Digite a forma de pagamento: \n";
                    std::cout << "[1] - Cartao de Credito (a vista) \n";
                    std::cout << "[2] - Dinheiro (a vista) \n";
                    std::cin >> forma_pagamento;
                    std::cout <<  "Digite o valor recebido: \n"; //Pensar em troco
                    std::cin >> valor_recebido;
                    std::cout << "Digite a data: \n";
                    std::cin >> data;
                    std::cout << "Digite o codigo do cliente atendido: \n";
                    std::cin >> cliente_atendido_codigo;

                    for (int i = 0; i < clientes.size(); i++) {
                        if (clientes[i].get_codigo() == cliente_atendido_codigo) {
                            cliente_atendido = &clientes[i];
                            break;
                        }
                    }

                    // cliente_atendido->exibir_dados();

                    std::cout << "Digite a senha do atendente consultado: \n";
                    std::cin >> atendente_consultado_senha;   

                    for (int i = 0; i < atendentes.size(); i++) {
                        if (atendentes[i]->get_senha() == atendente_consultado_senha) {
                            atendente_consultado = atendentes[i];
                            break;
                        }
                    }                

                    // atendente_consultado->exibir_dados();    

                    std::cout << "Digite o codigo do carrinho: \n";
                    std::cin >> carrinho_codigo;   

                    for (int i = 0; i < carrinhos.size(); i++) {
                        if (carrinhos[i].get_codigo() == carrinho_codigo) {
                            carrinho = &carrinhos[i];
                            break;
                        }
                    }                         

                    std::cout << "Digite o vn+numero (ex: vn3): \n";
                    std::cin >> numero_venda;

                    Venda *numero_venda_construtor = new Venda(codigo, forma_pagamento, data, cliente_atendido, atendente_consultado, valor_recebido, carrinho);
                    vendas.push_back(*numero_venda_construtor);

                    numero_venda_construtor->calcula_troco();
                    
                    break;
                }
                
                case 2:
                    std::cout << "---------- Excluir Venda ----------\n";
                    
                    int codigo;

                    std::cout << "Digite o codigo da venda: \n";
                    std::cin >> codigo;

                    for (int i = 0; i < vendas.size(); i++) {
                        if (vendas[i].get_codigo() == codigo) {
                            vendas.erase(vendas.begin() + i);
                            break;
                        }
                    }                    

                    break;

                case 3: {
                    std::cout << "---------- Exibir Vendas ----------\n"; //Qual o proposito ? - RFZ
                    vendas[vendas.size()-1].exibir_vendas(); //Adequando a funcao RFZ
                    break;
                }

                case 4: {
                    std::cout << "---------- Imprimir Nota Fiscal ----------\n";
                    
                    int codigo;

                    std::cout << "Digite o codigo da venda: \n";
                    std::cin >> codigo;

                    for (int i = 0; i < vendas.size(); i++) {
                        if (vendas[i].get_codigo() == codigo) {
                            vendas[i].imprimir_nota_fiscal();
                            break;
                        }
                    }
                    break;
                }
                
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
            std::cout << "-------------------------------------------\n";

            std::cin >> opcao_escolhida;

            switch (opcao_escolhida) {
            case 1:
                std::cout << "---------- Administrar Clientes ----------\n";
                std::cout << "[1] - Cadastrar Cliente \n";
                std::cout << "[2] - Excluir Cliente \n";
                std::cout << "[3] - Exibir Dados \n";
                std::cout << "[0] - Voltar \n";
                std::cout << "-------------------------------------------\n";

                std::cin >> opcao_escolhida2;

                switch (opcao_escolhida2) {
                case 1: {
                    std::cout << "---------- Cadastrar Cliente ----------\n";

                    try {
                        int codigo2;
                        std::string nome2, cpf2, telefone, endereco2, _num2;

                        std::cout << "Digite o codigo: \n";
                        std::cin >> codigo2;
                        std::cout << "Digite o nome: \n";
                        std::cin >> nome2;
                        std::cout << "Digite o CPF: \n";
                        std::cin >> cpf2;
                        std::cout << "Digite o telefone: \n";
                        std::cin >> telefone;
                        std::cout << "Digite o endereco: \n";
                        std::cin >> endereco2;
                        std::cout << "Digite cl+numero: (ex: cl4) \n";
                        std::cin >> _num2;

                        for (int i=0; i < clientes.size(); i++) {
                            if (clientes[i].get_codigo() == codigo2) {
                                throw std::invalid_argument("Codigo invalido! Ja esta sendo utilizado por outro cliente. \n");
                            }
                        }

                        Cliente *num2 = new Cliente(codigo2, nome2, cpf2, telefone, endereco2);
                        clientes.push_back(*num2);

                    } 
                    catch(std::invalid_argument &error) {
                        std::cerr << error.what();
                    }

                    break;
                }
                
                case 2: {
                    std::cout << "---------- Excluir Cliente ----------\n";

                    int codigo, contador;
                    std::string senha;
                    int contador2;

                    std::cout << "Digite o codigo do cliente que deseja exluir: \n";
                    std::cin >> codigo;

                    for (contador = 0; contador < clientes.size(); contador++) {
                        if (clientes[contador].get_codigo() == codigo) {
                            clientes.erase(clientes.begin() + contador);
                            std::cout << "Cliente deleteado com sucesso! \n";
                            break;
                        }
                    }

                    break;
                }
                case 3:
                    std::cout << "---------- Exibir Dados ----------\n";

                    for (int contador = 0; contador < clientes.size(); contador++) {
                            clientes[contador].exibir_dados();
                            std::cout << std::endl;
                    }

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
                std::cout << "[4] - Imprimir Nota Fiscal \n";                
                std::cout << "[0] - Voltar \n";
                std::cout << "-------------------------------------------\n";

                std::cin >> opcao_escolhida2;

                switch (opcao_escolhida2) {
                case 1: {
                    std::cout << "---------- Cadastrar Venda ----------\n";

                    int forma_pagamento, cliente_atendido_codigo, carrinho_codigo, codigo;
                    double valor_recebido;
                    std::string data, atendente_consultado_senha, numero_venda;
                    Cliente *cliente_atendido;
                    Atendente *atendente_consultado;
                    Carrinho *carrinho;

                    std::cout << "Digite o codigo da venda: \n";
                    std::cin >> codigo;
                    std::cout << "Digite a forma de pagamento: \n";
                    std::cout << "[1] - Cartao de Credito (a vista) \n";
                    std::cout << "[2] - Dinheiro (a vista) \n";
                    std::cin >> forma_pagamento;
                    std::cout <<  "Digite o valor recebido: \n"; //Pensar em troco
                    std::cin >> valor_recebido;
                    std::cout << "Digite a data: \n";
                    std::cin >> data;
                    std::cout << "Digite o codigo do cliente atendido: \n";
                    std::cin >> cliente_atendido_codigo;

                    for (int i = 0; i < clientes.size(); i++) {
                        if (clientes[i].get_codigo() == cliente_atendido_codigo) {
                            cliente_atendido = &clientes[i];
                            break;
                        }
                    }

                    // cliente_atendido->exibir_dados();

                    std::cout << "Digite a senha do atendente consultado: \n";
                    std::cin >> atendente_consultado_senha;   

                    for (int i = 0; i < atendentes.size(); i++) {
                        if (atendentes[i]->get_senha() == atendente_consultado_senha) {
                            atendente_consultado = atendentes[i];
                            break;
                        }
                    }                

                    // atendente_consultado->exibir_dados();    

                    std::cout << "Digite o codigo do carrinho: \n";
                    std::cin >> carrinho_codigo;   

                    for (int i = 0; i < carrinhos.size(); i++) {
                        if (carrinhos[i].get_codigo() == carrinho_codigo) {
                            carrinho = &carrinhos[i];
                            break;
                        }
                    }                         

                    std::cout << "Digite o vn+numero (ex: vn3): \n";
                    std::cin >> numero_venda;

                    Venda *numero_venda_construtor = new Venda(codigo, forma_pagamento, data, cliente_atendido, atendente_consultado, valor_recebido, carrinho);
                    vendas.push_back(*numero_venda_construtor);

                    numero_venda_construtor->calcula_troco();                    
                    break;
                }
                
                case 2: {
                    std::cout << "---------- Excluir Venda ----------\n";

                    int codigo;

                    std::cout << "Digite o codigo da venda: \n";
                    std::cin >> codigo;

                    for (int i = 0; i < vendas.size(); i++) {
                        if (vendas[i].get_codigo() == codigo) {
                            vendas.erase(vendas.begin() + i);
                            break;
                        }
                    }    
                    break;
                }

                case 3: {
                    std::cout << "---------- Exibir Vendas ----------\n"; //Qual o proposito ? - RFZ
                    vendas[vendas.size()-1].exibir_vendas(); //Adequando a funcao RFZ
                    break;
                }

                case 4:
                    std::cout << "---------- Imprimir Nota Fiscal ----------\n";
                    
                    int codigo;

                    std::cout << "Digite o codigo da venda: \n";
                    std::cin >> codigo;

                    for (int i = 0; i < vendas.size(); i++) {
                        if (vendas[i].get_codigo() == codigo) {
                            vendas[i].imprimir_nota_fiscal();
                            break;
                        }
                    }                
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
            std::cout << "-------------------------------------------\n";

            std::cin >> opcao_escolhida;

            if (opcao_escolhida == 1) {
                std::cout << "---------- Administrar Estoque ----------\n";
                std::cout << "[1] - Adicionar Produto \n";
                std::cout << "[2] - Excluir Produto \n";
                std::cout << "[3] - Exibir Estoque \n";
                std::cout << "[4] - Procurar Produto \n";
                std::cout << "[0] - Voltar \n";

                std::cin >> opcao_escolhida2;
                 int quantidade1 = 0;
                switch (opcao_escolhida2) {
                case 1:{
                    std::cout << "---------- Adicionar Produto ----------\n";
                     int __codigo;
                        std::string __nome,__validade,__marca;
                        double __preco;
                        
                        
                        std::cout << "Digite o codigo do produto: " << std::endl;
                        std::cin >> __codigo;
                        std::cout << "Digite o nome do produto: " << std::endl;
                        std::cin >> __nome;
                        std::cout << "Digite o preco do produto: " << std::endl;  
                        std::cin >> __preco;
                        std::cout << "Digite a marca do produto: " << std::endl;
                        std::cin >> __marca;
                        std::cout << "Digite a validade do produto: " << std::endl;
                        std::cin >> __validade;
                        std::cout << "Digite a quantidade: " << std::endl;
                        std::cin >> quantidade1;
                        
                        Produto *pr = new Produto(__codigo,__nome,__preco,__marca,__validade);
                        
                        estoque.adicionar_produto(pr,quantidade1); 
                    
                }
                    break;
                
                case 2:{
                    std::cout << "---------- Excluir Produto ----------\n"; 
                    int _codigo,quantidade;
                    std::cout << "Digite o codigo e a quantidade do produto que deseja excluir" << std::endl;
                     std::cin >> _codigo;
                     std::cin >> quantidade;
                     estoque.excluir_produto(_codigo,quantidade);
                }
                    break;

                case 3:
                    std::cout << "---------- Exibir Estoque ----------\n";
                    estoque.exibir_estoque();
                    break;
                
                case 4:{
                    std::cout << "---------- Procurar Produto ----------\n";//tratar erro associado a digitaçao errada de dados
                    int _codigo1; 
                    std::cout << "Digite o codigo do produto que deseja procurar: " << std::endl;
                    std::cin >> _codigo1;
                    bool existir = estoque.procurar_produto(_codigo1);
                       if(!(existir)){
                          std::cout << "Produto inexistente no estoque" << std::endl;
                     }
                }
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
            std::cout << "-------------------------------------------\n";

            std::cin >> opcao_escolhida;

            switch (opcao_escolhida) {
            case 1:
                std::cout << "---------- Exibir Estoque ----------\n";
                estoque.exibir_estoque();
                break;
            
            case 2:{
                std::cout << "---------- Procurar Produto ----------\n";//tratar erro associado a digitaçao errada de dados
                int _codigo1; 
                std::cout << "Digite o codigo do produto que deseja procurar: " << std::endl;
                std::cin >> _codigo1;
                bool existir = estoque.procurar_produto(_codigo1);
                    if(!(existir)){
                        std::cout << "Produto inexistente no estoque" << std::endl;
                    }
                } 
                break;
            
            default:
                break;
            }
        }

    } while (opcao_escolhida != 0);
    
}
