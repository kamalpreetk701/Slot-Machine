#pragma once

#include<iostream>
#include<string>
#include<vector>
using namespace std;

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
protected:
	int identity_number;
	string generic_name;
	string descriptive_name;
	static int id;
	 
public:
	Shape(string gnmae="Shape", string dname="Shape");
	int get_identitiy_number() const;
	string get_generic_name() const;
	string get_descriptive_name() const;
	void set_descriptive_name(string);
	virtual string toString() const=0;
	virtual void scale(int)=0;
	virtual float geometricArea() const=0;
	virtual float perimeter()const=0;
	virtual vector<vector<char>> draw(char,char)=0;
	virtual int boundingbox_width() const=0;
	virtual int boundingbos_height()const=0;
	virtual int smallest_box() const=0;
	virtual int screen_area() const=0;
	virtual int screen_perimeter() const=0;
	virtual void draw_on_screen(char,char) =0;
	friend  ostream & operator<<(ostream&, vector<vector<char>>);
};

#endif
