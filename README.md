# Compilação:
- make
- ./supermercado

# Menu:

- Irá aparecer uma tela de opções para o cliente.
- O menu já inicia com um cliente (Cliente 1);
- O cliente inicia com saldo zero, portanto, caso queira realizar uma comprar, será necessário adicionar saldo ao cliente. Isso pode ser feito pelo menu.

- O menu possui as seguintes opções:

	1. Realizar compra:
		- Solicita o nome do produto e o valor unitário dele;
	2. Adicionar saldo ao cliente:
		- Solicita o valor de saldo que deseja adicionar ao cliente;
	3. Listar os produtos da loja:
		- Lista todos os produtos disponiveis da loja e seus respectivos preços;
	4. Ver a sacola do cliente:
		- Ver a sacola do atual cliente;
	5. Ver produtos vendidos:
		- Mostra todos os produtos vendidos até o momento e o valor atual em caixa;

	0. Finalizar compra:
		- Finaliza a compra e pergunta se irá ter um novo cliente:
			- Caso sim, instancia um novo cliente e mostra novamente o menu de opções.
			- Caso não, finaliza a aplicação gerando todos os arquivos de venda e cliente.