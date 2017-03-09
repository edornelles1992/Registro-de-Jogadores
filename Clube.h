#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "JogadorContrato.h"
#include "Jogador.h"
#include "JogadorLivre.h"
#ifndef __CLUBE_H__
#define __CLUBE_H__

using namespace std;

class Clube {

private:
string nome;
int qntJogadores;
Jogador **j;
void organizaLista(int pos);

public:
~Clube();
Clube(string n);
void ContratarJogador(Jogador *jc);
void DispensarJogador(Jogador *jc);
int getQntJogador();
string getNome();
void getListaJogador();
Jogador** getJ();
//void Jogador* setJ(Jogador* jog);
void setQntJogador(int qnt);
void detalheJogador();
};
#endif
