#ifndef NRW_FUNCIONARIO_H
#define NRW_FUNCIONARIO_H

#include <iostream>
#include <string>

class Funcionario {

// Componentes reusaveis nas subclasses (gerente, caixa, atendente, estoquista)
protected:
  std::string _nome;
  int _codigo;
  double _salario;
  std::string _cpf;
  std::string _endereco;
  std::string _email;
  std::string _data_nascimento;
  std::string _senha;
  
public:
  // Construtor
  Funcionario(int codigo, std::string nome, double salario, std::string cpf, std::string endereco, std::string email, std::string data_nascimento, std::string senha);
  // Destrutor
  ~Funcionario();

  // Metodos gets dos atributos protected
  std::string get_nome();
  int get_codigo();
  double get_salario();
  std::string get_cpf();
  std::string get_endereco();
  std::string get_email();
  std::string get_data_nascimento();
  std::string get_senha();

  // Metodos sets dos atributos protected
  void set_nome(std::string nome);
  void set_codigo(int codigo);
  void set_salario(double salario);
  void set_cpf(std::string cpf);
  void set_endereco(std::string endereco);
  void set_email(std::string email);
  void set_data_nascimento(std::string data_nascimento);
  void set_senha(std::string senha);

  // Metodo polimorfico que pode ser sobrescrito de forma especializada nas subclasses
  // Ele ira obrigar a implementacao desse metodo nas subclasses
  virtual void exibir_dados() = 0;
  
};

#endif 
