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
	MyMatrix.Assign(pSourceData);
	MyMatrix.Dump(std::cout);
	MyMatrix.Transpose();
	MyMatrix.Dump(std::cout);

	//Asign
	CMatrix MyMatrix2(rows, cols);
	MyMatrix2 = MyMatrix;
	MyMatrix2.Dump(std::cout);


	CMatrix OneMatrix(rows, cols);
	OneMatrix.Assign(pSourceData);
	float* p1 = NULL;
	float *p2 = NULL;
	p1 = OneMatrix.GetRow(rows - 1);
	for(int i = 0; i < cols; i++)
	{
		std::cout << p1[i] <<"  ";
	}
	std::cout << std::endl;
	delete []p1;
	p2 = OneMatrix.GetCol(cols - 1);
	for(int i = 0; i < rows; i++)
	{
		std::cout << p2[i] <<" ";
	}
	std::cout << std::endl;
	delete []p2;
	const CMatrix TwoMatrix(rows,cols);
	CMatrix ThreeMatrix(TwoMatrix);
	ThreeMatrix.Dump(std::cout);


	//std::cout << MyMatrix2 << std::endl; 

	//test the operator "()"
	std::cout << "MyMatrix(0,1): " << MyMatrix(0,1) << std::endl << std:: endl;
	//test the operator "=="
	CMatrix TestMatrix;
	TestMatrix = MyMatrix;
	if(TestMatrix == MyMatrix)
	{
		std::cout << "MyMatrix2 and MyMatrix is equal!" << std::endl;
	}

	delete []pSourceData;

	system("pause");
	return 0;
}