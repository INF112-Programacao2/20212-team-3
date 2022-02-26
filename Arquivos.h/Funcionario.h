#ifndef NRW_FUNCIONARIO_H
#define NRW_FUNCIONARIO_H

#include <iostream>
#include <string>

class Funcionario {

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
  Funcionario(std::string nome, int codigo, double salario, std::string cpf, std::string endereco, std::string email, std::string data_nascimento, std::string senha);
  
  std::string get_nome();
  int get_codigo();
  double get_salario();
  std::string get_cpf();
  std::string get_endereco();
  std::string get_email();
  std::string get_data_nascimento();
  std::string get_senha();

  void set_nome(std::string nome);
  void set_codigo(int codigo);
  void set_salario(double salario);
  void set_cpf(std::string cpf);
  void set_endereco(std::string endereco);
  void set_email(std::string email);
  void set_data_nascimento(std::string data_nascimento);
  void set_senha(std::string senha);

  virtual void exibir_dados() = 0;
  
};

#endif 
