#include "stdafx.h"

_CMATRIX CMatrix::CMatrix(size_t fuck_row, size_t fuck_col)
{
	row = fuck_row;
	col = fuck_col;
	pMatrix = new float *[row];
	for (size_t idx = 0; idx != row; ++idx)
	{
		pMatrix[idx] = new float[col];
	}
	for (size_t row_idx = 0; row_idx != row; ++row_idx)
	{
		for (size_t col_idx = 0; col_idx != col; ++col_idx)
		{
			pMatrix[row_idx][col_idx] = 0.0;
		}
	}
}


_CMATRIX CMatrix::CMatrix()
{
	row = 0;
	col = 0;
}

_CMATRIX CMatrix::~CMatrix()
{
	for (size_t idx = 0; idx != row; ++idx)
	{
		delete [] pMatrix[idx];
	}
	delete []pMatrix;
}


_CMATRIX CMatrix& CMatrix::operator=(const CMatrix &other)
{
	if (this == &other)
		return *this;
	for (size_t idx = 0; idx != row; ++idx)
	{
		delete [] pMatrix[idx];
	}
	delete []pMatrix;

	row = other.row;
	col = other.col;

	pMatrix = new float *[row];
	for (size_t idx = 0; idx != row; ++idx)
	{
		pMatrix[idx] = new float[col];
	}


	for (size_t row_idx = 0; row_idx != row; ++row_idx)
	{
		for (size_t col_idx = 0; col_idx != col; ++col_idx)
		{
			pMatrix[row_idx][col_idx] = other.pMatrix[row_idx][col_idx];
		}
	}
	return *this;
}

_CMATRIX CMatrix::CMatrix(const CMatrix &Other)
{
	row = Other.row;
	col = Other.col;
	pMatrix = new float *[row];
	for (size_t idx = 0; idx < row; ++idx)
	{
		pMatrix[idx] = new float[col];
	}
	 *this = Other;
}

_CMATRIX float* CMatrix::GetRow(size_t rows)
{
	float *p = new float[col];
	if(pMatrix[rows] == NULL)
	{
		std::cout << "该行为空！" << std::endl;
		exit(0);
	}
	else
	{
		for(int i = 0; i < col; i++)
		{
			p[i] = pMatrix[rows][i];
		}
	}
	return p;
}

_CMATRIX float* CMatrix::GetCol(size_t cols)
{
	float *q = new float[row];
	if(pMatrix == NULL)
	{
		std::cout << "该列为空！" << std::endl;
		exit(-1);
	}
	else
	{
		for(int i = 0; i < row; i++)
		{
			q[i] = pMatrix[i][cols];
		}
	}
	return q;
}

//std::ostream& operator<<(std::ostream& out, const CMatrix &other)
//{
//	for (size_t row_idx = 0; row_idx != other.row; ++row_idx)
//	{
//		for (size_t col_idx = 0; col_idx != other.col; ++col_idx)
//		{
//			out << std::left << std::setw(8) << other.pMatrix[row_idx][col_idx]; 
//		}
//		std::cout << std::endl;
//	}
//	out << std::endl;
//	return out;
//}


_CMATRIX void CMatrix::Assign(float *pSourceVale)
{
	size_t index = 0;
	for (size_t row_idx = 0; row_idx != row; ++row_idx)
	{
		for (size_t col_idx = 0; col_idx != col; ++col_idx)
		{
			pMatrix[row_idx][col_idx] = pSourceVale[index++];
		}
	}
}


_CMATRIX void CMatrix::Transpose()
{
	float **pTemp;
	pTemp = new float*[col];
	for (size_t idx = 0; idx != col; ++idx)
	{
		pTemp[idx] = new float[row];
	}
	for (size_t row_idx = 0; row_idx != row; ++row_idx)
	{
		for (size_t col_idx = 0; col_idx != col; ++col_idx)
		{
			pTemp[col_idx][row_idx] = pMatrix[row_idx][col_idx]; 
		}
	}
	std::swap(row, col);
	pMatrix = pTemp;
}


_CMATRIX void CMatrix::Dump(std::ostream &s)
{
	for (size_t row_idx = 0; row_idx != row; ++row_idx)
	{
		for (size_t col_idx = 0; col_idx != col; ++col_idx)
		{
			std::cout << std::left << std::setw(8) << pMatrix[row_idx][col_idx]; 
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


//operator "()" overload
_CMATRIX float CMatrix::operator ()(const int &nRow, const int &nCol)
{
	if(nRow >= row || nCol >= col)
	{
		std::cout << "Invalid reference, exceed the matrix boundary!" << std::endl;
		return -1;
	}

	else
		return pMatrix[nRow][nCol];
}


//operator "==" overload
_CMATRIX bool CMatrix::operator ==(const CMatrix &rightMatrix)
{
	if(rightMatrix.row != row || rightMatrix.col != col)
	{
		std::cout << "Dimensions do not match" << std::endl;
		return false;
	}
	else
	{
		for(int row_idx = 0; row_idx != row; ++row_idx)
		{
			for(int col_idx = 0; col_idx != col; ++col_idx)
			{
				if(pMatrix[row_idx][col_idx] != rightMatrix.pMatrix[row_idx][col_idx])
				{
					std::cout << "Elements do not match" << std::endl;
					return false;
				}
			}
		}

		return true;
	}
}

