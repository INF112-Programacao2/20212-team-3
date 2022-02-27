output: main.o Atendente.o Caixa.o Carrinho.o Cliente.o Estoque.o Estoquista.o Funcionario.o Gerente.o Produto.o Venda.o
	g++ main.o Atendente.o Caixa.o Carrinho.o Cliente.o Estoque.o Estoquista.o Funcionario.o Gerente.o Produto.o Venda.o -o output

main.o: main.cpp
	g++ -c Arquivos.cpp/main.cpp

Atendente.o: Atendente.cpp Atendente.h
	g++ -c Arquivos.cpp/Atendente.cpp

Caixa.o: Caixa.cpp Caixa.h
	g++ -c Arquivos.cpp/Caixa.cpp

Carrinho.o: Carrinho.cpp Carrinho.h
	g++ -c Arquivos.cpp/Carrinho.cpp
	
Cliente.o: Cliente.cpp Cliente.h
	g++ -c Arquivos.cpp/Cliente.cpp 

Estoque.o: Estoque.cpp Estoque.h
	g++ -c Arquivos.cpp/Estoque.cpp
	
Estoquista.o: Estoquista.cpp Estoquista.h
	g++ -c Arquivos.cpp/Estoquista.cpp

Funcionario.o: Funcionario.cpp Funcionario.h
	g++ -c Arquivos.cpp/Funcionario.cpp

Gerente.o: Gerente.cpp Gerente.h
	g++ -c Arquivos.cpp/Gerente.cpp

Produto.o: Produto.cpp  Produto.h
	g++ -c Arquivos.cpp/Produto.cpp

Venda.o: Venda.cpp Venda.h
	g++ -c Arquivos.cpp/Venda.cpp

clean:
	rm *.o output