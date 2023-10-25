#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

/* 1 task */
#include "Curves.h"

using namespace std;

const double PI = 3.14159265359;


bool compare(Curve* a, Curve* b){
    return a->get_params() < b->get_params();
}

int main(){

    /* 2 task */
    vector<Curve*> first_v;
    int cur_type; 
    srand(time(NULL));

    cout << "First vector:" << endl;
    for (int i = 0; i < 5; i++){
        cur_type = rand() % 3;
        switch (cur_type)
        {
        case 0:
            // circle
        {
            double radius = rand() % 15 + 1; // [1, 15]
            cout << "Circle " << i << " with radius " << radius << endl;
            first_v.push_back(new Circle(radius));
            break;
        }
        case 1:
            // ellipse
        {
            double radius_x = rand() % 15 + 1; // [1, 15]
            double radius_y = rand() % 15 + 1; // [1, 15]
            cout << "Ellipse " << i << " with a, b (" << radius_x << ", " << radius_y << ")" << endl;
            first_v.push_back(new Ellipse(radius_x, radius_y));
            break;
        }
        default:
            // helix
            double radius = rand() % 15 + 1; // [1, 15]
            double step = rand() % 10 + 1; // [1, 10]
            cout << "Helix " << i << " with radius " << radius << ", step " << step << endl;
            first_v.push_back(new Helix(radius, step));
            break;
        }
    }
    cout << endl;

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
    cout << "Second vector:" << endl;
    for (Curve* item : second_v){
        cout << "Circle " << "with radius " << item->get_params() << endl;
    }
    cout << endl;

    /* 6 task */
    double sum = 0;
    for (Curve* item : second_v){
        sum += item->get_params();
    }
    cout << "Total sum of radii of all cirles: " << sum << endl;

    return 0;
}