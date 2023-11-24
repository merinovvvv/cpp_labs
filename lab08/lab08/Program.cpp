#include <iostream>
#include "RationalNumber.h"
#include "Program.h"

void Program::workShow() {
	RationalNumber <int> fraction1 (4, 2);
	RationalNumber <int> fraction2(1, 4);


	std::cout << fraction1 + fraction2 << '\n';
	RationalNumber <int> fractionTest;
	std::cout << "initial fractions:" << '\n' << "first : 4/2, second : 1/4" << '\n' << "results:\n";
	std::cout << "fraction1 OPERATION fraction2, if operation is unary (un) it is used for the first fraction\n\n";
	std::cout << "+(un)\t" << +fraction1 << '\n';
	fractionTest = fraction1 + fraction2;
	std::cout << "+\t" << fraction1 + fraction2 << '\n';
	fractionTest = fraction1;
	std::cout << "-(un)\t" << -fractionTest << '\n';
	fractionTest = fraction1 - fraction2;
	std::cout << "-\t" << fractionTest << '\n';
	fractionTest = fraction1 * fraction2;
	std::cout << "*\t" << fractionTest << '\n';
	fractionTest = fraction1 / fraction2;
	std::cout << "/\t" << fractionTest << '\n';
	fractionTest = fraction1;
	std::cout << "=\t" << "fraction1 = fraction2 = " << fractionTest << '\n';
	fractionTest = fraction1;
	fractionTest += fraction2;
	std::cout << "+=\t" << "fraction 1 = " << fraction1 << "; fraction1 += fraction2 = " << fractionTest << '\n';
	fractionTest = fraction1;
	fractionTest -= fraction2;
	std::cout << "-=\t" << "fraction 1 = " << fraction1 << "; fraction1 -= fraction2 = " << fractionTest << '\n';
	fractionTest = fraction1;
	fractionTest *= fraction2;
	std::cout << "*=\t" << "fraction 1 = " << fraction1 << "; fraction1 *= fraction2 = " << fractionTest << '\n';
	fractionTest = fraction1;
	fractionTest /= fraction2;
	std::cout << "/=\t" << "fraction 1 = " << fraction1 << "; fraction1 /= fraction2 = " << fractionTest << '\n';
	std::cout << "==\t" << (fraction1 == fraction2) << '\n';
	std::cout << "!=\t" << (fraction1 != fraction2) << '\n';
	std::cout << "<\t" << (fraction1 < fraction2) << '\n';
	std::cout << ">\t" << (fraction1 > fraction2) << '\n';
	std::cout << "<=\t" << (fraction1 <= fraction2) << '\n';
	std::cout << ">=\t" << (fraction1 >= fraction2) << '\n';
	fractionTest = fraction1;
	std::cout << "++\t" << ++fractionTest << '\n';
	fractionTest = fraction1;
	std::cout << "--\t" << --fractionTest << '\n';
}

