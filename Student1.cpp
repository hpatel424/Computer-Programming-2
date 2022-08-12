#include "Student1.h"

#include<iostream>
#include<string>

using namespace std;

int main() {

	Student1 <int>A("ABC", "DEF", 111, 0.10, 0.15, 0.25, 0.50);
	A.setT1(85.5);
	A.setT2(83);
	A.setT3(96.2);
	A.setT4(77);

	Student1 <float>B;
	B.setFirstName("GHI");
	B.setLastName("JKL");
	B.setID(222);
	B.setW1(0.10), B.setW2(0.10), B.setW3(0.30), B.setW4(0.50);
	B.setT1(99.78), B.setT2(92.66), B.setT3(87.07), B.setT4(74);

	cout << A.getWeight(0) << endl;

	A.print();
	cout << endl;
	B.print();

	system("pause");
	return 0;
}

template <class T>
Student1<T>::Student1(string arg1, string arg2, int arg3, float w1, float w2, float w3, float w4, T t1, T t2, T t3, T t4, int n1) {
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

	setWeight(n1, 0);

}

template <class T>
string Student1<T>::getFirstName(void) {
	return firstName;
}
template <class T>
void Student1<T>::setFirstName(string first) {
	firstName = first;
}

template <class T>
string Student1<T>::getLastName(void) {
	return lastName;
}
template <class T>
void Student1<T>::setLastName(string last) {
	lastName = last;
}

template <class T>
int Student1<T>::getID(void) {
	return ID;
}
template <class T>
void Student1<T>::setID(int id) {
	ID = id;
}


template <class T>
float Student1<T>::getW1(void) {
	return w1;
}
template <class T>
void Student1<T>::setW1(float W1) {
	w1 = W1;
}
template <class T>
float Student1<T>::getW2(void) {
	return w2;
}
template <class T>
void Student1<T>::setW2(float W2) {
	w2 = W2;
}
template <class T>
float Student1<T>::getW3(void) {
	return w3;
}
template <class T>
void Student1<T>::setW3(float W3) {
	w3 = W3;
}
template <class T>
float Student1<T>::getW4(void) {
	return w4;
}
template <class T>
void Student1<T>::setW4(float W4) {
	w4 = W4;
}


template <class T>
T Student1<T>::getT1(void) {
	return t1;
}
template <class T>
void Student1<T>::setT1(T test1) {
	if (test1 <= 0)
		t1 = 0;
	else
		t1 = test1;
}
template <class T>
T Student1<T>::getT2(void) {
	return t2;
}
template <class T>
void Student1<T>::setT2(T test2) {
	if (test2 <= 0)
		t2 = 0;
	else
		t2 = test2;
}
template <class T>
T Student1<T>::getT3(void) {
	return t3;
}
template <class T>
void Student1<T>::setT3(T test3) {
	if (test3 <= 0)
		t3 = 0;
	else
		t3 = test3;
}
template <class T>
T Student1<T>::getT4(void) {
	return t4;
}
template <class T>
void Student1<T>::setT4(T test4) {
	if (test4 <= 0)
		t4 = 0;
	else
		t4 = test4;
}


template <class T>
T Student1<T>::getWeightedAvg(void) {
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
char Student1<T>::getGrade(void) {
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
void Student1<T>::print(void) {
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