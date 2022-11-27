#include<iostream>
#include<string>
#include<conio.h>
#include<math.h>
using namespace std;

class binaryCalculator {
private:
	bool isBinary(string number); // function to check whether a number is binary or not
	string addition(string numberOne, string numberTwo); // function that adds two binary numbers and returns result
	string twosComplement(string number); // function that returns 2's complement of a binary number
	void takeCarry(string& number, int i); // function that takes carry from MSB
	string subtraction(string numberOne, string numberTwo); // function that subtracts two binary numbers and returns result
	int returnDecimal(string number); // function that returns decimal value of a binary nummber
	void inputBinaryNumber(string& number); // function to input a binary number to a variable
public:
	void app();
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
string binaryCalculator::addition(string numberOne, string numberTwo) {
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
string binaryCalculator::twosComplement(string number) {
	string complement = "\0";
	for (int i = 0; i < number.length(); i++) {
		if (number[i] == '1') {
			number[i] = '0';
		}
		else {
			number[i] = '1';
		}
	}
	complement = addition(number, "1");
	return complement;
}
void binaryCalculator::takeCarry(string& number, int i) {
	if (i == -1) {
		return;
	}
	else if (number[i] == '1') {
		number[i] = '0';
		return;
	}
	else if (number[i] == '0') {
		takeCarry(number, i - 1);
		number[i] = '1';
		return;
	}
}
string binaryCalculator::subtraction(string numberOne, string numberTwo) {
	string result = "\0";
	int i = 0, j = 0;
	for (i = numberOne.length() - 1, j = numberTwo.length() - 1; i >= 0 && j >= 0; i--, j--) {
		if (numberOne[i] == '0' && numberTwo[j] == '0') {
			result = '0' + result;
		}
		else if (numberOne[i] == '1' && numberTwo[j] == '0') {
			result = '1' + result;
		}
		else if (numberOne[i] == '1' && numberTwo[j] == '1') {
			result = '0' + result;
		}
		else {
			result = '1' + result;
			takeCarry(numberOne, i-1);
		}
	}
	return result;
}
int binaryCalculator::returnDecimal(string number) {
	int decimalNumber = 0;
	for (int i = number.length() - 1, j = 0; i >= 0; i--, j++) {
		if (number[i] == '0') {
			continue;
		}
		else {
			decimalNumber += 1*pow(2, j);
		}
	}
	return decimalNumber;
}
void binaryCalculator::inputBinaryNumber(string& number) {
	getline(cin, number);
	while (!isBinary(number)) {
		cout << "\nError: Number should only contain 0s and 1s\n";
		cout << "Enter Number again: ";
		getline(cin, number);
	}
}
void binaryCalculator::app() {
	string numberOne = "\0", numberTwo = "\0", result = "0";
	char option = '\0';
	while (true) {
		numberOne = "\0";
		numberTwo = "\0";
		result = "\0";
		option = '\0';
		system("cls");
		cout << "BINARY CALCULATOR\n";
		cout << "1. Binary Addition\n";
		cout << "2. Binary Subtraction\n";
		cout << "3. Convert Binary Number to Decimal Number\n";
		cout << "Option: ";
		option = _getche();
		switch (option) {
		case '1':
			cout << "\n\nEnter Number 1: ";
			inputBinaryNumber(numberOne);
			cout << "Enter Number 2: ";
			inputBinaryNumber(numberTwo);
			result = addition(numberOne, numberTwo);
			cout << "Result: " << result << '\n';
			cout << "\nPress any key to return...";
			_getch();
			break;
		case '2':
			cout << "\n\nEnter Number 1: ";
			inputBinaryNumber(numberOne);
			cout << "Enter Number 2: ";
			inputBinaryNumber(numberTwo);
			result = subtraction(numberOne, numberTwo);
			cout << "Result: " << result << "\n";
			cout << "\nPress any key to return...";
			_getch();
			break;
		case '3':
			cout << "\n\nEnter a number: ";
			inputBinaryNumber(numberOne);
			result = returnDecimal(numberOne);
			cout << "Result: " << result << "\n";
			cout << "\nPress any key to return...";
			_getch();
		default:
			break;
		}
	}
}

int main() {
	binaryCalculator calc;
	calc.app();

	return 0;
}
