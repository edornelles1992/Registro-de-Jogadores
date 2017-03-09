#include "Jogador.h"
#include "JogadorLivre.h"
#include "JogadorContrato.h"
#include "Clube.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

using namespace std;

int qtdClubes(){ //retornar quantidade de times do BD
int contador = 0;
ifstream arq;
arq.open ("BD.txt", ios::in);

do{
	string aux;
	getline(arq,aux);
	if (aux == "SIAPERGS") {continue;}
	char c = aux[0];	
	if (c >= 65 & c <= 90){ // testar se inicia com uma letra
		contador++;
	}
}while(arq.good());

arq.close();
return contador;
}

int qtdJogadores(){ //quantidade de jogadores do BD

int contador = 0;
ifstream arq;
arq.open ("BD.txt", ios::in);

do{
	string aux;
	getline(arq,aux);
	
	char c = aux[0];	
	if (c >= 48 & c <= 57){ // testar se inicia com um numero
		contador++;
	}
}while(arq.good());

arq.close();


return contador;
}

Jogador* selecionaJogadorLivre(Jogador *j[]){ //retorna o jogador se estiver livre

int reg;
int qtd = qtdJogadores();

cout << "Digite o nro registro do jogador desejado:" << endl;
cin >> reg; 


int x;
for (x=0;x<qtd;x++){
  if (j[x]->getRegistro() == reg) {
		if (j[x]->getVinculo() == 0) {
			return j[x]; //selecionar jogador
		} else {
			cout << "Jogador Já vinculado a algum clube!" << endl;
			return NULL;
		}
	}
}

cout << "Jogador não localizado!" << endl;
return NULL;
}

void alteraVinculo( Jogador* alvo,  Jogador *j[],Clube *c){ //trocar de jogar livre para contrato na lista de jogadores



int x;
 for (x=0;x<qtdJogadores();x++){
 if( j[x] == alvo ) {
		JogadorContrato* novo = new JogadorContrato(alvo->getNome(),alvo->getRegistro(),c->getNome());
		j[x] = novo;
	}
 }

}

void liberaVinculo(int reg,  Jogador *j[]){ //troca de jogadorContrato para livre na lista

int x;
for (x=0;x<qtdJogadores();x++){
 if(j[x]->getRegistro() == reg) {
		JogadorLivre* novo = new JogadorLivre(j[x]->getNome(),j[x]->getRegistro());		
		j[x] = novo;		
	}
}

}

Jogador* selecionaDispensaJogador(Clube *c) { //selecionar jogador a ser dispensado

int reg;
cout << "Digite o nro registro do jogador desejado:" << endl;
cin >> reg; 
Jogador **jogadoresClube = c->getJ();

int x;
for (x=0;x<c->getQntJogador();x++){
  if (jogadoresClube[x]->getRegistro() == reg) {
		
		return jogadoresClube[x];
	}
}
cout << "Jogador não localizado!" << endl;
return NULL;
}

void menuTime(Clube *c, Jogador *j[]){ // 1.x sub menu para gerenciar um time

do{
int op;
cout << "-----MENU DO CLUBE ----"<< endl;
cout << "1 - Mostrar lista de jogadores"<< endl;
cout << "2 - Mostrar detalhes de um jogador "<< endl;
cout << "3 - Mostrar quantidade de jogadores"<< endl;
cout << "4 - Contratar um jogador"<< endl;
cout << "5 - Dispensar um jogador"<< endl;
cout << "6 - Voltar ao menu principal"<< endl;

cin >> op;
cin.ignore();
if (op==1) { c->getListaJogador();}
else if (op==2) {c->detalheJogador();}
else if (op==3) { cout << "Num de jogadores: " << c->getQntJogador() << endl;}
else if (op==4) { if (c->getQntJogador() >= 32) 
				  {  cout << "Plantel Cheio ! MAX = 32 jogadores!" << endl; }
				  else {
					 Jogador* alvo = selecionaJogadorLivre(j);
					 if (alvo != NULL) { c->ContratarJogador(alvo); alteraVinculo(alvo,j,c);}
				  }
				}
else if (op==5) { 
					if (c->getQntJogador() >=0) {  
					Jogador* alvo = selecionaDispensaJogador(c);				  
				     if (alvo !=NULL) { 
						int reg = alvo->getRegistro();
						c->DispensarJogador(alvo); liberaVinculo(reg,j);
					 }
				 	} else {
						cout << "Plantel Vazio!" << endl;
					}
				}	
else if (op==6) {return;}


}while(1);

}

void escolheClube(Clube *c[], int qtd, Jogador *j[]){ //selecionar um clube da lista - 1

char clube[100];
cout << "Digite o nome do clube:" << endl;
cin.getline(clube,100);

int x;
for (x=0;x<qtd;x++){

	if (c[x]->getNome() == clube) { 
		menuTime(c[x],j);
		return;
	}
}
cout << "Clube não encontrado!" << endl;

}

