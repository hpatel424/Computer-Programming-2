

//Harry Patel

#include<iostream>
#include<queue>
#include <string>

using namespace std;

class Person {
private:
	string name;
	string phoneNumber;

public:

	Person(string argn, string argp);

	void setName(string argn);
	string getName(void);

	void setPhoneNumber(string argp);
	string getPhoneNumber(void);

};
void print(queue<Person*> arg);

int main() {

	queue<Person*> waitLine;
	char response = 'y', service = 'y';
	string inputName;
	string inputPhoneNumber;

	cout << "Let's Create a Customer's Wait Line " << endl;

	do{

		cout << "Enter Customer's Name: ";
		getline(cin, inputName);

		cout << "Enter Customers's Phone Number: US +1 ";
		getline(cin, inputPhoneNumber);

		waitLine.push(new Person(inputName, inputPhoneNumber));

		cout << "\nOur Next Customer is: " << endl;
		print(waitLine);

		cout << "Service Completed? (y or n): ";
		cin >> service;

		if (service == 'y' || service == 'Y') {
			waitLine.pop();
			if (waitLine.empty()) {
				cout << "The line is Empty" << endl;
			}
			else {
				cout << "\nOur Next Customer is: " << endl;
				print(waitLine);
			}
		}


		cout << "Want to add a customer in Wait Line? (y or n): ";
		cin >> response;
		cin.ignore();
		cout << endl;

	} while (response == 'y' || response == 'Y');


	while (!waitLine.empty()) {
		waitLine.pop();
	}

	system("pause");
	return 0;
}

Person::Person(string argn, string argp) {
	setName(argn);
	setPhoneNumber(argp);
}

void Person::setName(string argn) {
	name = argn;
}
string Person::getName(void) {
	return name;
}

void Person::setPhoneNumber(string argp) {
	phoneNumber = argp;
}
string Person::getPhoneNumber(void) {
	return phoneNumber;
}

void print(queue<Person*> arg) {
	
	cout << "Name: " << arg.front()->getName() << endl;
	cout << "Phone Number: " << arg.front()->getPhoneNumber() << endl;
	cout << endl;
}