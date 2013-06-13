
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
	_CMATRIX ~CMatrix();
	_CMATRIX void AssignValue(float *pSourceVale);
	_CMATRIX void InverseMatrix();
	_CMATRIX void PrintMatrix();

};