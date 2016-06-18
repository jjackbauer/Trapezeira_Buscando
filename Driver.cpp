#include "Matriz.hpp"
#include <iostream>
using namespace std;
int main()
{
	int l,c;
	cout<< "Digite o numero de  linhas: ";
	cin>>l;
	cout<< "Digite o numero de  colunas: ";
	cin>>c;
	
	Matriz nova(l,c);
	
	nova.SetMatriz();
	nova.PrintMatriz();
	nova.EliminacaoGaus();
	nova.PrintMatriz();
}