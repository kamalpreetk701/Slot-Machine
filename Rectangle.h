#pragma once
#include"Shape.h"

using namespace std;

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public Shape
{
private:
	int height;
	int width;
	int getHeight();
	int getWidth();
public:
	//Rectangle(int, int);
	Rectangle(int h=4, int w=5, string dname="Generic Rectangle");
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
	
	friend  ostream & operator<<(ostream&, Rectangle r) ;
};
#endif 
