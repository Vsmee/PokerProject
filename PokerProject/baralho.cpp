#include <iostream>
#include "baralho.h"

using namespace std;

TCarta inicializar_carta(string naipe, int valor) {

	TCarta carta;

	carta.valor = valor;

	carta.naipe = naipe;

	return carta;

}

TBaralho inicializar_baralho() {

	TBaralho baralho;

	int i = 0;

	for (int qnt_naipe = 0; qnt_naipe < 4; qnt_naipe++) {

		for (int valor = 2; valor < 15; valor++) {

			string naipe;

			switch (qnt_naipe)
			{
			case 0:
				naipe = "D";

			case 1:
				naipe = "H";

			case 2:
				naipe = "S";

			case 3:
				naipe = "C";

			default:
				break;
			}

			TCarta carta = inicializar_carta(naipe, valor);

			baralho.cartas[i++] = carta;

		}

	}

	return baralho;
}