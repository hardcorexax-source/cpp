#include <iostream>
#include <string>
#include <vector>

using namespace std;

class figure() {
    double x;
    double y;
  public:
    figure() : x(0), y(0) {}
    figure() : x(x), y(y) {}
    virtual double perimetr();
    virtual double area();
};

class round : public figure {
    double perimetr() {
        return x*y*3.14;
    }
};

class round : public figure {
    round() : figure(0,0) {}
    round(x,y) : figure(x,y) {}
    double perimetr() {
        return x/2*3.14;
    }
    double area() {
        return x/2*y/2*3.14;
    }
};

class quadr : public figure {
    double perimetr() {
        return 2*(x+y);
    }
    double area() {
        return x*y;
    }
};

int main() {
    
    vector<figure> arr;

    arr.push_back(quadr(2,2));
    arr.push_back(round(2,2));

    cout << arr[0].area() << arr[1].area() << endl;
    cout << arr[0].perimetr() << arr[1].perimetr() << endl;

    return 0;
}