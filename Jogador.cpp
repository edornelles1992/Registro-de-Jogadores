#include "Jogador.h"
#include <string>

Jogador::~Jogador(){
delete this;
}

Jogador::Jogador(string n,int num){
nome_apelido= n;
num_cbf = num;
}


string Jogador::getNome() {return nome_apelido;}
int Jogador::getRegistro() {return num_cbf;}
