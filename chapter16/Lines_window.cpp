#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-150,0}, 70, 20, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-70,0}, 70, 20, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{x_max()-310,0}, 50, 20, "next x:"},
    next_y{Point{x_max()-210,0}, 50, 20, "next y:"},
    xy_out{Point{100,0}, 100, 20, "current (x,y):"},
    color_menu{Point{x_max()-70,30},70,20,Menu::vertical,"color"},
    style_menu{Point{x_max()-70,90},70,20,Menu::vertical,"style"},
    menu_button{Point{x_max()-80,30},80,20,"color menu", cb_menu}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);
    color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
    color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
    color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
    style_menu.attach(new Button{Point{0,0},0,0,"dot",cb_style_menu1});
    style_menu.attach(new Button{Point{0,0},0,0,"solid",cb_style_menu2});
    attach(color_menu);
    attach(style_menu);
    color_menu.hide();
    style_menu.hide();
    attach(menu_button);
    attach(lines);    
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

void Lines_window::cb_red(Address, Address adr)
{
    reference_to<Lines_window>(adr).red_pressed();
}

void Lines_window::cb_blue(Address, Address adr)
{
    reference_to<Lines_window>(adr).blue_pressed();
}

void Lines_window::cb_black(Address, Address adr)
{
    reference_to<Lines_window>(adr).black_pressed();
}

void Lines_window::cb_menu(Address, Address adr)
{
    reference_to<Lines_window>(adr).menu_pressed();
}

void Lines_window::cb_style_menu1(Address, Address adr)
{
    reference_to<Lines_window>(adr).style_menu1_pressed();
}
void Lines_window::cb_style_menu2(Address, Address adr)
{
    reference_to<Lines_window>(adr).style_menu2_pressed();
}