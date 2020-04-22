#include "game_of_life.h"

bool game_of_life::slucajna_vrijednost()
{
	
	if (rand() % 4 == 0)
	{
		return true;
	}
		return false;
}

game_of_life::game_of_life()
{
	for (int i = 0; i < UKUPNO_REDAKA; i++)
	{
		for (int j = 0; j < UKUPNO_STUPACA; j++)
		{
			if (i == 0 || i == UKUPNO_REDAKA - 1 || j == 0 || j == UKUPNO_STUPACA - 1)
			{
				_sljedeca_generacija[i][j] = false;
			}
			_sljedeca_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < UKUPNO_REDAKA - 1; i++)
	{
		for (int j = 0; j < UKUPNO_STUPACA - 1; j++)
		{
			int n = 0;
			if (_generacija[i - 1][j - 1]) n++;
			if (_generacija[i - 1][j]) n++;
			if (_generacija[i - 1][j + 1]) n++;
			if (_generacija[i][j - 1]) n++;
			if (_generacija[i][j + 1]) n++;
			if (_generacija[i + 1][j - 1]) n++;
			if (_generacija[i + 1][j]) n++;
			if (_generacija[i + 1][j + 1]) n++;

			if (_generacija[i][j])
			{
				if (n > 3 || n < 2)
				{
					_sljedeca_generacija[i][j] = false;
				}
			}
			else
			{
				if (n == 3)
				{
					_sljedeca_generacija[i][j] = true;
				}
			}

				
			
		}
	}
}

void game_of_life::iscrtaj()
{
	for (int i = 1; i < UKUPNO_REDAKA; i++)
	{
		for (int j = 1; j < UKUPNO_STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
	for (int i = 1; i < UKUPNO_REDAKA - 1; i++)
	{
		for (int j = 1; j < UKUPNO_STUPACA - 1; j++)
		{
			if (_generacija[i][j])
			{
				cout << "+";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}
}
