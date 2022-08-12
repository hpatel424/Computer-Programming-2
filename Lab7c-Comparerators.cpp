

//Harry Patel

//Class Notes on using sort method in list STL
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Person
{
private:
	string fname, lname;
	int ss;
public:
	Person(int arg1, string arg2, string arg3) {
		ss = arg1;
		fname = arg2;
		lname = arg3;
	}
	string getLname() { return lname; }
	string getFname() { return fname; }
	int getSS() { return ss; }
	void display() {
		cout << this->getFname() << "\t" << this->getLname() << "\t" << this->getSS() << endl;
	}
};

//comparator for the list sort method
bool firstNameCompare(Person* arg1, Person* arg2) {

	return(arg1->getFname() < arg2->getFname());

}
bool lastNameCompare(Person* arg1, Person* arg2) {

	return(arg1->getLname() < arg2->getLname());

}
int main(void)
{
	list<Person*> myList;

	myList.push_back(new Person(123, "Jim", "Manry"));
	myList.push_back(new Person(456, "Aaron", "Bartmis"));
	myList.push_back(new Person(234, "Mandy", "Astgra"));
	myList.push_back(new Person(111, "Zoe", "Catmil"));
	myList.push_back(new Person(312, "Jane", "Darhma"));

	myList.sort(firstNameCompare);
	
	cout << "Sorted by First Name: " << endl;
	for (list<Person*>::iterator myItr = myList.begin(); myItr != myList.end(); myItr++) {
		(*myItr)->display();
	}

	myList.sort(lastNameCompare);

	cout << "\nSorted by Last Name: " << endl;
	for (list<Person*>::iterator myItr = myList.begin(); myItr != myList.end(); myItr++) {
		(*myItr)->display();
	}


	system("pause");
	return (0);
}