#include "JogadorContrato.h"
#include "Jogador.h"
#include <iostream>
#include <string>

JogadorContrato::JogadorContrato(string n,int num,string c) : Jogador( n, num){
clube = c;
}


JogadorContrato::~JogadorContrato(){
delete this;
}

void JogadorContrato::getStatus() {cout << "Jogador Atuando" << endl; }
int JogadorContrato::getVinculo() {return 1;}
string JogadorContrato::getClube() {return clube;}
string JogadorContrato::getNome() {return Jogador::getNome();}
