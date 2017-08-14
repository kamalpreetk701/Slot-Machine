#pragma once
#include<array>
#include"Shape.h"
using namespace std;

#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H
class SlotMachine
{
private:
	int bet;
	int token=10;
	std::array<Shape*, 3> shape_reel{};
	void make_shapes();
	void make_shapes(int r);
	void report_status();
	void release_shapes();
	void display_shapes();
	
public:
	
	void run();
	virtual ~SlotMachine();

};
#endif