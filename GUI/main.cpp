#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

int main(){
    Simple_window win { Point{100,100},600,400,"My Window" };
    Image img {Point{100,100}, "handsome.jpg"};

    Text title {Point{50,50}, "Love at first sight <3"};
	title.set_font(NewFont::times_bold);
	title.set_font_size(20);

    Axis x {Axis::x, Point{200,300}, 200, 100/20, "x axis"};
    Axis y {Axis::y, Point{200,300}, 200, 100/20, "y axis"};

    Function cosfunc {cos,0,100,Point{200,200},1000,50,50};

    Polygon pol;
        pol.add(Point{60,130});
        pol.add(Point{30,150});
        pol.add(Point{80,220});
        pol.add(Point{130,150});
        pol.add(Point{100,130});
        pol.add(Point{80,150});
        pol.set_fill_color(Color::red);

    win.attach(img);
    win.attach(pol);
    win.attach(title);
    win.attach(x);
    win.attach(y);
    win.attach(cosfunc);
    win.wait_for_button();
}