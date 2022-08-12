#pragma once

namespace utility {

	const double PI = 3.14;
	
}

namespace areaOfShapes {

	double areaOfCircle(double radius);
	double areaOfTriangle(double base, double height);
	double areaOfSquare(double length);
	double areaOfRectangle(double length, double width);
	double areaOfPolygon(int sides, double length);
}