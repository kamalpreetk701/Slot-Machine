
#include<iostream>
#include"Rectangle.h"
#include<typeinfo>
#include"Shape.h"
#include <typeinfo>
#include <iomanip> // setprecision
#include <sstream>

using namespace std;


Rectangle::Rectangle(int w,int h,string dname):  Shape("Rectangle", dname)
{
	if (h < 1)
		h = 1;
	if (w < 1)
		w = 1;
	height = h;
	width= w ;
}


int Rectangle::getHeight()
{
	return height;
}

int Rectangle::getWidth()
{
	return width;
}

string Rectangle::toString() const
{
	ostringstream output;
	output << std::setprecision(2) << std::fixed;
	output << "SHAPE INFORMATION\n----------------" << endl;
	output << std::setw(17) << std::left << "Static Type : " << typeid(this).name() << endl;
	output << std::setw(17) << "Dynamic Type:" << typeid(this).name();
	output << std::setw(17) << "\nGeneric Name: " << get_generic_name();
	output << std::setw(17) << "\nDescription: " << this->get_descriptive_name();
	output << std::setw(17) << "\nId: " << this->get_identitiy_number();
	output << std::setw(17) << "\nB. box Width : " << this->boundingbox_width();
	output << std::setw(17) << "\nB. box Height: " << this->boundingbos_height();
	output << std::setw(17) << "\nSrc Area: " << this->screen_area();
	output << std::setw(17) << "\nGeo Area: " << this->geometricArea();
	output << std::setw(17) << "\nSrc perimeter: " << this->screen_perimeter();
	output << std::setw(17) << "\nGeo Perimeter: " << this->perimeter();
	string x = output.str();
	return x;
}




void Rectangle::scale(int n)
{
	if ((height + n) >= 1 && (width + n) >= 1)

	{
		this->height = height + n;
		this->width = width + n;
	}
}


float Rectangle::geometricArea() const
{
	return height*width;
}


float Rectangle::perimeter() const
{
	return 2*(height+width);
}


int Rectangle::boundingbox_width() const
{
	return width;
}


int Rectangle::boundingbos_height() const
{
	return height;
}


int Rectangle::smallest_box() const
{
	return height*width;
}


int Rectangle::screen_area() const
{
	return height*width;
}


int Rectangle::screen_perimeter() const
{
	return 2*(height+width)-4;
}


void Rectangle::draw_on_screen(char penchar , char fillchar) 
{
	vector<vector<char>> grid = draw(penchar, fillchar);
	cout << grid;
}


vector<vector<char>> Rectangle::draw(char penchar, char fillchar) 
{
	vector<vector<char>> grid;
	int h = this->getHeight();
	int w = this->getWidth();
	grid.resize(h);
	for (size_t x = 0; x < grid.size(); x++)
	{
		grid[x].resize(w);
	}

	for (size_t r = 0; r < h; r++)
	{
		for (size_t c = 0; c < w; c++)
		{
			grid[r][c] = penchar;
		}
		
	}
	
	return grid;
}

ostream & operator<<(ostream & out, Rectangle r)
{
	
			out<<r.toString();
		
	return out;
}
