
#pragma once
#include"Shape.h"
#include "Triangle.h"
using namespace std;

#ifndef RHOMBUS_H
#define RHOMBUS_H

class  Rhombus:public Shape
{
private:

	int diagonal;
	int getDiagonal() const;

public:

	Rhombus(int d = 5, string dname = "Generic Rhombus");
	string toString() const override;
	vector<vector<char>> draw(char penchar = '*', char fillchar = ' ') override;
	virtual void scale(int) override;
	virtual float geometricArea() const override;
	virtual float perimeter() const override;
	virtual int boundingbox_width() const override;
	virtual int boundingbos_height() const override;
	virtual int smallest_box() const override;
	virtual int screen_area() const override;
	virtual int screen_perimeter() const override;
	virtual void draw_on_screen(char penchar = '*', char fillchar = ' ') override;

	friend  ostream & operator<<(ostream&, Rhombus i);
};
#endif 
