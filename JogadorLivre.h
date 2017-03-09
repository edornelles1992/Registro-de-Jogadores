#include <string>
#include "Jogador.h"
#ifndef __JOGADORLIVRE_H__
#define __JOGADORLIVRE_H__

using namespace std;

class JogadorLivre : public Jogador{

public:

~JogadorLivre();
JogadorLivre(string n,	int num);
void getStatus();
int getVinculo();
string getClube();

};
#endif
