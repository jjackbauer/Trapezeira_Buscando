#include "LinearSystem.h"
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

LinearSystem::LinearSystem()
{
    //ctor
}

LinearSystem::~LinearSystem()
{
    int i;

	for(i = 0; i < lines; i++)
	{
		delete [](coefficientMtrx[i]);
	}

	delete []coefficientMtrx;
	delete []answerVctr;
}

void LinearSystem::readMatrixes()
{
	int i, j, k;
	cin >> lines;
	columns = lines + 1;

	coefficientMtrx = new float*[lines];
	answerVctr = new float[lines];

	for(k = 0; k != columns; k++)
    {
    	coefficientMtrx[k] = new float(columns);
    }

    for(i = 0; i != lines; i++)
    {
    	for(j = 0; j != columns; j++)
    	{
    		cin >> coefficientMtrx[i][j];
    	}
    }
}

void LinearSystem::printMatrixes()
{
	int i, j;

	cout << "A matriz entrada e:" << endl;

	for(i = 0; i != lines; i++)
	{
		for(j = 0; j != columns; j++)
		{
			cout << coefficientMtrx[i][j] <<  " ";
		}

		cout << endl;
	}
}

void LinearSystem::triangularize()
{
	int i, j, k;
	float m;

	for(j = 0; j < (columns - 1); j++)
	{
		for(i = j + 1; i < lines; i++)
		{
			LinearSystem::pivoting(j);

			m = ((coefficientMtrx[i][j]) / (coefficientMtrx[j][j]));

			coefficientMtrx[i][j] = 0;

			for(k = j + 1; k <= columns; k++)
			{
				coefficientMtrx[i][k] = coefficientMtrx[i][k] - (m * coefficientMtrx[j][k]);
			}

		}
	}

	for(j = 0; j != columns; j++)
    {
    	answerVctr[j] = coefficientMtrx[j][columns - 1];
    }


}

void LinearSystem::backsubstitution()
{
	int i, j;
	float S;

	for(i = lines - 1; i >= 0; i--)
	{
		S = 0;

		for(j = i + 1; j < lines; j++)
		{
			S = (S + (coefficientMtrx[i][j] * answerVctr[j]));
		}

		answerVctr[i] =  ((coefficientMtrx[i][lines] - S) / (coefficientMtrx[i][i]));
	}
}

void LinearSystem::printAnswer()
{
	int i;

	cout << "O vetor resposta e: ";

    for(i = 0; i != columns - 1; i++)
    {
    	cout << answerVctr[i] << " ";
    }
}

void LinearSystem::pivoting(int j)
{
	int i, max = 0, LineOfMax, k;
	float* vectorAux;

	vectorAux = new float[(lines + 1)];

	for(i = j; i != lines; i++)
	{
		if(fabs(coefficientMtrx[i][j]) > max)
		{
			max = coefficientMtrx[i][j];
			LineOfMax = i;
		}
	}

	for(k = 0; k != (lines + 1); k++)
	{
		vectorAux[k] = coefficientMtrx[j][k];
		coefficientMtrx[j][k] = coefficientMtrx[LineOfMax][k];
	}

	for(k = 0; k != (lines + 1); k++)
	{
		coefficientMtrx[LineOfMax][k] = vectorAux[k];
	}

}

void LinearSystem::gaussianElimination()
{
	LinearSystem::triangularize();
	LinearSystem::backsubstitution();
}
