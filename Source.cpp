#include <stdio.h>
#include <conio.h>

#define PozitieLibera 0
#define M 9

bool CautareSpatiuLiber(int cursor[M][M], int &linie, int &coloana)
{
	for (linie = 0; linie < M; linie++)
		for (coloana = 0; coloana < M; coloana++)
			if (cursor[linie][coloana] == PozitieLibera)
			{
				return true;
			}
	return false;
}
bool PozitieSigura(int cursor[M][M], int linie, int coloana, int numar);

bool Solutie(int cursor[M][M])
{
	int linie, coloana;

	if (!CautareSpatiuLiber(cursor, linie, coloana))
	{
		return true;
	}
	for (int numar = 1; numar <= 9; numar++)
	{
		if (PozitieSigura(cursor, linie, coloana, numar))
		{

			cursor[linie][coloana] = numar;


			if (Solutie(cursor))
			{
				return true;
			}
			cursor[linie][coloana] = PozitieLibera;
		}
	}
	return false;
}

bool VerificareLinie(int cursor[M][M], int linie, int numar)
{
	for (int coloana = 0; coloana < M; coloana++)
		if (cursor[linie][coloana] == numar)
		{
			return false;
		}
	return true;
}

bool VerificareColoana(int cursor[M][M], int coloana, int numar)
{
	for (int linie = 0; linie < M; linie++)
		if (cursor[linie][coloana] == numar)
		{
			return false;
		}
	return true;
}

bool VerificarePatrat(int cursor[M][M], int coloana, int linie, int numar)
{
	if (linie >= 0 && linie <= 2 && coloana >= 0 && coloana <= 2)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (cursor[i][j] == numar)
				{
					return false;
				}
			}
		}
	}
	if (linie >= 0 && linie <= 2 && coloana >= 3 && coloana <= 5)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				if (cursor[i][j] == numar)
				{
					return false;
				}
			}
		}
	}
	if (linie >= 0 && linie <= 2 && coloana >= 6 && coloana <= 8)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				if (cursor[i][j] == numar)
				{
					return false;
				}
			}
		}
	}
	if (linie >= 3 && linie <= 5 && coloana >= 0 && coloana <= 2)
	{
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (cursor[i][j] == numar)
				{
					return false;
				}
			}
		}
	}
	if (linie >= 3 && linie <= 5 && coloana >= 3 && coloana <= 5)
	{
		for (int i = 3; i < 6; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				if (cursor[i][j] == numar)
				{
					return false;
				}
			}
		}
	}
	if (linie >= 3 && linie <= 5 && coloana >= 6 && coloana <= 8)
	{
		for (int i = 3; i < 6; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				if (cursor[i][j] == numar)
				{
					return false;
				}
			}
		}
	}
	if (linie >= 6 && linie <= 8 && coloana >= 0 && coloana <= 2)
	{
		for (int i = 6; i < 9; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (cursor[i][j] == numar)
				{
					return false;
				}
			}
		}
	}
	if (linie >= 6 && linie <= 8 && coloana >= 3 && coloana <= 5)
	{
		for (int i = 6; i < 9; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				if (cursor[i][j] == numar)
				{
					return false;
				}
			}
		}
	}
	if (linie >= 6 && linie <= 8 && coloana >= 6 && coloana <= 8)
	{
		for (int i = 6; i < 9; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				if (cursor[i][j] == numar)
				{
					return false;
				}
			}
		}
	}

	return true;
}

bool PozitieSigura(int cursor[M][M], int linie, int coloana, int numar)
{
	return VerificarePatrat(cursor, coloana, linie, numar) &&
		VerificareLinie(cursor, linie, numar) &&
		VerificareColoana(cursor, coloana, numar);
}

void Afisare(int cursor[M][M])
{
	for (int linie = 0; linie < M; linie++)
	{
		for (int coloana = 0; coloana < M; coloana++)
			printf("%d ", cursor[linie][coloana]);
		printf("\n");
	}
}

int main()
{
	int cursor[M][M] = {
		{ 0, 0, 4, 6, 0, 8, 9, 1, 2 },
	{ 0, 7, 2, 0, 0, 0, 3, 4, 8 },
	{ 1, 0, 0, 3, 4, 2, 5, 0, 7 },
	{ 0, 5, 9, 7, 0, 1, 4, 2, 0 },
	{ 0, 2, 6, 0, 5, 0, 7, 9, 0 },
	{ 0, 1, 3, 9, 0, 4, 8, 5, 0 },
	{ 9, 0, 1, 5, 3, 7, 0, 0, 4 },
	{ 2, 8, 7, 0, 0, 0, 6, 3, 0 },
	{ 3, 4, 5, 2, 0, 6, 1, 0, 0 }
	};
	if (Solutie(cursor) == true)
		Afisare(cursor);
	else
		printf("Nici-o solutie gasita!");
	_getch();
	return 0;
}