#include <string>
#ifndef __JOGADOR_H__
#define __JOGADOR_H__

using namespace std;

class Jogador{

private:
string nome_apelido; 
int num_cbf;

public:

Jogador(string n,int num);
~Jogador();
virtual void getStatus() = 0;
virtual int getVinculo() = 0;
virtual string getClube() = 0;
string getNome();
int getRegistro();

};
#endif
