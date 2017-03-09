#include <string>
#include "Jogador.h"
#ifndef __JOGADORCONTRATO_H__
#define __JOGADORCONTRATO_H__

using namespace std;

class JogadorContrato: public Jogador{

private:
string clube;

public:
~JogadorContrato();
JogadorContrato(string n,int num,string c);
void getStatus();
int getVinculo();
string getClube();
string getNome();
};
#endif
