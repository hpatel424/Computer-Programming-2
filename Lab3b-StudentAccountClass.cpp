
//Harry Patel

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
	string firstName, lastName;
public:
	Person(string argf = "N/A", string argl = "N/A");

	void setFirst(string argf);
	string getFirst(void);

	void setLast(string argl);
	string getLast(void);

	virtual void print(void);

	~Person();
};

class Student : public Person {
private:
	int id, units;
	double deposit, withdraw;
public:
	Student(string argf = "N/A", string argl = "N/A", int argid = 111, double argd = 0.0, double argw = 0.0, int argu = 0);

	void setId(int argid);
	int getId(void);

	void setDeposit(double argd);
	double getDeposit(void);

	void setWithdraw(double argw);
	double getWithdraw(void);

	void setAddUnit(int argu);
	int getAddUnit(void);

	int unitBalance(void);
	double accountBalance(void);
	void print(void);

	~Student();
};


int main() {

	Student* student1ptr;
	student1ptr = new Student("James", "Gates", 222, 800.50, 50.25, 12);

	student1ptr->print();
	cout << "*****************************\n" << endl;

	delete student1ptr;
	student1ptr = NULL;

	Student* student2ptr;
	student2ptr = new Student("Rich", "Man", 333, 1500.63, 9.99);
	student2ptr->setAddUnit(12);

	student2ptr->print();
	cout << endl;

	delete student2ptr;
	student2ptr = nullptr;

	
	system("pause");
	return 0;
}



Person::Person(string argf, string argl) {
	setFirst(argf);
	setLast(argl);
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
void Person::print(void) {
	string f = getFirst();
	string l = getLast();
	cout << "Name: " << f << " " << l << endl;
}

Person::~Person() {

}

Student::Student(string argf,string argl,int argid, double argd, double argw, int argu): Person(argf,argl) {
	Person::setFirst(argf);
	Person::setLast(argl);
	setId(argid);
	setDeposit(argd);
	setWithdraw(argw);
	setAddUnit(argu);
}

void Student::setId(int argid) {
	id = argid;
}
int Student::getId(void) {
	return id;
}

void Student::setDeposit(double argd) {
	if (argd > 0)
		deposit = argd;
	else
		deposit = 0;
}
double Student::getDeposit(void) {
	return deposit;
}

void Student::setWithdraw(double argw) {
	if (argw > 0)
		withdraw = argw;
	else
		withdraw = 0;
}
double Student::getWithdraw(void) {
	return withdraw;
}

void Student::setAddUnit(int argu) {
	if (argu >= 0)
		units = argu;
	else
		units = 0;
}
int Student::getAddUnit(void) {
	return units;
}

int Student::unitBalance(void) {
	int u = getAddUnit();
	return u * 46;
}

double Student::accountBalance(void) {
	double d = getDeposit();
	double w = getWithdraw();
	double ub = unitBalance();
	return d - w - ub;
}


void Student::print(void){
	int i = getId();
	double d = getDeposit();
	double w = getWithdraw();
	int u = getAddUnit();
	double a = accountBalance();
	double ub = unitBalance();

	Person::print();
	cout << "COS ID: @" << i << endl;
	cout << "Total Number of Unit(s): " << u << endl << endl;
	cout << "Amount Deposit $" << d << endl;
	cout << "Amount Withdraw $-" << w << endl;
	cout << "Unit(s) Cost $-" << ub << endl;
	cout << "--------------------------" << endl;
	cout << "Account Balance $" << a << endl;
}


Student::~Student() {

}