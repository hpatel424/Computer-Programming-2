
//Harry Patel

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
private:
	string firstName, lastName;
	int age;
	string gender;

public:
	Person(string argf = "N/A", string argl = "N/A", int arga = 0, string argg = "N/A");

	void setFirst(string argf);
	string getFirst(void);

	void setLast(string argl);
	string getLast(void);

	void setAge(int arga);
	int getAge(void);

	void setGender(string argg);
	string getGender(void);

	
	virtual void display(void);
};

class Student : public Person {
private:
	int id;
	float gpa;
	string major;
public:
	Student(string argf = "N/A", string argl = "N/A", int arga = 0, string argg = "N/A", int argid = 0, float arggpa = 0.0, string argm = "N/A");

	void setId(int argid);
	int getId(void);

	void setGpa(float arggpa);
	float getGpa(void);

	void setMajor(string argm);
	string getMajor(void);

	
	void display(void);

};


class Athlete : public Person {
private:
	int id;
	string sports;

public:
	Athlete(string argf = "N/A", string argl = "N/A", int arga = 0, string argg = "N/A",int argid = 0, string args = "N/A");
	
	void setID(int argid);
	int getID(void);

	void setSports(string args);
	string getSports(void);

	
	void display(void);
};


class Employee : public Person {
private:
	int id;
	double salary;
	string department;

public:
	Employee(string argf = "N/A", string argl = "N/A", int arga = 0, string argg = "N/A",int argid = 0, double args = 0.0, string argd = "N/A");

	void setID(int argid);
	int getID(void);

	void setSalary(double args);
	double getSalary(void);

	void setDepartment(string argd);
	string getDepartment(void);

	
	void display(void);
};

int main() {

	// Vector of base class pointers (To enable polymorphism)
	vector<Person*> myShapeList;

	myShapeList.push_back(new Student("Aron", "Finch", 20, "Male", 333, 3.7, "Math"));
	myShapeList.push_back(new Athlete("Ab de", "Villers", 30, "M", 17, "Baseball"));
	myShapeList.push_back(new Employee("Jaenne", "Steyn", 30, "F", 76097, 6096.5, "Working"));


	for (int i = 0; i < myShapeList.size(); i++) {
		cout << "Person " << i + 1 << ": " << typeid(*myShapeList[i]).name() << endl;
		// polymorphism here
		 myShapeList[i]->display();
		 cout << endl;
	}

	// memory management...
	while (!myShapeList.empty()) {

		//cout << "Deleting " << typeid(*myShapeList.back()).name() << endl;

		delete myShapeList.back(); //deallocate memory
		myShapeList.pop_back(); // pop address off vector
		//cout << "Num Shapes in vector: " << myShapeList.size() << endl;

	}
	
	system("pause");
	return 0;
}


Person::Person(string argf, string argl, int arga, string argg) {
	setFirst(argf);
	setLast(argl);
	setAge(arga);
	setGender(argg);
}

void Person::setFirst(string argf) {
	firstName = argf;
}
string Person::getFirst(void) {
	return firstName;
}

void Person::setLast(string argl) {
	lastName = argl;
}
string Person::getLast(void) {
	return lastName;
}

void Person::setAge(int arga) {
	age = arga;
}
int Person::getAge(void) {
	return age;
}

void Person::setGender(string argg) {
	gender = argg;
}
string Person::getGender(void) {
	return gender;
}


void Person::display(void) {
	cout << "First Name: " << getFirst() << endl;
	cout << "Last Name: " << getLast() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Gender: " << getGender() << endl;
}

//****************Student***************************************

Student::Student(string argf, string argl, int arga, string argg,int argid, float arggpa, string argm) {
	setFirst(argf);
	setLast(argl);
	setAge(arga);
	setGender(argg);

	setId(argid);
	setGpa(arggpa);
	setMajor(argm);
}

void Student::setId(int argid) {
	id = argid;
}
int Student::getId(void) {
	return id;
}

void Student::setGpa(float arggpa) {
	gpa = arggpa;
}
float Student::getGpa(void){
	return gpa;
}

void Student::setMajor(string argm) {
	major = argm;
}
string Student::getMajor(void) {
	return major;
}


void Student::display(void) {
	Person::display();
	cout << "Student ID: " << getId() << endl;
	cout << "GPA: " << getGpa() << endl;
	cout << "Major: " << getMajor() << endl;
}

//*****************Athlete*************************************

Athlete::Athlete(string argf, string argl, int arga, string argg,int argid, string args) {
	setFirst(argf);
	setLast(argl);
	setAge(arga);
	setGender(argg);

	setID(argid);
	setSports(args);
}

void Athlete::setID(int argid) {
	id = argid;
}
int Athlete::getID(void) {
	return id;
}

void Athlete::setSports(string args) {
	sports = args;
}
string Athlete::getSports(void) {
	return sports;
}


void Athlete::display(void) {
	Person::display();
	cout << "Athlete ID: " << getID() << endl;
	cout << "Sports: " << getSports() << endl;
}

//************************Employee*****************************


Employee::Employee(string argf, string argl, int arga, string argg,int argid, double args , string argd ) {
	setFirst(argf);
	setLast(argl);
	setAge(arga);
	setGender(argg);

	setID(argid);
	setSalary(args);
	setDepartment(argd);
}

void Employee::setID(int argid) {
	id = argid;
}
int Employee::getID(void) {
	return id;
}

void Employee::setSalary(double args) {
	salary = args;
}
double Employee::getSalary(void) {
	return salary;
}

void Employee::setDepartment(string argd) {
	department = argd;
}
string Employee::getDepartment(void) {
	return department;
}


void Employee::display(void) {
	Person::display();
	cout << "Employee ID: " << getID() << endl;
	cout << "Salary $" << getSalary() << endl;
	cout << "Department: " << getDepartment() << endl;
}