#include <iostream>
#include "baralho.h"

using namespace std;

const int QNT_mao = 5; // Quantidade de carta na mao de cada jogador

struct TJogador
{
	TCarta mao[5];
};

void definir_mao(TJogador jogador) {

	for (int i = 1; i < QNT_mao+1; i++)
	{
		cout << "Valor carta " << i << ": ";
		cin >> jogador.mao->valor;
		cout << "Naipe carta " << i << ": ";
		cin >> jogador.mao->naipe;
	}
}

void comparar_cartas(TJogador jogador, TJogador jogador2){
	
	int sequencia = 0;


	for (int i = 0; i < QNT_mao; i++)
	{
		for (int j = 0; j < QNT_mao; j++)
		{
			if (jogador.mao[i].valor == jogador.mao[j].valor) {


			}
			if (sequencia == 4) {

				break;
			}
			else if (sequencia == 3)
			{

			}
			else if (sequencia == 2)
			{

			}
			

		}
	}
}

void definir_quem_ganhou(TJogador jogador1, TJogador jogador2) {

	if (true)
	{

	}

}

int main()
{
	TBaralho baralho = inicializar_baralho();

	TJogador jogador1, jogador2;

	cout << "Definir mao do jogador 1: " << endl;
	definir_mao(jogador1);

	cout << "Definir mao do jogador 2: " << endl;
	definir_mao(jogador2);


	cout << baralho.cartas[0].valor;
	

	return 0;
}