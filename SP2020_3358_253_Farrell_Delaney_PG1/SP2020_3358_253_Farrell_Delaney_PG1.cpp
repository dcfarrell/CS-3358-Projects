// Author / s : Delaney Farrell
// Serial Number / s : 9
// Due Date : 02/05/2020
// Programming Assignment Number 1
// Spring 2020 - CS 3358 - 253
//
// Instructor: Husain Gholoom.
//
// Returns information about circles from the radius.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.1415926; // constant pi

//******************************************************************************
// circleType.h
//
// Private: double radiusOfCircle
// Public: Constructors: circleType(), circleType(double radius),
// Functions: setRadius, getRadius, getCircumference, getDiameter,
// getArea
// Returns information about circle according from radiusOfCircle
//******************************************************************************
class circleType {

public:
    circleType(); // default constructor
    circleType(double radius); // constructor

    void setRadius(double radius); // sets radiusOfCircle to radius

    double getRadius(); // returns radiusOfCircle
    double getCircumference(); // returns circumference
    double getDiameter(); // returns diameter
    double getArea(); // returns area

private:
    double radiusOfCircle; // Radius of Circle
};

//******************************************************************************
// circleTypeImp.cpp
//
// Implements circleType functions.
//******************************************************************************
// Default constructor of circleType. Sets radiusOfCircle to zero
//******************************************************************************
circleType::circleType() {
    setRadius(0);
}

//******************************************************************************
// Constructor of circleType. Sets radiusOfCircle to radius.
//
// parameter(s): double radius
//******************************************************************************
circleType::circleType(double radius) {
    setRadius(radius);
}

//******************************************************************************
// Sets radiusOfCircle to radius.
//
// parameter(s): double radius
//******************************************************************************
void circleType::setRadius(double radius) {
    radiusOfCircle = radius;
}

//******************************************************************************
// Gets radiusOfCircle
//
// Returns radiusOfCircle
//******************************************************************************
double circleType::getRadius() {
    return radiusOfCircle;
}

//******************************************************************************
// Calculates circumference
//
// Returns circumference
//******************************************************************************
double circleType::getCircumference() {
    return getDiameter()*PI;
}

//******************************************************************************
// Calculates diameter
//
// Returns diameter
//******************************************************************************
double circleType::getDiameter() {
    return 2*radiusOfCircle;
}

//******************************************************************************
// Calculates area
//
// Returns area
//******************************************************************************
double circleType::getArea() {
    return PI*pow(radiusOfCircle, 2);
}

//******************************************************************************
// circleTypeDriver.cpp
//
// Tests circleType.h and circleTypeImp.cpp to make sure they work
// correctly
//******************************************************************************
int main()
{
    double userInput; // holds user input for radius

    cout << "The purpose of this program is to implement the basic properties"
         " of a circle\n" << endl;

    circleType circle1(8);
    circleType circle2;

    cout << "Circle1 - Radius: " << fixed << setprecision(2)
         << circle1.getRadius() << ", Area: " << circle1.getArea()
         << ", Circumference: " << circle1.getCircumference()
         << ", Diameter: " << circle1.getDiameter() << endl;
    cout << "Circle2 - Radius: " << circle2.getRadius() << ", Area: "
         << circle2.getArea() << ", Circumference: " << circle2.getCircumference()
         << ", Diameter: " << circle2.getDiameter() << "\n" << endl;

    cout << "Enter the Radius of a Circle: ";
    cin >> userInput;

    circle2.setRadius(userInput);

    cout << "After setting the radius." << endl;
    cout << "Circle2 - Radius: " << circle2.getRadius() << ", Area: "
         << circle2.getArea() << ", Circumference: " << circle2.getCircumference()
         << ", Diameter: " << circle2.getDiameter() << endl;

    cout << "\nImplemented by Delaney Farrell" << endl;
    cout << "February 5th - 2020" << endl;

    return 0;
}
