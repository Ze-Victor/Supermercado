#include "../include/Cliente.hpp"

int Cliente::qnt_Clientes;

Cliente::Cliente(){
	qnt_Clientes += 1;
}
void Cliente::compra(Estabelecimento* e, std::string nome_produto, double valor){

	std::string aux;

	if(saldo >= valor){
		for (auto it = e->produtos.begin(); it != e->produtos.end(); ++it){
			aux = (*it).produto;
			if(nome_produto.length() == (*it).produto.length()){

				std::locale loc;

  				aux = (*it).produto;
  				for (std::string::size_type i=0; i<aux.length(); ++i){
  					aux[i] = std::toupper(aux[i],loc);
  				}

  				for (std::string::size_type i=0; i<nome_produto.length(); ++i){
  					nome_produto[i] = std::toupper(nome_produto[i],loc);
  				}

				if(nome_produto == aux){
					if((*it).qnt_disponivel > 0){
						e->venda((*it).codigo);
						saldo -= (*it).preco;
						sacola.push_back((*it).produto);
						std::cout << "Produto adicionado a sacola! " << std::endl;

						return;
					}else{
						std::cout << "Produto indisponível! " << std::endl;
						return;
					}
					
				}

			}
		}
	}
	else{
		std::cout << "Saldo insuficiente!" << std::endl;
	}
}
void Cliente::verSacola(){
	for (auto it = this->sacola.begin(); it < this->sacola.end(); ++it){
			
		std::cout << *it << std::endl;
	}
}
void Cliente::registro(){

	std::string nome_arquivo;

	nome_arquivo = "cliente_" + std::to_string(qnt_Clientes) + ".txt";

	std::ofstream file_out(nome_arquivo);

	if(file_out.is_open()){
		for (int j = 0; j < this->sacola.size(); ++j)
		{
			file_out << this->sacola[j] << "\n";
		}
		}else{
			std::cout << "Impossível abrir o arquivo!" << std::endl;
		}
		file_out.close();
		this->sacola.clear();
		this->saldo = 0;
}