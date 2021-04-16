#include <iostream>

using namespace std;

const int QNT_mao = 5; // Quantidade de carta na mao de cada jogador 

struct TCarta {

	int valor; // 2, 3, 4, 5, 6, 7, 8, 9, 10, Valete (11), Dama (12), Rei (13), Ás (14).

	int naipe; // 1-Ouro (D), 2-Copa (H), 3-Espadas (S), 4-Paus (C)

};

struct TJogador
{
	TCarta mao[5];
	int valor_mao = 1;
	TCarta maior_carta;
};

void definir_mao(TJogador& jogador) {

	char naipe;

	for (int i = 1; i < QNT_mao+1; i++)
	{

		cout << "Valor carta " << i << ": ";
		cin >> jogador.mao[i-1].valor;
		while (jogador.mao[i - 1].valor < 2 || jogador.mao[i - 1].valor > 10)
		{
			cout << "Valor invalido tente novamente, carta " << i << ": ";
			cin >> jogador.mao[i - 1].valor;
		}

		cout << "Naipe carta " << i << ": ";
		cin >> naipe;

		while (naipe != 'd' && naipe != 'h' && naipe != 's' && naipe != 'c')
		{
			cout << "Naipe invalido tente novamente, carta " << i << ": ";
			cin >> naipe;
		}

		switch (naipe)
		{
		case 'd':
			jogador.mao[i - 1].naipe = 0;
		case 'h':
			jogador.mao[i - 1].naipe = 1;
		case 's':
			jogador.mao[i - 1].naipe = 2;
		case 'c':
			jogador.mao[i - 1].naipe = 3;
		default:
			break;
		}
		system('cls')
	}
}

void maior_carta_sequencial(TJogador& jogador) {

	int sequencia;
	int sequencia_max = 0;
	for (int i = 0; i < QNT_mao; i++)
	{
		sequencia = 0;
		for (int j = 0; j < QNT_mao; j++)
		{
			if (jogador.mao[i].valor == jogador.mao[j].valor) {

				sequencia++;

			}

		}
		if (sequencia>= sequencia_max)
		{
			jogador.maior_carta = jogador.mao[i];
		}
		if (sequencia_max < sequencia) {
			sequencia_max = sequencia;
		}
	}
}

int varificar_valores_iguais(TJogador& jogador){
	
	int sequencia = 0;

	for (int i = 0; i < QNT_mao; i++)
	{
		for (int j = 0; j < QNT_mao; j++)
		{
			if (jogador.mao[i].valor == jogador.mao[j].valor) {
				
				sequencia++;
				
			}

		}
	}
	maior_carta_sequencial(jogador);
	// formula da condicao: numero de cartas repetidas**2 + numero de cartas nao repetidas
	if (sequencia == 17 || sequencia == 25) //4*4+1 = 17 ou 5*5 + 0 = 25
	{
		return 9; // quadra
	}
	else if (sequencia == 13) // 3*3 + 2*2 + 0 = 13
	{
		return 8; // full house
	}
	else if (sequencia == 11) // 3*3 + 2 = 11
	{
		return 4; // trinca
	}
	else if (sequencia == 9) { // duas duplas = 2*2*2 + 1 = 9

		return 3; // 2 pares
	}
	else if (sequencia == 7 || sequencia == 8+1) { // 2*2 + 3 = 7

		return 2; // par
	}
	else
	{
		return 1; // sem cartas iguais
	}

}

bool verificar_naipes_iguais(TJogador jogador) {

	for (int i = 0; i < QNT_mao-1; i++)
	{
		if (jogador.mao[i].naipe != jogador.mao[i + 1].naipe) {
			return false;
		}
	}
	return true;
}

void bubble_sort(TJogador &jogador) {
	for (int i = 0; i < QNT_mao - 1; i++)
	{
		TCarta temp;
		for (int j = 0; j < QNT_mao - 1; j++)
		{
			if (jogador.mao[j].valor > jogador.mao[j + 1].valor || ((jogador.mao[j].valor == jogador.mao[j + 1].valor)&& (jogador.mao[j].naipe > jogador.mao[j + 1].naipe))) {
				temp = jogador.mao[j];
				jogador.mao[j] = jogador.mao[j + 1];
				jogador.mao[j + 1] = temp;

			}
		}
	}
}

