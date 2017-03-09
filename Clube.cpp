#include "JogadorContrato.h"
#include "Jogador.h"
#include "JogadorLivre.h"
#include "Clube.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

Clube::Clube(string n) {
nome = n;
// j = (JogadorContrato*) malloc (32 * (sizeof(JogadorContrato)));
j = new Jogador*[32];
}

Clube::~Clube(){
delete this;
}

void Clube::ContratarJogador(Jogador *jc) { 

JogadorContrato* novo = new JogadorContrato(jc->getNome(),jc->getRegistro(),nome);
j[qntJogadores] = novo;
qntJogadores++;
cout << "Jogador adicionado com sucesso!" << endl;


}

void Clube::organizaLista(int pos){ //organiza lista apos apagar um jogador

int x;

for (x=0;x<qntJogadores;x++){
   if (x>=pos) 
	{
	j[x] = j[x+1];	
	}
}

}

void Clube::DispensarJogador(Jogador *jc) {

int x;
for(x=0;x<qntJogadores;x++){
 if (j[x]==jc){
  	j[x] = NULL; //apagar conteudo da posição
    qntJogadores--;
	organizaLista(x);
   cout << "Jogador removido com sucesso!" << endl;
   return;
 }
}

}
int Clube::getQntJogador() {return qntJogadores;}
string Clube::getNome() {return nome;}
Jogador** Clube::getJ() {return j;}
void Clube::setQntJogador(int qnt) {qntJogadores = qnt;}
void Clube::getListaJogador() { 
 int x;
 cout << "-Lista de Jogadores-" << endl;
 	for (x=0;x<qntJogadores;x++){
 		cout << j[x]->getNome() << endl;
	}
  cout << "---Fim da Lista---" << endl;
}
void Clube::detalheJogador(){
char nome[50];
cout << "Digite o nome do jogador:" << endl;
cin.getline(nome,50);

int x;
 for (x=0;x<qntJogadores;x++){
	if (j[x]->getNome() == nome) {
	  cout << "--Detalhes do Jogador:--" << endl;
	  cout << "Nome: " << j[x]->getNome() << endl;
	  cout << "Registro: " << j[x]->getRegistro() << endl;
	  cout << "Status: "; j[x]->getStatus();
	  
  	  cout << "---------Fim------------" << endl;
	  return;
	} 		
 }
  cout << "Jogador não localizado!" << endl;
}
