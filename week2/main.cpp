#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

int main(){
    Simple_window win { Point{100,100},800,1000,"My Window" };
    Lines grid;

    //DRAW GRID
    for(int i = 100; i < win.x_max(); i+=100){
        grid.add(Point{i,0}, Point{i, win.y_max()});
    }
    for(int i = 100; i < win.y_max(); i+=100){
        grid.add(Point{0,i}, Point{win.x_max(), i});
    }
    
/*     Rectangle rect00 {Point{0,0},100,100};
    Rectangle rect01 {Point{100,100},100,100};
    Rectangle rect02 {Point{200,200},100,100};
    Rectangle rect03 {Point{300,300},100,100};
    Rectangle rect04 {Point{400,400},100,100};
    Rectangle rect05 {Point{500,500},100,100};
    Rectangle rect06 {Point{600,600},100,100};
    Rectangle rect07 {Point{700,700},100,100};
 */
    Vector_ref<Rectangle> vr;
    win.attach(grid);

    for(int i = 0; i<8; ++i){
        vr.push_back(new Rectangle{Point{i*100,i*100},100,100});
        vr[vr.size()-1].set_fill_color(Color::red);
        win.attach(vr[vr.size()-1]);
    }

/*     rect00.set_fill_color(Color::red);
    rect01.set_fill_color(Color::red);  
    rect02.set_fill_color(Color::red);  
    rect03.set_fill_color(Color::red);  
    rect04.set_fill_color(Color::red);  
    rect05.set_fill_color(Color::red);  
    rect06.set_fill_color(Color::red);  
    rect07.set_fill_color(Color::red);  */ 

    Image smoll0 {Point{0,200}, "200x200.jpg"};
    Image smoll1 {Point{200,0}, "200x200.jpg"};
    Image smoll2 {Point{400,0}, "200x200.jpg"};

    Image moving {Point {100,100}, "100x100.jpg"};

    win.attach(smoll0);
    win.attach(smoll1);
    win.attach(smoll2);

    win.attach(moving);

 /*    win.attach(rect00);
    win.attach(rect01);
    win.attach(rect02);
    win.attach(rect03);
    win.attach(rect04);
    win.attach(rect05);
    win.attach(rect06);
    win.attach(rect07); */
    
    while (true){
        win.wait_for_button();
        moving.move(100,0);
    }    
}