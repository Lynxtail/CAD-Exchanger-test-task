#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double PI = 3.14159265359;

/* 1 task */

class Curve{
    public:
        virtual double get_params() const = 0;

        virtual double get_x(double t) const = 0;
        virtual double get_y(double t) const = 0;
        virtual double get_z(double t) const = 0;

        virtual double get_der_x(double t) const = 0;
        virtual double get_der_y(double t) const = 0;
        virtual double get_der_z(double t) const = 0;

        virtual void get_info(double t) const = 0;
};

class Circle : public Curve{
    private:
        double radius;
    
    public:
        Circle(double _radius) {
            if (_radius >= 0)
                radius = _radius;
            else
                radius = 0; // default value
        }

        double get_params() const override { return radius; }

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

        void get_info(double t) const override {
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
};

class Ellipse : public Curve{
    private:
        double radius_x;
        double radius_y;
    
    public:
        Ellipse(double _radius_x, double _radius_y) {
            if (_radius_x >= 0 || _radius_y >= 0) {
                radius_x = _radius_x; radius_y = _radius_y;
            }
            else {
                radius_x = 0; radius_y = 0; // default value
            }
        }

        double get_params() const override { return radius_x, radius_y; }

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

        void get_info(double t) const override {
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
};

class Helix : public Curve{
    private:
        double radius;
        double step;
    
    public:
        Helix(double _radius, double _step) {
            if (_radius >= 0)
                radius = _radius;
            else
                radius = 0; // default value
            step = _step;
        }

        double get_params() const override { return radius, step; }

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

        void get_info(double t) const override {
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
};

bool compare(Curve* a, Curve* b){
    return a->get_params() < b->get_params();
}

int main(){

    /* 2 task */
    vector<Curve*> first_v;
    int cur_type; 
    srand(time(NULL));
    for (int i = 0; i < 5; i++){
        cur_type = rand() % 3;
        switch (cur_type)
        {
        case 0:
            // circle
        {
            double radius = rand() % 15 + 1; // [1, 15]
            first_v.push_back(new Circle(radius));
            break;
        }
        case 1:
            // ellipse
        {
            double radius_x = rand() % 15 + 1; // [1, 15]
            double radius_y = rand() % 15 + 1; // [1, 15]
            first_v.push_back(new Ellipse(radius_x, radius_y));
            break;
        }
        default:
            // helix
            double radius = rand() % 15 + 1; // [1, 15]
            double step = rand() % 10 + 1; // [1, 10]
            first_v.push_back(new Helix(radius, step));
            break;
        }
    }

    /* 3 task */
    for (Curve* item : first_v){
        item->get_info(PI / 4);
        cout << endl;
    }

    /* 4 task */
    vector<Curve*> second_v;
    for (Curve* item : first_v){
        if (typeid(*item) == typeid(Circle)) { 
            second_v.push_back(item);        
        }

    }

    /* 5 task */
    sort(second_v.begin(), second_v.end(), compare);

    /* 6 task */
    double sum = 0;
    for (Curve* item : second_v){
        sum += item->get_params();
    }
    cout << "Total sum of radii of all cirles: " << sum << endl;

    return 0;
}