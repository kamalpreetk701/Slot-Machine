#include "Triangle.h"

int Triangle::getBase() const
{
	//if (base % 2 == 0)
	//	base++;
	return base;
}

void Triangle::setBase(int b)
{
	if (b <= 0)
		b = 1;
	base = b;
}

Triangle::Triangle(int b, string gname, string dname) : Shape(gname, dname)
{
	if (b <= 0)
		b = 1;
	base= b ;
}






