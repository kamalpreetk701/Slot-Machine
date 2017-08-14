#pragma once
#include"Shape.h"
#include "Rhombus.h"
#include <iomanip> // setprecision
#include <sstream>
using namespace std;



int Rhombus::getDiagonal() const
{
	return diagonal;
}


Rhombus::Rhombus(int d, string dname) : Shape("Rhombus", dname)
{
	if (d < 1)
		diagonal = 1;
	if (d % 2 == 0)
		diagonal = d + 1;
	else
		diagonal = d;	
}



string Rhombus::toString() const
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




void Rhombus::scale(int n)
{
	if ((getDiagonal() + 2 * n) >= 1)
	{
		diagonal=diagonal + 2 * n;
	}
}


float Rhombus::geometricArea() const
{
	return pow(diagonal,2)/ 2;
}




float Rhombus::perimeter() const
{
	
	return  2 * sqrt(2)*getDiagonal();
}


int Rhombus::boundingbox_width() const
{
	return getDiagonal();
}


int Rhombus::boundingbos_height() const
{
	return  getDiagonal();
}


int Rhombus::smallest_box() const
{
	return  getDiagonal()* getDiagonal();
}


int Rhombus::screen_area() const
{
	int n = getDiagonal() / 2;
	return 2*n*(n+1)+1;
}


int Rhombus::screen_perimeter() const
{
	return 2 * (getDiagonal() - 1);
}


void Rhombus::draw_on_screen(char penchar, char fillchar)
{
	vector<vector<char>> grid = draw(penchar, fillchar);
	cout << grid;
}


vector<vector<char>> Rhombus::draw(char penchar, char fillchar)
{
	vector<vector<char>> grid;
	int d = this->getDiagonal();
	
	int h = d / 2 + 1;
	grid.resize(d);
	for (size_t x = 0; x < grid.size(); x++)
	{
		grid[x].resize(d);
	}

	for (int i = 0; i < d; ++i)
	{
		for (int j = 0; j < d; j++)
		{
			grid[i][j] = fillchar;
		}
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = h - i - 1; j < h; j++)
		{
			grid[i][j] = penchar;
		}
	}

	for (int i = 1; i < h; ++i)
	{
		int j, k;
		for (j = h, k = 1; k <= i; ++j, k++) {
			grid[i][j] = penchar;
	}
	}

	for (int i = h; i < d; ++i)
	{
		int j, k;
		for (j = h-1,k=d-i; k >0; j--,k--)
		{
			grid[i][j] = penchar;
		}
	}
	

	for (int i = h; i < d-1; ++i)
	{
		int j, k;
		for (j = h, k = i; k < d-1; ++j, k++)
		{
			grid[i][j] = penchar;
		}
	}
	
	
	return grid;
}

ostream & operator<<(ostream & out, Rhombus i)
{

	out << i.toString();

	return out;
}
