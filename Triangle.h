
#pragma once
#include"Shape.h"

using namespace std;

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle :public Shape
{
private:
	int base;
	
	public:
	int getBase() const;
	void setBase(int b);
	Triangle(int b = 5, string gname = "Triangle", string dname = "Generic Triangle");
	
};
#endif 
