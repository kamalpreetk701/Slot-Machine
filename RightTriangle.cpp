#pragma once
#include"Shape.h"
#include"Triangle.h"
#include "RightTriangle.h"
#include <iomanip> // setprecision
#include <sstream>
using namespace std;



int RightTriangle::getHeight()
{
	return height;
}


RightTriangle::RightTriangle(int b, string dname) :Triangle(b, "Right Triangle", dname) 
{
	if (b <= 0)
		b = 1;
		height = b;
}



string RightTriangle::toString() const
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




void RightTriangle::scale(int n)
{
	if ((getBase() + n) >= 1)
	{
		setBase(getBase() +  n);
		this->height = height+n;
	}
}


float RightTriangle::geometricArea() const
{
	int b = getBase();
	return height*b / 2;
}




float RightTriangle::perimeter() const
{
	return (2+sqrt(2))*height;
}


int RightTriangle::boundingbox_width() const
{
	return getBase();
}


int RightTriangle::boundingbos_height() const
{
	return height;
}


int RightTriangle::smallest_box() const
{
	return height*getBase();
}


int RightTriangle::screen_area() const
{
	return height*(height+1)/2;
}


int RightTriangle::screen_perimeter() const
{
	return 3 * (height - 1);
}


void RightTriangle::draw_on_screen(char penchar, char fillchar)
{
	vector<vector<char>> grid = draw(penchar, fillchar);
	cout << grid;
}


vector<vector<char>>RightTriangle::draw(char penchar, char fillchar)
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
		for (int j = 0; j <b; ++j)
		{
			grid[i][j] = fillchar;
		}
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j <=i; ++j)
		{
			grid[i][j] = penchar;
		}
	}
	return grid;
}

ostream & operator<<(ostream & out, RightTriangle i)
{
	out << i.toString();
	return out;
}
