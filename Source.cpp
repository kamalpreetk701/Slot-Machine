#include "Rectangle.h"
#include "Isosceles.h"
#include"Rhombus.h"
#include "RightTriangle.h"
#include"SlotMachine.h"
using namespace std;


int main()
{
	Rectangle r(12, 30, "heelo");
	cout << r;
	SlotMachine s;
	s.run();
	cin.get();
	
}