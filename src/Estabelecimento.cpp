#include "../include/Estabelecimento.hpp"

float Estabelecimento::totalGanho;
std::vector<Produtos> Estabelecimento::produtos_vendidos;

Estabelecimento::Estabelecimento(){

	std::ifstream file_in("produtos.txt");
	if(!file_in.is_open()){
		std::cout << "Impossivel abrir o arquivo" << std::endl;
	}else{

		std::string aux;
		char discard;
		std::getline(file_in, aux);

		Produtos p;

		while(!file_in.eof()){

			std::getline(file_in, aux);
			std::stringstream stream(aux);
			stream >> p.codigo;
			stream >> discard;
			stream >> p.produto;
			stream >> discard;
			stream >> p.und_medida;
			stream >> discard;
			stream >> discard;
			stream >> discard;
			stream >> discard;
			stream >> p.preco;
			stream >> discard;
			stream >> discard;
			stream >> p.qnt_disponivel;

			produtos.push_back(p);

		}
	}

	file_in.close();

}
Estabelecimento::~Estabelecimento(){
	std::ofstream fprodutos("produtos.txt");
	fprodutos << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << "\n";
	if(fprodutos.is_open()){
		for (auto it = produtos.begin(); it != --produtos.end(); ++it)
		{
			fprodutos << (*it).codigo << ", " << (*it).produto << " , " << (*it).und_medida
					  << " , 'R$ " << (*it).preco << "'," << (*it).qnt_disponivel << "\n";
		}

	}
	std::ofstream file_out("caixa.cvs");
	file_out << "COD,PRODUTO,PREÇO,QUANTIDADE VENDIDA" << "\n";
	if(file_out.is_open()){
		for (int i = 0; i < produtos_vendidos.size(); ++i)
		{
			file_out << produtos_vendidos[i].codigo << "," << produtos_vendidos[i].produto << ",'R$ " << produtos_vendidos[i].preco << "'," << produtos_vendidos[i].qnt_disponivel << "\n";
		}

	}
	file_out << "\n" << "TOTAL GANHO: " << totalGanho << "\n";

}
void Estabelecimento::listar(){

	for (auto it = produtos.begin(); it != --produtos.end(); ++it)
	{
		if((*it).qnt_disponivel > 0){
			std::cout << (*it).produto << " - R$" << (*it).preco << " - " << (*it).qnt_disponivel << " und. disponiveis" << std::endl;
		}
	}

}
void Estabelecimento::venda(int codigo_produto){

	Produtos p;

	for (auto it = produtos.begin(); it != produtos.end(); ++it)
	{
		if((*it).codigo == codigo_produto && (*it).qnt_disponivel > 0){

			(*it).qnt_disponivel -= 1;
			totalGanho += (*it).preco;
			if (produtos_vendidos.size() == 0)
			{	
				p.qnt_disponivel = 0;
				p.codigo = (*it).codigo;
				p.produto = (*it).produto;
				p.und_medida = (*it).und_medida;
				p.preco = (*it).preco;
				p.qnt_disponivel += 1;
				produtos_vendidos.push_back(p);
				return;

			}else{
				for (int i = 0; i < produtos_vendidos.size(); ++i)
				{
					if(produtos_vendidos[i].produto == (*it).produto){
						produtos_vendidos[i].qnt_disponivel += 1;
						return;
					}else{
						p.qnt_disponivel = 0;
						p.codigo = (*it).codigo;
						p.produto = (*it).produto;
						p.und_medida = (*it).und_medida;
						p.preco = (*it).preco;
						p.qnt_disponivel += 1;
						produtos_vendidos.push_back(p);
						return;
					}
				
				}
			}
			

			
		}
	}

	std::cout << "Produto Indisponivel!" << std::endl;
	
}
void Estabelecimento::caixa(){
	for (int i = 0; i < produtos_vendidos.size(); ++i)
	{
		std::cout << produtos_vendidos[i].qnt_disponivel << " " <<  produtos_vendidos[i].und_medida << " - " << produtos_vendidos[i].produto << std::endl;
	}
	std::cout << "\n" << "Total em caixa: R$ " << totalGanho << std::endl;
}
