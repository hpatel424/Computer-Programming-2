

//Harry Patel

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <list>
using namespace std;

int stringToIndexHash(string userName, int size);
void simplePrintTable(list<string>[], int); //pass array and size

int main(void) {
	
	string input;
	char response = 'y';
	const int size = 3;
	list<string>hash[size];

	do {

		cout << "Enter name: ";
		getline(cin, input);

		int key = stringToIndexHash(input, size);
		hash[key].push_back(input);
		hash[key].sort();
		simplePrintTable(hash, size);
		
		cout << "Enter again? (y or n): ";
		cin >> response;
		cin.ignore();
		cout << endl;

	} while (response == 'y' || response == 'Y');

	

	system("pause");
	return(0);
}

int stringToIndexHash(string userName, int size) {

	int add = 0;
	for (int i = 0; i < userName.size(); i++) {
		add = add + (int)userName[i];
	}
	return add % size;
}

//Implementations
void simplePrintTable(list<string> arg[], int size) {
	// Print the buckets...
	list<string>::iterator myItr;

	for (int i = 0; i < size; i++) {
		cout << "bucket " << i << " ==> ";
		myItr = arg[i].begin();

		while (myItr != arg[i].end()) {
			cout << *myItr << ", ";
			myItr++;
		}
		cout << endl;
	}
}