#ifndef ESTABELECIMENTO_HPP
#define ESTABELECIMENTO_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include "Produtos.hpp"

class Estabelecimento{

public:
	std::list<Produtos> produtos;
	static float totalGanho;

	static std::vector<Produtos> produtos_vendidos;

	Estabelecimento();
	~Estabelecimento();
	void listar();
	void venda(int codigo_produto);
	void caixa();

};

#endif