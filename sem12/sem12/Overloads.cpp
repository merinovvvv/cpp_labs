#include <iostream>
#include "Matrix.h"

Matrix Matrix::operator+ (const Matrix& other) const {
	try {
		Matrix result(n_, m_);
		if (n_ == other.n_ && m_ == other.m_) {

			for (size_t i = 0; i < n_; ++i) {
				for (size_t j = 0; j < m_; ++j) {
					result.a_[i][j] = a_[i][j] + other.a_[i][j];
				}
			}
		}
		else {
			throw std::logic_error("sum error.");
		}
		return result;
	}
	catch (const std::exception& e) {
		// Обработка исключения
		std::cerr << "Error during calculations: " << e.what() << std::endl;
		exit(0);
	}
}

Matrix Matrix::operator- (const Matrix& other) const {
	try {
		Matrix result(n_, m_);
		if (n_ == other.n_ && m_ == other.m_) {
			for (size_t i = 0; i < n_; ++i) {
				for (size_t j = 0; j < m_; ++j) {
					result.a_[i][j] = a_[i][j] - other.a_[i][j];
				}
			}
		}
		else {
			throw std::logic_error("subtraction error.");
		}
		return result;
	}
	catch (const std::exception& e) {
		std::cerr << "Error during calculations: " << e.what() << std::endl;
		exit(0);
	}
}

Matrix Matrix::operator* (const int& other) const {
	Matrix result(n_, m_);
	for (size_t i = 0; i < n_; ++i) {
		for (size_t j = 0; j < m_; ++j) {
			result.a_[i][j] = a_[i][j] * other;
		}
	}
	return result;

}

Matrix Matrix::operator/ (const int& other) const {
	try {
		if (other == 0) {
			throw std::logic_error("division by 0.");
		}
		Matrix result(n_, m_);
		for (size_t i = 0; i < n_; ++i) {
			for (size_t j = 0; j < m_; ++j) {
				result.a_[i][j] = a_[i][j] / other;
			}
		}
		return result;
	}
	catch (std::exception& e) {
		std::cerr << "Error during calculations: " << e.what() << std::endl;
	}
}

Matrix Matrix::operator+= (const Matrix& other) {
	return *this + other;
}

Matrix Matrix::operator-= (const Matrix& other) {
	return *this - other;
}

Matrix Matrix::operator*= (const int& other) {
	return *this * other;
}

Matrix Matrix::operator/= (const int& other) {
	return *this / other;
}

bool Matrix::operator== (const Matrix& other) const {
	bool result = false;
	if (n_ == other.n_ && m_ == other.m_) {
		for (size_t i = 0; i < n_; ++i) {
			for (size_t j = 0; j < m_; ++j) {
				if (a_[i][j] = other.a_[i][j]) {
					result = true;
				}
			}
		}
	}
	return result;
}

bool Matrix::operator!= (const Matrix& other) const {
	return !(*this == other);
}

std::ostream& operator<< (std::ostream& stream, const Matrix& matrix) {
	for (int i = 0; i < matrix.n_; i++) {
		for (int j = 0; j < matrix.m_; j++) {
			std::cout << matrix.a_[i][j] << " ";
		}
		std::cout << '\n';
	}
	return stream;
}

std::istream& operator>> (std::istream& in, const Matrix& matrix) {

	for (size_t i = 0; i < matrix.n_; ++i) {
		for (size_t j = 0; j < matrix.m_; ++j) {
			in >> matrix.a_[i][j];
		}
	}
	return in;
}
