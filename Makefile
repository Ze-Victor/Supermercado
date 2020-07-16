PROG = supermercado
CC = g++
CPPFLAGS = -O0 -std=c++11 -g 

$(PROG) : main.o Cliente.o Estabelecimento.o Produtos.o
	$(CC)  main.o Cliente.o Estabelecimento.o Produtos.o  -o $(PROG)

main.o :
	$(CC) $(CPPFLAGS) -c src/main.cpp

Cliente.o : include/Cliente.hpp
	$(CC) $(CPPFLAGS) -c src/Cliente.cpp

Estabelecimento.o :  include/Estabelecimento.hpp
	$(CC) $(CPPFLAGS) -c src/Estabelecimento.cpp

Produtos.o :  include/Produtos.hpp
	$(CC) $(CPPFLAGS) -c src/Produtos.cpp

clean:
	rm -f *.o