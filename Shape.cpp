#include "Shape.h"

int Shape::id = 0;



Shape::Shape(string gname, string dname)
{
	generic_name = gname;
	descriptive_name = dname;
	++id;
	identity_number = id;
}

 int Shape::get_identitiy_number() const
{
	 return identity_number;
}

string Shape::get_generic_name() const
{
	return generic_name;
}

string Shape::get_descriptive_name() const
{
	return descriptive_name;
}

void Shape::set_descriptive_name(string str)
{
	descriptive_name = str;
}

ostream & operator<<(ostream & out, vector<vector<char>> grid)
{
	for (size_t r = 0; r < grid.size(); r++)
	{
		for (size_t c = 0; c < grid[r].size(); c++)
		{
			out << grid[r][c];
		}
		out << endl;
	}
	return out;
}
