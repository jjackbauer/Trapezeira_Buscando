#ifndef LINEARSYSTEM_H
#define LINEARSYSTEM_H


class LinearSystem
{
   private:
   	float **coefficientMtrx;
      float *answerVctr;
   	int lines;
   	int columns;
      void triangularize();
      void backsubstitution();
      void pivoting(int j);

   public:
   	LinearSystem();
   	~LinearSystem();
   	void readMatrixes();
   	void printMatrixes();
      void printAnswer();
      void gaussianElimination();
      
};

#endif // LINEARSYSTEM_H
