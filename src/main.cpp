#include<iostream>
using namespace std;

class binaryCalculator {
private:

public:
	bool isBinary(string number);
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

int main() {
	binaryCalculator calc;

	return 0;
}
