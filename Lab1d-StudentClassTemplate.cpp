

//Harry Patel
#include<iostream>
#include<string>

using namespace std;

template <class T>
class Student {
private:
	string firstName, lastName;
	int ID;
	T test[4];
	float weight[4];
	
public:
	Student(string arg1 = "N/A", string arg2 = "N/A", int arg3 = 0, T argt[] = {}, float argw[] = {});

	string getFirstName(void);
	void setFirstName(string first);

	string getLastName(void);
	void setLastName(string last);

	int getID(void);
	void setID(int id);

	float* getWeight(void);
	void setWeight(float arg[]);

	T* getTest(void);
	void setTest(T arg[]);

	T getWeightedAvg(void);
	char getGrade(void);

	void print(void);
};

int main() {

	string first = "stud1";
	string last = "stud2";
	float weights[4] = { 0.10, 0.15, 0.25, 0.50 };
	double tests[4] = { 85.5,83,96,77 };

	Student<double> one("bill", last, 111, tests, weights);
	one.print();

	float w[4] = { 0.20,0.30,0.25,0.25 };
	int t[4] = { 97,89,92,88 };
	Student<int> two("eric", "tom", 222, t, w);
	cout << "-------------\n";
	two.print();

	system("pause");
	return 0;
}

template <class T>
Student<T>::Student(string arg1, string arg2, int arg3, T argt[] , float argw[]) {
	setFirstName(arg1);
	setLastName(arg2);
	setID(arg3);
	setWeight(argw);
	setTest(argt);

	
}

template <class T>
float* Student<T>::getWeight(void) {
	return weight;
}
template <class T>
void Student<T>::setWeight(float arg[]) {
	for (int i = 0; i < 4; i++) {
		weight[i] = arg[i];
	}
}
template <class T>
T* Student<T>::getTest(void) {
	return test;
}
template <class T>
void Student<T>::setTest(T arg[]) {
	for (int i = 0; i < 4; i++) {
		if (arg[i] >= 0){
			test[i] = arg[i];
		}
		else
			arg[i] = 0;
	}
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
T Student<T>::getWeightedAvg(void) {
	float w1 = weight[0];
	float w2 = weight[1];
	float w3 = weight[2];
	float w4 = weight[3];

	T t1 = test[0];
	T t2 = test[1];
	T t3 = test[2];
	T t4 = test[3];

	
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
	float* wptr = getWeight();
	T* tptr = getTest();

	T Avg = getWeightedAvg();
	char grade = getGrade();

	cout <<"First Name: "<< fName << endl;
	cout << "Last Name: " << lName << endl;
	cout << "ID: " << id<< endl;
	for (int i = 0; i < 4; i++) {
		cout << "Test " << i+1 << ") weight = " << wptr[i] << endl;
		cout << "Test " << i + 1 << ") = " << tptr[i] << endl;
	}


	//cout << "Weights:-------------- \nW1 = " << w1 << "\nW2 = " << w2 << "\nW3 = " << w3 << "\nW4 = " << w4 << endl;
	//cout << "Tests:----------------\nTest-1 = " << t1 << "\nTest-2 = " << t2 << "\nTest-3 = " << t3 << "\nTest-4 = " << t4 << endl;
	cout << "\nWeighted Average = " << Avg << endl;
	cout << "Grade: " << grade << endl;
	
}