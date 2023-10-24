#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

const double PI = 3.14159265359;

class Curve{
    public:
        virtual double get_x(double t) const = 0;
        virtual double get_y(double t) const = 0;
        virtual double get_z(double t) const = 0;

        virtual double get_der_x(double t) const = 0;
        virtual double get_der_y(double t) const = 0;
        virtual double get_der_z(double t) const = 0;

        virtual void get_info() const = 0;
        virtual ~Curve() {}
};

class Circle : public Curve{
    private:
        double radius;
    
    public:
        Circle(double radius);

        double get_x(double t) const override {
            return radius * cos(t);
        }

        double get_y(double t) const override {
            return radius * sin(t);
        }

        double get_z(double t) const override {
            return 0.;
        }

        double get_der_x(double t) const override {
            return -radius * sin(t);
        }

        double get_der_y(double t) const override {
            return radius * cos(t);
        }

        double get_der_z(double t) const override {
            return 0.;
        }

        void get_info() const override {
            cout << "Circle:\n";
            cout << "x = " << get_x(PI / 4) << ", ";
            cout << "y = " << get_y(PI / 4) << ", ";
            cout << "z = " << get_z(PI / 4) << "\n";
            cout << "dx / dt = " << get_der_x(PI / 4) << ", ";
            cout << "dy / dt = " << get_der_y(PI / 4) << ", ";
            cout << "dz / dt = " << get_der_z(PI / 4) << "\n";

        }
};

class Ellipse : public Curve{
    private:
        double radius_x;
        double radius_y;
    
    public:
        Ellipse(double radius_x, double radius_y);

        double get_x(double t) const override {
            return radius_x * cos(t);
        }

        double get_y(double t) const override {
            return radius_y * sin(t);
        }

        double get_z(double t) const override {
            return 0.;
        }

        double get_der_x(double t) const override {
            return -radius_x * sin(t);
        }

        double get_der_y(double t) const override {
            return radius_y * cos(t);
        }

        double get_der_z(double t) const override {
            return 0.;
        }

        void get_info() const override {
            cout << "Ellipse:\n";
            cout << "x = " << get_x(PI / 4) << ", ";
            cout << "y = " << get_y(PI / 4) << ", ";
            cout << "z = " << get_z(PI / 4) << "\n";
            cout << "dx / dt = " << get_der_x(PI / 4) << ", ";
            cout << "dy / dt = " << get_der_y(PI / 4) << ", ";
            cout << "dz / dt = " << get_der_z(PI / 4) << "\n";

        }
};

class Helix : public Curve{
    private:
        double radius;
        double step;
    
    public:
        Helix(double radius, double step);

        double get_x(double t) const override {
            return (radius + step * t) * cos(t);
        }

        double get_y(double t) const override {
            return (radius + step * t) * sin(t);
        }

        double get_z(double t) const override {
            return t;
        }

        double get_der_x(double t) const override {
            return step * cos(t) + (radius + step * t) * (-sin(t));
        }

        double get_der_y(double t) const override {
            return step * sin(t) + (radius + step * t) * cos(t);
        }

        double get_der_z(double t) const override {
            return 1.;
        }

        void get_info() const override {
            cout << "Helix:\n";
            cout << "x = " << get_x(PI / 4) << ", ";
            cout << "y = " << get_y(PI / 4) << ", ";
            cout << "z = " << get_z(PI / 4) << "\n";
            cout << "dx / dt = " << get_der_x(PI / 4) << ", ";
            cout << "dy / dt = " << get_der_y(PI / 4) << ", ";
            cout << "dz / dt = " << get_der_z(PI / 4) << "\n";

        }
};

int main(){
    cout << "Hey!\n";
    return 0;
}