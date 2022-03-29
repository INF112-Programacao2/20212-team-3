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
std::vector<Produto*> produtos;
std::vector<Cliente> clientes;
std::vector<Funcionario*> funcionarios;
std::vector<Gerente*> gerentes;
std::vector<Caixa*> caixas;
std::vector<Estoquista*> estoquistas;
std::vector<Atendente*> atendentes;
std::vector<Carrinho*> carrinhos;
std::vector<Venda*> vendas;

/* TELAS */
void tela_iniciar_software(int *verifica_acesso);
void tela_login(int *add_codigo, std::string *add_senha);
void encontrar_funcionario_logado(int *add_codigo, std::string *add_senha, Funcionario **funcionario_login);
void tela_funcionario(Funcionario *funcionario_login);
void tela_encerrar_software();
void tela_cliente();

int main(void) {

    // Inicializando objetos da classe Produto
    Produto *pr1 = new Produto(1, "Macarrao", 19.90, "09/22", "Barilla");
    Produto *pr2 = new Produto(2, "Arroz", 21.90, "04/23", "Rei Arthur");
    Produto *pr3 = new Produto(3, "Feijao", 25.90, "05/22", "Camil");
    Produto *pr4 = new Produto(4, "Sabao em Po", 11.00, "07/22", "Omo");
    Produto *pr5 = new Produto(5, "Oleo", 10.00, "10/22", "Soya");
    Produto *pr6 = new Produto(6, "Sabonete", 3.00, "05/22", "Lux");
    Produto *pr7 = new Produto(7, "File de Peito de Frango", 17.00, "12/22", "Uniaves");
    Produto *pr8 = new Produto(8, "Biscoito Recheado", 5.00, "11/22", "Oreo");
    Produto *pr9 = new Produto(9, "Pasta de Dente", 4.00, "10/22", "Colgate");
    Produto *pr10 = new Produto(10, "Cup Noodles", 10.00, "07/23", "Nissin");
    Produto *pr11 = new Produto(11, "Miojo", 2.00, "10/23", "Nissin");
    Produto *pr12 = new Produto(12, "Leite Condensado", 10.00, "03/22", "Piracanjuba");
    Produto *pr13 = new Produto(13, "Doce de Leite", 25.00, "10/22", "Vicosa");

    //Adiciona os produtos no vector de produtos
    produtos.push_back(pr1);
    produtos.push_back(pr2);
    produtos.push_back(pr3);
    produtos.push_back(pr4);
    produtos.push_back(pr5);
    produtos.push_back(pr6);
    produtos.push_back(pr7);
    produtos.push_back(pr8);
    produtos.push_back(pr9);
    produtos.push_back(pr10);
    produtos.push_back(pr11);
    produtos.push_back(pr12);
    produtos.push_back(pr13);

    // Adiciona os produtos no estoque
    estoque.adicionar_produto(pr1,3); 
    estoque.adicionar_produto(pr2,5);
    estoque.adicionar_produto(pr3,6);
    estoque.adicionar_produto(pr4,10);
    estoque.adicionar_produto(pr5,2); 
    estoque.adicionar_produto(pr6,20);
    estoque.adicionar_produto(pr7,40);
    estoque.adicionar_produto(pr8,10);
    estoque.adicionar_produto(pr9,30); 
    estoque.adicionar_produto(pr10,25);
    estoque.adicionar_produto(pr11,35);
    estoque.adicionar_produto(pr12,46);
    estoque.adicionar_produto(pr13,22);

    // Inicializando objetos da classe Cliente
    Cliente *cl1 = new Cliente(1, "Viviane Silva", "325678435-16", "31 99415-6278", "Av. PH Holfs, 174, Vicosa");
    Cliente *cl2 = new Cliente(2, "Rafael Zardo", "158205782-00", "28 99983-7469", "Rua Estudante, 65, Vicosa");
    Cliente *cl3 = new Cliente(3, "Walter Bueno", "143784539-42", "77 99956-0568", "Av. Santa Rita, 168, Vicosa");

    // Adiciona os clientes no vector clientes
    clientes.push_back(*cl1);
    clientes.push_back(*cl2);
    clientes.push_back(*cl3);

    // Codigos dos gerentes = 1, dos caixas = 2, dos estoquistas = 3, dos atendentes = 4

    // Inicializando os objetos das subclasses de Funcionario
    Gerente gr1(1, "Roberto Costa", 15000, "245987542-87", "Av. Castelo Branco, 43, Vicosa", "roberto.costa@gmail.com", "02/04/1983", "1roberto", true);
    
    // Adiciona o gerente no vector gerentes e no vector funcionarios
    gerentes.push_back(&gr1);
    funcionarios.push_back(&gr1);

    Caixa cx1(2, "Ana Clara", 3500, "165378930-72", "Av. Brasil, 12, Vicosa", "clara.lispector@gmail.com", "08/04/2000", "2ana", true);
    Caixa cx2(2, "Toli Ramos", 2000, "124528547-01", "Av. PH Rolfs, 56, Vicosa", "toli.ramos@yahoo.com", "20/06/1996", "2toli", false);

    // Adiciona os caixas no vector caixas e no vector funcionarios
    caixas.push_back(&cx1);
    caixas.push_back(&cx2);
    funcionarios.push_back(&cx1);
    funcionarios.push_back(&cx2);

    Estoquista es1(3, "Flavinho Pneu", 5000, "646233490-80", "Av. Santa Rita, 101, Vicosa", "flavio.pneu@yahoo.com", "01/01/1991", "3flavio", true);

    // Adiciona o estoquista no vector estoquistas e no vector funcionarios
    estoquistas.push_back(&es1);
    funcionarios.push_back(&es1);

    Atendente at1(4, "Pedro Alves", 1200, "342765498-06", "Av. Santo Antonio, 234, Vicosa", "pedro.alves@hotmail.com", "29/02/1992", "4pedro", 20);
    Atendente at2(4, "Maria Catarina", 1350, "062506530-15", "Av. Papa Joao, 322, Vicosa", "maria.catarina@gmail.com", "29/02/1992", "4maria", 20);

    // Adiciona os atendentes no vector atendentes e no vector funcionarios
    atendentes.push_back(&at1);
    atendentes.push_back(&at2);
    funcionarios.push_back(&at1);
    funcionarios.push_back(&at2);

    // Inicio do Software

    int add_codigo;
    std::string add_senha;
    Funcionario *funcionario_login;
    int verificar_acesso;

    while (true) {

        tela_iniciar_software(&verificar_acesso);

        if (verificar_acesso == 0) {
            tela_encerrar_software();
            // Deletando objetos alocados dinamicamente
            delete pr1;
            delete pr2;
            delete pr3;
            delete pr4;
            delete pr5;
            delete pr6;
            delete pr7;
            delete pr8;
            delete pr9;
            delete pr10;
            delete pr11;
            delete pr12;
            delete pr13;
            delete cl1;
            delete cl2;
            delete cl3;

            // Deletando itens alocados nos vectors (vectors ficam vazios)
            funcionarios.clear();
            gerentes.clear();
            caixas.clear();
            atendentes.clear();
            estoquistas.clear();
            carrinhos.clear();
            clientes.clear();
            vendas.clear();

            exit(0); // Interrompe o programa
        }

        if (verificar_acesso == 2) {
            tela_cliente();
        }

        if (verificar_acesso == 1) {
            tela_login(&add_codigo, &add_senha);

            encontrar_funcionario_logado(&add_codigo, &add_senha, &funcionario_login);
            
            tela_funcionario(funcionario_login);
        }
    }

}

