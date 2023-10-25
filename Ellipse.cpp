#include <iostream>
#include <cmath>

#include "Curves.h"

using namespace std;


Ellipse::Ellipse(double _radius_x, double _radius_y) {
    if (_radius_x >= 0 || _radius_y >= 0) {
        radius_x = _radius_x; radius_y = _radius_y;
    }
    else {
        radius_x = 0; radius_y = 0; // default value
    }
}

double Ellipse::get_params() const { return radius_x, radius_y; }

double Ellipse::get_x(double t) const {
    return radius_x * cos(t);
}

double Ellipse::get_y(double t) const {
    return radius_y * sin(t);
}

double Ellipse::get_z(double t) const {
    return 0.;
}

double Ellipse::get_der_x(double t) const {
    return -radius_x * sin(t);
}

double Ellipse::get_der_y(double t) const {
    return radius_y * cos(t);
}

double Ellipse::get_der_z(double t) const {
    return 0.;
}

void Ellipse::get_info(double t) const {
    cout << "Ellipse:\n";
    cout << "Point at t = " << t << " {";
    cout << get_x(t) << ", ";
    cout << get_y(t) << ", ";
    cout << get_z(t) << "}\n";
    cout << "3D vector at t = " << t << " {";
    cout << get_der_x(t) << ", ";
    cout << get_der_y(t) << ", ";
    cout << get_der_z(t) << "}\n";
}