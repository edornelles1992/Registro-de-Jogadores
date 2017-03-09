#include "JogadorLivre.h"
#include "Jogador.h"
#include <iostream>
#include <string>

JogadorLivre::JogadorLivre(string n,int num) : Jogador( n, num){}

JogadorLivre::~JogadorLivre(){
delete this;
}

void JogadorLivre::getStatus() { cout << "Jogador Parado" << endl; }
string JogadorLivre::getClube() { return "Sem Clube";}
int JogadorLivre::getVinculo() {return 0;}
