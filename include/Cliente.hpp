#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <vector>
#include <cstring>
#include <fstream>
#include <locale>
#include "Produtos.hpp"
#include "Estabelecimento.hpp"

class Cliente{

public:
	double saldo;
	std::vector<std::string> sacola;

	static int qnt_Clientes;

	Cliente();
	void compra(Estabelecimento* e, std::string produto, double valor);
	void verSacola();
	void registro();

};

#endif