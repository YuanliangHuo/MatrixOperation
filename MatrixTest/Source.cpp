#include <iostream>
#include <iomanip>
#include "../MatrixDll/MatrixClass.h"

int main()
{
	size_t rows;
	size_t cols;
	std::cout << "Input the value of row and column: " << std::endl;
	std::cin >> rows >> cols;
	float *pSourceData = new float[rows*cols];
	for (size_t idx = 0; idx != rows*cols; ++idx)
	{
		pSourceData[idx] = (float)(rand()/(float)100.0);             
	}

	CMatrix MyMatrix(rows, cols);
	MyMatrix.AssignValue(pSourceData);
	MyMatrix.PrintMatrix();
	MyMatrix.InverseMatrix();
	MyMatrix.PrintMatrix();

	delete []pSourceData;

	system("pause");
	return 0;
}