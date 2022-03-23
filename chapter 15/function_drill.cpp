#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

double one(double x) {return 1;};
double slope(double x) {return x/2;};
double square(double x) {return x*x;};
double cosSlope(double x) {return cos(x) + slope(x);};

int main(){

    Simple_window win { Point{100,100}, 600, 600, "Function graphs"};

    Axis x {Axis::x, Point{0,300}, 400, 400/20, "1==20 pixels"};
    Axis y {Axis::y, Point{300,400}, 400, 400/20, "1==20 pixels"};
    x.set_color(Color::red);
    y.set_color(Color::red);

    /* Function o {one, -10,11, Point{300,300},400}; */
    Function o {one, -10,11, Point{300,300},400,20,20};
    Function s {slope, -10,11, Point{300,300},400,20,20};
    Function sq {square, -10,11, Point{300,300},400,20,20};
    Function co {cos, -10,11, Point{300,300},400,20,20};
    Function coSl {cosSlope, -10,11, Point{300,300},400,20,20};

    Text t {Point{100,375}, "x/2"};


    win.attach(x);
    win.attach(y);
    win.attach(o);
    win.attach(t);
    win.attach(sq);
    win.attach(s);
    win.attach(co);
    co.set_color(Color::blue);
    win.attach(coSl);
    win.wait_for_button();


    return 0;
}