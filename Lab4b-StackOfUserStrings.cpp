

//Harry Patel

#include<iostream>
#include <stack>
#include<string>

using namespace std;

void print(stack<string*> arg);

int main() {

	char response = 'y';
	string userString = "";
	stack<string*> myStack;

	do {

		cout << "Enter string: ";
		getline(cin, userString);

		myStack.push(new string(userString));


		cout << "Add another string (y or n)?";
		cin >> response;
		cin.ignore();

	} while (response == 'y');

	print(myStack);

	//Memory Management

	while (!myStack.empty()) {
		delete myStack.top();
		myStack.pop();
	}
	print(myStack);

	system("pause");
	return 0;
}

void print(stack<string*> arg) {
	if (arg.empty()) {
		cout << "Stack is Empty!!!" << endl;
	}
	else {
		while (!arg.empty()) {
			cout << *arg.top() << endl;
			arg.pop();
		}
	}
}