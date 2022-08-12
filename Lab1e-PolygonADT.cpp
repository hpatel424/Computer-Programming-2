
//Harry Patel

#include <iostream>
#include<string>
#include <cmath>

using namespace std;
const double PI= 3.14159;

//Abstract base class shape
class Shape {
private:
	string color;

public:
	Shape(string argColor = "transparent");

	void setColor(string);
	string getColor(void);

	virtual double calculatePerimeter() = 0;
	virtual double calculateArea() = 0;
	virtual void displayInfo(void);

};

class Polygon : public Shape {
private:
	int numberOfSides;
	double length;
	string name;

public:
	Polygon(string argColor, int argSides = 3, double argl = 1.0, string argName = "");

	void setsides(int argsides);
	int getsides(void);

	void setLength(double argl);
	double getLength(void);

	void setName(string argName);
	string getName(void);

	double calculatePerimeter();
	double calculateArea();
	void displayInfo(void);

};



int main() {

	Polygon obj("Blue");
	obj.displayInfo();
	cout << endl;

	Polygon a("white", 4, 5.5, "square");
	a.displayInfo();
	cout << endl;

	Polygon b("Yellow");
	b.setsides(5);
	b.setLength(8);
	b.setName("Pentagon");
	b.displayInfo();
	cout << endl;

	Polygon c("orange", 6, 10);
	c.displayInfo();
	cout << endl;
	
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


Polygon::Polygon(string argColor, int argSides, double argl, string argName) : Shape(argColor) {
	Shape::setColor(argColor);

	setsides(argSides);
	setLength(argl);
	setName(argName);
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

void Polygon::setName(string argName) {
	int s = getsides();

	if (s == 3)
		name = "Triangle";
	else if (s == 4)
		name = "Square";
	else if (s == 5)
		name = "Pentagon";
	else if (s == 6)
		name = "Hexagon";
	else
		name = argName;
}
string Polygon::getName(void) {
	return name;
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
	
	cout << "Name: " << getName() << endl;
	Shape::displayInfo();
	cout << "Number of Sides = " << getsides() << endl;
	cout << "Length = " << getLength() << " unit " << endl;
	cout << "Perimeter = " << calculatePerimeter() << " unit " << endl;
	cout << "Area = " << calculateArea() << " square unit " << endl;
}