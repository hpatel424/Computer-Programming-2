

//Harry Patel

#include <iostream>
#include<list>
#include<cstdlib>
#include<ctime>
#include <iterator>

using namespace std;

list<int>::iterator searchListLinear(list<int>& arg, int target, int& count);
list<int>::iterator searchListBinary(list<int>& arg, int target, int& count);

int main() {

	srand(time(0));
	int const size = 100;

	list<int> myNumbers;
	list<int>::iterator itr;
	int r, LsComparison = 0, BsComparison = 0;
	//cout << "input = " << input << endl;

	do {
		int r = rand() % 301;
		myNumbers.sort();
		myNumbers.unique();
		myNumbers.push_back(r);
		myNumbers.sort();

	} while (myNumbers.size() != size);

	cout << "Size: " << myNumbers.size() << endl;

	cout << "**************Linear**************\n";

	for (int i = 0; i < 50000; i++) {
		itr = searchListLinear(myNumbers, rand() % 301, LsComparison);
	}
	cout << "# of Comparison = " << LsComparison << endl;
	cout << "Average = " << LsComparison / 50000 << endl;
	
	
	cout << "**************Binary**************\n";

	for (int i = 0; i < 50000; i++) {
		itr = searchListBinary(myNumbers, rand() % 301, BsComparison);
	}
	cout << "# of Comparison = " << BsComparison << endl;
	cout << "Average = " << BsComparison / 50000 << endl;


	system("pause");
	return 0;
}


list<int>::iterator searchListLinear(list<int>& arg, int target, int& count) {

	list<int>::iterator itr;
	for (itr = arg.begin(); itr != arg.end(); itr++) {
		
		count++;
		if ((*itr) == target) {
			return itr;
		}
	}
	return arg.end();
}


list<int>::iterator searchListBinary(list<int>& arg, int target, int& count) {

	if (target < arg.front() || target > arg.back()) { //out of range, dont bother looking
		return arg.end();
	}
	list<int>::iterator start = arg.begin(); // ends the loop and narrows search
	list<int>::iterator finish = arg.end(); //ends loop and narrows search
	finish--; //starting at the last element because .end is really like the nulptr after the last element
	int mid = arg.size() / 2; //mid point

	while (*start <= *finish) {
		count++;

		list<int>::iterator index = start;

		advance(index, mid);

		count++;
		if (target == *index) {
			return index;
		}
		count++;
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