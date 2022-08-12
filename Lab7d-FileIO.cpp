

//Harry Patel

#include <iostream> 
#include<fstream>
#include<string>
#include<list>

using namespace std;

class Person {
private:
	string name;
	int age;
public:

	Person(string argn, int arga);
	void setName(string argn);
	string getName(void);

	void setAge(int arga);
	int getAge(void);

};

bool personCompare(Person* arg1, Person* arg2);

int main() {

	char response = 'y';
	int age = 0;
	string name;
	list<Person*> personList;
	list<Person*>::iterator itr;
	ifstream myFilei;
	ofstream myFileo;
	
	
	cout << "Person List";
	do {

		cout << "\nEnter Persons Name: ";
		getline(cin, name);
		cout << "Enter Persons Age: ";
		cin >> age;

		personList.push_back(new Person(name, age));
		

		cout << "Add again? (y or n): ";
		cin >> response;
		cin.ignore();
		
	} while (response == 'y' || response == 'Y');

	personList.sort(personCompare);
	itr = personList.begin();

	myFileo.open("person.txt");

	for (itr = personList.begin(); itr != personList.end(); itr++) {
		myFileo << "Name: " << (*itr)->getName() << "  Age: " << (*itr)->getAge() << endl;
	}
	myFileo.close();

	//****************** Part-2 ********************************
	
	myFilei.open("person.txt");
	
	
	string line;
	string arr[] = { line };
	cout << endl;

	for (int i = 0; i < personList.size(); i++) {
		while (!myFilei.eof()) {
			getline(myFilei, line);
			arr[i] = line;
			cout << arr[i] << endl;
		}
	}
	
	myFilei.close();

	system("pause");
	return(0);
}

Person::Person(string argn, int arga) {
	name = argn;
	age = arga;
}

void Person::setName(string argn) {
	name = argn;
}
string Person::getName(void) {
	return name;
}

void Person::setAge(int arga) {
	if (arga >= 0) {
		age = arga;
	}
	else {
		age = 0;
	}
}
int Person::getAge(void) {
	return age;
}

bool personCompare(Person* arg1, Person* arg2) {
	return(arg1->getAge() < arg2->getAge());
}