#include <iostream>
#include "RationalNumber.h"
#include "Program.h"

void Program::workShow() {

	auto num1 = 0;
	std::cout << "Input the numerator of the 1st fraction: ";
	std::cin >> num1;

	auto den1 = 0;
	std::cout << "Input the denominator of the 1st fraction: ";
	std::cin >> den1;

	auto num2 = 0;
	std::cout << "Input the numerator of the 2nd fraction: ";
	std::cin >> num2;

	auto den2 = 0;
	std::cout << "Input the denominator of the 2nd fraction: ";
	std::cin >> den2;

	RationalNumber <int> fraction1 (num1, den1);
	RationalNumber <int> fraction2(num2, den2);
	RationalNumber <int> fractionTest;

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