void listaClubes(Clube *c[], int qtd){ //listar todos os clubes - 2

int x;
cout << "---CLUBES----" << endl;
for(x=0;x<qtd;x++){ cout << c[x]->getNome() << endl;}
cout << "----FIM-----" << endl;
}

void jogadoresSemClube(Jogador *j[], int qtd){ //listar jogadores sem clube - 3

int x;
cout << "---JOGADORES S/CLUBE----" << endl;
for (x=0;x<qtd;x++){

	if (j[x]->getVinculo() == 0 ){
		cout << "Nome: " << j[x]->getNome() << " Registro: " << j[x]->getRegistro() << endl;
	}

}
cout << "----FIM-----" << endl;
}

void inicializarClubes(Clube *c[], int qtd){ //carregar os clubes da lista com seus respectivos jogadores

int x;

ifstream arq;
arq.open ("BD.txt", ios::in);
string nome_clube;
string linha;
getline(arq,linha);
 for (x=0;x<qtd;x++){
	int cont = 0; //pegar a qtidade de jogadores do clube
	nome_clube = linha;
	if (nome_clube == "SIAPERGS") {break;}
	Clube *novo = new Clube(nome_clube);
	string nova;
	getline(arq,nova);
	char l = nova[0];
	Jogador **jogadores = novo->getJ();

	do {	//colocar os jogadores na lista	
		
		string reg = nova.substr (0,6);
		int aux = nova.find(" ");
		string nome = nova.substr (aux+1);		
		jogadores[cont] = new JogadorContrato(nome,atoi(reg.c_str()),nome_clube);
		cont++;	
		string proxima;
		getline(arq,proxima);
		l = proxima[0];
		nova = proxima;
	 } while (l >= 48 & l <= 57);		

  novo->setQntJogador(cont); //gravar a qtidade de jogadores no time
  linha = nova; //pegar o nome do proximo clube
  c[x] = novo; //guardar clube na lista

 }
 arq.close();

}

void inicializarJogadores(Jogador *j[], int qtd){

int x;

ifstream arq;
arq.open ("BD.txt", ios::in);
string clube;
 for (x=0;x<qtd;x++){
	string linha;
	getline(arq,linha);
	char c = linha[0];	
	if (c >= 65 & c <= 90) { //pula se for o nome de um time e guarda o nome do clube
		clube = linha; 
		x--; continue;
	} 
	string reg = linha.substr (0,6);
	int aux = linha.find(" ");
	string nome = linha.substr (aux+1);
	if (clube=="SIAPERGS") { //jogadorLivre
	j[x] = new JogadorLivre(nome, atoi(reg.c_str()));
	} else { //JogadorContrato
		j[x] = new JogadorContrato(nome, atoi(reg.c_str()), clube);
	  }
 }
arq.close();
}

void atualizaBanco(Clube *c[],Jogador *j[], int qtdC, int qtdJ){ //atualizar txt antes de sair do programa

ofstream arq;
arq.open("BD.txt", ios::out);

int x;
 for(x=0;x<qtdC;x++){
   Clube *atual = c[x];	
	arq << atual->getNome() << endl; 
    Jogador** jogadores = atual->getJ();
    int i;
	for (i=0;i<atual->getQntJogador();i++){
     int a = jogadores[i]->getRegistro();		
	arq << jogadores[i]->getRegistro() << " " << jogadores[i]->getNome() << endl;	
	}
 }

arq << "SIAPERGS" << endl; 
int y;
 for (y=0;y<qtdJ;y++) {
		if (j[y]->getVinculo() == 0)
		{
			int b = j[y]->getRegistro();			
			arq << j[y]->getRegistro() << " " << j[y]->getNome() << endl;
		}
 }

arq.close();
}

int main(void){

int qntC = qtdClubes();
Clube *c[qntC];
inicializarClubes(c, qntC);

int qntJ = qtdJogadores();
Jogador *j[qntJ];
inicializarJogadores(j, qntJ);

do{
int op;
cout << "-----MENU PRINCIPAL ----"<< endl;
cout << "1 - Escolha o clube "<< endl;
cout << "2 - Mostrar lista dos clubes "<< endl;
cout << "3 - Mostrar lista de jogadores sem clube"<< endl;
cout << "4 - Sair do programa"<< endl;
cin >> op;
cin.ignore();
if (op==1) {escolheClube(c,qntC,j);}
else if (op==2) {listaClubes(c,qntC);}
else if (op==3) {jogadoresSemClube(j,qntJ);}
else if (op==4) {atualizaBanco(c,j,qntC,qntJ);
				 return 0;
				}
}while(1);

return 0;
}
