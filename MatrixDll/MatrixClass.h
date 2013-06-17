#include <iostream>

#ifdef MATRIXCLASS_H
#define _CMATRIX __declspec(dllexport)
#else 
#define _CMATRIX __declspec(dllimport)
#endif

class CMatrix{
private:
	float **pMatrix;
	size_t row;
	size_t col;
public:
	_CMATRIX CMatrix(size_t fuck_row, size_t fuck_col);
	//add a default CMatrix
	_CMATRIX CMatrix();
	_CMATRIX virtual ~CMatrix();
	_CMATRIX CMatrix& operator=(const CMatrix &other);
	_CMATRIX CMatrix(const CMatrix &Other);
	_CMATRIX float* GetRow(size_t row);
	_CMATRIX float* GetCol(size_t col);
	//_CMATRIX friend std::ostream& operator<<(std::ostream& out, const CMatrix &other);
	_CMATRIX void Assign(float *pSourceVale);
	_CMATRIX void Transpose();
	_CMATRIX void Dump(std::ostream &s);

	//add two functions as follows

	//_CMATRIX operator "()"  overload
	_CMATRIX float operator ()(const int &nRow, const int &nCol);
	//_CMATRIX operator "==" over load
	_CMATRIX bool operator ==(const CMatrix &rightMatrix);
};