bool verificar_sequencia(TJogador jogador) {

	for (int i = 0; i < QNT_mao - 1; i++)
	{
		if (jogador.mao[i].valor != jogador.mao[i + 1].valor - 1) {
			return false;
		}
	}
	return true;
}

void definir_valor_da_mao(TJogador& jogador) {

	bubble_sort(jogador);

	jogador.valor_mao = varificar_valores_iguais(jogador); // Condicao para Sequencias

	if (jogador.valor_mao < 6 && verificar_naipes_iguais(jogador) == true) { // Condicao para Flush
		jogador.maior_carta = jogador.mao[4];
		jogador.valor_mao = 6;
	}
	if (jogador.valor_mao < 5 && verificar_sequencia(jogador)== true) { // Condicao para Straight
		jogador.maior_carta = jogador.mao[4];
		jogador.valor_mao = 5;

	}
	if (verificar_sequencia(jogador) == true && verificar_naipes_iguais(jogador) == true) // Condicao para Straight Flush
	{
		jogador.maior_carta = jogador.mao[4];
		jogador.valor_mao = 10;
		if (jogador.mao[4].valor == 14) // Condicao para Royal Flush
		{
			jogador.valor_mao = 11;
		}

	}

}

int main()
{

	TJogador jogador_1, jogador_2;

	cout << "Definir mao do jogador 1: " << endl;
	definir_mao(jogador1);

	cout << "Definir mao do jogador 2: " << endl;
	definir_mao(jogador2);
		/*jogador_1.mao[0].naipe = 2;
		jogador_1.mao[0].valor = 2;

		jogador_1.mao[1].naipe = 4;
		jogador_1.mao[1].valor = 2;

		jogador_1.mao[2].naipe = 3;
		jogador_1.mao[2].valor = 4;

		jogador_1.mao[3].naipe = 4;
		jogador_1.mao[3].valor = 6;

		jogador_1.mao[4].naipe = 1;
		jogador_1.mao[4].valor = 4;


		jogador_2.mao[0].naipe = 3;
		jogador_2.mao[0].valor = 2;

		jogador_2.mao[1].naipe = 3;
		jogador_2.mao[1].valor = 3;

		jogador_2.mao[2].naipe = 3;
		jogador_2.mao[2].valor = 4;

		jogador_2.mao[3].naipe = 3;
		jogador_2.mao[3].valor = 5;

		jogador_2.mao[4].naipe = 3;
		jogador_2.mao[4].valor = 6;*/

	definir_valor_da_mao(jogador_1);
	definir_valor_da_mao(jogador_2);

	if (jogador_1.valor_mao == jogador_2.valor_mao) {
		if (jogador_1.maior_carta.valor > jogador_2.maior_carta.valor)
		{
			jogador_1.valor_mao++;
		}else if (jogador_1.maior_carta.valor < jogador_2.maior_carta.valor)
		{
			jogador_2.valor_mao++;
		}
		else
		{
			if (jogador_1.maior_carta.naipe > jogador_2.maior_carta.naipe) {
				jogador_1.valor_mao++;
			}
			else
			{
				jogador_2.valor_mao++;
			}
		}
	}

	if (jogador_1.valor_mao > jogador_2.valor_mao) {
		cout << "jogador 1 ganhou" << endl;
	}
	else
	{
		cout << "jogador 2 ganhou" << endl;
	}

	cout << "jogador 1 maior carta nipe: "<< jogador_1.maior_carta.naipe << endl;
	cout << "jogador 1 maior carta valor: " << jogador_1.maior_carta.valor << endl;
	cout << "jogador 2 maior carta nipe: " << jogador_2.maior_carta.naipe << endl;
	cout << "jogador 2 maior carta valor: " << jogador_2.maior_carta.valor << endl;


	return 0;
}