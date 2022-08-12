

//Harry Patel
#include<iostream>
#include<string>

using namespace std;

template <class T>
class Student {
private:
	string firstName, lastName;
	int ID;
	float w1, w2, w3, w4;
	T t1, t2, t3, t4;

public:
	Student(string arg1 = "N/A", string arg2 = "N/A", int arg3 = 0, float w1 = 0, float w2 = 0, float w3 = 0, float w4 = 0, T t1 = 0, T t2 = 0, T t3 = 0, T t4 = 0);

	string getFirstName(void);
	void setFirstName(string first);

	string getLastName(void);
	void setLastName(string last);

	int getID(void);
	void setID(int id);

	float getW1(void);
	void setW1(float W1);
	float getW2(void);
	void setW2(float W2);
	float getW3(void);
	void setW3(float W3);
	float getW4(void);
	void setW4(float W4);

	T getT1(void);
	void setT1(T test1);
	T getT2(void);
	void setT2(T test2);
	T getT3(void);
	void setT3(T test3);
	T getT4(void);
	void setT4(T test4);

	T getWeightedAvg(void);
	char getGrade(void);

	void print(void);
};

int main() {

	Student <int>A("ABC", "DEF", 111, 0.10, 0.15, 0.25, 0.50);
	A.setT1(85.5);
	A.setT2(83);
	A.setT3(96.2);
	A.setT4(77);

	Student <float>B;
	B.setFirstName("GHI");
	B.setLastName("JKL");
	B.setID(222);
	B.setW1(0.10), B.setW2(0.10), B.setW3(0.30), B.setW4(0.50);
	B.setT1(99.78), B.setT2(92.66), B.setT3(87.07), B.setT4(74);

	A.print();
	cout << endl;
	B.print();

	system("pause");
	return 0;
}

template <class T>
Student<T>::Student(string arg1, string arg2, int arg3, float w1, float w2, float w3, float w4, T t1, T t2, T t3, T t4) {
	setFirstName(arg1);
	setLastName(arg2);
	setID(arg3);

	setW1(w1);
	setW2(w2);
	setW3(w3);
	setW4(w4);

	setT1(t1);
	setT2(t2);
	setT3(t3);
	setT4(t4);

}

template <class T>
string Student<T>::getFirstName(void) {
	return firstName;
}
template <class T>
void Student<T>::setFirstName(string first) {
	firstName = first;
}

template <class T>
string Student<T>::getLastName(void) {
	return lastName;
}
template <class T>
void Student<T>::setLastName(string last) {
	lastName = last;
}

template <class T>
int Student<T>::getID(void) {
	return ID;
}
template <class T>
void Student<T>::setID(int id) {
	ID = id;
}


template <class T>
float Student<T>::getW1(void) {
	return w1;
}
template <class T>
void Student<T>::setW1(float W1) {
	w1 = W1;
}
template <class T>
float Student<T>::getW2(void) {
	return w2;
}
template <class T>
void Student<T>::setW2(float W2) {
	w2 = W2;
}
template <class T>
float Student<T>::getW3(void) {
	return w3;
}
template <class T>
void Student<T>::setW3(float W3) {
	w3 = W3;
}
template <class T>
float Student<T>::getW4(void) {
	return w4;
}
template <class T>
void Student<T>::setW4(float W4) {
	w4 = W4;
}


template <class T>
T Student<T>::getT1(void) {
	return t1;
}
template <class T>
void Student<T>::setT1(T test1) {
	if (test1 <= 0)
		t1 = 0;
	else
		t1 = test1;
}
template <class T>
T Student<T>::getT2(void) {
	return t2;
}
template <class T>
void Student<T>::setT2(T test2) {
	if (test2 <= 0)
		t2 = 0;
	else
		t2 = test2;
}
template <class T>
T Student<T>::getT3(void) {
	return t3;
}
template <class T>
void Student<T>::setT3(T test3) {
	if (test3 <= 0)
		t3 = 0;
	else
		t3 = test3;
}
template <class T>
T Student<T>::getT4(void) {
	return t4;
}
template <class T>
void Student<T>::setT4(T test4) {
	if (test4 <= 0)
		t4 = 0;
	else
		t4 = test4;
}


template <class T>
T Student<T>::getWeightedAvg(void) {
	float w1 = getW1();
	float w2 = getW2();
	float w3 = getW3();
	float w4 = getW4();

	T t1 = getT1();
	T t2 = getT2();
	T t3 = getT3();
	T t4 = getT4();


	return w1 * t1 + w2 * t2 + w3 * t3 + w4 * t4;


}
template <class T>
char Student<T>::getGrade(void) {
	if (getWeightedAvg() >= 90)
		return 'A';
	else if (getWeightedAvg() >= 80 && getWeightedAvg() < 90)
		return 'B';
	else if (getWeightedAvg() >= 70 && getWeightedAvg() < 80)
		return 'C';
	else if (getWeightedAvg() >= 60 && getWeightedAvg() < 70)
		return 'D';
	else
		return 'F';
}


template <class T>
void Student<T>::print(void) {
	string fName = getFirstName();
	string lName = getLastName();
	int id = getID();

	float w1 = getW1();
	float w2 = getW2();
	float w3 = getW3();
	float w4 = getW4();

	T t1 = getT1();
	T t2 = getT2();
	T t3 = getT3();
	T t4 = getT4();

	T Avg = getWeightedAvg();
	char grade = getGrade();

	cout << "First Name: " << fName << endl;
	cout << "Last Name: " << lName << endl;
	cout << "ID: " << id << endl;
	cout << "Weights:-------------- \nW1 = " << w1 << "\nW2 = " << w2 << "\nW3 = " << w3 << "\nW4 = " << w4 << endl;
	cout << "Tests:----------------\nTest-1 = " << t1 << "\nTest-2 = " << t2 << "\nTest-3 = " << t3 << "\nTest-4 = " << t4 << endl;
	cout << "\nWeighted Average = " << Avg << endl;
	cout << "Grade: " << grade << endl;
}