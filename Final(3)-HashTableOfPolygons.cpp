

//Harry Patel

#include <iostream>
#include <cmath>
#include<ctime>
#include <cstdlib>
#include<list>

using namespace std;

class Polygon {
private:
	int side;
	double radius;
public:
	Polygon(int args, double argr);

	void setSides(int args);
	int getSides(void);

	void setRadii(double argr);
	double getRadii(void);
	
};
int sides(void);
double radii(void);
int hashFunction(int ID, int tableSize);
bool compare(Polygon* arg1, Polygon* arg2);
void simplePrintTable(list<Polygon*> arg[], int size);

int main() {
	srand(time(0));

	const int size = 10;
	list<Polygon*> myList;
	list<Polygon*> hashTable[size];
	list<Polygon*>::iterator itr;
	
	int i = 0;
	while (i <= 100) {
		myList.push_back(new Polygon(sides(), radii()));
		i++;
	}
	
	itr = myList.begin();
	myList.sort(compare);
	
	while (itr != myList.end()) {
		int key = hashFunction((*itr)->getSides(), size);
		hashTable[key].push_back(new Polygon((*itr)->getSides(), (*itr)->getRadii()));
		itr++;
	}

	hashTable->sort(compare);
	simplePrintTable(hashTable, size);
	
	//Memory Management
	while (!myList.empty()){
		delete myList.back();
		myList.pop_back();
	}
	while (hashTable->empty()) {
		delete hashTable->back();
		hashTable->pop_back();
	}

	system("pause");
	return 0;
}

Polygon::Polygon(int args, double argr) {
	setSides(args);
	setRadii(argr);
}
void Polygon::setSides(int args) {
	side = args;
}
int Polygon::getSides(void) {
	return side;
}

void Polygon::setRadii(double argr) {
	radius = argr;
}
double Polygon::getRadii(void) {
	return radius;
}

int sides(void) {
	int s;
	s = rand() % 26;
	if (s >= 3 && s <= 25) {
		return s;
	}
	else {
		return 3;
	}
}
double radii(void) {
	double r;
	r = rand() % 201;
	if (r >= 1 && r <= 200) {
		return r / 10;
	}
	else {
		return 0.1;
	}
}

int hashFunction(int ID, int tableSize) {
	return(ID % tableSize);
}
bool compare(Polygon* arg1, Polygon* arg2) {
	return(arg1->getRadii() < arg2->getRadii());
}

void simplePrintTable(list<Polygon*> arg[], int size) {
	// Print the buckets...
	list<Polygon*>::iterator myItr;

	for (int i = 0; i < size; i++) {
		cout << "bucket " << i << " ==> ";
		myItr = arg[i].begin();

		while (myItr != arg[i].end()) {
			cout << "S = " << (*myItr)->getSides() << " ";
			cout << "R = " << (*myItr)->getRadii()<<"|";
			myItr++;
		}
		
		cout << endl << endl;
	}
}