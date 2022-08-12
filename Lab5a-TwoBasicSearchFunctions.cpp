

//Harry Patel

#include <iostream>
#include<list>
#include<cstdlib>
#include<ctime>

using namespace std;

list<int>::iterator searchListLinear(list<int>& arg, int target);
list<int>::iterator searchListBinary(list<int>& arg, int target);

int main() {

	srand(time(0));
	int const size = 100;
	
	list<int> myNumbers;
	list<int>::iterator itr;
	int r, i = 0, input;
	char response = 'y';
	
	do {
		int r = rand() % 301;
		myNumbers.sort();
		myNumbers.unique();
		myNumbers.push_back(r);
		myNumbers.sort();

	} while (myNumbers.size() != size);

	cout << "Size: " << myNumbers.size() << endl;
	

	for (itr = myNumbers.begin(); itr != myNumbers.end(); itr++) {
		i++;
		cout << i << ") " << (*itr) << endl;
	}

	do {

		cout << "------------------------------------------\n";
		cout << "Enter a number between 0-300 to search in the list : ";
		cin >> input;

		itr = searchListLinear(myNumbers, input);

		cout << "**************Linear**************\n";

		if (itr != myNumbers.end()) {
			cout << *itr <<" integer found"<< endl;
		}
		else {
			cout << "integer not found" << endl;
		}

		itr = searchListBinary(myNumbers, input);

		cout << "**************Binary**************\n";

		if (itr != myNumbers.end()) {
			cout << *itr << " integer found" << endl;
		}
		else {
			cout << "integer not found" << endl;
		}

		cout << "search again (y or n)?";
		cin >> response;
		cin.ignore();

	} while (response == 'y' || response == 'Y');

	system("pause");
	return 0;
}


list<int>::iterator searchListLinear(list<int>& arg, int target) {
	
	list<int>::iterator itr;
	for (itr = arg.begin(); itr != arg.end(); itr++) {
		if ((*itr) == target) {
			return itr;
		}
	}
	return arg.end();
}


list<int>::iterator searchListBinary(list<int>& arg, int target) {
	
	if (target < arg.front() || target > arg.back()) { //out of range, dont bother looking
		return arg.end();
	}
	list<int>::iterator start = arg.begin(); // ends the loop and narrows search
	list<int>::iterator finish = arg.end(); //ends loop and narrows search
	finish--; //starting at the last element because .end is really like the nulptr after the last element
	int mid = arg.size() / 2; //mid point
	while (*start <= *finish) {

		list<int>::iterator index = start;
		for (int i = 0; i < mid; i++) {
			index++; //put the index at mid so it only searches half
			//do not count this in the algorithm comparison count
		}

		if (target == *index) {
			return index;
		}
		if (target < *index) {
			finish = --index; //minus one so we dont search mid again
		}
		else {
			start = ++index; //plus one so we dont search mid again
		}
		mid = (mid - 1) / 2;
	}
	return arg.end(); //if not found
}