void tela_iniciar_software(int *verificar_acesso) {

    int verificar_acessar_sistema;

    std::cout << "Deseja entrar no sistema NRW Supermarket: \n";
    std::cout << "[1] - Sim (eh Funcionario) \n";
    std::cout << "[2] - Sim (eh Cliente) \n";
    std::cout << "[0] - Nao\n";
    std::cin >> verificar_acessar_sistema;

    // Verifica se foi digitado uma opcao valida
    while (verificar_acessar_sistema != 0 && verificar_acessar_sistema != 1 && verificar_acessar_sistema != 2) {
        std::cout << "Deseja entrar no sistema NRW Supermarket: \n";
        std::cout << "[1] - Sim (Funcionario) \n";
        std::cout << "[2] - Sim (Cliente) \n";
        std::cout << "[0] - Nao\n";
        std::cin >> verificar_acessar_sistema;
    }

    if (verificar_acessar_sistema == 0) {
        *verificar_acesso = 0;
        return;
    }

    *verificar_acesso = verificar_acessar_sistema;
}

void tela_encerrar_software() {
    std::cout << "==================\n";
    std::cout << "Obrigado por utilizar nossso Software, volte sempre!\n";
    std::cout << "==================\n";
}

void tela_login(int *add_codigo, std::string *add_senha) {

    int codigo;
    std::string senha;

    while (true) {
        try {
            bool existe_funcionario = false;

            std::cout << "Bem Vindo ao sistema NRW Supermarket: \n" << std::endl;
            std::cout << "Para ter acesso a lista de usuarios (senha e codigos) Acesse a pagina funcionarios do nosso website:\n";
            std::cout << "https://inf112-programacao2.github.io/20212-team-3/NRW%20Supermarket%20Web/index.html\n" << std::endl;

            std::cout << "Digite seu codigo: \n";
            std::cin >> codigo;
            std::cout << "Digite sua senha: \n";
            std::cin >> senha;

            // Verifica se existe um funcionario com a senha e codigo digitado
            for (int i=0; i < funcionarios.size(); i++) {
                if (funcionarios[i]->get_codigo() == codigo && funcionarios[i]->get_senha() ==  senha) {
                    existe_funcionario = true;
                    break;
                }
            }

            // Tratamento de excecao se nao existir funcionario com o esse codigo e/ou senha
            if (existe_funcionario == false) {
                throw std::invalid_argument("Erro: Nao existe um funcionario com esse codigo e/ou senha. \n");
            }
            // Para o loop se foi digitado uma senha e codigo valido
            else {
                break;
            }
        }
        catch (std::invalid_argument &error) {
            std::cerr << error.what() << std::endl;
        }
    }

    // Passa adiante os valores da senha e codigo digitados
    *add_codigo = codigo;
    *add_senha = senha;

}

void encontrar_funcionario_logado(int *add_codigo, std::string *add_senha, Funcionario **funcionario_login) {
    // Percorre o vector funcionarios para encontrar qual o funcionario que entrou no sistema
    for (int i=0; i < funcionarios.size(); i++) {
        if (funcionarios[i]->get_senha() == *add_senha) {
            *funcionario_login = funcionarios[i];

            std::cout << "Bem Vindo(a), ";

            if (*add_codigo == 1)
                std::cout << "Gerente ";
            else if (*add_codigo == 2)
                std::cout << "Caixa ";
            else if (*add_codigo == 3)
                std::cout << "Estoquista ";
            else
                std::cout << "Atendente ";

            std::cout << (*funcionario_login)->get_nome() << std::endl;
            break;
        }
    }
}

