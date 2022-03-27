#include "GUI.h"
#include "Graph.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	Open_polyline lines;

	bool wait_for_button();

private:
	Button next_button;
	Button quit_button;
	Button menu_button;

	Menu color_menu;
	Menu style_menu;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	void next();
	void quit();
	void change(Color c){lines.set_color(c);}
	void change_style(Line_style ls){lines.set_style(ls);}
	void hide_menu(){color_menu.hide(); style_menu.hide(); menu_button.show();}
	void red_pressed(){change(Color::red); hide_menu();}
	void blue_pressed(){change(Color::blue); hide_menu();}
	void black_pressed(){change(Color::black); hide_menu();}
	void style_menu1_pressed(){change_style(Line_style::dot); hide_menu();}
	void style_menu2_pressed(){change_style(Line_style::solid); hide_menu();}
	void menu_pressed(){ menu_button.hide(); color_menu.show(); style_menu.show();}

	static void cb_red(Address, Address);	
	static void cb_blue(Address, Address);
	static void cb_black(Address, Address);	
	static void cb_menu(Address, Address);
	static void cb_next(Address, Address);	
	static void cb_quit(Address, Address);
	static void cb_style_menu1(Address, Address);
	static void cb_style_menu2(Address, Address);





};