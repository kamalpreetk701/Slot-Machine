#pragma once
#include"Shape.h"
#include"Triangle.h"
#include "Isosceles.h"
#include <iomanip> // setprecision
#include <sstream>
using namespace std;



int Isosceles::getHeight()
{
	
	return height;
}


Isosceles::Isosceles(int b, string dname) : Triangle(b % 2 == 0 ? ++b:b , "Isosceles Triangle", dname)
{
	height = (getBase() + 1) / 2;
}



string Isosceles::toString() const
{	
	ostringstream output;
	output << std::setprecision(2) << std::fixed;
	output << "SHAPE INFORMATION\n----------------"<<endl;
	output<<std:: setw(17) << std::left <<"Static Type : "<<typeid(this).name()<<endl;
	output<<std::setw(17)<<"Dynamic Type:"<< typeid(this).name();
	output<<std:: setw(17) << "\nGeneric Name: "<<get_generic_name();
	output<<std::setw(17)<<"\nDescription: "<<this->get_descriptive_name();
	output<<std::setw(17)<<"\nId: "<<this->get_identitiy_number();
	output<<std::setw(17)<<"\nB. box Width : "<<this->boundingbox_width();
	output<<std::setw(17)<<"\nB. box Height: "<<this->boundingbos_height();
	output<<std::setw(17)<<"\nSrc Area: "<<this->screen_area();
	output << std::setw(17) << "\nGeo Area: " << this->geometricArea();
	output<<std::setw(17)<<"\nSrc perimeter: "<<this->screen_perimeter();
	output<<std::setw(17)<<"\nGeo Perimeter: "<<this->perimeter();
	 string x=output.str();
	return x;
}




void Isosceles::scale(int n)
{
	if ((getBase() + 2*n) >= 1)
	{
		setBase(getBase() + 2*n);
		this->height = (getBase()+1)/2;
	}
}


float Isosceles::geometricArea() const
{
	int b = getBase();
	return height*b/(double)2;
}




float Isosceles::perimeter() const
{
	int b = getBase();
	return getBase()+2*sqrt(0.25*b*b+height*height);
}


int Isosceles::boundingbox_width() const
{
	return getBase();
}


int Isosceles::boundingbos_height() const
{
	return height;
}


int Isosceles::smallest_box() const
{
	return height*getBase();
}


int Isosceles::screen_area() const
{
	return height*height;
}


int Isosceles::screen_perimeter() const
{
	return 4 * (height -1);
}


void Isosceles::draw_on_screen(char penchar, char fillchar)
{
	vector<vector<char>> grid = draw(penchar, fillchar);
	cout << grid;
}


vector<vector<char>> Isosceles::draw(char penchar, char fillchar)
{
	vector<vector<char>> grid;
	int h = this->getHeight();
	int b = this->getBase();
	grid.resize(h);
	for (size_t x = 0; x < grid.size(); x++)
	{
		grid[x].resize(b);
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0 ; j < b ; j++)
		{
			grid[i][j] = fillchar;
		}
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = h - i-1; j < h; j++)
		{
			grid[i][j] = penchar;
		}
	}

	for (int i = 1; i < h; ++i)
	{
		int j, k;
		for (j = h,k=1; k <= i ; ++j,k++){
			grid[i][j] = penchar;	
			}
		}
	return grid;
}

ostream & operator<<(ostream & out, Isosceles i)
{
	out << i.toString();
	return out;
}
