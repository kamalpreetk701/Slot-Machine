#include "SlotMachine.h"
#include"Rhombus.h"
#include"Isosceles.h"
#include"Rectangle.h"
#include"RightTriangle.h"
#include<ctime>

void SlotMachine::make_shapes()
{
	srand(time(NULL));
	for (int i = 0; i <3; i++)
	{
		make_shapes(i);
	}
}

void SlotMachine::make_shapes(int r)
{
	int h = 10;
	
	int n = rand() % 4;
	
	int w = rand() % 25;
	
	if (n == 0)
		shape_reel[r] = new Rhombus(w);
	else if (n == 1)
		shape_reel[r] = new Isosceles(w);
	else if (n == 2)
		shape_reel[r] =new RightTriangle(w);
	else
		shape_reel[r] = new Rectangle(h,w);
}


void SlotMachine::report_status()
{
	string shape1 = shape_reel[0]->get_generic_name();
	int height1 = shape_reel[0]->boundingbos_height();
	int width1= shape_reel[0]->boundingbox_width();

	string shape2 = shape_reel[1]->get_generic_name();
	int height2 = shape_reel[1]->boundingbos_height();
	int width2 = shape_reel[1]->boundingbox_width();

	string shape3 = shape_reel[2]->get_generic_name();
	int height3 = shape_reel[2]->boundingbos_height();
	int width3 = shape_reel[2]->boundingbox_width();

	cout << "(" << shape1 << "," << height1 << "," << width1 << ")   (" << shape2 << "," << height2 << "," << width2;
	cout << ") (" << shape3 << "," << height3 << "," << width3 << ")"<<endl;

	if (shape1 == shape2&&shape2 == shape3)
	{
		if ((width1 == width2&&width2 == width3)&&(height1==height2&&height2==height3))
		
			token = token + bet * 3;
		
		else
			token =token+ bet * 2;
		cout << "you win your bet " << endl;
	}
	else if(shape1 == shape2||shape2 == shape3||shape1==shape3)
	{
		cout << "you don't win ,you don't lose,you are safe " << endl;
	}
	else
	{
		token = token - bet;
		cout << "you loose your bet " << endl;
	}
	cout << "you now have " <<token  <<"tokens"<<endl<<endl;

}


void SlotMachine::release_shapes()
{
	for (int i = 0; i < 3; i++)
	{
		delete shape_reel[i];
	}
	
}

void SlotMachine::display_shapes()
{
	
	vector<vector<char>> grid1=shape_reel[0]->draw('*', ' ');
	vector<vector<char>> grid2 =shape_reel[1]->draw('*',' ');
	vector<vector<char>> grid3 = shape_reel[2]->draw('*', ' ');
	

	int gridheight1 = grid1.size();
	int gridheight2 = grid2.size();
	int gridheight3 = grid3.size();

	int gridwidth1 = grid1[0].size();
	int gridwidth2 = grid2[0].size();
	int gridwidth3 = grid3[0].size();


	int height = gridheight1 > gridheight2 ? gridheight1: gridheight2;

	height =( height > gridheight3 ? height : gridheight3)+4;
	int width = gridwidth1 + gridwidth2 + gridwidth3+10;

	

	vector<vector<char>> outer_grid;
	
	
	outer_grid.resize(height);
	

	for (size_t x = 0; x < height; x++)
	{
		outer_grid[x].resize(width);
	}


	for (size_t x = 0; x < height; x++)
	{
		for (size_t y = 0; y < width; y++)
		{
			if ((x == 0 && y == 0) || (x == height - 1 && y == 0) || (x == 0 && y == width - 1) || (x == height - 1 && y == width - 1))
				outer_grid[x][y] = '+';
			else if (x == 0)
				outer_grid[0][y] = '-';
			else if (x == height - 1)
				outer_grid[height - 1][y] = '-';
			else if (y == 0 || y == width - 1)
				outer_grid[x][y] = '|';
			else if (y == gridwidth1 + 3)
				outer_grid[x][y] = '|';
			else if (y == gridwidth1 + gridwidth2 + 6)
				outer_grid[x][y] = '|';
			else
				outer_grid[x][y] = ' ';
			 if ((x == 0 && y == gridwidth1 + 3)||(x==height-1&&y== gridwidth1 + 3))
				outer_grid[x][y] = '+';
			 if((x == 0 && y == gridwidth1 + gridwidth2 + 6) || (x == height - 1 && y == gridwidth1 + gridwidth2 + 6))
				outer_grid[x][y] = '+';
			

		}
		
	}
	
	
		for (size_t x = 2; x<gridheight1+2; x++)
		{
			for (size_t y = 2; y < gridwidth1+2; y++)
			{
				outer_grid[x][y] = grid1[x-2][y-2];
			}
			
		}
		

		for (size_t x = 2; x < gridheight2+2; x++)
		{
			for (size_t y = gridwidth1+5; y <gridwidth2+5+ gridwidth1; y++)
			{
				outer_grid[x][y] = grid2[x-2][y- gridwidth1-5];
			}	
		}
		

		for (size_t x = 2; x <gridheight3+2; x++)
		{
				for (size_t y = (8 + gridwidth1 + gridwidth2); y <gridwidth3+8 + gridwidth1 + gridwidth2; y++)
			{
				outer_grid[x][y] = grid3[x-2][y-( 8 + gridwidth1 + gridwidth2)];
			}	
		}
		
		cout << outer_grid;
}

void SlotMachine::run()
{
	cout << "Welcome to this 3-Reel Slot Machine Game!\nEach reel will randomly display one of four shapes,each in 25 sizes" << endl;
	cout << "To win 3 times your bet you need 3 similar shapes of the same size." << endl;
	cout << "To win 2 times your bet you need 3 similar shapes." << endl;
	cout << "To win or loose nothing you need 2 similar shapes." << endl;
	cout << "Otherwise you lose your bet.\nYou start with 10 free tokens.\n ";
	
		
	do{
		if (token <= 0)
		{
			cout << "No more Tokens......";
			getchar();
			break;
		}
		cout << "How much would you like to bet(enter 0 to quit) ? : ";
		cin >> bet;

		if (token<bet)
		{
			cout << "You dont have enough  token" << endl;
			cout << "How much would you like to bet(enter 0 to quit) ? : ";
			cin >> bet;
		}
		make_shapes();
		display_shapes();
		report_status();
		
		cout << endl;
	} while (bet != 0);

	cout << "Game Over";
}

SlotMachine::~SlotMachine()
{
}
