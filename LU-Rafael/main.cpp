#include <iostream>
#include <cstdio>
#include "LinearSystem.h"

using namespace std;

int main()
{
	freopen("InputMatrix.txt","r",stdin);
	freopen("Output.txt","w",stdout);

	LinearSystem Ls;
    Ls.readMatrixes();
    Ls.printMatrixes();
    cout << endl << endl;
    Ls.luDecomposition();
    Ls.printMatrixes();
    cout << endl << endl;
    Ls.printAnswer();

    return 0;
}
