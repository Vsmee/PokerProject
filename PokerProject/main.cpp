#include <iostream>
#include "baralho.h"

using namespace std;

const int QNT_mao = 5; // Quantidade de carta na mao de cada jogador

struct TJogador
{
	TCarta mao[5];
};

void definir_mao(TJogador& jogador) {

	for (int i = 1; i < QNT_mao+1; i++)
	{
		cout << "Valor carta " << i << ": ";
		cin >> jogador.mao[i-1].valor;
		cout << "Naipe carta " << i << ": ";
		cin >> jogador.mao[i-1].naipe;
	}
}

int varificar_valores_iguais(TJogador jogador){
	
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
	// formula: numero de cartas repetidas**2 + numero de cartas nao repetidas
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

		cout << "par" << endl;
		return 2; // par
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

bool verificar_sequencia(TJogador& jogador) {

	for (int i = 0; i < QNT_mao-1; i++)
	{
		TCarta temp;
		for (int j = 0; j < QNT_mao-1; j++)
		{
			if (jogador.mao[j].valor > jogador.mao[j + 1].valor) {
				temp = jogador.mao[j];
				jogador.mao[j] = jogador.mao[j + 1];
				jogador.mao[j + 1] = temp;

			}
		}
	}
	for (int i = 0; i < QNT_mao - 1; i++)
	{
		if (jogador.mao[i].valor != jogador.mao[i + 1].valor - 1) {
			return false;
		}
	}
	return true;
}

int definir_valor_da_mao(TJogador jogador) {

	int valor_da_mao = 1;
	valor_da_mao = varificar_valores_iguais(jogador);
	if (valor_da_mao < 6 && verificar_naipes_iguais(jogador) == true) {
		valor_da_mao = 6;
	}
	if (valor_da_mao < 5 && verificar_sequencia(jogador)== true) {
		valor_da_mao = 5;
	}
	if (verificar_sequencia(jogador) == true && verificar_naipes_iguais(jogador) == true)
	{
		valor_da_mao = 10;
		if (jogador.mao[4].valor == 14)
		{
			valor_da_mao = 11;
		}
	}

	return valor_da_mao;
}

int main()
{
	TBaralho baralho = inicializar_baralho();

	TJogador jogador1, jogador2;

	cout << "Definir mao do jogador 1: " << endl;
	definir_mao(jogador1);

	/*cout << "Definir mao do jogador 2: " << endl;
	definir_mao(jogador2);*/
	
	cout << definir_valor_da_mao(jogador1) << endl;


	

	return 0;
}