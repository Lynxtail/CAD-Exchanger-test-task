#include <iostream>
#include <cmath>

#include "Curves.h"

using namespace std;

Helix::Helix(double _radius, double _step) {
    if (_radius >= 0)
        radius = _radius;
    else
        radius = 0; // default value
    step = _step;
}

double Helix::get_params() const { return radius, step; }

double Helix::get_x(double t) const {
    return (radius + step * t) * cos(t);
}

double Helix::get_y(double t) const {
    return (radius + step * t) * sin(t);
}

double Helix::get_z(double t) const {
    return t;
}

double Helix::get_der_x(double t) const {
    return step * cos(t) + (radius + step * t) * (-sin(t));
}

double Helix::get_der_y(double t) const {
    return step * sin(t) + (radius + step * t) * cos(t);
}

double Helix::get_der_z(double t) const {
    return 1.;
}

void Helix::get_info(double t) const {
    cout << "Helix:\n";
    cout << "Point at t = " << t << " {";
    cout << get_x(t) << ", ";
    cout << get_y(t) << ", ";
    cout << get_z(t) << "}\n";
    cout << "3D vector at t = " << t << " {";
    cout << get_der_x(t) << ", ";
    cout << get_der_y(t) << ", ";
    cout << get_der_z(t) << "}\n";
}