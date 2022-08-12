
//Harry Patel

#include <iostream>
#include<string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<vector>


using namespace std;
const double PI = 3.14159;

//Abstract base class shape
class Shape {
private:
	string color;

public:
	Shape(string argColor);

	void setColor(string);
	string getColor(void);

	virtual double calculatePerimeter() = 0;
	virtual double calculateArea() = 0;
	virtual void displayInfo(void);

	~Shape();
};

class Polygon : public Shape {
private:
	int numberOfSides;
	double length;

public:

	Polygon(string argColor = "Transperant", int argSides = 3, double argl = 1.0);

	void setsides(int argsides);
	int getsides(void);

	void setLength(double argl);
	double getLength(void);


	double calculatePerimeter();
	double calculateArea();
	void displayInfo(void);

	~Polygon();
};

class Prism :public Polygon {
private:
	double base;
	double height;
public:
	Prism(string argColor = "Transperant", int argSides = 3, double argl = 1.0, double argb = 1, double argh = 1);

	void setBase(int argb);
	double getBase(void);

	void setHeight(double argh);
	double getHeight(void);

	void displayInfo(void);
	~Prism();
};



int main() {
	srand(time(0));

	vector<Shape*> myPoly;
	vector<Polygon*> myPrism;

	//Polygon* myPoly = new Polygon[3];
	//Prism* myPrism = new Prism[3];
	myPoly.push_back(new Polygon("Black", 5, 7));
	myPoly.push_back(new Polygon("Yellow", 4, 9));
	myPoly.push_back(new Polygon("Blue", 3, 8));

	myPrism.push_back(new Prism("Green", 5, 7.9, 4, 9));
	myPrism.push_back(new Prism("Orange", 8, 8.9, 2, 8));
	myPrism.push_back(new Prism("Brown", 7, 7.5, 6.5, 8));

	for (int i = 0; i < 3; i++) {
		cout << "Polygon " << i + 1 << ": " << typeid(*myPoly[i]).name() << endl;
		// polymorphism here 
		myPoly[i]->displayInfo();
		cout << endl;
	}
	//Memory Management
	while (!myPoly.empty()) {
		delete myPoly.back();
		myPoly.pop_back();
	}
	cout << "-------------------" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Prism " << i + 1 << ": " << typeid(*myPrism[i]).name() << endl;
		// polymorphism here 
		myPrism[i]->displayInfo();
		cout << endl;
	}
	//Memory Management
	while (!myPrism.empty()) {
		delete myPrism.back();
		myPrism.pop_back();
	}

	system("pause");
	return 0;
}




Shape::Shape(string argColor) {
	setColor(argColor);
}
void Shape::setColor(string arg) {
	color = arg;
}
string Shape::getColor(void) {
	return(color);
}
void Shape::displayInfo(void) {
	cout << "Color: " << getColor() << endl;
}

Shape::~Shape() {

}


Polygon::Polygon(string argColor, int argSides, double argl) : Shape(argColor) {
	Shape::setColor(argColor);

	setsides(argSides);
	setLength(argl);

}

void Polygon::setsides(int argsides) {
	if (argsides < 3)
		numberOfSides = 3;
	else
		numberOfSides = argsides;
}
int Polygon::getsides(void) {
	return numberOfSides;
}

void Polygon::setLength(double argl) {
	if (argl < 0)
		length = 0;
	else
		length = argl;
}
double Polygon::getLength(void) {
	return length;
}

double Polygon::calculatePerimeter() {
	return getsides() * getLength();
}
double Polygon::calculateArea() {
	int s = getsides();
	double l = getLength();
	return s * (l * l) / (4 * tan(PI / s));
}

Prism::Prism(string argColor, int argSides, double argl, double argb, double argh) {
	Polygon::setsides(argSides);
	Polygon::setLength(argl);

	setBase(argb);
	setHeight(argh);
}

void Prism::setBase(int argb) {
	if (argb < 0)
		base = 0;
	else
		base = argb;
}
double Prism::getBase(void) {
	return base;
}

void Prism::setHeight(double argh) {
	if (argh < 0)
		height = 0;
	else
		height = argh;
}
double Prism::getHeight(void) {
	return height;
}



void Polygon::displayInfo(void) {

	//cout << "Name: " << getName() << endl;
	cout << endl;
	Shape::displayInfo();
	cout << "Number of Sides = " << getsides() << endl;
	cout << "Length = " << getLength() << " unit " << endl;
	cout << "Perimeter = " << calculatePerimeter() << " unit " << endl;
	cout << "Area = " << calculateArea() << " square unit " << endl;
}
void Prism::displayInfo(void) {
	Polygon::displayInfo();
	//Area and Perimeter would be wrong-------****
	cout << "color= " << getColor() << endl;
	cout << "Base = " << getBase() << " unit" << endl;
	cout << "Height = " << getHeight() << " unit" << endl;
}

Polygon::~Polygon() {

}
Prism::~Prism() {

}