#include<iostream>
using namespace std;

class binaryCalculator {
private:
	bool isBinary(string number);

public:
	string binaryAddition(string numberOne, string numberTwo);
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
	for (i = numberOne.length() - 1, j = numberTwo.length() - 1; i > 0 || j > 0; i--, j--) {
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
	return result;
}

int main() {
	binaryCalculator calc;
	cout << calc.binaryAddition("0", "0");
	cout << calc.binaryAddition("1", "0");
	cout << calc.binaryAddition("0", "1");
	cout << calc.binaryAddition("1", "1");



	return 0;
}
