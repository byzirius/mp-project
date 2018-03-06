#include <iostream>
#include <time.h>
using namespace std;
const int MAX = 20;
const int MIN = 0;

typedef struct
{
	int i;
	int j;
}posicio;

bool ComprabacionLimite(int matriz[MAX][MAX], posicio futura)
{
	bool check = true;

	if ((futura.i >= MAX) || (futura.i < MIN))
	{
		check = false;
	}

	if ((futura.j >= MAX) || (futura.j < MIN))
	{
		check = false;
	}

	if (matriz[futura.i][futura.j] != 0)
	{
		check = false;
	}

	return check;
}

bool ComprobacionLimiteBoss(int matriz[MAX][MAX], posicio futura, posicio actual)
{
	bool check = true;

	if (matriz[futura.i][futura.j + 1] != 0)
		if ((futura.i != actual.i) && ((futura.j + 1) != actual.j))
			check = false;

	if (matriz[futura.i][futura.j - 1] != 0)
		if ((futura.i != actual.i) && ((futura.j - 1) != actual.j))
			check = false;

	if (matriz[futura.i + 1][futura.j] != 0)
		if (((futura.i + 1) != actual.i) && (futura.j != actual.j))
			check = false;

	if (matriz[futura.i - 1][futura.j] != 0)
		if (((futura.i - 1) != actual.i) && (futura.j != actual.j))
			check = false;

	return check;
}

void PintarMatriz(int matriz[MAX][MAX])
{
	for (int j = 0; j < MAX; j++)
	{
		for (int i = 0; i < MAX; i++)
		{
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}
void InicializarMatriz(int matriz[MAX][MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			matriz[i][j] = 0;
		}
	}
}

void PosicionMapa(posicio &futura, posicio &actual)
{
	int selec;

	futura.j = actual.j;
	futura.i = actual.i;

	selec = rand() % 4 + 1;

	switch (selec)
	{
	case 1:
		futura.i++;
		break;
	case 2:
		futura.i--;
		break;
	case 3:
		futura.j++;
		break;
	case 4:
		futura.j--;
		break;
	}
}

void GenerarMapa(int matriz[MAX][MAX])
{
	posicio actual, futura;

	actual.i = MAX / 2;
	actual.j = MAX / 2;
	matriz[actual.i][actual.j] = 3;

	int limitsales = rand() % 20 + 10;

	for (int sales = 1; sales < limitsales; sales++)
	{
		if (sales == limitsales - 1)
		{
			do {
				PosicionMapa(futura, actual);
			} while (!ComprabacionLimite(matriz, futura));

			if (ComprobacionLimiteBoss(matriz, futura, actual))
			{
				actual.i = futura.i;
				actual.j = futura.j;
				matriz[actual.i][actual.j] = 2;
			}
			else
			{
				actual.i = futura.i;
				actual.j = futura.j;
				matriz[actual.i][actual.j] = 1;
				limitsales++;
			}
			
		}

		else
		{
			do {
				PosicionMapa(futura, actual);
			} while (!ComprabacionLimite(matriz, futura));

			actual.i = futura.i;
			actual.j = futura.j;
			matriz[actual.i][actual.j] = 1;
		}
	}

}

int main()
{
	srand(time(NULL));
	int matriz[MAX][MAX];

	InicializarMatriz(matriz);

	GenerarMapa(matriz);

	PintarMatriz(matriz);


	system("pause");
	return 0;
}