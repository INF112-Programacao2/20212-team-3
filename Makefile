output: main.o Atendente.o Caixa.o Carrinho.o Cliente.o Estoque.o Estoquista.o Funcionario.o Gerente.o Produto.o Venda.o
	g++ main.o Atendente.o Caixa.o Carrinho.o Cliente.o Estoque.o Estoquista.o Funcionario.o Gerente.o Produto.o Venda.o -o output

main.o: Arquivos.cpp/main.cpp
	g++ -c Arquivos.cpp/main.cpp

Atendente.o: Arquivos.cpp/Atendente.cpp Arquivos.h/Atendente.h
	g++ -c Arquivos.cpp/Atendente.cpp

Caixa.o: Arquivos.cpp/Caixa.cpp Arquivos.h/Caixa.h
	g++ -c Arquivos.cpp/Caixa.cpp

Carrinho.o: Arquivos.cpp/Carrinho.cpp Arquivos.h/Carrinho.h
	g++ -c Arquivos.cpp/Carrinho.cpp
	
Cliente.o: Arquivos.cpp/Cliente.cpp Arquivos.h/Cliente.h
	g++ -c Arquivos.cpp/Cliente.cpp 

Estoque.o: Arquivos.cpp/Estoque.cpp Arquivos.h/Estoque.h
	g++ -c Arquivos.cpp/Estoque.cpp
	
Estoquista.o: Arquivos.cpp/Estoquista.cpp Arquivos.h/Estoquista.h
	g++ -c Arquivos.cpp/Estoquista.cpp

Funcionario.o: Arquivos.cpp/Funcionario.cpp Arquivos.h/Funcionario.h
	g++ -c Arquivos.cpp/Funcionario.cpp

Gerente.o: Arquivos.cpp/Gerente.cpp Arquivos.h/Gerente.h
	g++ -c Arquivos.cpp/Gerente.cpp

Produto.o: Arquivos.cpp/Produto.cpp  Arquivos.h/Produto.h
	g++ -c Arquivos.cpp/Produto.cpp

Venda.o: Arquivos.cpp/Venda.cpp Arquivos.h/Venda.h
	g++ -c Arquivos.cpp/Venda.cpp

clean:
	rm *.o output