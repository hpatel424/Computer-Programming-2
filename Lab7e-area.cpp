

#include<iostream>
#include <cmath>
#include "area.h";
using namespace std;

double areaOfShapes::areaOfCircle(double radius) {
	return utility::PI* radius* radius;
}

double areaOfShapes::areaOfTriangle(double base, double height) {
	return (base * height) / 2;
}

double areaOfShapes::areaOfSquare(double length) {
	return length * length;
}

double areaOfShapes::areaOfRectangle(double length, double width) {
	return length * width;
}

double areaOfShapes::areaOfPolygon(int sides, double length) {
	return sides * (length * length) / (4 * tan(utility::PI / sides));
}