// funcao para o cliente criar/excluir um carrinho de compras e para adicionar/remover produtos do carrinho
void tela_cliente() {

    int opcao_escolhida;
    int opcao_escolhida2;

    do {
        std::cout << "---------- Tela Inicial Cliente ----------\n";
        std::cout << "[1] - Admistrar Carrinho \n";
        std::cout << "[0] - Sair \n";

        std::cin >> opcao_escolhida;

        switch (opcao_escolhida) {
        case 1: {

                std::cout << "---------- Administrar Carrinho ----------\n";
                std::cout << "[1] - Criar Carrinho \n";
                std::cout << "[2] - Excluir Carrinho \n";
                std::cout << "[3] - Adicionar Produto no Carrinho \n";
                std::cout << "[4] - Remover Produto do Carrinho \n";
                std::cout << "[0] - Voltar\n";

                std::cin >> opcao_escolhida2;

                switch (opcao_escolhida2) {
                case 1: {

                    std::cout << "---------- Criar Carrinho ----------\n";

                    Carrinho *cr = new Carrinho();
    
                    carrinhos.push_back(cr);

                    std::cout << "O codigo do seu carrinho eh: " << cr->get_codigo() << std::endl;
                    std::cout << std::endl;
                    break;
                }

                case 2: {

                    std::cout << "---------- Excluir Carrinho ----------\n";

                    try {
                        int codigo_carrinho;
                        bool existe_carrinho = false;

                        std::cout << "Digite o codigo do carrinho que deseja excluir: \n";
                        std::cin >> codigo_carrinho;

                        // deleta o carrinho
                        for (int i = 0; i < carrinhos.size(); i++) {
                            if (carrinhos[i]->get_codigo() == codigo_carrinho) {
                                carrinhos.erase(carrinhos.begin()+i);
                                std::cout << "Carrinho excluido com sucesso! \n";
                                existe_carrinho = true;
                                break;
                            }
                        }
                        // verifica se tem um carrinho com esse codigo
                        if (existe_carrinho == false) {
                            throw std::invalid_argument("Erro: Nao existe carrinho com esse codigo! \n");
                        }
                    }
                    catch (std::invalid_argument &erro) {
                        std::cerr << erro.what() << std::endl;
                    }

                    break;
                }

                case 3: {

                    std::cout << "---------- Adicionar Produto no Carrinho ----------\n";

                    try {
                        int codigo_produto;
                        int codigo_carrinho;
                        int quantidade;
                        bool existe_carrinho = false;
                        bool existe_produto = false;

                        Carrinho* carrinho_suporte;

                        std::cout << "Digite o codigo do seu carrinho: \n";
                        std::cin >> codigo_carrinho;

                        // carrinho_suporte aponta para o carrinho desejado
                        for (int i = 0; i < carrinhos.size(); i++) {
                            if (carrinhos[i]->get_codigo() == codigo_carrinho) {
                                carrinho_suporte = carrinhos[i];
                                existe_carrinho = true;
                                break;
                            }
                        }

                        std::cout << "Os codigos dos produtos disponivies no estoque sao: \n" << std::endl;
                        estoque.exibir_estoque_reduzido();

                        while (true) {

                            std::cout << "Digite o codigo do produto que deseja comprar (Digite -1 para encerrar): \n";
                            std::cin >> codigo_produto;

                            if (codigo_produto == -1) {
                                break;
                            }

                            std::cout << "Digite a quantidade desse produto que deseja comprar: \n";
                            std::cin >> quantidade;

                            for (int i = 0; i < produtos.size(); i++) {
                                if (produtos[i]->get_codigo() == codigo_produto) {
                                    carrinho_suporte->adicionar_produto(produtos[i],quantidade);   // adiciona produto e sua quantidade no carrinho
                                    estoque.excluir_produto(codigo_produto,quantidade);   // exclui a quantidade do produto adicionado no carrinho do estoque
                                    existe_produto = true;
                                    break;
                                }
                            }

                            // verifica se tem um carrinho com esse codigo
                            if (existe_carrinho == false) {
                                throw std::invalid_argument("Erro: Nao existe carrinho com esse codigo. \n");
                            }

                            // verifica se tem um produto com esse codigo
                            if (existe_produto == false) {
                                throw std::invalid_argument("Erro: Nao existe produto com esse codigo. \n");
                            }                      
                        }
                    }
                    catch (std::invalid_argument &erro) {
                        std::cerr << erro.what() << std::endl;
                    } 

                    break;
                }

                case 4: {
                    std::cout << "---------- Remover Produto do Carrinho ----------\n";                    

                    try {
                        int codigo_produto;
                        int codigo_carrinho;
                        int quantidade;
                        bool existe_carrinho = false;
                        bool existe_produto = false;

                        Carrinho* carrinho_suporte;

                        std::cout << "Digite o codigo do seu carrinho (Digite -1 para encerrar): \n";
                        std::cin >> codigo_carrinho;

                        if (codigo_produto == -1) {
                                break;
                            }

                        // carrinho_suporte aponta para o carrinho desejado
                        for (int i = 0; i < carrinhos.size(); i++) {
                            if (carrinhos[i]->get_codigo() == codigo_carrinho) {
                                carrinho_suporte = carrinhos[i];
                                existe_carrinho = true;
                                break;
                            }
                        }

                        while (true) {

                            std::cout << "Digite o codigo do produto que deseja excluir: \n";
                            std::cin >> codigo_produto;

                            std::cout << "Digite a quantidade desse produto que deseja excluir: \n";
                            std::cin >> quantidade;

                            for (int i = 0; i < produtos.size(); i++) {
                                if (produtos[i]->get_codigo() == codigo_produto) {
                                    carrinho_suporte->remover_produto(produtos[i],quantidade); // remove o produto e sua quantidade do carrinho
                                    estoque.adicionar_produto(produtos[i],quantidade); // adiciona o produto e sua quantidade removida do carrinho de volta ao estoque
                                    existe_produto = true;
                                    break;
                                }
                            }                      
                        }

                        if (existe_carrinho == false) {
                            throw std::invalid_argument("Erro: Nao existe carrinho com esse codigo. \n");
                        }

                        if (existe_produto == false) {
                            throw std::invalid_argument("Erro: Nao existe produto com esse codigo. \n");
                        }
                    }
                    catch (std::invalid_argument &erro) {
                        std::cerr << erro.what() << std::endl;
                    }

                    break;
                }

                default:
                    std::cout << "Opcao invalida! \n";
                    break;
                }

                break;
            }

            case 0:
                break;

            default:
                std::cout << "Opcao invalida! \n";
                break;
        }
    }
    while (opcao_escolhida != 0);
}

