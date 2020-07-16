#include "../include/Estabelecimento.hpp"
#include "../include/Cliente.hpp"

void pause();

int main(int argc, char* argv[]){



	Estabelecimento a;
	Cliente c;
	bool interacao = true;
	int op;
	std::string produto;
	float valor;

	while(interacao == true){

		std::cout << std::endl;
	    std::cout<< "+-------------------------------------+" << std::endl;
	    std::cout<< "|           OPÇÕES DE ENTRADA         |" <<std::endl;
	    std::cout<< "+-------------------------------------+" << std::endl;
	    std::cout<< "|                                     |" <<std::endl;
	    std::cout<< "|   1 - Realizar compra.              |" <<std::endl;
	    std::cout<< "|   2 - Adicionar Saldo ao Cliente.   |" <<std::endl;
	    std::cout<< "|   3 - Ver produtos da loja.         |" <<std::endl;
	    std::cout<< "|   4 - Ver sacola do cliente.        |" <<std::endl;
	    std::cout<< "|   5 - Ver produtos vendidos.        |" <<std::endl;
	    std::cout<< "|                                     |" <<std::endl;
	    std::cout<< "|   0 - Finalizar compra.             |" <<std::endl;
	    std::cout<< "|                                     |" <<std::endl;
	    std::cout<< "+-------------------------------------+" << std::endl;

	    std::cout << "Digite uma opção para dar continuidade ao atendimento: " << std::endl;
	    std::cin >> op;

	    if(op == 1){
	    	std::cout << "Insira o nome do produto que deseja adicionar a sacola! " << std::endl;
	    	std::cin >> produto;

	    	std::cout << "Qual o valor do produto? " << std::endl;
	    	std::cin >> valor;
	    	c.compra(&a, produto, valor);

	    	pause();
	    }

	    else if(op == 2){

	    	std::cout << "Quanto de saldo deseja adicionar? " << std::endl;
	    	std::cin >> c.saldo;

	    	pause();
	    }
	    else if(op == 3){

	    	a.listar();
	    	pause();
	    }
	    else if(op == 4){
	    	c.verSacola();
	    	pause();
	    }
	    else if(op == 5){
	    	a.caixa();
	    	pause();
	    }
	    else if(op == 0){

	    	std::string opcao;

	    	std::cout << "Deseja instanciar um novo cliente? [y/n]" << std::endl;
	    	std::cin >> opcao;

	    	if(opcao == "Y" || opcao == "y"){
	    		c.registro();
	    		Cliente c;
	    		pause();
	    	}else if(opcao == "N" || opcao == "n"){
	    		c.registro();
	    		pause();
	    		interacao = false;
	    	}else{
	    		std::cout << "Opção Inválida!" << std::endl;
	    		pause();

	    	}

	    }
	    else{
	    	std::cout << "Opção Inválida! Tente novamente." << std::endl;
	    	pause();
	    }

	    system("clear");

	}

	return 0;
	
}

void pause(){
	std::cout << "Pressione ENTER para continuar... " << std::endl;
	std::getchar();
    std::cin.ignore();
}