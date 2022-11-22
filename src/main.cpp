#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

class binaryCalculator {
private:
	string numberOne, numberTwo, result;
	char option;
	bool isBinary(string number);
	string binaryAddition(string numberOne, string numberTwo);
public:
	binaryCalculator() {
		numberOne = "\0";
		numberTwo = "\0";
		result = "\0";
		option = '\0';
	}
	void run() {
		while (true) {
			system("cls");
			cout << "BINARY CALCULATOR\n";
			cout << "1. Addition\n";
			cout << "2. Subtraction\n";
			cout << "3. Multiplication\n";
			cout << "4. Division\n";
			cout << "Option: ";
			option = _getche();
			switch (option) {
			case '1':
				break;
			default:
				break;
			}
		}
	}
};
bool binaryCalculator::isBinary(string number) {
	bool binary = true;
	for (int i = 0; i < number.length(); i++) {
		if (number[i] == '0' || number[i] == '1') {
			continue;
		}
		binary = false;
	}
	return binary;
}
string binaryCalculator::binaryAddition(string numberOne, string numberTwo) {
	string result = "\0";
	int i = 0, j = 0;
	bool carry = 0;
	for (i = numberOne.length() - 1, j = numberTwo.length() - 1; i >= 0 && j >= 0; i--, j--) {
		if (numberOne[i] == '0' && numberTwo[j] == '0') {
			if (carry) {
				result = '1' + result;
				carry = 0;
				continue;
			}
			result = '0' + result;
			continue;
		}
		else if (numberOne[i] == '0' && numberTwo[j] == '1') {
			if (carry) {
				result = '0' + result;
				carry = 1;
				continue;
			}
			result = '1' + result;
			continue;
		}
		else if (numberOne[i] == '1' && numberTwo[j] == '0') {
			if (carry) {
				result = '0' + result;
				carry = 1;
				continue;
			}
			result = '1' + result;
			continue;
		}
		else {
			if (carry) {
				result = '1' + result;
				carry = 1;
				continue;
			}
			result = '0' + result;
			carry = 1;
			continue;
		}
	}
	while (i >= 0 && carry) {
		if (numberOne[i] == '0') {
			carry = 0;
			result = '1' + result;
		}
		else {
			result = '0' + result;
		}
		i--;
	}
	while (i >= 0 && !carry) {
		result = numberOne[i] + result;
		i--;
	}
	while (j >= 0 && carry) {
		if (numberTwo[j] == '0') {
			carry = 0;
			result = '1' + result;
		}
		else {
			result = '0' + result;
		}
		j--;
	}
	while (j >= 0 && !carry) {
		result = numberTwo[j] + result;
		j--;
	}
	if (carry) {
		result = '1' + result;
		carry = 0;
	}
	return result;
}


int main() {
	binaryCalculator calc;
	calc.run();
	
	return 0;
}
