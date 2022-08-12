
//Harry Patel

#include <iostream>
#include<string>
#include <cmath>
#include <cstdlib>
#include <ctime>


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



int main() {
	srand(time(0));

	int n;
	cout << "Enter number of Polygons: ";
	cin >> n;

	Polygon* myPoly = new Polygon[n];

	for (int i = 0; i < n; i++) {

		int sides = rand() % 10;
		double length = rand() % 99;

		myPoly[i].setsides(sides);
		myPoly[i].setLength(length);
		
	}

	for (int j = 0; j < n; j++) {
		cout << "\nPolygon " << j + 1;
		myPoly[j].displayInfo();
		cout << endl;
	}

	delete[] myPoly;
	//myPoly = nullptr;
	myPoly = NULL;


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

void Polygon::displayInfo(void) {

	//cout << "Name: " << getName() << endl;
	cout << endl;
	//Shape::displayInfo();
	cout << "Number of Sides = " << getsides() << endl;
	cout << "Length = " << getLength() << " unit " << endl;
	cout << "Perimeter = " << calculatePerimeter() << " unit " << endl;
	cout << "Area = " << calculateArea() << " square unit " << endl;
}

Polygon::~Polygon() {
	
}