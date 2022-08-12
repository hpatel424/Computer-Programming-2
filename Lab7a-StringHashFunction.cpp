

//Harry Patel

#include <iostream>
#include<string>

using namespace std;

int stringToIndexHash(string userName, int size);

int main() {

	char response = 'y';
	string input;
	const int tableSize = 11;

	cout << "Bucket Index Number";

	do {
		
		cout << "\nEnter a string: ";
		getline(cin, input);

		cout << "Bucket Index Number = " << stringToIndexHash(input, tableSize) << endl;

		cout << "Run again? (y or n): ";
		cin >> response;
		cin.ignore();

	} while (response == 'y' || response == 'Y');

	system("pause");
	return 0;
}

int stringToIndexHash(string userName, int size) {
	
	int add = 0;
	for (int i = 0; i < userName.size(); i++) {
		add = add + (int)userName[i];
	}
	return add % size;
}