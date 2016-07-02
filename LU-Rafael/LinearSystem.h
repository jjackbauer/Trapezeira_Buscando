#ifndef LINEARSYSTEM_H
#define LINEARSYSTEM_H


class LinearSystem
{
   private:
   	double **coefficientMtrx;
    double *answerVctr;
   	int lines;
   	int columns;
    void triangularize();
    void pivoting(int j);

   public:
   	LinearSystem();
   	~LinearSystem();
   	void readMatrixes();
   	void printMatrixes();
    void printAnswer();
    void gaussianElimination();
    void lyB();
    void uxY();
    void luDecomposition();
      
};

#endif // LINEARSYSTEM_H
