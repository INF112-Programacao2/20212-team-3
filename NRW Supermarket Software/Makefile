output: main.o Atendente.o Caixa.o Carrinho.o Cliente.o Estoque.o Estoquista.o Funcionario.o Gerente.o Produto.o Venda.o
	g++ main.o Atendente.o Caixa.o Carrinho.o Cliente.o Estoque.o Estoquista.o Funcionario.o Gerente.o Produto.o Venda.o -o output

main.o: main.cpp
	g++ -c main.cpp

Atendente.o: Atendente.cpp Atendente.h
	g++ -c Atendente.cpp

Caixa.o: Caixa.cpp Caixa.h
	g++ -c Caixa.cpp

Carrinho.o: Carrinho.cpp Carrinho.h
	g++ -c Carrinho.cpp 
	
Cliente.o: Cliente.cpp Cliente.h
	g++ -c Cliente.cpp 

Estoque.o: Estoque.cpp Estoque.h
	g++ -c Estoque.cpp
	
Estoquista.o: Estoquista.cpp Estoquista.h
	g++ -c Estoquista.cpp

Funcionario.o: Funcionario.cpp Funcionario.h
	g++ -c Funcionario.cpp

Gerente.o: Gerente.cpp Gerente.h
	g++ -c Gerente.cpp

Produto.o: Produto.cpp  Produto.h
	g++ -c Produto.cpp

Venda.o: Venda.cpp Venda.h
	g++ -c Venda.cpp

clean:
	rm *.o output