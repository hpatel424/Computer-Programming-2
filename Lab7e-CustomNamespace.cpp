

#include<iostream>
#include<cmath>
#include "area.h";


int main() {

	std::cout << "Area of Diffrent shapes" << std::endl;

	std::cout << "PI = " << utility::PI << std::endl;

	std::cout << "Area of a circle = " << areaOfShapes::areaOfCircle(2) << " squared units" << std::endl;
	std::cout << "Area of a Triangle = " << areaOfShapes::areaOfTriangle(2, 4) << " squared units" << std::endl;
	std::cout << "Area of a Square = " << areaOfShapes::areaOfSquare(5) << " squared units" << std::endl;
	std::cout << "Area of a rectangle = " << areaOfShapes::areaOfRectangle(3, 6) << " squared units" << std::endl;
	std::cout << "Area of any regular polygon = " << areaOfShapes::areaOfPolygon(7, 9) << " squared units" << std::endl;


	system("pause");
	return 0;
}
