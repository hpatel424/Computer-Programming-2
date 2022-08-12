

//Harry Patel

#include <iostream>
#include<string>
#include <vector>	
#include <list>

using namespace std;

class Person
{
private:
	string fname, lname;
	
public:
	Person(string arg2, string arg3);

	void setLname(string arg3);
	string getLname();

	void setFname(string arg2);
	string getFname();

};

class Student : public Person {
private:
	int COSID;
public:
	Student(int arg1, string arg2, string arg3);
	
	void setid(int arg1);
	int getid(void);
	
};

//hash function
int hashFunction(int ID, int tableSize);
bool personCompare(Student* arg1, Student* arg2);
bool search(list<Student*> arg[], int size, int id);
void print(list<Student*> arg[], int size);

int main() {

	const int tableSize = 5;

	list<Student*> myList;
	list<Student*> hashTable[tableSize];
	list<Student*>::iterator itr;
	int input = 0;
	char response = 'y';

	myList.push_back(new Student(12345, "Jim", "Manry"));
	myList.push_back(new Student(55345, "Aaron", "Bartmis"));
	myList.push_back(new Student(23434, "Mandy", "Astgra"));
	myList.push_back(new Student(11111, "Zoe", "Catmil"));
	myList.push_back(new Student(31212, "Jane", "Darhma"));
	myList.push_back(new Student(33333, "Harry", "Patel"));
	myList.push_back(new Student(98752, "Computer", "Laptop"));
	myList.push_back(new Student(98798, "Apple", "Orange"));
	myList.push_back(new Student(33806, "Jenish", "Patel"));

	myList.sort(personCompare);
	itr = myList.begin();

	while (itr != myList.end()) {
		int key = hashFunction((*itr)->getid(), tableSize);
		int id = (*itr)->getid();
		string f = (*itr)->getFname();
		string l = (*itr)->getLname();
		hashTable[key].push_back(new Student(id, f, l));
		itr++;
	}
	hashTable->sort(personCompare);

	print(hashTable, tableSize);

	cout << "**************************************" << endl;
	do {
		
		cout << "\nEnter a COSID to search: ";
		cin >> input;

		bool s = search(hashTable, tableSize, input);
		itr = myList.begin();

		if (s == true) {
			while ((*itr)->getid() != input) {
				itr++;
			}
			cout << "COSID: " << (*itr)->getid() << endl;
			cout << "First Name: " << (*itr)->getFname() << endl;
			cout << "Last Name: " << (*itr)->getLname() << endl;
		}
		else {
			cout << "Error 404! NOT Found" << endl;
		}

		cout << "Search again? (y or n): ";
		cin >> response;

	} while (response == 'y' || response == 'Y');


	system("pause");
	return 0;
}
Person::Person(string arg2, string arg3) {
	setLname(arg3);
	setFname(arg2);
}

Student::Student(int arg1, string arg2, string arg3) :Person(arg2, arg3) {
	setid(arg1);
	Person::setLname(arg3);
	Person::setFname(arg2);
}

void Person::setLname(string arg3) {
	lname = arg3;
}
void Person::setFname(string arg2) {
	fname = arg2;
}
void Student::setid(int arg1) {
	COSID = arg1;
}
string Person::getLname(void) {
	return lname;
}
string Person::getFname(void) {
	return fname; 
}
int Student::getid(void) {
	return COSID; 
}

int hashFunction(int ID, int tableSize) {
	return(ID % tableSize);
}

bool personCompare(Student* arg1, Student* arg2) {
	return(arg1->getid() < arg2->getid());
}

bool search(list<Student*> arg[], int size, int id) {
	list<Student*>::iterator itr;

	int i = hashFunction(id, size);
	itr = arg[i].begin();

	while (itr != arg[i].end()) {
		if ((*itr)->getid() == id) {
			int id = (*itr)->getid();
			return true;
			itr++;
		}
		return false;
	}
}

void print(list<Student*> arg[], int size) {

	list<Student*>::iterator itr;


	for (int i = 0; i < size; i++) {
		cout << "bucket " << i << " ==> ";
		itr = arg[i].begin();

		while (itr != arg[i].end()) {
			cout << (*itr)->getid() << ", ";
			cout << (*itr)->getFname() << " ";
			cout << (*itr)->getLname() << " | ";
			itr++;
		}
		cout << endl << endl;

	}
}