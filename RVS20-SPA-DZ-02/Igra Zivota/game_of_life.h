#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life {
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	static const unsigned int UKUPNO_STUPACA = STUPACA + 2;
	static const unsigned int UKUPNO_REDAKA = REDAKA + 2;
	bool _generacija[UKUPNO_REDAKA][UKUPNO_STUPACA];
	bool _sljedeca_generacija[UKUPNO_REDAKA][UKUPNO_STUPACA];
	bool slucajna_vrijednost();
public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};

#endif