void tela_funcionario(Funcionario *funcionario_login) {
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

            std::cin >> opcao_escolhida;

            switch (opcao_escolhida) {
            case 1:
                std::cout << "---------- Administrar Funcionario(a) ----------\n";
                std::cout << "[1] - Cadastrar Funcionario(a) \n";
                std::cout << "[2] - Excluir Funcionario(a) \n";
                std::cout << "[3] - Exibir Dados \n";
                std::cout << "[4] - Procurar Funcionario(a) \n";
                std::cout << "[0] - Voltar \n";
                std::cout << "-------------------------------------------\n";

                std::cin >> opcao_escolhida2; 

                switch (opcao_escolhida2) {
                case 1: {
                    
                    std::cout << "---------- Cadastrar Funcionario(a) ----------\n";
                    try {
                        int codigo;
                        std::string nome, cpf, endereco, email, data_nascimento, senha;
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
                        std::cin.ignore();
                        std::getline(std::cin,nome);
                        std::cout << "Digite o salario: \n";
                        std::cin >> salario; 
                        std::cout << "Digite o CPF: \n";
                        std::cin.ignore();
                        std::getline(std::cin,cpf);                                      
                        std::cout << "Digite o endereco: \n";
                        std::getline(std::cin,endereco);                    
                        std::cout << "Digite o e-mail: \n";
                        std::getline(std::cin,email);                    
                        std::cout << "Digite a data de nascimento: \n";
                        std::getline(std::cin,data_nascimento);    
                        std::cout << "Digite o senha: \n";
                        std::getline(std::cin,senha);

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

                            Gerente *num1 = new Gerente (codigo, nome, salario, cpf, endereco, email, data_nascimento, senha, informacao_extra_construtor);
                            gerentes.push_back(num1);
                            funcionarios.push_back(num1);
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
                            Caixa *num2 = new Caixa (codigo, nome, salario, cpf, endereco, email, data_nascimento, senha, informacao_extra_construtor);
                            caixas.push_back(num2);
                            funcionarios.push_back (num2);                        
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
                            Estoquista *num2 = new Estoquista (codigo, nome, salario, cpf, endereco, email, data_nascimento, senha, informacao_extra_construtor);
                            estoquistas.push_back(num2);
                            funcionarios.push_back(num2);                        
                        }     
                        else if (codigo == 4) {
                            std::cout << "Qual a comissao? \n";
                            std::cin >> informacao_extra_comissao;

                            Atendente *num2 = new Atendente (codigo, nome, salario, cpf, endereco, email, data_nascimento, senha, informacao_extra_comissao);
                            atendentes.push_back(num2);
                            funcionarios.push_back(num2);                        
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
                    std::cout << "---------- Excluir Funcionario(a) ----------\n";

                    int codigo, contador;
                    std::string senha;
                    int contador2;

                    try {
                        std::cout << "Digite o codigo do funcionario que deseja exluir: \n";
                        std::cin >> codigo;
                        std::cout << "Digite a senha do funcionario que deseja excluir: \n";
                        std::cin.ignore();
                        std::getline(std::cin, senha);

                        for (contador = 0; contador < funcionarios.size(); contador++) {
                            if (funcionarios[contador]->get_senha() == senha && funcionarios[contador]->get_codigo() == codigo) {
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

                    if (funcionarios.size() > 0) {
                        for (int contador = 0; contador < funcionarios.size(); contador++) {
                                funcionarios[contador]->exibir_dados();
                                std::cout << std::endl;
                        }
                    }
                    else {
                        std::cout << "Nao existe funcionarios cadastrados. \n";
                    }
                    break;
                }

                case 4: {

                    std::cout << "---------- Procurar Funcionario(a) ----------\n";

                    try {
                        int codigo;
                        std::string senha;
                        bool funcionario_existe = false;

                        std::cout << "Digite o codigo do funcionario: \n";
                        std::cin >> codigo;
                        std::cout << "Digite a senha do funcionario: \n";
                        std::cin.ignore();
                        std::getline(std::cin, senha);

                        for (int i = 0; i < funcionarios.size(); i++) {
                            if (funcionarios[i]->get_senha() == senha && funcionarios[i]->get_codigo() == codigo) {
                                funcionario_existe = true;
                                funcionarios[i]->exibir_dados();
                                break;
                            }
                        }

                        if (funcionario_existe == false) {
                            throw std::invalid_argument("Erro: Funcionario nao encontrado. Nao existe nenhum fucionario com esse codigo e senha. \n");
                        }
                    }
                    catch (std::invalid_argument &error) {
                        std::cout << error.what();
                    }
                    break;
                }

                case 0:
                    break;
                
                default:
                    std::cout << "Opcao invalida! \n";
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
                    std::cout << "---------- Adicionar Produto ----------\n";

                    try {
                        int codigo;
                        std::string nome, validade, marca;
                        double preco;
                            
                            
                        std::cout << "Digite o codigo do produto: " << std::endl;
                        std::cin >> codigo;
                        std::cout << "Digite o nome do produto: " << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin,nome);
                        std::cout << "Digite o preco do produto: " << std::endl;  
                        std::cin >> preco;
                        std::cout << "Digite a validade do produto: " << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin, validade);
                        std::cout << "Digite a marca do produto: " << std::endl;
                        std::getline(std::cin, marca);
                        std::cout << "Digite a quantidade: " << std::endl;
                        std::cin >> quantidade1;

                        if (estoque.verificar_codigo(codigo) == true) {
                            throw std::invalid_argument("Erro: Ja existe um produto com esse codigo.\n");
                        }

                        if (estoque.verificar_codigo(codigo) == false) {
                            Produto *pr = new Produto(codigo, nome, preco, validade, marca);
                            estoque.adicionar_produto(pr,quantidade1);
                            produtos.push_back(pr);
                        }
                    }
                    catch (std::invalid_argument &erro) {
                        std::cerr << erro.what() << std::endl;
                    }
                }
                    break;
                
                case 2: {
                    std::cout << "---------- Excluir Produto ----------\n";

                    try {
                        int codigo, quantidade;
                        std::cout << "Digite o codigo: \n";
                        std::cin >> codigo;
                        std::cout << "Digite a quantidade que deseja excluir: \n";
                        std::cin >> quantidade;
                        if (estoque.verificar_codigo(codigo) == false) {
                            throw std::invalid_argument("Erro: Nao foi possivel excluir esse produto. Nao existe nenhum produto com esse codigo. \n");
                        }
                        else {
                            estoque.excluir_produto(codigo,quantidade);
                            std::cout << "Produto excluido com sucesso! \n";
                        }
                    } 
                    catch(std::invalid_argument &error) {
                        std::cout << error.what();
                    }
                }
                    break;

                case 3:
                    std::cout << "---------- Exibir Estoque ----------\n";
                    estoque.exibir_estoque();
                    break;
                
                case 4: {
                    std::cout << "---------- Procurar Produto ----------\n";
                    int codigo1; 
                    std::cout << "Digite o codigo do produto que deseja procurar: " << std::endl;
                    std::cin >> codigo1;
                    bool existir = estoque.procurar_produto(codigo1);
                     if(!(existir)){
                        std::cout << "Produto inexistente no estoque" << std::endl;
                     }
                }
                    break;
                
                case 0:
                    break;
                
                default:
                    std::cout << "Opcao invalida! \n";
                    break;
                }
                break;                
            }
            case 3:
                std::cout << "---------- Administrar Clientes ----------\n";
                std::cout << "[1] - Cadastrar Cliente \n";
                std::cout << "[2] - Excluir Cliente \n";
                std::cout << "[3] - Exibir Dados \n";
                std::cout << "[4] - Procurar Cliente \n";
                std::cout << "[0] - Voltar \n";
                std::cout << "-------------------------------------------\n";

                std::cin >> opcao_escolhida2;

                switch (opcao_escolhida2) {
                case 1: {
                    std::cout << "---------- Cadastrar Cliente ----------\n";

                    try {
                        int codigo;
                        std::string nome, cpf, telefone, endereco;

                        std::cout << "Digite o codigo: \n";
                        std::cin >> codigo;
                        std::cout << "Digite o nome: \n";
                        std::cin.ignore();
                        std::getline(std::cin, nome);
                        std::cout << "Digite o CPF: \n";
                        std::getline(std::cin, cpf);
                        std::cout << "Digite o telefone: \n";
                        std::getline(std::cin, telefone);
                        std::cout << "Digite o endereco: \n";
                        std::getline(std::cin, endereco);

                        for (int i=0; i < clientes.size(); i++) {
                            if (clientes[i].get_codigo() == codigo) {
                                throw std::invalid_argument("Codigo invalido! Ja esta sendo utilizado por outro cliente. \n");
                            }
                        }

                        Cliente *num2 = new Cliente(codigo, nome, cpf, telefone, endereco);
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
                        int codigo;
                        bool existe = false;

                        std::cout << "Digite o codigo do cliente que deseja exluir: \n";
                        std::cin >> codigo;

                        for (int i=0; i < clientes.size(); i++) {
                            if (clientes[i].get_codigo() == codigo) {
                                existe = true;
                                break;
                            }
                        }

                        if (existe == false) {
                            throw std::invalid_argument("Erro: Nao foi possivel deletar esse cliente. Nao existe nenhum cliente com esse codigo. \n");
                        }

                        for (int i = 0; i < clientes.size(); i++) {
                            if (clientes[i].get_codigo() == codigo) {
                                clientes.erase(clientes.begin() + i);
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

                case 3: {
                    std::cout << "---------- Exibir Dados ----------\n";

                    if (clientes.size() > 0) {
                        for (int i = 0; i < clientes.size(); i++) {
                                clientes[i].exibir_dados();
                                std::cout << std::endl;
                        }
                    }
                    else {
                        std::cout << "Nao existe clientes cadastrados. \n";
                    }

                    break;
                }

                case 4: {

                    std::cout << "---------- Procurar Cliente ----------\n";

                    try {
                        int codigo;
                        bool cliente_existe = false;

                        std::cout << "Digite o codigo do cliente: \n";
                        std::cin >> codigo;

                        for (int i = 0; i < clientes.size(); i++) {
                            if (clientes[i].get_codigo() == codigo) {
                                cliente_existe = true;
                                clientes[i].exibir_dados();
                                break;
                            }
                        }

                        if (cliente_existe == false) {
                            throw std::invalid_argument("Erro: Cliente nao encontrado. Nao existe nenhum cliente com esse codigo. \n");
                        }
                    }
                    catch (std::invalid_argument &error) {
                        std::cout << error.what();
                    }
                    break;
                }
                
                case 0:
                    break;
                
                default:
                    std::cout << "Opcao invalida! \n";
                    break;
                }
                break;                

            case 4:
                std::cout << "---------- Administrar Vendas ----------\n";
                std::cout << "[1] - Cadastrar Venda \n";
                std::cout << "[2] - Excluir Venda \n";
                std::cout << "[3] - Exibir Vendas \n";
                std::cout << "[4] - Procurar Venda \n";
                std::cout << "[0] - Voltar \n";
                std::cout << "-------------------------------------------\n";

                std::cin >> opcao_escolhida2;

                switch (opcao_escolhida2) {
                case 1: {
                    std::cout << "---------- Cadastrar Venda ----------\n";

                    try {
                        int forma_pagamento, cliente_atendido_codigo, carrinho_codigo, codigo;
                        double valor_recebido;
                        std::string data, atendente_consultado_senha;
                        Cliente *cliente_atendido;
                        Atendente *atendente_consultado;
                        Carrinho *carrinho;
                        bool existe_cliente = false, existe_atendente = false, existe_carrinho = false;

                        std::cout << "Digite o codigo da venda: \n";
                        std::cin >> codigo;
                        std::cout << "Digite a forma de pagamento: \n";
                        std::cout << "[1] - Cartao de Credito (a vista) \n";
                        std::cout << "[2] - Dinheiro (a vista) \n";
                        std::cin >> forma_pagamento;
                        std::cout <<  "Digite o valor recebido: \n";
                        std::cin >> valor_recebido;
                        std::cout << "Digite a data: \n";
                        std::cin.ignore();
                        std::getline(std::cin, data);
                        std::cout << "Digite o codigo do cliente atendido: \n";
                        std::cin >> cliente_atendido_codigo;

                        for (int i=0; i < vendas.size(); i++) {
                            if (vendas[i]->get_codigo() == codigo) {
                                throw std::invalid_argument("Erro: Nao foi possivel cadastrar essa venda. Ja esta sendo utilizado esse codigo. \n");
                            }
                        }

                        for (int i = 0; i < clientes.size(); i++) {
                            if (clientes[i].get_codigo() == cliente_atendido_codigo) {
                                existe_cliente = true;
                                cliente_atendido = &clientes[i];
                                break;
                            }
                        }

                        if (existe_cliente == false) {
                            throw std::invalid_argument("Erro: Nao existe nenhum cliente com esse codigo. \n");
                        }

                        std::cout << "Digite a senha do atendente consultado: \n";
                        std::cin >> atendente_consultado_senha;   

                        for (int i = 0; i < atendentes.size(); i++) {
                            if (atendentes[i]->get_senha() == atendente_consultado_senha) {
                                existe_atendente = true;
                                atendente_consultado = atendentes[i];
                                break;
                            }
                        }

                        if (existe_atendente == false) {
                            throw std::invalid_argument("Erro: Nao existe nenhum atendente com essa senha. \n");
                        }                

                        std::cout << "Digite o codigo do carrinho: \n";
                        std::cin >> carrinho_codigo;   

                        for (int i = 0; i < carrinhos.size(); i++) {
                            if (carrinhos[i]->get_codigo() == carrinho_codigo) {
                                existe_carrinho = true;
                                carrinho = carrinhos[i];
                                break;
                            }
                        }

                        if (existe_carrinho == false) {
                            throw std::invalid_argument("Erro: Nao existe nenhum carrinho com esse codigo. \n");
                        }                         

                        Venda *venda_construtor = new Venda(codigo, forma_pagamento, data, cliente_atendido, atendente_consultado, valor_recebido, carrinho);
                        vendas.push_back(venda_construtor);

                        venda_construtor->calcula_troco();
                    }
                    catch(std::invalid_argument &error) {
                        std::cout << error.what();
                    }

                    break;
                }
                
                case 2:
                    std::cout << "---------- Excluir Venda ----------\n";
                    
                    try {
                        int codigo;
                        bool existe = false;

                        std::cout << "Digite o codigo da venda: \n";
                        std::cin >> codigo;

                        for (int i=0; i < vendas.size(); i++) {
                            if (vendas[i]->get_codigo() == codigo) {
                                existe = true;
                                break;
                            }
                        }

                        if (existe == false){
                            throw std::invalid_argument("Erro: Nao foi possivel excluir essa venda. Nao existe nenhuma venda com esse codigo. \n");
                        }

                        for (int i = 0; i < vendas.size(); i++) {
                            if (vendas[i]->get_codigo() == codigo) {
                                vendas.erase(vendas.begin() + i);
                                std::cout << "Venda excluida com sucesso! \n";
                                break;
                            }
                        }
                    }
                    catch(std::invalid_argument &error) {
                        std::cout << error.what();
                    }                    

                    break;

                case 3: {
                    std::cout << "---------- Exibir Vendas ----------\n";

                    if (vendas.size() > 0) {
                        double receita_total = 0;
                        int quantidade_vendas = 0;

                        for (int i = 0; i < vendas.size(); i++) {
                            std::cout << "Codigo da Venda: " << vendas[i]->get_codigo() << std::endl;
                            std::cout << "Receita da Venda: R$" << vendas[i]->get_valor_total_pagar() << std::endl;   
                            std::cout << "---------------- \n";              
                            receita_total += vendas[i]->get_valor_total_pagar();       
                            quantidade_vendas++;
                        }

                        std::cout << "Quantidade total de vendas: " << quantidade_vendas << std::endl;
                        std::cout << "Receita total das vendas: R$" << receita_total << std::endl;
                    }

                    else {
                        std::cout << "Nao existe vendas cadastradas! \n";
                    }

                    break;
                }

                case 4: {
                    std::cout << "---------- Procurar Venda ----------\n";
                    
                    try {
                        int codigo;
                        bool existe_venda = false;

                        std::cout << "Digite o codigo da venda: \n";
                        std::cin >> codigo;

                        for (int i = 0; i < vendas.size(); i++) {
                            if (vendas[i]->get_codigo() == codigo) {
                                existe_venda = true;
                                vendas[i]->imprimir_nota_fiscal();
                                break;
                            }
                        }

                        if (existe_venda == false) {
                            throw std::invalid_argument("Erro: Nao foi possivel imprimir a nota fiscal dessa venda. Nao existe nehuma venda com esse codigo. \n");
                        }
                    }
                    catch (std::invalid_argument &error) {
                        std::cout << error.what();
                    }

                    break;
                }
                
                case 0:
                    break;
                
                default:
                    std::cout << "Opcao invalida! \n";
                    break;
                }
                break;

            case   0:
                break;              
            
            default:
                std::cout << "Opcao invalida! \n";
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
                std::cout << "[4] - Procurar Cliente \n";
                std::cout << "[0] - Voltar \n";
                std::cout << "-------------------------------------------\n";

                std::cin >> opcao_escolhida2;

                switch (opcao_escolhida2) {
                case 1: {
                    std::cout << "---------- Cadastrar Cliente ----------\n";

                    try {
                        int codigo;
                        std::string nome, cpf, telefone, endereco;

                        std::cout << "Digite o codigo: \n";
                        std::cin >> codigo;
                        std::cout << "Digite o nome: \n";
                        std::getline(std::cin, nome);
                        std::cout << "Digite o CPF: \n";
                        std::getline(std::cin, cpf);
                        std::cout << "Digite o telefone: \n";
                        std::getline(std::cin, telefone);
                        std::cout << "Digite o endereco: \n";
                        std::getline(std::cin, endereco);

                        for (int i=0; i < clientes.size(); i++) {
                            if (clientes[i].get_codigo() == codigo) {
                                throw std::invalid_argument("Codigo invalido! Ja esta sendo utilizado por outro cliente. \n");
                            }
                        }

                        Cliente *num2 = new Cliente(codigo, nome, cpf, telefone, endereco);
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
                        int codigo;
                        bool existe_cliente = false;

                        std::cout << "Digite o codigo do cliente que deseja exluir: \n";
                        std::cin >> codigo;

                        for (int i = 0; i < clientes.size(); i++) {
                            if (clientes[i].get_codigo() == codigo) {
                                existe_cliente = true;
                                clientes.erase(clientes.begin() + i);
                                std::cout << "Cliente deleteado com sucesso! \n";
                                break;
                            }
                        }

                        if (existe_cliente == false) {
                            throw std::invalid_argument("Erro: Nao foi possivel excluir esse cliente. Nao existe nenhum cliente com esse codigo. \n");
                        }
                    }
                    catch (std::invalid_argument &error) {
                        std::cout << error.what();
                    }

                    break;
                }
                case 3:
                    std::cout << "---------- Exibir Dados ----------\n";

                    if (clientes.size() > 0) {
                        for (int i = 0; i < clientes.size(); i++) {
                                clientes[i].exibir_dados();
                                std::cout << std::endl;
                        }
                    }

                    else {
                        std::cout << "Nao existe clientes cadastrados. \n";
                    }

                    break;
                
                case 4: {

                    std::cout << "---------- Procurar Cliente ----------\n";

                    try {
                        int codigo;
                        bool cliente_existe = false;

                        std::cout << "Digite o codigo do cliente: \n";
                        std::cin >> codigo;

                        for (int i = 0; i < clientes.size(); i++) {
                            if (clientes[i].get_codigo() == codigo) {
                                cliente_existe = true;
                                clientes[i].exibir_dados();
                                break;
                            }
                        }

                        if (cliente_existe == false) {
                            throw std::invalid_argument("Erro: Cliente nao encontrado. Nao existe nenhum cliente com esse codigo. \n");
                        }
                    }
                    catch (std::invalid_argument &error) {
                        std::cout << error.what();
                    }
                    break;
                }
                
                case 0:
                    break;
                
                default:
                    std::cout << "Opcao invalida! \n";
                    break;
                }

                break;
            
            case 2:
                std::cout << "---------- Administrar Vendas ----------\n";
                std::cout << "[1] - Cadastrar Venda \n";
                std::cout << "[2] - Excluir Venda \n";
                std::cout << "[3] - Exibir Vendas \n";
                std::cout << "[4] - Procurar Venda \n";             
                std::cout << "[0] - Voltar \n";
                std::cout << "-------------------------------------------\n";

                std::cin >> opcao_escolhida2;

                switch (opcao_escolhida2) {
                case 1: {
                    std::cout << "---------- Cadastrar Venda ----------\n";

                    try {
                        int forma_pagamento, cliente_atendido_codigo, carrinho_codigo, codigo;
                        double valor_recebido;
                        std::string data, atendente_consultado_senha;
                        Cliente *cliente_atendido;
                        Atendente *atendente_consultado;
                        Carrinho *carrinho;
                        bool existe_cliente = false, existe_atendente = false, existe_carrinho = false;

                        std::cout << "Digite o codigo da venda: \n";
                        std::cin >> codigo;
                        std::cout << "Digite a forma de pagamento: \n";
                        std::cout << "[1] - Cartao de Credito (a vista) \n";
                        std::cout << "[2] - Dinheiro (a vista) \n";
                        std::cin >> forma_pagamento;
                        std::cout <<  "Digite o valor recebido: \n";
                        std::cin >> valor_recebido;
                        std::cout << "Digite a data: \n";
                        std::cin.ignore();
                        std::getline(std::cin, data);
                        std::cout << "Digite o codigo do cliente atendido: \n";
                        std::cin >> cliente_atendido_codigo;

                        for (int i=0; i < vendas.size(); i++) {
                            if (vendas[i]->get_codigo() == codigo) {
                                throw std::invalid_argument("Erro: Nao foi possivel cadastrar essa venda. Ja esta sendo utilizado esse codigo. \n");
                            }
                        }

                        for (int i = 0; i < clientes.size(); i++) {
                            if (clientes[i].get_codigo() == cliente_atendido_codigo) {
                                existe_cliente = true;
                                cliente_atendido = &clientes[i];
                                break;
                            }
                        }

                        if (existe_cliente == false) {
                            throw std::invalid_argument("Erro: Nao existe nenhum cliente com esse codigo. \n");
                        }

                        std::cout << "Digite a senha do atendente consultado: \n";
                        std::cin >> atendente_consultado_senha;   

                        for (int i = 0; i < atendentes.size(); i++) {
                            if (atendentes[i]->get_senha() == atendente_consultado_senha) {
                                existe_atendente = true;
                                atendente_consultado = atendentes[i];
                                break;
                            }
                        }

                        if (existe_atendente == false) {
                            throw std::invalid_argument("Erro: Nao existe nenhum atendente com essa senha. \n");
                        }                

                        std::cout << "Digite o codigo do carrinho: \n";
                        std::cin >> carrinho_codigo;   

                        for (int i = 0; i < carrinhos.size(); i++) {
                            if (carrinhos[i]->get_codigo() == carrinho_codigo) {
                                existe_carrinho = true;
                                carrinho = carrinhos[i];
                                break;
                            }
                        }

                        if (existe_carrinho == false) {
                            throw std::invalid_argument("Erro: Nao existe nenhum carrinho com esse codigo. \n");
                        }                         

                        Venda *venda_construtor = new Venda(codigo, forma_pagamento, data, cliente_atendido, atendente_consultado, valor_recebido, carrinho);
                        vendas.push_back(venda_construtor);

                        venda_construtor->calcula_troco();
                    }
                    catch(std::invalid_argument &error) {
                        std::cout << error.what();
                    }

                    break;
                }
                
                case 2: {
                    std::cout << "---------- Excluir Venda ----------\n";

                    try {
                        int codigo;
                        bool existe_venda = false;

                        std::cout << "Digite o codigo da venda: \n";
                        std::cin >> codigo;

                        for (int i = 0; i < vendas.size(); i++) {
                            if (vendas[i]->get_codigo() == codigo) {
                                existe_venda = true;
                                vendas.erase(vendas.begin() + i);
                                break;
                            }
                        }

                        if (existe_venda == false) {
                            throw std::invalid_argument("Erro: Nao foi possivel excluir essa venda. Nao existe nenhuma venda com esse codigo. \n");
                        } 
                    }
                    catch (std::invalid_argument &error) {
                        std::cout << error.what();
                    }   
                    break;
                }

                case 3: {
                    std::cout << "---------- Exibir Vendas ----------\n"; 

                    if (vendas.size() > 0) {
                        double receita_total = 0;
                        int quantidade_vendas = 0;

                        for (int i = 0; i < vendas.size(); i++) {
                            std::cout << "Codigo da Venda: " << vendas[i]->get_codigo() << std::endl;
                            std::cout << "Receita da Venda: R$" << vendas[i]->get_valor_total_pagar() << std::endl;   
                            std::cout << "---------------- \n";              
                            receita_total += vendas[i]->get_valor_total_pagar();       
                            quantidade_vendas++;
                        }

                        std::cout << "Quantidade total de vendas: " << quantidade_vendas << std::endl;
                        std::cout << "Receita total das vendas: R$" << receita_total << std::endl;
                    }

                    else {
                        std::cout << "Nao existe vendas cadastradas. \n";
                    }

                    break;
                }

                case 4: {
                    std::cout << "---------- Procurar Venda  ----------\n";
                    
                    try {
                        int codigo;
                        bool existe_venda = false;

                        std::cout << "Digite o codigo da venda: \n";
                        std::cin >> codigo;

                        for (int i = 0; i < vendas.size(); i++) {
                            if (vendas[i]->get_codigo() == codigo) {
                                existe_venda = true;
                                vendas[i]->imprimir_nota_fiscal();
                                break;
                            }
                        }

                        if (existe_venda == false) {
                            throw std::invalid_argument("Erro: Nao foi possivel imprimir a nota fiscal dessa venda. Nao existe nenhuma venda com esse codigo. \n");
                        } 
                    }
                    catch (std::invalid_argument &error){
                        std::cout << error.what();
                    }               
                    break;
                }
                
                case 0:
                    break;
                
                default:
                    std::cout << "Opcao invalida! \n";
                    break;
                }
                break;

            case 0:
                break;                
            
            default:
                std::cout << "Opcao invalida! \n";
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
                case 1: {
                    std::cout << "---------- Adicionar Produto ----------\n";

                    try {
                        int codigo;
                        std::string nome, validade, marca;
                        double preco;
                            
                        std::cout << "Digite o codigo do produto: " << std::endl;
                        std::cin >> codigo;
                        std::cout << "Digite o nome do produto: " << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin,nome);
                        std::cout << "Digite o preco do produto: " << std::endl;  
                        std::cin >> preco;
                        std::cout << "Digite a validade do produto: " << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin, validade);
                        std::cout << "Digite a marca do produto: " << std::endl;
                        std::getline(std::cin, marca);
                        std::cout << "Digite a quantidade: " << std::endl;
                        std::cin >> quantidade1;

                        if (estoque.verificar_codigo(codigo) == true) {
                            throw std::invalid_argument("Erro: Ja existe um produto com esse codigo.\n");
                        }

                        if (estoque.verificar_codigo(codigo) == false) {
                            Produto *pr = new Produto(codigo, nome, preco, validade, marca);
                            estoque.adicionar_produto(pr,quantidade1);
                            produtos.push_back(pr);
                        }
                    }
                    catch (std::invalid_argument &erro) {
                        std::cerr << erro.what() << std::endl;
                    }
                    
                    break;
                }
                
                case 2: {
                    std::cout << "---------- Excluir Produto ----------\n";

                    try {
                        int codigo, quantidade;
                        std::cout << "Digite o codigo: \n";
                        std::cin >> codigo;
                        std::cout << "Digite a quantidade que deseja excluir: \n";
                        std::cin >> quantidade;

                        if (estoque.verificar_codigo(codigo) == false) {
                            throw std::invalid_argument("Erro: Nao foi possivel excluir esse produto. Nao existe nenhum produto com esse codigo no estoque. \n");
                        }

                        estoque.excluir_produto(codigo, quantidade);
                    }
                    catch (std::invalid_argument &error){
                        std::cerr << error.what(); 
                    }
                    break;
                }

                case 3:
                    std::cout << "---------- Exibir Estoque ----------\n";
                    estoque.exibir_estoque();
                    break;
                
                case 4: {
                    std::cout << "---------- Procurar Produto ----------\n";

                    int codigo1; 
                    std::cout << "Digite o codigo do produto que deseja procurar: " << std::endl;
                    std::cin >> codigo1;
                    bool existir = estoque.procurar_produto(codigo1);
                       if(!(existir)){
                          std::cout << "Produto inexistente no estoque" << std::endl;
                     }

                    break;
                }
                
                case 0:
                    break;
                
                default:
                    std::cout << "Opcao invalida! \n";
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
            
            case 2: {
                std::cout << "---------- Procurar Produto ----------\n";

                int codigo; 
                std::cout << "Digite o codigo do produto que deseja procurar: " << std::endl;
                std::cin >> codigo;
                bool existir = estoque.procurar_produto(codigo);
                    if(!(existir)){
                        std::cout << "Produto inexistente no estoque" << std::endl;
                    }
                 
                break;
            }

            case 0:
                break;
            
            default:
                std::cout << "Opcao invalida! \n";
                break;
            }
        }

    } while (opcao_escolhida != 0);
    
}
