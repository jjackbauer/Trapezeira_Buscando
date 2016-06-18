#ifndef MATRIZ_HPP
#define MATRIZ_HPP
typedef struct 
{
	int l,c;
	double valor;
}lista;

class Matriz
{
	private:
	int linhas;
	int colunas;
	double **elementos;
	void SetLinhas(int);
	void SetColunas(int);
	int GetLinhas(void);
	int GetColunas(void);
	void Pivoteamento(int*);
	double DecressimoDoJaCalculado(int l,double *x,char modo);
	void LmLY(int l1,int l2,double m);//linha1 - linha2 * m apartir de linha2+1
	
	public:
	Matriz(int l, int c);
	~Matriz();
	void SetElementos(int,int,double);
	double GetElementos(int,int);
	void TrocaLinhas(int,int);
	double LU(int modo,int *b,int *p);
	void PrintMatriz(void);
	void SetMatriz(void);
	int* EliminacaoGaus(void);
	double* ResolveSistemaTriangular(char modo,double*x);
	Matriz* CopiaMatriz(Matriz*);
	
	
};
#endif