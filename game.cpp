#include "game.h"
#include <iostream>
#include <ctime>

bool game::slucajna_vrijednost()
{
	return(rand() % 4 == 0);
}

bool game::celija_zauzeta(int i, int j)
{

	if (i < 0 or i >= REDAKA or j < 0 or j >= STUPACA)
	{
		return false;
	}
	return _generacija[i][j];
}

game::game()
{
	srand(time(nullptr));

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void game::sljedeca_generacija()
{
	srand(time(nullptr));

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++) {
			int susjedi = 0;
			susjedi += celija_zauzeta(i - 1, j - 1);
			susjedi += celija_zauzeta(i - 1, j);
			susjedi += celija_zauzeta(i - 1, j + 1);
			susjedi += celija_zauzeta(i, j - 1);
			susjedi += celija_zauzeta(i, j + 1);
			susjedi += celija_zauzeta(i + 1, j - 1);
			susjedi += celija_zauzeta(i + 1, j);
			susjedi += celija_zauzeta(i + 1, j + 1);

			if (_generacija[i][j])
			{
				if (susjedi == 2 or susjedi == 3)
				{
					_sljedeca_generacija[i][j] = true;
				}
				else
				{
					_sljedeca_generacija[i][j] = false;
				}
			}
			else
			{
				if (susjedi == 3)
				{
					_sljedeca_generacija[i][j] = true;
				}
				else
				{
					_sljedeca_generacija[i][j] = false;
				}
			}
		}
	}
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game::iscrtaj()
{

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j])
			{
				cout << "*";
			}
			else
				cout << "_";
		}
		cout << endl;
	}
}
