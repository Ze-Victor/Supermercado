#ifndef PRODUTOS_HPP
#define PRODUTOS_HPP

#include <iostream>
#include <string>

class Produtos
{
public:
	int codigo;
	std::string produto;
	std::string und_medida;
	double preco;
	int qnt_disponivel;

	Produtos();
 	
};

#endif