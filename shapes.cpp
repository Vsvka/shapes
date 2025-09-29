
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

//General declaration
class Shape {
public:
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual const char* name() const = 0;  
    virtual ~Shape() = default;
};

//for circle
class Circle : public Shape {
    double r;
public:
    Circle(double radius) : r(radius) {}
    double getArea() const override { return M_PI * r * r; }
    double getPerimeter() const override { return 2 * M_PI * r; }
    const char* name() const override { return "Circle"; }
};


//for Rectangle
class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double width, double height) : w(width), h(height) {}
    double getArea() const override { return w * h; }
    double getPerimeter() const override { return 2 * (w + h); }
    const char* name() const override { return "Rectangle"; }
private:
    double width() const { return w; }
    double height() const { return h; }
};

//for RightTriangle
class RightTriangle : public Shape {
    double b, h;
public:
    RightTriangle(double base, double height) : b(base), h(height) {}
    double getArea() const override { return 0.5 * b * h; }
    double getPerimeter() const override { return b + h + std::sqrt(b*b + h*h); }
    const char* name() const override { return "RightTriangle"; }
private:
    double baseLen() const { return b; }
    double heightLen() const { return h; }
};


//for Rectangle
class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}
    const char* name() const override { return "Square"; }
};

//for IsoscelesRightTriangle
class IsoscelesRightTriangle : public RightTriangle {
public:
    IsoscelesRightTriangle(double leg) : RightTriangle(leg, leg) {}
    const char* name() const override { return "IsoscelesRightTriangle"; }
};


//function for printing values
void printAreaToScreen(Shape* form) {
    if (form) {
        cout << form->name() << ":\n" << "Area: " << form->getArea()<< "\nPerimeter: " << form->getPerimeter()<< "\n \n";
    }
}

//main function for declarations
int main() {
    
    Circle circ(5);
    printAreaToScreen(&circ);
    assert(abs(circ.getArea() - (M_PI * 25)) < 0.000001);
    assert(abs(circ.getPerimeter() - (2 * M_PI * 5)) < 0.000001);



    Rectangle rectan(4, 6);
    printAreaToScreen(&rectan);
    assert(rectan.getArea() == 24);
    assert(rectan.getPerimeter() == 20);



    RightTriangle triangle(3, 4);
    printAreaToScreen(&triangle);
    assert(triangle.getArea() == 6);
    assert(triangle.getPerimeter() == 12);



    Square form(5);
    printAreaToScreen(&form);
    assert(form.getArea() == 25);
    assert(form.getPerimeter() == 20);



    IsoscelesRightTriangle irightrTriang(1.0);
    printAreaToScreen(&irightrTriang);
    assert(abs(irightrTriang.getArea() - 0.5) < 0.000001);
    assert(abs(irightrTriang.getPerimeter() - (2.0 + sqrt(2.0))) < 0.000001);

    cout << "Passed!\n";
}