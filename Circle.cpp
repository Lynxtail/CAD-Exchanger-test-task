#include <iostream>
#include <cmath>

#include "Curves.h"

using namespace std;

Circle::Circle(double _radius) {
    if (_radius >= 0)
        radius = _radius;
    else
        radius = 0; // default value
}

double Circle::get_params() const { return radius; }

double Circle::get_x(double t) const {
    return radius * cos(t);
}

double Circle::get_y(double t) const {
    return radius * sin(t);
}

double Circle::get_z(double t) const {
    return 0.;
}

double Circle::get_der_x(double t) const {
    return -radius * sin(t);
}

double Circle::get_der_y(double t) const {
    return radius * cos(t);
}

double Circle::get_der_z(double t) const {
    return 0.;
}

void Circle::get_info(double t) const {
    cout << "Circle:\n";
    cout << "Point at t = " << t << " {";
    cout << get_x(t) << ", ";
    cout << get_y(t) << ", ";
    cout << get_z(t) << "}\n";
    cout << "3D vector at t = " << t << " {";
    cout << get_der_x(t) << ", ";
    cout << get_der_y(t) << ", ";
    cout << get_der_z(t) << "}\n";
}