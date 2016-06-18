#ifndef ARQUIVO_MATRIZES_HPP
#define ARQUIVO_MATRIZES_HPP

#include <cstdlib>
class Arquivo_Matriz
{	private:
	FILE *Matriz;
	int n;
};

class Arquivo
{	private:
	FILE *arquivo_texto;
	Arquivo_Matriz *Salvas;
};

#endif
