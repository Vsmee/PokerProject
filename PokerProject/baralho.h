#pragma once
using namespace std;

const int TAM_BARALHO = 52; //  Tamanho do baralho

struct TCarta {

	int valor; // 2, 3, 4, 5, 6, 7, 8, 9, 10, Valete (11), Dama (12), Rei (13), Ás (14).

	string naipe; // Ouro (D), Copa (H), Espadas (S), Paus (C)

};

struct TBaralho {

	TCarta cartas[TAM_BARALHO];

};

TCarta inicializar_carta(int naipe, int valor);

TBaralho inicializar_baralho();
