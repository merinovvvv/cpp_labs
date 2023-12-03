#ifndef DEMOMATRIX_SRC_MATRIX_H_
#define DEMOMATRIX_SRC_MATRIX_H_


class Matrix {
private:
	int** a_;
	int n_;
	int m_;
public:
	Matrix();
	~Matrix();
	Matrix(const Matrix& other);
	Matrix(Matrix&& other) noexcept;
	Matrix operator= (const Matrix& other);
	Matrix operator= (Matrix&& other) noexcept;
	Matrix(const int n, const int m);
	Matrix(const int n, const int m, const int k);
	int GetN();
	int GetM();
	int** GetA();
	void show();
};

#endif //DEMOMATRIX_SRC_MATRIX_H_

