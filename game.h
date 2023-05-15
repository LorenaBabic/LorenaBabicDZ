#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game {
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost();
	bool celija_zauzeta(int i, int j);

public:
	game();
	void sljedeca_generacija();
	void iscrtaj();
};

#endif


