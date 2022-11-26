#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

class binaryCalculator {
private:
	string numberOne, numberTwo, result;
	char option; 
	bool isBinary(string number); // function to check whether a number is binary or not
	string addition(string numberOne, string numberTwo); // function that add two binary numbers and return result
public:
	string twosComplement(string number); // function that returns 2's complement of a number
	binaryCalculator() {
		numberOne = "\0";
		numberTwo = "\0";
		result = "\0";
		option = '\0';
	}
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
void binaryCalculator::app() {
	while (true) {
		system("cls");
		cout << "BINARY CALCULATOR\n";
		cout << "1. Addition\n";
		// cout << "2. Subtraction\n";
		// cout << "3. Convert Binary to Decimal\n";
		cout << "Option: ";
		option = _getche();
		switch (option) {
		case '1':
			cout << "\n\nEnter Number 1: ";
			getline(cin, numberOne);
			while (!isBinary(numberOne)) {
				cout << "\nError: Number should only contain 0s and 1s\n";
				cout << "Enter Number 1 again: ";
				getline(cin, numberOne);
			}
			cout << "Enter Number 2: ";
			getline(cin, numberTwo);
			while (!isBinary(numberTwo)) {
				cout << "\nError: Number should only contain 0s and 1s\n";
				cout << "Enter Number 2 again: ";
				getline(cin, numberTwo);
			}
			result = addition(numberOne, numberTwo);
			cout << "Result: " << result << '\n';
			cout << "\nPress any key to return...";
			_getch();
			break;
		default:
			break;
		}
	}
}

int main() {
	binaryCalculator calc;
	//calc.app();

	cout << calc.twosComplement("0000") << endl;
	cout << calc.twosComplement("1010") << endl;
	cout << calc.twosComplement("0101") << endl;
	cout << calc.twosComplement("1111") << endl;
	
	return 0;
}
