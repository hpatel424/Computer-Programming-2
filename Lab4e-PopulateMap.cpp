

//Harry Patel

#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

class Person {
public:
	Person(string = "", string = "", bool = 0, int = 0);

	void setFName(string);
	void setLName(string);
	void setGender(bool);
	void setAge(int);

	string getFName();
	string getLName();
	bool getGender();
	int getAge();

	void display();

private:
	string firstName, lastName;
	bool gender;
	int age;
};


int main(){

	map<string, Person*> email_to_name;
	map<string, Person*>::iterator itr;

	string input;
	char response = 'y';
	
	email_to_name["maryj@cos.edu"] = new Person("mary", "jones", 0, 22);
	email_to_name["bills@cos.edu"] = new Person("bill", "smith", 1, 23);
	email_to_name["jerryj@cos.edu"] = new Person("jerry", "jones", 1, 25);
	email_to_name["bens@cos.edu"] = new Person("Ben", "stocks", 1, 26);
	email_to_name["jpm@cos.edu"] = new Person("JP", "Morgan", 1, 21);
	

	itr = email_to_name.begin();
	
	cout << "Entire original database\n" << endl;

	while (itr != email_to_name.end()) {
		cout << "Key : " << (*itr).first << endl;
		cout << "Value: \n";
		(*itr).second->display();
		itr++;
	}
	cout << "************************************" << endl;
	do {
		
		cout << "Enter E-mail to pull up first name : ";
		getline(cin, input);

		if (input == "maryj@cos.edu" || input == "bills@cos.edu" || input == "jerryj@cos.edu" || input == "bens@cos.edu" || input == "jpm@cos.edu") {
			cout << "First Name : " << email_to_name[input]->getFName() << endl;
		}
		else {
			cout << "NOT in database" << endl;
		}

		cout << "Search again? ";
		cin >> response;
		cin.ignore();

	} while (response == 'y' || response == 'Y');

	

	system("pause");
	return(0);
}

Person::Person(string argF, string argL, bool argG, int argA)
{
	setFName(argF);
	setLName(argL);
	setGender(argG);
	setAge(argA);
}

void Person::setFName(string arg)
{
	arg[0] = toupper(arg[0]);
	firstName = arg;
}
void Person::setLName(string arg)
{
	arg[0] = toupper(arg[0]);
	lastName = arg;
}
void Person::setGender(bool arg)
{
	gender = arg;
}
void Person::setAge(int arg)
{
	age = arg;
}

string Person::getFName()
{
	return firstName;
}
string Person::getLName()
{
	return lastName;
}
bool Person::getGender()
{
	return gender;
}
int Person::getAge()
{
	return age;
}

void Person::display()
{
	cout << "Name : " << getFName() << " " << getLName() << endl;
	if (getGender() == true) {
		cout << "Gender : Male" << endl;
	}
	else {
		cout << "Gender: Female" << endl;
	}
	cout << "Age : " << getAge() << endl << endl;
}
