#include "Matriz.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
void Matriz::SetLinhas(int l)
{
	linhas=l;
}
void Matriz::SetColunas(int c)
{
	colunas=c;
}
int Matriz::GetLinhas(void)
{
	return linhas;
}
int Matriz::GetColunas(void)
{
	return colunas;
}
void Matriz::SetElementos(int l,int c,double el)
{	if(l>=0 && l<GetLinhas() && c>=0 && c<GetColunas())
		elementos[l][c] = el;
	else
		cout<<"Possicao Invalida"<<endl;
}
double Matriz::GetElementos(int l,int c)
{
	if(l>=0 && l<GetLinhas() && c>=0 && c<GetColunas())
		return elementos[l][c];
	else
	{
		cout<<"("<<l<<","<<c<<")"<<"Possicao Invalida"<<endl;
		return 1;
	}	
		
}
Matriz::Matriz(int l, int c)
{
	int k;
	elementos = (double**)malloc(sizeof(double*)*l);
	if(!elementos)
	{
		printf("Error pointer for pointer dinamic alocation");
		exit(0);
	}
	else
	{

		for(k=0;k<l;k++)
		{
			elementos[k] = (double *)malloc(sizeof(double)*c);
				if(!(elementos[k]))
				{
					printf("Error pointer float alocation n(%d)",k+1);
					exit(1);
				}
		}
		SetLinhas(l);
		SetColunas(c);
	}
}
Matriz::~Matriz()
{	int k;

	for(k=0;k<GetLinhas();k++)
			delete [](elementos[k]); 
				
	delete []elementos;
}

void Matriz::PrintMatriz()
{
	int k,w;

		printf("\n");
		for(k=0;k<GetLinhas();k++)
		{
			for(w=0;w<GetColunas();w++)
			{
				printf(" %10.3lf",GetElementos(k,w));
			}
			printf("\n");
		}
		printf("\n");
}
void Matriz::SetMatriz()
{
	int k,w;
	double aux;

	for(k=0;k<GetLinhas();k++)
		for(w=0;w<GetColunas();w++)
		{
			printf("\nDigite o elemento [%d][%d]: ",k+1,w+1);
			scanf("%lf",&aux);
			SetElementos(k,w,aux);
		}



}
void Matriz::TrocaLinhas(int l1,int l2)
{
	double *aux;
	if(l1>=0 && l1<GetLinhas() && l2>=0 && l2<GetLinhas())
	{
		aux = elementos[l1];
		elementos[l1]=elementos[l2];
		elementos[l2]=aux;
	}
	else
	{
		cout << "Operacao Invalida"<<endl;
	}
}
int* Matriz::EliminacaoGaus(void)
{
	int l,c,*p=(int*)malloc(sizeof(int)*GetLinhas()),flag=(GetLinhas()-GetColunas())?-1:0;
	double m,mr;
	
	for(c=0,mr=1;c<GetColunas();c++)
	{	//pivoteamento(p);
		for(l=c+1;l<GetLinhas();l++)
		{
			m=(GetElementos(l,c)/GetElementos(c,c));
			SetElementos(l,c,m);
			SetElementos(l,c,0);
			LmLY(l,c,m);
		}
		cout<<"Multiplicador "<<c<<" eh: "<<m<<endl;
		mr*=m;
	}
	for(c=0,m=1;c<GetColunas()+flag;c++)
		m*=GetElementos(c,c);
	
	cout<<"O determinante da matriz eh"<<m*mr;
}
void Matriz::LmLY(int l1,int l2,double m)
{
	int c;
	
	for(c=l2+1;c<GetColunas();c++)
		SetElementos(l1,c,(GetElementos(l1,c)-m*GetElementos(l2,c)));
	
	return;
}
double* Matriz::ResolveSistemaTriangular(char modo,double*x)
{
	int c,L,a;
	double *x;
	
	if(!(modo-'U'))//Para sistemar matriz UPPER
	{
		c = GetLinhas()-1;
		L = -1;
		a=-1;
	}
	else
	if(!(modo-'L'))//Para sistema matriz LOWER
	{
		c = 0;
		L = GetLinhas();
		a=1;
	}
	else
	{
		cout<<"ERRO!!";
	}
	x=(double*)malloc(sizeof(double)*GetLinhas);
	if(!x)
	{
		cout<<"ERRO!!";
	}
	
	for(;controle(c,L,modo);c+=a)
	{
		x[c]=DecressimoDoJaCalculado(c,x,modo);
	}
}
double DecressimoDoJaCalculado(int l,double *x,char modo)
{
	int c,L,a;
	
	if(!(modo-'U'))//Para sistemar matriz UPPER
	{
		c = GetLinhas()-1;
		L = -1;
		a=-1;
	}
	else//Para sistema matriz LOWER
	{
		c = 0;
		L = GetLinhas();
		a=1;
	}
}
bool controle(int a,int b,char modo)
{
	if(!(modo-'U'))
		return(a>b);
	else
	if(!(modo-'L'))
		return (a<b);
}
void pivoteamento(lista *x);